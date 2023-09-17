#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <sstream>

#include <utils/Math.hpp>
#include <utils/Math.cpp> // pybind seems not only to need the header but also the source

namespace py = pybind11;

void init_utils(py::module &m) {
    py::class_<math::vector>(m, "vec")
        .def(py::init([](const std::list<double>& l) {
            return math::vector(l.begin(), l.end());
        }))
        .def("__getitem__", [](const math::vector &v, size_t index) {
            if (index >= v.size()) {
                throw py::index_error();
            }
            return v[index];
        })
        .def("__setitem__", [](math::vector &v, size_t index, double value) {
            if (index >= v.size()) {
                throw py::index_error();
            }
            v[index] = value;
        })
        .def("__len__", [](const math::vector &v) {
            return v.size();
        })
        .def("__iter__", [](const math::vector &v) {
            return py::make_iterator(v.begin(), v.end());
        }, py::keep_alive<0, 1>())
        .def("__str__", [](const math::vector &v) {
            std::ostringstream oss;
            oss << "[";
            for (size_t i = 0; i < v.size(); ++i) {
                oss << v[i];
                if (i < v.size() - 1) {
                    oss << ", ";
                }
            }
            oss << "]";
            return oss.str();
        })
        .def("__add__", &math::vector::operator+, py::is_operator())
        .def("__sub__", &math::vector::operator-, py::is_operator())
        .def("__mul__", [](const math::vector& v, double scalar) {
            return v*scalar;
        })
        .def("__rmul__", [](const math::vector& v, double scalar) {
            return scalar * v;
        });

    m.def("norm", &norm);
    m.def("dot", &dot);
    m.def("cross", &cross);
}
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <bodies/Body.hpp>

namespace py = pybind11;

void init_bodies(py::module &m) {
    py::class_<Body>(m, "Body")
        .def(py::init<double, math::vector>())
        .def(py::init<std::string, double, math::vector>())
        .def(py::init([](double m, std::list<double>& l) {
            return Body{m, math::vector(l.begin(), l.end())};
        }))
        .def(py::init([](std::string n, double m, std::list<double>& l) {
            return Body{n, m, math::vector(l.begin(), l.end())};
        }))
        .def("set_name", &Body::set_name)
        .def("get_pos", &Body::get_pos)
        .def("get_vel", &Body::get_vel)
        .def("get_sv", &Body::get_sv)
        .def("get_mass", &Body::get_mass)
        .def("get_name", &Body::get_name);
}
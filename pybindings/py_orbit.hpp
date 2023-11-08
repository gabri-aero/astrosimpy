#include <pybind11/pybind11.h>
#include <orbit/Orbit.hpp>
#include <orbit/StateVector.hpp>
#include <sstream>

namespace py = pybind11;

void init_orbit(py::module &m) {

    py::class_<Orbit, std::shared_ptr<Orbit>>(m, "Orbit")
        .def(py::init<double, double, double, double, double, double>())
        .def("to_sv", &Orbit::to_sv)
        .def("get_oe", &Orbit::get_oe)
        .def("get_type", &Orbit::get_type)
        .def("__repr__", [](const Orbit& obj) {
            std::ostringstream oss;
            oss << obj;
            return oss.str();
        });

    py::class_<StateVector, std::shared_ptr<StateVector>>(m, "StateVector")
        .def(py::init<double, double, double, double, double, double>())
        .def(py::init<math::vector>())
        .def("to_orbit", &StateVector::to_orbit)
        .def("get_rv", &StateVector::get_rv)
        .def("__repr__", [](const StateVector& obj) {
            std::ostringstream oss;
            oss << obj;
            return oss.str();
        });
}
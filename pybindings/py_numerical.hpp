#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <numerical/Euler.hpp>
#include <numerical/Euler.cpp>
#include <numerical/RK4.hpp>
#include <numerical/RK4.cpp>

namespace py = pybind11;

void init_numerical(py::module &m) {
    
    py::class_<BaseIntegrator, std::shared_ptr<BaseIntegrator>>(m, "BaseIntegrator")
        .def("set_ic", &BaseIntegrator::set_ic)
        .def("set_dX", &BaseIntegrator::set_dX)
        .def("run", &BaseIntegrator::run)
        .def("get_data", &BaseIntegrator::get_data);

    py::class_<Euler, BaseIntegrator, std::shared_ptr<Euler>>(m, "Euler")
        .def(py::init<double>())
        .def("integrate", &Euler::integrate);

    py::class_<RK4, BaseIntegrator, std::shared_ptr<RK4>>(m, "RK4")
        .def(py::init<double>())
        .def("integrate", &RK4::integrate);
}
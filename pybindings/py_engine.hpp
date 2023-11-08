#include <pybind11/pybind11.h>
#include <engine/AstroEngine.hpp>

namespace py = pybind11;

void AstroEngine::add_bodies_py(const std::vector<Body>& body_list) {
    for (const auto& body : body_list) {
        bodies.push_back(body);
    }
};

void init_engine(py::module &m) {
    py::class_<AstroEngine>(m, "AstroEngine")
        .def(py::init<>())
        .def("set_integrator", &AstroEngine::set_integrator)
        .def("run", &AstroEngine::run)
        .def("add_bodies", &AstroEngine::add_bodies_py);
}

#include <pybind11/pybind11.h>
#include "py_utils.hpp" 
#include "py_bodies.hpp" 
#include "py_numerical.hpp"
#include "py_engine.hpp"

namespace py = pybind11;

PYBIND11_MODULE(astrosimpy, m) {
    m.doc() = "Main module for the astrosimpy package";
    
    py::module utils = m.def_submodule("utils", "Utilities submodule");
    py::module bodies = m.def_submodule("bodies", "Bodies submodule");
    py::module numerical = m.def_submodule("numerical", "Numerical submodule");
    py::module engine = m.def_submodule("engine", "Engine submodule");
    init_utils(utils); 
    init_bodies(bodies); 
    init_numerical(numerical);
    init_engine(engine);
}

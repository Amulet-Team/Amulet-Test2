#include <amulet_test1/test1.hpp>
#include <amulet_test2/test2.hpp>

#include <pybind11/pybind11.h>
namespace py = pybind11;

static void init_module(py::module m){
    // pybind11 extension to another shared library
    m.def("test1_1", &Amulet::test1_1);
    m.def("test1_2", &Amulet::test1_2);
    // pybind11 extension to own shared library
    m.def("test2_1", &Amulet::test2_1);
    m.def("test2_2", &Amulet::test2_2);
}

PYBIND11_MODULE(_amulet_test2, m) {
    m.def("init", &init_module);
}

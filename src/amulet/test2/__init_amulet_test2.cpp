#include <pybind11/pybind11.h>
namespace py = pybind11;

static bool init_run = false;

static void init(py::module m){
    if (init_run){ return; }
    init_run = true;

    m.attr("__version__") = py::make_tuple(1, 0, 0);
}

PYBIND11_MODULE(__init__, m) { init(m); }
PYBIND11_MODULE(test2, m) { init(m); }

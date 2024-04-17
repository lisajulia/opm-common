#include <opm/input/eclipse/Schedule/ScheduleState.hpp>

#include "export.hpp"

namespace {
        const Group& get_group(const ScheduleState& st, const std::string& group_name) {
        return st.groups.get(group_name);
    }
}

/**
 * @brief Function to export the ScheduleState class and some methods to Python.
 * 
 * In the below class we use std::shared_ptr as the holder type, see https://pybind11.readthedocs.io/en/stable/advanced/smart_ptrs.html
 * this makes it possible to share the ScheduleState (which is created only once per simulation) with e.g. the opm.simulators.BlackOilSimulator Python object.
 * 
 * @param module Reference to the python module.
 */
void python::common::export_ScheduleState(py::module& module) {

    py::class_<ScheduleState>(module, "ScheduleState")
        .def_property_readonly("nupcol", py::overload_cast<>(&ScheduleState::nupcol, py::const_), R"(
            The NUPCOL value at this Schedule State. This is a positive integer that defines the maximum number of Newton iterations used to update well targets within a time step.
        )")
        .def("group", &get_group, ref_internal, R"(
        Get the group with the specified name from the schedule state.

        Args:
            group_name (str): The name of the group to retrieve from the schedule state.

        Returns:
            group: The group with the specified name from the schedule state.
        )")
        ;
}

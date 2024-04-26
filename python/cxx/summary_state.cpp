/*
  Copyright 2019 Equinor ASA.

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <chrono>

#include <opm/input/eclipse/Schedule/SummaryState.hpp>
#include <opm/common/utility/TimeService.hpp>

#include <pybind11/stl.h>
#include <pybind11/chrono.h>
#include "export.hpp"

namespace {


std::vector<std::string> groups(const SummaryState * st) {
    return st->groups();
}

std::vector<std::string> wells(const SummaryState * st) {
    return st->wells();
}


}


void python::common::export_SummaryState(py::module& module) {

    py::class_<SummaryState, std::shared_ptr<SummaryState>>(module, "SummaryState", R"pbdoc(
            The Opm::SummaryState class - this is where the current summary results of the simulator are stored.
            The SummaryState class has methods to get hold of well, group and general variables.
        )pbdoc")
        .def(py::init<std::time_t>())
        .def("update", &SummaryState::update)
        .def("update_well_var", &SummaryState::update_well_var, R"(
        Update the variable of a well.

        Args:
            well_name (str): The name of the well.
            variable_name (str): The name of the variable to update.
            new_value (double): The new value of the variable.

        Returns:
            None
        )")
        .def("update_group_var", &SummaryState::update_group_var, R"(
        Update the variable of a group.

        Args:
            group_name (str): The name of the group.
            variable_name (str): The name of the variable to update.
            new_value (double): The new value of the variable.

        Returns:
            None
        )")
        .def("well_var", py::overload_cast<const std::string&, const std::string&>(&SummaryState::get_well_var, py::const_), R"(
        Get the value of a variable for a well.

        Args:
            well_name (str): The name of the well.
            variable_name (str): The name of the variable to retrieve.

        Returns:
            double: The value of the specified variable for the well.
        )")
        .def("group_var", py::overload_cast<const std::string&, const std::string&>(&SummaryState::get_group_var, py::const_), R"(
        Get the value of a variable for a group.

        Args:
            group_name (str): The name of the group.
            variable_name (str): The name of the variable to retrieve.

        Returns:
            double: The value of the specified variable for the group.
        )")
        .def("elapsed", &SummaryState::get_elapsed, R"(
        Return the elapsed time in seconds of the current simulation.

        Returns:
            double: The elapsed time in seconds.
        )")
        .def_property_readonly("groups", groups, R"(
        Return a list of strings containing all group names.

        Returns:
            list: A list of strings representing all group names.
        )")
        .def_property_readonly("wells", wells, R"(
        Return a list of strings containing all well names.

        Returns:
            list: A list of strings representing all well names.
        )")
        .def("__contains__", &SummaryState::has)
        .def("has_well_var", py::overload_cast<const std::string&, const std::string&>(&SummaryState::has_well_var, py::const_),R"(
        Check if a well variable exists.

        Args:
            well_name (str): The name of the well.
            variable_name (str): The name of the variable to check.

        Returns:
            bool: True if the variable exists for the well, False otherwise.
        )")
        .def("has_group_var", py::overload_cast<const std::string&, const std::string&>(&SummaryState::has_group_var, py::const_), R"(
        Check if a group variable exists.

        Args:
            group_name (str): The name of the group.
            variable_name (str): The name of the variable to check.

        Returns:
            bool: True if the variable exists for the group, False otherwise.
        )")
        .def("__setitem__", &SummaryState::set)
        .def("__getitem__", py::overload_cast<const std::string&>(&SummaryState::get, py::const_))
        ;
}

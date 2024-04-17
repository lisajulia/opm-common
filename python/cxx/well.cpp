#include <tuple>

#include <opm/input/eclipse/Schedule/Well/Well.hpp>
#include <opm/input/eclipse/Schedule/Well/WellConnections.hpp>
#include <pybind11/stl.h>
#include "export.hpp"


namespace {

    std::vector<Connection> connections( const Well& w ) {
        const auto& well_connections = w.getConnections();
        return std::vector<Connection>(well_connections.begin(), well_connections.end());
    }

    std::string status( const Well& w )  {
        return WellStatus2String( w.getStatus() );
    }

    std::string preferred_phase( const Well& w ) {
        switch( w.getPreferredPhase() ) {
            case Phase::OIL:   return "OIL";
            case Phase::GAS:   return "GAS";
            case Phase::WATER: return "WATER";
            default: throw std::logic_error( "Unhandled enum value" );
        }
    }

    std::tuple<int, int, double> get_pos( const Well& w ) {
        return std::make_tuple(w.getHeadI(), w.getHeadJ(), w.getRefDepth());
    }

}

void python::common::export_Well(py::module& module) {

    py::class_< Well >( module, "Well")
        .def_property_readonly( "name", &Well::name )
        .def_property_readonly( "preferred_phase", &preferred_phase )
        .def( "pos",             &get_pos, R"(
        Retrieve the position of the well.

        Returns:
            tuple: A tuple containing the (i, j) coordinates and the reference depth of the well.
        )")
        .def( "status",          &status )
        .def( "isdefined",       &Well::hasBeenDefined, R"(
        Check if the well is defined at a specific report step.

        Args:
            report_step (int): The report step to check for the well's definition.

        Returns:
            bool: True if the well is defined at the specified report step, False otherwise.
        )")
        .def( "isinjector",      &Well::isInjector )
        .def( "isproducer",      &Well::isProducer )
        .def( "group",           &Well::groupName )
        .def( "guide_rate",      &Well::getGuideRate )
        .def( "available_gctrl", &Well::isAvailableForGroupControl, R"(
        Check if the well is available for group control.

        Returns:
            bool: True if the well is available for group control, False otherwise.
        )")
        .def( "connections",     &connections, R"(
        Get a list of all connections associated with the well.

        Returns:
            list: A list containing all connections of the well.
        )")
        ;

}

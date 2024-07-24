/*
  Copyright 2013 Statoil ASA.

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

#include <opm/input/eclipse/Schedule/Well/PossibleFutureConnection.hpp>

#include <array>
#include <sstream>

namespace Opm
{

    PossibleFutureConnection::PossibleFutureConnection(const int i, const int j, const int k)
        : ijk              { i, j, k }
    {}

    PossibleFutureConnection PossibleFutureConnection::serializationTestObject()
    {
        PossibleFutureConnection result;
        result.ijk = {9, 10, 11};
        return result;
    }

    int PossibleFutureConnection::getI() const
    {
        return ijk[0];
    }

    int PossibleFutureConnection::getJ() const
    {
        return ijk[1];
    }

    int PossibleFutureConnection::getK() const
    {
        return ijk[2];
    }

    std::string PossibleFutureConnection::str() const
    {
        std::stringstream ss;

        ss << "ijk: " << this->ijk[0] << ','  << this->ijk[1] << ',' << this->ijk[2] << '\n';

        return ss.str();
    }

    bool PossibleFutureConnection::operator==(const PossibleFutureConnection& that) const
    {
        return (this->ijk == that.ijk);
    }


} // end of namespace Opm

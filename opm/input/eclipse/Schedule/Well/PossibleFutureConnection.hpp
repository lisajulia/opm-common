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

#ifndef POSSIBLE_FUTURE_CONNECTION_HPP
#define POSSIBLE_FUTURE_CONNECTION_HPP

#include <array>

namespace Opm {

    class PossibleFutureConnection
    {
    public:
        PossibleFutureConnection() = default;
        PossibleFutureConnection(int i, int j, int k);

        static PossibleFutureConnection serializationTestObject();

        int getI() const;
        int getJ() const;
        int getK() const;
        template<class Serializer>
        void serializeOp(Serializer& serializer)
        {
            serializer(this->ijk);
        }

    private:
        std::array<int,3> ijk{};
    };

} // namespace Opm

#endif // POSSIBLE_FUTURE_CONNECTION_HPP

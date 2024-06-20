#pragma once

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct compute_mat3_transpose {};

    template<RealType T>
    struct compute_mat3_transpose<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix3<T, false>& r, const TMatrix3<T, false>& m1)
        {
            r = TMatrix4<T, false>(m1(0, 0), m1(1, 0), m1(2, 0),
                                   m1(0, 1), m1(1, 1), m1(2, 1),
                                   m1(0, 2), m1(1, 2), m1(2, 2)
                                   );
        }


    };
}
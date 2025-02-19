#pragma once

#include "Core/Math/Boilerplate.h"
#include "Core/Math/MathCommon.hpp"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct compute_mat3_transpose {};

    template<RealType T, bool S>
    struct compute_mat3_mul {};



    template<RealType T>
    struct compute_mat3_transpose<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix3<T, false>& r, const TMatrix3<T, false>& m1)
        {
            r = TMatrix3<T, false>(m1(0, 0), m1(1, 0), m1(2, 0),
                                   m1(0, 1), m1(1, 1), m1(2, 1),
                                   m1(0, 2), m1(1, 2), m1(2, 2)
                                   );
        }
    };

    template<RealType T>
    struct compute_mat3_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix3<T, false>& r, const TMatrix3<T, false>& m1, const TMatrix3<T, false>& m2)
        {
            r(0, 0) = m1(0, 0) * m2(0, 0) + m1(0, 1) * m2(1, 0) + m1(0, 2) * m2(2, 0);
            r(0, 1) = m1(0, 0) * m2(0, 1) + m1(0, 1) * m2(1, 1) + m1(0, 2) * m2(2, 1);
            r(0, 2) = m1(0, 0) * m2(0, 2) + m1(0, 1) * m2(1, 2) + m1(0, 2) * m2(2, 2);

            r(1, 0) = m1(1, 0) * m2(0, 0) + m1(1, 1) * m2(1, 0) + m1(1, 2) * m2(2, 0);
            r(1, 1) = m1(1, 0) * m2(0, 1) + m1(1, 1) * m2(1, 1) + m1(1, 2) * m2(2, 1);
            r(1, 2) = m1(1, 0) * m2(0, 2) + m1(1, 1) * m2(1, 2) + m1(1, 2) * m2(2, 2);

            r(2, 0) = m1(2, 0) * m2(0, 0) + m1(2, 1) * m2(1, 0) + m1(2, 2) * m2(2, 0);
            r(2, 1) = m1(2, 0) * m2(0, 1) + m1(2, 1) * m2(1, 1) + m1(2, 2) * m2(2, 1);
            r(2, 2) = m1(2, 0) * m2(0, 2) + m1(2, 1) * m2(1, 2) + m1(2, 2) * m2(2, 2);
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const TMatrix3<T, false>& m1, const TVector3<T, false>& v)
        {
            r.x = m1(0, 0) * v.x + m1(0, 1) * v.y + m1(0, 2) * v.z;
            r.y = m1(1, 0) * v.x + m1(1, 1) * v.y + m1(1, 2) * v.z;
            r.z = m1(2, 0) * v.x + m1(2, 1) * v.y + m1(2, 2) * v.z;
        }
    };
}
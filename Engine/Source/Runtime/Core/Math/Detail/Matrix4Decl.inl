#pragma once

#include "Core/Math/Boilerplate.h"
#include "Core/Math/MathCommon.hpp"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct compute_mat4_det {};

    template<RealType T, bool S>
    struct compute_mat4_inv {};

    template<RealType T, bool S>
    struct compute_mat4_transpose {};

    template<RealType T, bool S>
    struct compute_mat4_mul {};


    template<RealType T>
    struct compute_mat4_det<T, false>
    {
        static constexpr T map(const Phanes::Core::Math::TMatrix4<T, false>& m)
        {
            const TVector3<T, false>& a = reinterpret_cast<const TVector3<T, false>&>(m[0]);
            const TVector3<T, false>& b = reinterpret_cast<const TVector3<T, false>&>(m[1]);
            const TVector3<T, false>& c = reinterpret_cast<const TVector3<T, false>&>(m[2]);
            const TVector3<T, false>& d = reinterpret_cast<const TVector3<T, false>&>(m[3]);

            const float& x = m(3, 0);
            const float& y = m(3, 1);
            const float& z = m(3, 2);
            const float& w = m(3, 3);

            TVector3<T, false> s = CrossP(a, b);
            TVector3<T, false> t = CrossP(c, d);
            TVector3<T, false> u = a * y - b * x;
            TVector3<T, false> v = c * w - d * z;
            return DotP(s, v) + DotP(t, u);
        }
    };

    template<RealType T>
    struct compute_mat4_inv<T, false>
    {
        static constexpr bool map(Phanes::Core::Math::TMatrix4<T, false>& r, const Phanes::Core::Math::TMatrix4<T, false>& m)
        {
            const TVector3<T, false>& a = reinterpret_cast<const TVector3<T, false>&>(m[0]);
            const TVector3<T, false>& b = reinterpret_cast<const TVector3<T, false>&>(m[1]);
            const TVector3<T, false>& c = reinterpret_cast<const TVector3<T, false>&>(m[2]);
            const TVector3<T, false>& d = reinterpret_cast<const TVector3<T, false>&>(m[3]);
            
            const float& x = m(3, 0);
            const float& y = m(3, 1);
            const float& z = m(3, 2);
            const float& w = m(3, 3);

            TVector3<T, false> s = CrossP(a, b);
            TVector3<T, false> t = CrossP(c, d);
            TVector3<T, false> u = a * y - b * x;
            TVector3<T, false> v = c * w - d * z;

            float _1_det = (T)1.0 / (DotP(s, v) + DotP(t, u));

            if (_1_det == (T)0.0)
            {
                return false;
            }

            s *= _1_det;
            t *= _1_det;
            u *= _1_det;
            v *= _1_det;

            TVector3<T, false> r0 = CrossP(b, v) + t * y;
            TVector3<T, false> r1 = CrossP(v, a) - t * x;
            TVector3<T, false> r2 = CrossP(d, u) + s * w;
            TVector3<T, false> r3 = CrossP(u, c) - s * z;

            r = TMatrix4<T, false>(r0.x, r0.y, r0.z, -DotP(b, t),
                                   r1.x, r1.y, r1.z,  DotP(a, t),
                                   r2.x, r2.y, r2.z, -DotP(d, s),
                                   r3.x, r3.y, r3.z,  DotP(c, s));

            return true;
        }
    };

    template<RealType T>
    struct compute_mat4_transpose<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix4<T, false>& r, const Phanes::Core::Math::TMatrix4<T, false>& m)
        {
            r = Phanes::Core::Math::TMatrix4<T, false>(m(0, 0), m(1, 0), m(2, 0), m(3, 0),
                                                       m(0, 1), m(1, 1), m(2, 1), m(3, 1),
                                                       m(0, 2), m(1, 2), m(2, 2), m(3, 2),
                                                       m(0, 3), m(1, 3), m(2, 3), m(3, 3));
        }
    };

    template<RealType T>
    struct compute_mat4_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix4<T, false>& r, const Phanes::Core::Math::TMatrix4<T, false>& m1, const Phanes::Core::Math::TMatrix4<T, false>& m2)
        {
            r(0, 0) = m1(0, 0) * m2(0, 0) + m1(0, 1) * m2(1, 0) + m1(0, 2) * m2(2, 0) + m1(0, 3) * m2(3, 0);
            r(0, 1) = m1(0, 0) * m2(0, 1) + m1(0, 1) * m2(1, 1) + m1(0, 2) * m2(2, 1) + m1(0, 3) * m2(3, 1);
            r(0, 2) = m1(0, 0) * m2(0, 2) + m1(0, 1) * m2(1, 2) + m1(0, 2) * m2(2, 2) + m1(0, 3) * m2(3, 2);
            r(0, 3) = m1(0, 0) * m2(0, 3) + m1(0, 1) * m2(1, 3) + m1(0, 2) * m2(2, 3) + m1(0, 3) * m2(3, 3);
            
            r(1, 0) = m1(1, 0) * m2(0, 0) + m1(1, 1) * m2(1, 0) + m1(1, 2) * m2(2, 0) + m1(1, 3) * m2(3, 0);
            r(1, 1) = m1(1, 0) * m2(0, 1) + m1(1, 1) * m2(1, 1) + m1(1, 2) * m2(2, 1) + m1(1, 3) * m2(3, 1);
            r(1, 2) = m1(1, 0) * m2(0, 2) + m1(1, 1) * m2(1, 2) + m1(1, 2) * m2(2, 2) + m1(1, 3) * m2(3, 2);
            r(1, 3) = m1(1, 0) * m2(0, 3) + m1(1, 1) * m2(1, 3) + m1(1, 2) * m2(2, 3) + m1(1, 3) * m2(3, 3);

            r(2, 0) = m1(2, 0) * m2(0, 0) + m1(2, 1) * m2(1, 0) + m1(2, 2) * m2(2, 0) + m1(2, 3) * m2(3, 0);
            r(2, 1) = m1(2, 0) * m2(0, 1) + m1(2, 1) * m2(1, 1) + m1(2, 2) * m2(2, 1) + m1(2, 3) * m2(3, 1);
            r(2, 2) = m1(2, 0) * m2(0, 2) + m1(2, 1) * m2(1, 2) + m1(2, 2) * m2(2, 2) + m1(2, 3) * m2(3, 2);
            r(2, 3) = m1(2, 0) * m2(0, 3) + m1(2, 1) * m2(1, 3) + m1(2, 2) * m2(2, 3) + m1(2, 3) * m2(3, 3);
            
            r(3, 0) = m1(3, 0) * m2(0, 0) + m1(3, 1) * m2(1, 0) + m1(3, 2) * m2(2, 0) + m1(3, 3) * m2(3, 0);
            r(3, 1) = m1(3, 0) * m2(0, 1) + m1(3, 1) * m2(1, 1) + m1(3, 2) * m2(2, 1) + m1(3, 3) * m2(3, 1);
            r(3, 2) = m1(3, 0) * m2(0, 2) + m1(3, 1) * m2(1, 2) + m1(3, 2) * m2(2, 2) + m1(3, 3) * m2(3, 2);
            r(3, 3) = m1(3, 0) * m2(0, 3) + m1(3, 1) * m2(1, 3) + m1(3, 2) * m2(2, 3) + m1(3, 3) * m2(3, 3);
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TMatrix4<T, false>& m1, const Phanes::Core::Math::TVector4<T, false>& v)
        {
            r.x = m1(0, 0) * v.x + m1(0, 1) * v.y + m1(0, 2) * v.z + m1(0, 3) * v.w;
            r.y = m1(1, 0) * v.x + m1(1, 1) * v.y + m1(1, 2) * v.z + m1(1, 3) * v.w;
            r.z = m1(2, 0) * v.x + m1(2, 1) * v.y + m1(2, 2) * v.z + m1(2, 3) * v.w;
            r.w = m1(3, 0) * v.x + m1(3, 1) * v.y + m1(3, 2) * v.z + m1(3, 3) * v.w;
        }
    };
}
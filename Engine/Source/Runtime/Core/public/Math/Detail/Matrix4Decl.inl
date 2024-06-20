#pragma once

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct compute_mat4_det {};

    template<RealType T, bool S>
    struct compute_mat4_inv {};

    template<RealType T, bool S>
    struct compute_mat4_transpose {};


    template<RealType T>
    struct compute_mat4_det<T, false>
    {
        static constexpr T map(Phanes::Core::Math::TMatrix4<T, S>& m)
        {
            const TVector3<T, false>& a = reinterpret_cast<TVector3<T, false>&>(m[0]);
            const TVector3<T, false>& b = reinterpret_cast<TVector3<T, false>&>(m[1]);
            const TVector3<T, false>& c = reinterpret_cast<TVector3<T, false>&>(m[2]);
            const TVector3<T, false>& d = reinterpret_cast<TVector3<T, false>&>(m[3]);

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
            const TVector3<T, false>& a = reinterpret_cast<TVector3<T, false>&>(m[0]);
            const TVector3<T, false>& b = reinterpret_cast<TVector3<T, false>&>(m[1]);
            const TVector3<T, false>& c = reinterpret_cast<TVector3<T, false>&>(m[2]);
            const TVector3<T, false>& d = reinterpret_cast<TVector3<T, false>&>(m[3]);
            
            const float& x = m(3, 0);
            const float& y = m(3, 1);
            const float& z = m(3, 2);
            const float& w = m(3, 3);

            TVector3<T, false> s = CrossP(a, b);
            TVector3<T, false> t = CrossP(c, d);
            TVector3<T, false> u = a * y - b * x;
            TVector3<T, false> v = c * w - d * z;

            float _1_det = (T)1.0 / (DotP(s, v) + DotP(t, u));

            if (_1_det == 0.0)
            {
                return false;
            }

            s *= _1_det;
            t *= _1_det;
            u *= _1_det;
            v *= _1_det;

            TVector3<T, false> r0 = Cross(b, v) + t * y;
            TVector3<T, false> r1 = Cross(v, a) + t * x;
            TVector3<T, false> r2 = Cross(d, u) + s * w;
            TVector3<T, false> r3 = Cross(u, c) + s * z;

            r = TMatrix4<T, false>(r0.x, r0.y, r0.z, -DotP(b, t),
                                   r1.x, r1.y, r1.z, DotP(a, t),
                                   r2.x, r2.y, r2.z, -DotP(d, s),
                                   r3.x, r3.y, r3.z, DotP(c, s));

            return true;
        }
    };

    template<RealType T>
    struct compute_mat4_transpose<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TMatrix4<T, S>& r, const Phanes::Core::Math::TMatrix4<T, S>& m)
        {
            r = Phanes::Core::Math::TMatrix4<T, false>(m(0, 0), m(1, 0), m(2, 0), m(3, 0),
                                                       m(0, 1), m(1, 1), m(2, 1), m(3, 1),
                                                       m(0, 2), m(1, 2), m(2, 2), m(3, 2),
                                                       m(0, 3), m(1, 3), m(2, 3), m(3, 3));
        }
    };
}
#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct construct_vec3 {};

    template<RealType T, bool S>
    struct compute_vec3_add {};

    template<RealType T, bool S>
    struct compute_vec3_sub {};

    template<RealType T, bool S>
    struct compute_vec3_mul {};

    template<RealType T, bool S>
    struct compute_vec3_div {};

    template<RealType T, bool S>
    struct compute_vec3_eq {};

    template<RealType T, bool S>
    struct compute_vec3_ieq {};

    template<RealType T, bool S>
    struct compute_vec3_inc {};

    template<RealType T, bool S>
    struct compute_vec3_dec {};

    template<RealType T, bool S>
    struct compute_vec3_cross_p {};



    template<RealType T>
    struct construct_vec3<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& v1, const TVector3<T, false>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = (T)0.0;
        }


        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = (T)0.0;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& v1, T x, T y, T z)
        {
            v1.x = x;
            v1.y = y;
            v1.z = z;
            v1.w = (T)0.0;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector2<T, false>& v2, T s)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = s;
        }


        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& v1, const T* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = (T)0.0;
        }
    };


    template<RealType T>
    struct compute_vec3_add<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
        }
    };


    template<RealType T>
    struct compute_vec3_sub<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
        }
    };


    template<RealType T>
    struct compute_vec3_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
        }
    };


    template<RealType T>
    struct compute_vec3_div<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
            r.z = v1.z / v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
        }
    };

    template<RealType T>
    struct compute_vec3_eq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.z - v2.z) < P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec3_ieq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TVector3<T, false>& v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.z - v2.z) > P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec3_inc<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
        }
    };

    template<RealType T>
    struct compute_vec3_dec<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
        }
    };

    template<RealType T>
    struct compute_vec3_cross_p<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector3<T, false>& r, const Phanes::Core::Math::TVector3<T, false> v1, const Phanes::Core::Math::TVector3<T, false>& v2)
        {
            // V1 has to be copied, as otherwise changes to r affect calculation -> r is v1.

            r.x = (v1.y * v2.z) - (v1.z * v2.y);
            r.y = (v1.z * v2.x) - (v1.x * v2.z);
            r.z = (v1.x * v2.y) - (v1.y * v2.x);
        }
    };
}


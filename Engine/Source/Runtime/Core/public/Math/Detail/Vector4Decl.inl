#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct construct_vec4 {};

    template<RealType T, bool S>
    struct compute_vec4_add {};

    template<RealType T, bool S>
    struct compute_vec4_sub {};

    template<RealType T, bool S>
    struct compute_vec4_mul {};

    template<RealType T, bool S>
    struct compute_vec4_div {};

    template<RealType T, bool S>
    struct compute_vec4_eq {};

    template<RealType T, bool S>
    struct compute_vec4_ieq {};

    template<RealType T, bool S>
    struct compute_vec4_inc {};

    template<RealType T, bool S>
    struct compute_vec4_dec {};



    template<RealType T>
    struct construct_vec4<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& v1, const TVector4<T, false>& v2)
        {
            memcpy(v1.data, v2.data, 4 * sizeof(T));
        }


        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = s;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& v1, T x, T y, T z, T w)
        {
            v1.x = x;
            v1.y = y;
            v1.z = z;
            v1.w = w;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector2<T, false>& v2, const Phanes::Core::Math::TVector2<T, false>& v3)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v3.x;
            v1.w = v3.y;
        }


        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& v1, const T* comp)
        {
            memcpy(v1.data, comp, 4 * sizeof(T));
        }
    };


    template<RealType T>
    struct compute_vec4_add<T, false>
    { 
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
            r.w = v1.w + v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
            r.w = v1.w + s;
        }
    };


    template<RealType T>
    struct compute_vec4_sub<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
            r.w = v1.w - v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
            r.w = v1.w - s;
        }
    };


    template<RealType T>
    struct compute_vec4_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
            r.w = v1.w * v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };


    template<RealType T>
    struct compute_vec4_div<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
            r.z = v1.z / v2.z;
            r.w = v1.w / v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };

    template<RealType T>
    struct compute_vec4_eq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                    Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC &&
                    Phanes::Core::Math::Abs(v1.z - v2.z) < P_FLT_INAC &&
                    Phanes::Core::Math::Abs(v1.w - v2.w) < P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec4_ieq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TVector4<T, false>& v1, const Phanes::Core::Math::TVector4<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                    Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC ||
                    Phanes::Core::Math::Abs(v1.z - v2.z) > P_FLT_INAC ||
                    Phanes::Core::Math::Abs(v1.w - v2.w) > P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec4_inc<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
            r.w = v1.w + 1;
        }
    };

    template<RealType T>
    struct compute_vec4_dec<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TVector4<T, false>& r, const Phanes::Core::Math::TVector4<T, false>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
            r.w = v1.w - 1;
        }
    };
}


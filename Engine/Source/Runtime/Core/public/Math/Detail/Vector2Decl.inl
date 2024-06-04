#pragma once

#include "Core/public/Math/Boilerplate.h"

#include <iostream>

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct construct_vec2 {};

    template<RealType T, bool S>
    struct compute_vec2_add {};

    template<RealType T, bool S>
    struct compute_vec2_sub {};

    template<RealType T, bool S>
    struct compute_vec2_mul {};

    template<RealType T, bool S>
    struct compute_vec2_div {};

    template<RealType T, bool S>
    struct compute_vec2_eq {};

    template<RealType T, bool S>
    struct compute_vec2_ieq {};

    template<RealType T, bool S>
    struct compute_vec2_inc {};

    template<RealType T, bool S>
    struct compute_vec2_dec {};



    template<RealType T>
    struct construct_vec2<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& v1, const TVector2<T, A>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& v1, T x, T y)
        {
            v1.x = x;
            v1.y = y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& v1, const T* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
        }
    };


    template<RealType T>
    struct compute_vec2_add<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
        }
    };


    template<RealType T>
    struct compute_vec2_sub<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
        }
    };


    template<RealType T>
    struct compute_vec2_mul<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };


    template<RealType T>
    struct compute_vec2_div<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
        }

        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };

    template<RealType T>
    struct compute_vec2_eq<T, false>
    {
        template<bool A>
        static constexpr bool map(const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec2_ieq<T, false>
    {
        template<bool A>
        static constexpr bool map(const Phanes::Core::Math::TVector2<T, A>& v1, const Phanes::Core::Math::TVector2<T, A>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC);
        }
    };

    template<RealType T>
    struct compute_vec2_inc<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
        }
    };

    template<RealType T>
    struct compute_vec2_dec<T, false>
    {
        template<bool A>
        static constexpr void map(Phanes::Core::Math::TVector2<T, A>& r, const Phanes::Core::Math::TVector2<T, A>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
        }
    };
}


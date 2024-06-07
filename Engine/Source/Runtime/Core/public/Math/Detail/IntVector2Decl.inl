#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<IntType T, bool S>
    struct construct_ivec2 {};

    template<IntType T, bool S>
    struct compute_ivec2_add {};

    template<IntType T, bool S>
    struct compute_ivec2_sub {};

    template<IntType T, bool S>
    struct compute_ivec2_mul {};

    template<IntType T, bool S>
    struct compute_ivec2_div {};

    template<IntType T, bool S>
    struct compute_ivec2_mod {};

    template<IntType T, bool S>
    struct compute_ivec2_eq {};

    template<IntType T, bool S>
    struct compute_ivec2_ieq {};

    template<IntType T, bool S>
    struct compute_ivec2_inc {};

    template<IntType T, bool S>
    struct compute_ivec2_dec {};

    template<IntType T, bool S>
    struct compute_ivec2_and {};
    
    template<IntType T, bool S>
    struct compute_ivec2_or {};

    template<IntType T, bool S>
    struct compute_ivec2_xor {};

    template<IntType T, bool S>
    struct compute_ivec2_left_shift {};

    template<IntType T, bool S>
    struct compute_ivec2_right_shift {};

    template<IntType T, bool S>
    struct compute_ivec2_bnot {};


    template<IntType T>
    struct construct_ivec2<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& v1, const TIntVector2<T, false>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& v1, T x, T y)
        {
            v1.x = x;
            v1.y = y;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& v1, const T* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
        }
    };


    template<IntType T>
    struct compute_ivec2_add<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
        }
    };


    template<IntType T>
    struct compute_ivec2_sub<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
        }
    };


    template<IntType T>
    struct compute_ivec2_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };


    template<IntType T>
    struct compute_ivec2_div<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };

    template<IntType T>
    struct compute_ivec2_mod<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x % v2.x;
            r.y = v1.y % v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            r.x = v1.x % s;
            r.y = v1.y % s;
        }
    };

    template<IntType T>
    struct compute_ivec2_eq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC);
        }
    };

    template<IntType T>
    struct compute_ivec2_ieq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC);
        }
    };

    template<IntType T>
    struct compute_ivec2_inc<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
        }
    };

    template<IntType T>
    struct compute_ivec2_dec<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
        }
    };


    template<IntType T>
    struct compute_ivec2_and<T, false> 
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x & v2.x;
            r.y = v1.y & v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, T s)
        {
            r.x = v1.x & s;
            r.y = v1.y & s;
        }
    };

    template<IntType T>
    struct compute_ivec2_or<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x | v2.x;
            r.y = v1.y | v2.y;
        }
    };

    template<IntType T>
    struct compute_ivec2_xor<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x ^ v2.x;
            r.y = v1.y ^ v2.y;
        }
    };

    template<IntType T>
    struct compute_ivec2_left_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x << v2.x;
            r.y = v1.y << v2.y;
        }
    };

    template<IntType T>
    struct compute_ivec2_right_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2)
        {
            r.x = v1.x >> v2.x;
            r.y = v1.y >> v2.y;
        }
    };

    template<IntType T>
    struct compute_ivec2_bnot<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector2<T, false>& r, const Phanes::Core::Math::TIntVector2<T, false>& v1)
        {
            r.x = ~v1.x;
            r.y = ~v1.y;
        }
    };
}


#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<IntType T, bool S>
    struct construct_ivec3 {};

    template<IntType T, bool S>
    struct compute_ivec3_add {};

    template<IntType T, bool S>
    struct compute_ivec3_sub {};

    template<IntType T, bool S>
    struct compute_ivec3_mul {};

    template<IntType T, bool S>
    struct compute_ivec3_div {};

    template<IntType T, bool S>
    struct compute_ivec3_mod {};

    template<IntType T, bool S>
    struct compute_ivec3_eq {};

    template<IntType T, bool S>
    struct compute_ivec3_ieq {};

    template<IntType T, bool S>
    struct compute_ivec3_inc {};

    template<IntType T, bool S>
    struct compute_ivec3_dec {};

    template<IntType T, bool S>
    struct compute_ivec3_and {};

    template<IntType T, bool S>
    struct compute_ivec3_or {};

    template<IntType T, bool S>
    struct compute_ivec3_xor {};

    template<IntType T, bool S>
    struct compute_ivec3_left_shift {};

    template<IntType T, bool S>
    struct compute_ivec3_right_shift {};

    template<IntType T, bool S>
    struct compute_ivec3_bnot {};


    template<IntType T>
    struct construct_ivec3<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& v1, const TIntVector3<T, false>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = (T)0;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = (T)0;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& v1, T x, T y, T z)
        {
            v1.x = x;
            v1.y = y;
            v1.y = z;
            v1.w = (T)0;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& v1, const T* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = (T)0;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector2<T, false>& v2, const T s)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = s;
            v1.w = (T)0;
        }
    };


    template<IntType T>
    struct compute_ivec3_add<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
        }
    };


    template<IntType T>
    struct compute_ivec3_sub<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
        }
    };


    template<IntType T>
    struct compute_ivec3_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
        }
    };


    template<IntType T>
    struct compute_ivec3_div<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
            r.z = v1.z / v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
        }
    };

    template<IntType T>
    struct compute_ivec3_mod<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x % v2.x;
            r.y = v1.y % v2.y;
            r.z = v1.z % v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x % s;
            r.y = v1.y % s;
            r.z = v1.z % s;
        }
    };

    template<IntType T>
    struct compute_ivec3_eq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                    Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC &&
                    Phanes::Core::Math::Abs(v1.z - v2.z) < P_FLT_INAC);
        }
    };

    template<IntType T>
    struct compute_ivec3_ieq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                    Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC ||
                    Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC);
        }
    };

    template<IntType T>
    struct compute_ivec3_inc<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
        }
    };

    template<IntType T>
    struct compute_ivec3_dec<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
        }
    };


    template<IntType T>
    struct compute_ivec3_and<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x & v2.x;
            r.y = v1.y & v2.y;
            r.z = v1.z & v2.y;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x & s;
            r.y = v1.y & s;
            r.z = v1.z & s;
        }
    };

    template<IntType T>
    struct compute_ivec3_or<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x | v2.x;
            r.y = v1.y | v2.y;
            r.z = v1.z | v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x | s;
            r.y = v1.y | s;
            r.z = v1.z | s;
        }
    };

    template<IntType T>
    struct compute_ivec3_xor<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x ^ v2.x;
            r.y = v1.y ^ v2.y;
            r.z = v1.z ^ v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x ^ s;
            r.y = v1.y ^ s;
            r.z = v1.z ^ s;
        }
    };

    template<IntType T>
    struct compute_ivec3_left_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x << v2.x;
            r.y = v1.y << v2.y;
            r.z = v1.z << v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x << s;
            r.y = v1.y << s;
            r.z = v1.z << s;
        }
    };

    template<IntType T>
    struct compute_ivec3_right_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, const Phanes::Core::Math::TIntVector3<T, false>& v2)
        {
            r.x = v1.x >> v2.x;
            r.y = v1.y >> v2.y;
            r.z = v1.z >> v2.z;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1, T s)
        {
            r.x = v1.x >> s;
            r.y = v1.y >> s;
            r.z = v1.z >> s;
        }
    };

    template<IntType T>
    struct compute_ivec3_bnot<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector3<T, false>& r, const Phanes::Core::Math::TIntVector3<T, false>& v1)
        {
            r.x = ~v1.x;
            r.y = ~v1.y;
            r.z = ~v1.z;
        }
    };
}


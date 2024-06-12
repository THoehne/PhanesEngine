#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<IntType T, bool S>
    struct construct_ivec4 {};

    template<IntType T, bool S>
    struct compute_ivec4_add {};

    template<IntType T, bool S>
    struct compute_ivec4_sub {};

    template<IntType T, bool S>
    struct compute_ivec4_mul {};

    template<IntType T, bool S>
    struct compute_ivec4_div {};

    template<IntType T, bool S>
    struct compute_ivec4_mod {};

    template<IntType T, bool S>
    struct compute_ivec4_eq {};

    template<IntType T, bool S>
    struct compute_ivec4_ieq {};

    template<IntType T, bool S>
    struct compute_ivec4_inc {};

    template<IntType T, bool S>
    struct compute_ivec4_dec {};

    template<IntType T, bool S>
    struct compute_ivec4_and {};

    template<IntType T, bool S>
    struct compute_ivec4_or {};

    template<IntType T, bool S>
    struct compute_ivec4_xor {};

    template<IntType T, bool S>
    struct compute_ivec4_left_shift {};

    template<IntType T, bool S>
    struct compute_ivec4_right_shift {};

    template<IntType T, bool S>
    struct compute_ivec4_bnot {};


    template<IntType T>
    struct construct_ivec4<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& v1, const TIntVector4<T, false>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = v2.w;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = s;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& v1, T x, T y, T z, T w)
        {
            v1.x = x;
            v1.y = y;
            v1.y = z;
            v1.y = w;
        }


        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& v1, const T* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = comp[3];
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<int, false>& r, const Phanes::Core::Math::TIntVector2<int, false>& v1, const Phanes::Core::Math::TIntVector2<int, false>& v2)
        {
            r.x = v1.x;
            r.y = v1.y;
            r.x = v2.x;
            r.y = v2.y;
        }
    };


    template<IntType T>
    struct compute_ivec4_add<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
            r.w = v1.w + v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
            r.w = v1.w + s;
        }
    };


    template<IntType T>
    struct compute_ivec4_sub<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
            r.w = v1.w - v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
            r.w = v1.w - s;
        }
    };


    template<IntType T>
    struct compute_ivec4_mul<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
            r.w = v1.w * v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };


    template<IntType T>
    struct compute_ivec4_div<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
            r.z = v1.z / v2.z;
            r.w = v1.w / v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            s = (T)1.0 / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };

    template<IntType T>
    struct compute_ivec4_mod<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x % v2.x;
            r.y = v1.y % v2.y;
            r.z = v1.z % v2.z;
            r.w = v1.w % v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x % s;
            r.y = v1.y % s;
            r.z = v1.z % s;
            r.w = v1.w % s;
        }
    };

    template<IntType T>
    struct compute_ivec4_eq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            return (v1.x == v2.x && 
                    v1.y == v2.y &&
                    v1.z == v2.z &&
                    v1.w == v2.w);
        }
    };

    template<IntType T>
    struct compute_ivec4_ieq<T, false>
    {
        static constexpr bool map(const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            return (v1.x != v2.x ||
                    v1.y != v2.y ||
                    v1.z != v2.z ||
                    v1.w != v2.w);
        }
    };

    template<IntType T>
    struct compute_ivec4_inc<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
            r.w = v1.w + 1;
        }
    };

    template<IntType T>
    struct compute_ivec4_dec<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
            r.w = v1.w - 1;
        }
    };


    template<IntType T>
    struct compute_ivec4_and<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x & v2.x;
            r.y = v1.y & v2.y;
            r.z = v1.z & v2.z;
            r.w = v1.w & v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x & s;
            r.y = v1.y & s;
            r.z = v1.z & s;
            r.w = v1.w & s;
        }
    };

    template<IntType T>
    struct compute_ivec4_or<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x | v2.x;
            r.y = v1.y | v2.y;
            r.z = v1.z | v2.z;
            r.w = v1.w | v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x | s;
            r.y = v1.y | s;
            r.z = v1.z | s;
            r.w = v1.w | s;
        }
    };

    template<IntType T>
    struct compute_ivec4_xor<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x ^ v2.x;
            r.y = v1.y ^ v2.y;
            r.z = v1.z ^ v2.z;
            r.w = v1.w ^ v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x ^ s;
            r.y = v1.y ^ s;
            r.z = v1.z ^ s;
            r.w = v1.w ^ s;
        }
    };

    template<IntType T>
    struct compute_ivec4_left_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x << v2.x;
            r.y = v1.y << v2.y;
            r.z = v1.z << v2.z;
            r.w = v1.w << v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x << s;
            r.y = v1.y << s;
            r.z = v1.z << s;
            r.w = v1.w << s;
        }
    };

    template<IntType T>
    struct compute_ivec4_right_shift<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, const Phanes::Core::Math::TIntVector4<T, false>& v2)
        {
            r.x = v1.x >> v2.x;
            r.y = v1.y >> v2.y;
            r.z = v1.z >> v2.z;
            r.w = v1.w >> v2.w;
        }

        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1, T s)
        {
            r.x = v1.x >> s;
            r.y = v1.y >> s;
            r.z = v1.z >> s;
            r.w = v1.w >> s;
        }
    };

    template<IntType T>
    struct compute_ivec4_bnot<T, false>
    {
        static constexpr void map(Phanes::Core::Math::TIntVector4<T, false>& r, const Phanes::Core::Math::TIntVector4<T, false>& v1)
        {
            r.x = ~v1.x;
            r.y = ~v1.y;
        }
    };
}


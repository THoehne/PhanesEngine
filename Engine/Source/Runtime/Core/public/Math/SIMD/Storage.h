// Defines on compile time, whether a xmm register or an array should be used.
#pragma once

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

#include "Core/public/Math/MathTypes.h"

namespace Phanes::Core::Math::SIMD
{
    template<size_t L, typename T, bool UseSimd>
    struct Storage;

    // General unaligned memory storage
    template<size_t L, typename T>
    struct Storage<L, T, false>
    {
        typedef struct type {
            T data[L];
        } type;
    };

    template<typename T>
    struct Storage<3, T, false>
    {
        typedef struct type {
            T data[4];
        } type;
    };


    // SSE4.2

    template<>
    struct Storage<4, float, true>
    {
        typedef Phanes::Core::Types::Vec4f32Reg type;
    };

    template<>
    struct Storage<3, float, true>
    {
        typedef Phanes::Core::Types::Vec4f32Reg type;
    };
    
    template<>
    struct Storage<4, int, true>
    {
        typedef Phanes::Core::Types::Vec4i32Reg type;
    };

    template<>
    struct Storage<3, int, true>
    {
        typedef Phanes::Core::Types::Vec4i32Reg type;
    };

    template<>
    struct Storage<4, unsigned int, true>
    {
        typedef Phanes::Core::Types::Vec4u32Reg type;
    };

    template<>
    struct Storage<3, unsigned int, true>
    {
        typedef Phanes::Core::Types::Vec4u32Reg type;
    };

    template<>
    struct Storage<2, double, true>
    {
        typedef Phanes::Core::Types::Vec2f64Reg type;
    };

    template<>
    struct Storage<2, Phanes::Core::Types::int64, true>
    {
        typedef Phanes::Core::Types::Vec2i64Reg type;
    };

    template<>
    struct Storage<2, Phanes::Core::Types::uint64, true>
    {
        typedef Phanes::Core::Types::Vec2u64Reg type;
    };


    // AVX
    template<>
    struct Storage<4, double, true>
    {
        typedef Phanes::Core::Types::Vec4f64Reg type;
    };

    template<>
    struct Storage<3, double, true>
    {
        typedef Phanes::Core::Types::Vec4f64Reg type;
    };

    template<>
    struct Storage<8, float, true>
    {
        typedef Phanes::Core::Types::Vec4x2f32Reg type;
    };


    // AVX2
    template<>
    struct Storage<4, Phanes::Core::Types::int64, true>
    {
        typedef Phanes::Core::Types::Vec4i64Reg type;
    };

    template<>
    struct Storage<3, Phanes::Core::Types::int64, true>
    {
        typedef Phanes::Core::Types::Vec4i64Reg type;
    };

    template<>
    struct Storage<4, Phanes::Core::Types::uint64, true>
    {
        typedef Phanes::Core::Types::Vec4u64Reg type;
    };

    template<>
    struct Storage<3, Phanes::Core::Types::uint64, true>
    {
        typedef Phanes::Core::Types::Vec4u64Reg type;
    };

    template<>
    struct Storage<8, int, true>
    {
        typedef Phanes::Core::Types::Vec4x2i32Reg type;
    };

    template<>
    struct Storage<8, unsigned int, true>
    {
        typedef Phanes::Core::Types::Vec4x2u32Reg type;
    };
}
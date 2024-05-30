#pragma once

// This file includes the necessary header for vectorization intrinsics. If no specifics are defined SSE4.2 is used.
// 
// ARM is not supported.

#include "Core/public/Math/SIMD/Platform.h"
#include "Core/public/Math/MathTypes.h"

#if P_INTRINSICS == P_INTRINSICS_AVX2
#   include <immintrin.h>
#elif P_INTRINSICS == P_INTRINSICS_AVX
#   include <immintrin.h>
#elif P_INTRINSICS == P_INTRINSICS_SSE
#   include <nmmintrin.h> 
#elif P_INTRINSICS == P_INTRINSICS_NEON
#   include "neon.h" // <- Not supported
#endif

// use_simd for metaprogramming
namespace Phanes::Core::Math::SIMD
{
    
    /// <summary>
    /// This decides, whether simd operations should be used, based on the vector type, it's size, the vector alignment and whether the right extension can be loaded during compiletime.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="L">Length of vector</typeparam>
    /// <typeparam name="SimdActive">Whether SIMD intrinsics exist, that support the vector type and length.</typeparam>
    /// <typeparam name="IsAligned">Whether the vector is aligned for simd usage.</typeparam>
    template<typename T, size_t L, bool IsAligned>
    struct use_simd
    {
        static const bool value = false;
    };


    // SSE / NEON

    template<>
    struct use_simd<float, 4, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    template<>
    struct use_simd<float, 3, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    template<>
    struct use_simd<int, 4, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    template<>
    struct use_simd<int, 3, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    template<>
    struct use_simd<unsigned int, 4, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    template<>
    struct use_simd<unsigned int, 3, true>
    {
        static const bool value = true && (P_SSE__ || P_NEON__);
    };

    // SSE

    template<>
    struct use_simd<double, 2, true>
    {
        static const bool value = true && P_SSE__;
    };

    template<>
    struct use_simd<Phanes::Core::Types::int64, 2, true>
    {
        static const bool value = true && P_SSE__;
    };

    template<>
    struct use_simd<Phanes::Core::Types::uint64, 2, true>
    {
        static const bool value = true && P_SSE__;
    };



    // AVX 

    template<>
    struct use_simd<double, 4, true>
    {
        static const bool value = true && P_AVX__;
    };

    template<>
    struct use_simd<double, 3, true>
    {
        static const bool value = true && P_AVX__;
    };

    template<>
    struct use_simd<float, 8, true>
    {
        static const bool value = true && P_AVX__;
    };


    // AVX2

    template<>
    struct use_simd<Phanes::Core::Types::int64, 4, true>
    {
        static const bool value = true && P_AVX2__;
    };

    template<>
    struct use_simd<Phanes::Core::Types::int64, 3, true>
    {
        static const bool value = true && P_AVX2__;
    };

    template<>
    struct use_simd<Phanes::Core::Types::uint64, 4, true>
    {
        static const bool value = true && P_AVX2__;
    };

    template<>
    struct use_simd<Phanes::Core::Types::uint64, 3, true>
    {
        static const bool value = true && P_AVX2__;
    };

    template<>
    struct use_simd<int, 8, true>
    {
        static const bool value = true && P_AVX2__;
    };

    template<>
    struct use_simd<unsigned int, 8, true>
    {
        static const bool value = true && P_AVX2__;
    };
}

// Register aliases
namespace Phanes::Core::Types
{

#if P_INTRINSICS >= 1

    typedef __m128      Vec4f32Reg;
    typedef __m128d     Vec2f64Reg;

    typedef __m128i     Vec4i32Reg;
    typedef __m128i     Vec2i64Reg;

    typedef __m128i     Vec4u32Reg;
    typedef __m128i     Vec2u64Reg;

#elif P_INTRINSICS != P_INTRINSICS_NEON

    typedef struct alignas(16) Vec4f32Reg { float data[4]; }                        Vec4f32Reg;
    typedef struct alignas(16) Vec2f64Reg { double data[2]; }                       Vec2f64Reg;
    typedef struct alignas(16) Vec4i32Reg { int data[4]; }                          Vec4i32Reg;
    typedef struct alignas(16) Vec2i64Reg { Phanes::Core::Types::int64 data[2]; }   Vec2i64Reg;
    typedef struct alignas(16) Vec4u32Reg { unsigned int data[4]; }                 Vec4u32Reg;
    typedef struct alignas(16) Vec2u64Reg { Phanes::Core::Types::uint64 data[4]; }  Vec2u64Reg;

#endif


#if P_INTRINSICS >= 2

    typedef __m256      Vec4x2f32Reg;
    typedef __m256      Vec8f32Reg;
    typedef __m256d     Vec2x2f64Reg;
    typedef __m256d     Vec4f64Reg;

#elif P_INTRINSICS != P_INTRINSICS_NEON

    typedef struct alignas(32) Vec4x2f32Reg { float data[8]; }  Vec4x2f32Reg;
    typedef struct alignas(32) Vec8f32Reg   { float data[8]; }  Vec8f32Reg;
    typedef struct alignas(32) Vec2x2f64Reg { double data[4]; } Vec2x2f64Reg;
    typedef struct alignas(32) Vec4f64Reg   { double data[4]; } Vec4f64Reg;

#endif


#if P_INTRINSICS == 3

    typedef __m256i     Vec4x2i32Reg;
    typedef __m256i     Vec8i32Reg;
    typedef __m256i     Vec2x2i64Reg;
    typedef __m256i     Vec4i64Reg;

    typedef __m256i     Vec4x2u32Reg;
    typedef __m256i     Vec8u32Reg;
    typedef __m256i     Vec2x2u64Reg;
    typedef __m256i     Vec4u64Reg;

#elif P_INTRINSICS != P_INTRINSICS_NEON

    typedef struct alignas(32) Vec4x2i32Reg { int data[8]; }                         Vec4x2i32Reg;
    typedef struct alignas(32) Vec8i32Reg   { int data[8]; }                         Vec8i32Reg;
    typedef struct alignas(32) Vec2x2i64Reg { Phanes::Core::Types::int64 data[4]; }  Vec2x2i64Reg;
    typedef struct alignas(32) Vec4i64Reg   { Phanes::Core::Types::int64 data[4]; }  Vec4i64Reg;

    typedef struct alignas(32) Vec4x2u32Reg { unsigned int data[8]; }                Vec4x2u32Reg;
    typedef struct alignas(32) Vec8u32Reg   { unsigned int data[8]; }                Vec8u32Reg;
    typedef struct alignas(32) Vec2x2u64Reg { Phanes::Core::Types::uint64 data[4]; } Vec2x2u64Reg;
    typedef struct alignas(32) Vec4u64Reg   { Phanes::Core::Types::uint64 data[4]; } Vec4u64Reg;

#endif

    // NEON ...
}
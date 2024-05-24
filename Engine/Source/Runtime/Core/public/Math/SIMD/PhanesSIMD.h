// This file includes the necessary header for vectorization intrinsics. If no specifics are defined SSE4.2 is used.
// 
// ARM is not supported.

#include "Core/public/Math/SIMD/Platform.h"
#include "Core/public/Math/MathTypes.h"


#if P_INTRINSICS == P_INTRINSICS_AVX2
#   include "PhanesVectorMathAVX2.hpp"
#elif P_INTRINSICS == P_INTRINSICS_AVX
#   include "PhanesVectorMathAVX.hpp"
#elif P_INTRINSICS == P_INTRINSICS_SSE
#   include "PhanesVectorMathSSE.hpp"
#elif P_INTRINSICS == P_INTRINSICS_NEON
#   include "PhanesVectorMathNeon.hpp"
#elif P_INTRINSICS == P_INTRINSICS_FPU 
#   include "PhanesVectorMathFPU.hpp"
#endif


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
// This file includes the necessary header for vectorization intrinsics. If no specifics are defined SSE4.2 is used.
// 
// ARM is not supported.

#include "Core/public/Math/SIMD/Platform.h"



#include <nmmintrin.h> // SSE4.2

#ifdef __AVX__
#   include <immintrin.h>
#endif


namespace Phanes::Core::Math::SIMD
{

    // XMM Register wrapper for 4x1 floats

    struct VectorRegister4f
    {
    public:
        __m128 data;
    };

    typedef VectorRegister4f    VectorRegister4f32;



    // XMM Register wrapper for 2x1 doubles
    struct VectorRegister2d
    {
    public:
        __m128d data;
    };

    typedef VectorRegister2d    VectorRegister2f64;



    // XMM Register wrapper for 4x1 integers
    struct VectorRegister4i
    {
    public:
        __m128i data;
    };

    typedef VectorRegister4i    VectorRegister4i32;



#   ifdef __AVX__

    // AVX specific types

    // XMM Register wrapper for 4x1 doubles
    struct VectorRegister4d
    {
    public:
        __m256d data;
    };

    typedef VectorRegister4d    VectorRegister4f64;
    
#   endif


#   ifdef __AVX2__

    // AVX2 specific types

    // XMM Register wrapper for 4x1 doubles
    struct VectorRegister4i64
    {
    public:
        __m256i data;
    };


#   endif
}
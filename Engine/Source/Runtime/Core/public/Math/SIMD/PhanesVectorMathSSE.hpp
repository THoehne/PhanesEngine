#pragma once

#include <nmmintrin.h> 

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"
#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"

#include <iostream>

// -> For IntelliSense

#include "Core/public/Math/Vector4.hpp"

// ========== //
//   Common   //
// ========== //


Phanes::Core::Types::Vec4f32Reg p_vec4_abs(const Phanes::Core::Types::Vec4f32Reg& v)
{
    return _mm_and_ps(v, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
}




// ============ //
//   TVector4   //
// ============ //


namespace Phanes::Core::Math::Detail
{
    // Template class has already been defined and is included through: Storage.h -> Vector4.hpp -> SIMDIntrinsics.h -> PhanesVectorMathSEE.hpp

    template<>
    struct compute_vec4_add<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_add_ps(v1.comp, v2.comp);
        }
    };

    template<>
    struct compute_vec4_sub<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_sub_ps(v1.comp, v2.comp);
        }
    };

    template<>
    struct compute_vec4_mul<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_mul_ps(v1.comp, v2.comp);
        }
    };

    template<>
    struct compute_vec4_div<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_div_ps(v1.comp, v2.comp);
        }
    };

    template<>
    struct compute_vec4_eq<float, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            float r;
            _mm_store_ps1(&r, _mm_cmpeq_ps(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };

    template<>
    struct compute_vec4_ieq<float, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            float r;
            _mm_store_ps1(&r, _mm_cmpneq_ps(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };
}


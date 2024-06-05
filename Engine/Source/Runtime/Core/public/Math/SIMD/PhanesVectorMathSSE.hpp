#pragma once

#include <nmmintrin.h> 

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"
#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"


// Required includes
#include "Core/public/Math/Vector3.hpp"
#include "Core/public/Math/Vector4.hpp"

// ========== //
//   Common   //
// ========== //

namespace Phanes::Core::Math::SIMD
{
    /// <summary>
    /// Adds all scalars of the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Sum stored in v[0:31].</returns>
    Phanes::Core::Types::Vec4f32Reg vec4_hadd(const Phanes::Core::Types::Vec4f32Reg v)
    {
        __m128 shufl = _mm_movehdup_ps(v);
        __m128 sum = _mm_add_ps(v, shufl);
        shufl = _mm_movehl_ps(sum, sum);
        return _mm_add_ss(sum, shufl);
    }

    /// <summary>
    /// Adds all scalars of the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Sum of components.</returns>
    float vec4_hadd_cvtf32(const Phanes::Core::Types::Vec4f32Reg v)
    {
        __m128 shufl = _mm_movehdup_ps(v);
        __m128 sum = _mm_add_ps(v, shufl);
        shufl = _mm_movehl_ps(sum, sum);
        sum = _mm_add_ss(sum, shufl);

        return _mm_cvtss_f32(sum);
    }

    /// <summary>
    /// Gets the absolute value of each scalar in the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Vector with all components positive.</returns>
    Phanes::Core::Types::Vec4f32Reg vec4_abs(const Phanes::Core::Types::Vec4f32Reg v)
    {
        return _mm_and_ps(v, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
    }

    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    Phanes::Core::Types::Vec4f32Reg vec4_dot(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        return vec4_hadd(_mm_mul_ps(v1, v2));
    }

    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    float vec4_dot_cvtf32(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        return vec4_hadd_cvtf32(_mm_mul_ps(v1, v2));
    }
}




// ============ //
//   TVector4   //
// ============ //


namespace Phanes::Core::Math::Detail
{
    // Template class has already been defined and is included through: Storage.h -> Vector4.hpp -> SIMDIntrinsics.h -> PhanesVectorMathSEE.hpp


    template<>
    struct construct_vec4<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const TVector4<float, true>& v2)
        {
            v1.comp = _mm_setr_ps(v2.x, v2.y, v2.z, v2.w);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            v1.comp = _mm_set_ps1(s);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, float x, float y, float z, float w)
        {
            v1.comp = _mm_setr_ps(x, y, z, w);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector2<float, false>& v2, const Phanes::Core::Math::TVector2<float, false>& v3)
        {
            v1.comp = _mm_set_ps(v2.x, v2.y, v3.x, v3.y);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const float* s)
        {
            v1.comp = _mm_loadu_ps(s);

        }
    };


    template<>
    struct compute_vec4_add<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_add_ps(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.comp = _mm_add_ps(v1.comp, _mm_set_ps1(s));
        }
    };

    template<>
    struct compute_vec4_sub<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_sub_ps(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.comp = _mm_sub_ps(v1.comp, _mm_set_ps1(s));
        }
    };

    template<>
    struct compute_vec4_mul<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_mul_ps(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.comp = _mm_mul_ps(v1.comp, _mm_set_ps1(s));
        }
    };

    template<>
    struct compute_vec4_div<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.comp = _mm_div_ps(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.comp = _mm_div_ps(v1.comp, _mm_set_ps1(s));
        }
    };

    template<>
    struct compute_vec4_inc<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1)
        {
            r.comp = _mm_add_ps(v1.comp, _mm_set_ps1(1.0f));
        }
    };

    template<>
    struct compute_vec4_dec<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1)
        {
            r.comp = _mm_sub_ps(v1.comp, _mm_set_ps1(1.0f));
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


    // ============ //
    //   TVector3   //
    // ============ //


    template<>
    struct construct_vec3<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const TVector3<float, true>& v2)
        {
            v1.comp = _mm_setr_ps(v2.x, v2.y, v2.z, 0.0f);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, float s)
        {
            v1.comp = _mm_set_ps1(s);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, float x, float y, float z)
        {
            v1.comp = _mm_setr_ps(x, y, z, 0.0f);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const Phanes::Core::Math::TVector2<float, true>& v2, float s)
        {
            v1.comp = _mm_set_ps(v2.x, v2.y, s, 0.0f);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const float* s)
        {
            v1.comp = _mm_setr_ps(s[0], s[1], s[2], 0.0f);

        }
    };



    template<> struct compute_vec3_eq<float, true> : public compute_vec4_eq<float, true>
    {
        static FORCEINLINE bool map(Phanes::Core::Math::TVector3<float, true>& v1, Phanes::Core::Math::TVector3<float, true>& v2)
        {
            v1.comp = _mm_setr_ps(v1.x, v1.y, v1.z, 0.0f);
            v2.comp = _mm_setr_ps(v2.x, v2.y, v2.z, 0.0f);

            float r;
            _mm_store_ps1(&r, _mm_cmpeq_ps(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };

    template<> struct compute_vec3_ieq<float, true> : public compute_vec4_ieq<float, true> 
    {
        static FORCEINLINE bool map(Phanes::Core::Math::TVector3<float, true>& v1, Phanes::Core::Math::TVector3<float, true>& v2)
        {
            v1.comp = _mm_setr_ps(v1.x, v1.y, v1.z, 0.0f);
            v2.comp = _mm_setr_ps(v2.x, v2.y, v2.z, 0.0f);
            
            float r;
            _mm_store_ps1(&r, _mm_cmpneq_ps(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };


    template<> struct compute_vec3_add<float, true> : public compute_vec4_add<float, true> {};
    template<> struct compute_vec3_sub<float, true> : public compute_vec4_sub<float, true> {};
    template<> struct compute_vec3_mul<float, true> : public compute_vec4_mul<float, true> {};
    template<> struct compute_vec3_div<float, true> : public compute_vec4_div<float, true> {};
    template<> struct compute_vec3_inc<float, true> : public compute_vec4_inc<float, true> {};
    template<> struct compute_vec3_dec<float, true> : public compute_vec4_dec<float, true> {};

    // ============ //
    //   TVector2   //
    // ============ //


    template<>
    struct construct_vec2<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, const TVector2<double, true>& v2)
        {
            v1.comp = _mm_setr_pd(v2.x, v2.y);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            v1.comp = _mm_set_pd1(s);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, double x, double y)
        {
            v1.comp = _mm_setr_pd(x, y);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, const double* s)
        {
            v1.comp = _mm_loadu_pd(s);

        }
    };


    template<>
    struct compute_vec2_add<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.comp = _mm_add_pd(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.comp = _mm_add_pd(v1.comp, _mm_set1_pd(s));
        }
    };

    template<>
    struct compute_vec2_sub<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.comp = _mm_sub_pd(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.comp = _mm_sub_pd(v1.comp, _mm_set1_pd(s));
        }
    };

    template<>
    struct compute_vec2_mul<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.comp = _mm_mul_pd(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.comp = _mm_mul_pd(v1.comp, _mm_set1_pd(s));
        }
    };

    template<>
    struct compute_vec2_div<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.comp = _mm_div_pd(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.comp = _mm_div_pd(v1.comp, _mm_set1_pd(s));
        }
    };

    template<>
    struct compute_vec2_inc<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1)
        {
            r.comp = _mm_add_pd(v1.comp, _mm_set1_pd(1.0f));
        }
    };

    template<>
    struct compute_vec2_dec<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1)
        {
            r.comp = _mm_sub_pd(v1.comp, _mm_set1_pd(1.0f));
        }
    };

    template<>
    struct compute_vec2_eq<double, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            double r;
            _mm_store1_pd(&r, _mm_cmpeq_pd(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };

    template<>
    struct compute_vec2_ieq<double, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            double r;
            _mm_store1_pd(&r, _mm_cmpneq_pd(v1.comp, v2.comp));
            return (r == 0xffffffff) ? true : false;
        }
    };

    // =============== //
    //   TIntVector2   //
    // =============== //



}
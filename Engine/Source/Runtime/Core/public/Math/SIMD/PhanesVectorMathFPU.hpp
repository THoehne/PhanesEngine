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
        Phanes::Core::Types::Vec4f32Reg r;
        r.data[0] = (v.data[0] + v.data[1] + v.data[2] + v.data[3]);
        return r;
    }

    /// <summary>
    /// Adds all scalars of the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Sum of components.</returns>
    float vec4_hadd_cvtf32(const Phanes::Core::Types::Vec4f32Reg v)
    {
        return (v.data[0] + v.data[1] + v.data[2] + v.data[3]);
    }

    /// <summary>
    /// Gets the absolute value of each scalar in the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Vector with all components positive.</returns>
    Phanes::Core::Types::Vec4f32Reg vec4_abs(const Phanes::Core::Types::Vec4f32Reg v)
    {
        Phanes::Core::Types::Vec4f32Reg r;
        r.data[0] = Phanes::Core::Math::Abs(v.data[0]);
        r.data[1] = Phanes::Core::Math::Abs(v.data[1]);
        r.data[2] = Phanes::Core::Math::Abs(v.data[2]);
        r.data[3] = Phanes::Core::Math::Abs(v.data[3]);

        return r;
    }

    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    Phanes::Core::Types::Vec4f32Reg vec4_dot(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        Phanes::Core::Types::Vec4f32Reg r;
        r.data[0] = (v1.data[0] * v2.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2] + v1.data[3] * v2.data[3]);
        return r;
    }

    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    float vec4_dot_cvtf32(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        return (v1.data[0] * v2.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2] + v1.data[3] * v2.data[3]);
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
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = v2.w;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = s;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, float x, float y, float z, float w)
        {
            v1.x = x;
            v1.y = y;
            v1.z = z;
            v1.w = w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector2<float, false>& v2, const Phanes::Core::Math::TVector2<float, false>& v3)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.x = v3.x;
            v1.y = v3.y;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const float* s)
        {
            v1.x = s[0];
            v1.y = s[1];
            v1.z = s[2];
            v1.w = s[3];

        }

    };


    template<>
    struct compute_vec4_add<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
            r.w = v1.w + v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
            r.w = v1.w + s;
        }
    };

    template<>
    struct compute_vec4_sub<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
            r.w = v1.w - v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
            r.w = v1.w - s;
        }
    };

    template<>
    struct compute_vec4_mul<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
            r.w = v1.w * v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };

    template<>
    struct compute_vec4_div<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
            r.z = v1.z / v2.z;
            r.w = v1.w / v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1, float s)
        {
            s = 1.0f / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };

    template<>
    struct compute_vec4_inc<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
            r.w = v1.w + 1;
        }
    };

    template<>
    struct compute_vec4_dec<float, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r, const Phanes::Core::Math::TVector4<float, true>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
            r.w = v1.w - 1;
        }
    };

    template<>
    struct compute_vec4_eq<float, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.z - v2.z) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.w - v2.w) < P_FLT_INAC);
        }
    };

    template<>
    struct compute_vec4_ieq<float, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector4<float, true>& v1, const Phanes::Core::Math::TVector4<float, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.z - v2.z) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.w - v2.w) > P_FLT_INAC);
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
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = 0.0f;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, float s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = 0.0f;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, float x, float y, float z)
        {
            v1.x = x;
            v1.y = y;
            v1.z = z;
            v1.w = 0.0f;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const Phanes::Core::Math::TVector2<float, true>& v2, float s)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = s;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const float* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = 0.0f;

        }
    };



    template<> struct compute_vec3_eq<float, true> : public compute_vec4_eq<float, true>
    {
        static FORCEINLINE bool map(Phanes::Core::Math::TVector3<float, true>& v1, Phanes::Core::Math::TVector3<float, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.z - v2.z) < P_FLT_INAC);
        }
    };

    template<> struct compute_vec3_ieq<float, true> : public compute_vec4_ieq<float, true>
    {
        static FORCEINLINE bool map(Phanes::Core::Math::TVector3<float, true>& v1, Phanes::Core::Math::TVector3<float, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.z - v2.z) > P_FLT_INAC);
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
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            v1.x = s;
            v1.y = s;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, double x, double y)
        {
            v1.x = x;
            v1.y = y;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, const double* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
        }
    };


    template<>
    struct compute_vec2_add<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
        }
    };

    template<>
    struct compute_vec2_sub<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
        }
    };

    template<>
    struct compute_vec2_mul<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };

    template<>
    struct compute_vec2_div<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            r.x = v1.x / v2.x;
            r.y = v1.y / v2.y;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1, double s)
        {
            s = 1.0f / s;

            r.x = v1.x * s;
            r.y = v1.y * s;
        }
    };

    template<>
    struct compute_vec2_inc<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
        }
    };

    template<>
    struct compute_vec2_dec<double, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r, const Phanes::Core::Math::TVector2<double, true>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
        }
    };

    template<>
    struct compute_vec2_eq<double, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) < P_FLT_INAC &&
                Phanes::Core::Math::Abs(v1.y - v2.y) < P_FLT_INAC);
        }
    };

    template<>
    struct compute_vec2_ieq<double, true>
    {
        static FORCEINLINE bool map(const Phanes::Core::Math::TVector2<double, true>& v1, const Phanes::Core::Math::TVector2<double, true>& v2)
        {
            return (Phanes::Core::Math::Abs(v1.x - v2.x) > P_FLT_INAC ||
                Phanes::Core::Math::Abs(v1.y - v2.y) > P_FLT_INAC);
        }
    };


}
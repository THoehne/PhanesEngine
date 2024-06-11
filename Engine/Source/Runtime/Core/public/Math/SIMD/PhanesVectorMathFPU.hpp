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


    // =============== //
    //   TIntVector4   //
    // =============== //

    template<>
    struct construct_ivec4<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, const TIntVector4<int, true>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = v2.w;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = s;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, int x, int y, int z, int w)
        {
            v1.x = x;
            v1.y = y;
            v1.y = z;
            v1.y = w;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, const int* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = comp[3];
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector2<int, true>& v1, const Phanes::Core::Math::TIntVector2<int, true>& v2)
        {
            r.x = v1.x;
            r.y = v1.y;
            r.x = v2.x;
            r.y = v2.y;
        }
    };

    template<>
    struct compute_ivec4_add<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x + v2.x;
            r.y = v1.y + v2.y;
            r.z = v1.z + v2.z;
            r.w = v1.w + v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x + s;
            r.y = v1.y + s;
            r.z = v1.z + s;
            r.w = v1.w + s;
        }
    };

    template<>
    struct compute_ivec4_sub<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x - v2.x;
            r.y = v1.y - v2.y;
            r.z = v1.z - v2.z;
            r.w = v1.w - v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x - s;
            r.y = v1.y - s;
            r.z = v1.z - s;
            r.w = v1.w - s;
        }
    };

    template<>
    struct compute_ivec4_mul<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x * v2.x;
            r.y = v1.y * v2.y;
            r.z = v1.z * v2.z;
            r.w = v1.w * v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x * s;
            r.y = v1.y * s;
            r.z = v1.z * s;
            r.w = v1.w * s;
        }
    };

    template<>
    struct compute_ivec4_inc<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1)
        {
            r.x = v1.x + 1;
            r.y = v1.y + 1;
            r.z = v1.z + 1;
            r.w = v1.w + 1;
        }
    };

    template<>
    struct compute_ivec4_dec<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1)
        {
            r.x = v1.x - 1;
            r.y = v1.y - 1;
            r.z = v1.z - 1;
            r.w = v1.w - 1;
        }
    };

    template<>
    struct compute_ivec4_and<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x & v2.x;
            r.y = v1.y & v2.y;
            r.z = v1.z & v2.z;
            r.w = v1.w & v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x & s;
            r.y = v1.y & s;
            r.z = v1.z & s;
            r.w = v1.w & s;
        }
    };

    template<>
    struct compute_ivec4_or<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x | v2.x;
            r.y = v1.y | v2.y;
            r.z = v1.z | v2.z;
            r.w = v1.w | v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x | s;
            r.y = v1.y | s;
            r.z = v1.z | s;
            r.w = v1.w | s;
        }
    };

    template<>
    struct compute_ivec4_xor<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x ^ v2.x;
            r.y = v1.y ^ v2.y;
            r.z = v1.z ^ v2.z;
            r.w = v1.w ^ v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x ^ s;
            r.y = v1.y ^ s;
            r.z = v1.z ^ s;
            r.w = v1.w ^ s;
        }
    };

    template<>
    struct compute_ivec4_left_shift<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x << v2.x;
            r.y = v1.y << v2.y;
            r.z = v1.z << v2.z;
            r.w = v1.w << v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x << s;
            r.y = v1.y << s;
            r.z = v1.z << s;
            r.w = v1.w << s;
        }
    };

    template<>
    struct compute_ivec4_right_shift<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, const Phanes::Core::Math::TIntVector4<int, true>& v2)
        {
            r.x = v1.x >> v2.x;
            r.y = v1.y >> v2.y;
            r.z = v1.z >> v2.z;
            r.w = v1.w >> v2.w;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r, const Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
        {
            r.x = v1.x >> s;
            r.y = v1.y >> s;
            r.z = v1.z >> s;
            r.w = v1.w >> s;
        }
    };


    // =============== //
    //   TIntVector3   //
    // =============== //


    template<>
    struct construct_ivec3<int, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, const TIntVector3<int, true>& v2)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = v2.z;
            v1.w = (T)0;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, int s)
        {
            v1.x = s;
            v1.y = s;
            v1.z = s;
            v1.w = (T)0;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, int x, int y, int z)
        {
            v1.x = x;
            v1.y = y;
            v1.y = z;
            v1.w = (T)0;
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, const int* comp)
        {
            v1.x = comp[0];
            v1.y = comp[1];
            v1.z = comp[2];
            v1.w = (T)0;
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& r, const Phanes::Core::Math::TIntVector2<int, true>& v1, const int s)
        {
            v1.x = v2.x;
            v1.y = v2.y;
            v1.z = s;
            v1.w = (T)0;
        }
    };


    template<> struct compute_ivec3_add<int, true> : public compute_ivec4_add<int, true> {};
    template<> struct compute_ivec3_sub<int, true> : public compute_ivec4_sub<int, true> {};
    template<> struct compute_ivec3_mul<int, true> : public compute_ivec4_mul<int, true> {};
    template<> struct compute_ivec3_div<int, true> : public compute_ivec4_div<int, true> {};
    template<> struct compute_ivec3_inc<int, true> : public compute_ivec4_inc<int, true> {};
    template<> struct compute_ivec3_dec<int, true> : public compute_ivec4_dec<int, true> {};


    template<> struct compute_ivec3_and<int, true> : public compute_ivec4_and<int, true> {};
    template<> struct compute_ivec3_or<int, true> : public compute_ivec4_or<int, true> {};
    template<> struct compute_ivec3_xor<int, true> : public compute_ivec4_xor<int, true> {};
    template<> struct compute_ivec3_left_shift<int, true> : public compute_ivec4_left_shift<int, true> {};
    template<> struct compute_ivec3_right_shift<int, true> : public compute_ivec4_right_shift<int, true> {};


    // =============== //
    //   TIntVector2   //
    // =============== //

    template<>
    struct construct_ivec2<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            v1.comp = _mm_setr_epi64x(v2.x, v2.y);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, Phanes::Core::Types::int64 s)
        {
            v1.comp = _mm_set1_epi64x(s);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, Phanes::Core::Types::int64 x, Phanes::Core::Types::int64 y)
        {
            v1.comp = _mm_setr_epi64x(x, y);
        }


        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Types::int64* comp)
        {
            v1.comp = _mm_loadu_epi64(comp);
        }
    };

    template<>
    struct compute_ivec2_add<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_add_epi64(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_add_epi64(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_sub<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_sub_epi64(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_sub_epi64(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_inc<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1)
        {
            r.comp = _mm_add_epi64(v1.comp, _mm_set1_epi64x(1));
        }
    };

    template<>
    struct compute_ivec2_dec<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1)
        {
            r.comp = _mm_sub_epi64(v1.comp, _mm_set1_epi64x(1));
        }
    };

    template<>
    struct compute_ivec2_and<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_and_si128(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_and_si128(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_or<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_or_si128(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_or_si128(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_xor<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_xor_si128(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_xor_si128(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_left_shift<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_sll_epi64(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_sll_epi64(v1.comp, _mm_set1_epi64x(s));
        }
    };

    template<>
    struct compute_ivec2_right_shift<Phanes::Core::Types::int64, true>
    {
        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
        {
            r.comp = _mm_srl_epi64(v1.comp, v2.comp);
        }

        static FORCEINLINE void map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r, const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1, T s)
        {
            r.comp = _mm_srl_epi64(v1.comp, _mm_set1_epi64x(s));
        }
    };

}
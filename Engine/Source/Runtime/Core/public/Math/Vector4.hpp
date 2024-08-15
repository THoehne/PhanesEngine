#pragma once


#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/SIMD/Storage.h"

#include "Core/public/Math/MathFwd.h"


#include "Core/public/Math/Vector2.hpp"

#define PZeroVector4(type, aligned)			Phanes::Core::Math::TVector4<##type, ##aligned>(0,0,0,0)

namespace Phanes::Core::Math
{

    /// 4D Vector defined with x, y, z, w. 
    /// Alignment allows for possible simd optimization.
    template<RealType T, bool IsAligned = false>
    struct TVector4
    {
    public:
        using Real = T;
        union
        {
            struct {
                /// <summary>
                /// X component of vector
                /// </summary>
                Real x;

                /// <summary>
                /// X component of vector
                /// </summary>
                Real y;

                /// <summary>
                /// Z component of vector
                /// </summary>
                Real z;

                /// <summary>
                /// W component of vector
                /// </summary>
                Real w;
                
            };
            /// <summary>
            /// Wraps components in one array / xmm register.
            /// </summary>
            union 
            {
                typename SIMD::Storage<4, Real, SIMD::use_simd<T, 4, IsAligned>::value>::type comp;
                typename SIMD::Storage<4, Real, SIMD::use_simd<T, 4, IsAligned>::value>::type data;
            };
            
        };

        /// Default constructor
        TVector4() = default;

        /// Copy constructor
        TVector4(const TVector4<Real, IsAligned>& v);

        /// <summary>
        /// Construct vector from one scalar.
        /// <para>x,y,z,w = s</para>
        /// </summary>
        /// <param name="s">Scalar</param>
        TVector4(Real s);

        /// <summary>
        /// Construct vector from x, y, z, w components.
        /// </summary>
        /// <param name="_x">X component</param>
        /// <param name="_y">Y component</param>
        /// <param name="_z">Z component</param>
        /// <param name="_w">W component</param>
        TVector4(Real _x, Real _y, Real _z, Real _w);

        /// <summary>
        /// Construct vector from two 2d vectors like: 
        /// <para>x, y = v1.x, v1.y</para>
        /// z, w = v2.x, v2.y
        /// </summary>
        /// <param name="v1">TVector2 one</param>
        /// <param name="v2">TVector2 two</param>
        TVector4(const TVector2<Real, IsAligned>& v1, const TVector2<Real, IsAligned>& v2);

        /// <summary>
        /// Construct vector from array of components
        /// </summary>
        /// <param name="comp">Array of at least 4 components</param>
        TVector4(const Real* comp);

    };

    // ===================== //
    //   Vector4 operators   //
    // ===================== //

    // Unary arithmetic operators

    /// <summary>
    /// Vector addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator+= (TVector4<T, A>& v1, const TVector4<T, A>& v2);
    
    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator+= (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator-= (TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator-= (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector - scalar multiplication.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator*= (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Scale vector by another vector componentwise.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator*= (TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/= (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Coponentwise vector division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/= (TVector4<T, A>& v1, const TVector4<T, A>& v2);



    // Unary arithmetic operators

    /// <summary>
    /// Vector addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator+ (const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator+ (const TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator- (const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator- (const TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector - scalar multiplication.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator* (const TVector4<T, A>& v1, T s);

    template<RealType T, bool A>
    FORCEINLINE TVector4<T, A> operator* (T s, const TVector4<T, A>& v1) { return v1 * s; };

    /// <summary>
    /// Scale vector by another vector componentwise.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator* (const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/ (const TVector4<T, A>& v1, T s);

    template<RealType T, bool A>
    FORCEINLINE TVector4<T, A> operator/ (T s, const TVector4<T, A>& v1) { return v1 / s; };

    /// <summary>
    /// Componentwise vector division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/ (const TVector4<T, A>& v1, const TVector4<T, A>& v2);



    // Comparison operators

    /// <summary>
    /// Test to vectors for equality.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns><code>True</code>, if equal and <code>false</code> if not.</returns>
    template<RealType T, bool A>
    bool operator==(const TVector4<T, A>& v1, const TVector4<T, A>& v2);


    /// <summary>
    /// Test to vectors for inequality.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns><code>True</code>, if inequal and <code>false</code> if equal.</returns>
    template<RealType T, bool A>
    bool operator!=(const TVector4<T, A>& v1, const TVector4<T, A>& v2);


    
    
    // Unaray increment operators


    /// <summary>
    /// Increment vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A>& operator++(TVector4<T, A>& v1);

    /// <summary>
    /// Decrement vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>v1</returns>
    template<RealType T, bool A>
    TVector4<T, A>& operator--(TVector4<T, A>& v1);

    /// <summary>
    /// Increment vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>v1</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator++(TVector4<T, A>& v1, int);

    /// <summary>
    /// Decrement vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator--(TVector4<T, A>& v1, int);







    // ====================== //
    //   TVector4 functions   //
    // ====================== //

    template<RealType T>
    void Set(TVector4<T, false>& v1, TVector4<T, false>& v2)
    {
        v1.x = v2.x;
        v1.y = v2.y;
        v1.z = v2.z;
        v1.w = v2.w;
    }

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T>
    T Magnitude(const TVector4<T, false>& v)
    {
        return sqrt(DotP(v, v));
    }

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T>
    T SqrMagnitude(const TVector4<T, false>& v)
    {
        return DotP(v, v);
    }

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T>
    constexpr T Length(const TVector4<T, false>& v)  {   return Magnitude(v);   }

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T>
    constexpr T SqrLength(const TVector4<T, false>& v) {   return SqrMagnitude(v);   }

    /// <summary>
    /// Angle between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns></returns>
    template<RealType T> 
    T Angle(const TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        return acos(DotP(v1, v2) / (Magnitude(v1) * Magnitude(v2)));
    }

    /// <summary>
    /// Cosine of angle between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns></returns>
    template<RealType T>
    T CosineAngle(const TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        return DotP(v1, v2) / (Magnitude(v1) * Magnitude(v2));
    }

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Normalized vector</returns>
    template<RealType T>
    TVector4<T, false> Normalize(const TVector4<T, false>& v1)
    {
        T vecNorm = Magnitude(v1);

        vecNorm = (vecNorm < P_FLT_INAC) ? (T)1.0 : vecNorm;

        return (v1 / vecNorm);
    }

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> NormalizeV(TVector4<T, false>& v1)
    {
        T vecNorm = Magnitude(v1);

        vecNorm = (vecNorm < P_FLT_INAC) ? (T)1.0 : vecNorm;

        v1 /= vecNorm;

        return v1;
    }

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <remarks>Doesn't check for zero vector.</remarks>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Normalized vector</returns>
    template<RealType T>
    TVector4<T, false> UnsafeNormalize(const TVector4<T, false>& v1)
    {
        return v1 / Magnitude(v1);
    }

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <remarks>Doesn't check for zero vector.</remarks>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> UnsafeNormalizeV(TVector4<T, false>& v1)
    {
        v1 /= Magnitude(v1);
        return v1;
    }

    /// <summary>
    /// Calculates the dot product between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Dot product between vectors.</returns>
    template<RealType T>
    T DotP(const TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T>
    TVector4<T, false> Max(const TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        return TVector4<T, false>(
            (v1.x > v2.x) ? v1.x : v2.x,
            (v1.y > v2.y) ? v1.y : v2.y,
            (v1.z > v2.z) ? v1.z : v2.z,
            (v1.w > v2.w) ? v1.w : v2.w
        );
    }

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> MaxV(TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        v1.x = (v1.x > v2.x) ? v1.x : v2.x;
        v1.y = (v1.y > v2.y) ? v1.y : v2.y;
        v1.z = (v1.z > v2.z) ? v1.z : v2.z;
        v1.w = (v1.w > v2.w) ? v1.w : v2.w;

        return v1;
    }

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T>
    TVector4<T, false> Min(const TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        return TVector4<T, false>(
            (v1.x < v2.x) ? v1.x : v2.x,
            (v1.y < v2.y) ? v1.y : v2.y,
            (v1.z < v2.z) ? v1.z : v2.z,
            (v1.w < v2.w) ? v1.w : v2.w
        );
    }

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> MinV(TVector4<T, false>& v1, const TVector4<T, false>& v2)
    {
        v1.x = (v1.x < v2.x) ? v1.x : v2.x;
        v1.y = (v1.y < v2.y) ? v1.y : v2.y;
        v1.z = (v1.z < v2.z) ? v1.z : v2.z;
        v1.w = (v1.w < v2.w) ? v1.w : v2.w;

        return v1;
    }

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Inverted vector</returns>
    template<RealType T>
    TVector4<T, false> Negate(const TVector4<T, false>& v1)
    {
        return TVector4<T, false>(
            -v1.x,
            -v1.y,
            -v1.z,
            -v1.w
        );
    }

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> NegateV(TVector4<T, false>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;
        v1.w = -v1.w;

        return v1;
    }

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Vector with reciprocal of components.</returns>
    template<RealType T>
    TVector4<T, false> CompInverse(const TVector4<T, false>& v1)
    {
        return TVector4<T, false>(
            (T)1.0 / v1.x,
            (T)1.0 / v1.y,
            (T)1.0 / v1.z,
            (T)1.0 / v1.w
        );
    }

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> CompInverseV(TVector4<T, false>& v1)
    {
        v1.x = (T)1.0 / v1.x;
        v1.y = (T)1.0 / v1.y;
        v1.z = (T)1.0 / v1.z;
        v1.w = (T)1.0 / v1.w;

        return v1;
    }

    /// <summary>
    /// Clamp the vectors length to a magnitude.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1"></param>
    /// <param name="s"></param>
    /// <returns>Vector with magnitude clamped to s.</returns>
    template<RealType T>
    TVector4<T, false> ClampToMagnitude(const TVector4<T, false>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        TVector4<T, false> unitVec;
        unitVec = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector4(T, false);

        magnitude = Clamp(magnitude, min, max);

        return unitVec * magnitude;
    }

    /// <summary>
    /// Clamp the vectors length to a magnitude.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> ClampToMagnitudeV(TVector4<T, false>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        v1 = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector4(T, false);

        v1 *= Clamp(magnitude, min, max);

        return v1;
    }

    /// <summary>
    /// Scale vector to a magnitude
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Vector with scaled magnitude.</returns>
    template<RealType T>
    TVector4<T, false> ScaleToMagnitude(const TVector4<T, false>& v1, T s)
    {
        return Normalize(v1) * s;
    }
    
    /// <summary>
    /// Scale vector to a magnitude
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> ScaleToMagnitudeV(TVector4<T, false>& v1, T s)
    {
        NormalizeV(v1);
        v1 *= s;
        return v1;
    }

    /// <summary>
    /// Reflect vector on plane.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="normal">Planes normal</param>
    /// <returns>Reflected vector</returns>
    template<RealType T>
    TVector4<T, false> Reflect(const TVector4<T, false>& v1, const TVector4<T, false> normal)
    {
        return (2 * DotP(v1, normal) * normal) - v1;
    }

    /// <summary>
    /// Reflect vector on plane.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="normal">Planes normal</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> ReflectV(TVector4<T, false>& v1, const TVector4<T, false> normal)
    {
        v1 = (2 * DotP(v1, normal) * normal) - v1;
        return v1;
    }

    /// <summary>
    /// Project vector v1 onto v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to project</param>
    /// <param name="v2">Vector to project on</param>
    /// <returns>Projected vector.</returns>
    template<RealType T>
    TVector4<T, false> Project(const TVector4<T, false>& v1, const TVector4<T, false> v2)
    {
        return (DotP(v1, v2) / DotP(v2, v2)) * v2;
    }

    /// <summary>
    /// Project vector v1 onto v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to project</param>
    /// <param name="v2">Vector to project on</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> ProjectV(TVector4<T, false>& v1, const TVector4<T, false> v2)
    {
        v1 = (DotP(v1, v2) / DotP(v2, v2)) * v2;

        return v1;
    }

    /// <summary>
    /// Reject vector v1 from v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to reject</param>
    /// <param name="v2">Vector to reject from</param>
    /// <returns>Rejected vector.</returns>
    template<RealType T>
    TVector4<T, false> Reject(const TVector4<T, false>& v1, const TVector4<T, false> v2)
    {
        return v1 - (DotP(v1, v2) / DotP(v2, v2)) * v2;
    }

    /// <summary>
    /// Reject vector v1 from v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to reject</param>
    /// <param name="v2">Vector to reject from</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> RejectV(TVector4<T, false>& v1, const TVector4<T, false> v2)
    {
        v1 = v1 - (DotP(v1, v2) / DotP(v2, v2)) * v2;

        return v1;
    }

    /// <summary>
    /// Perspective divide vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Perspective divided vector.</returns>
    template<RealType T>
    TVector4<T, false> PerspectiveDivide(const TVector4<T, false>& v1)
    {
        float _1_w = (T)1.0 / v1.w;
        return TVector4<T, false>(
            v1.x * _1_w,
            v1.y * _1_w,
            v1.z * _1_w,
            (T)0.0
        );
    }

    /// <summary>
    /// Perspective divide vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T>
    TVector4<T, false> PerspectiveDivideV(TVector4<T, false>& v1)
    {
        float _1_w = (T)1.0 / v1.w;
        
        v1.x *= _1_w;
        v1.y *= _1_w;
        v1.z *= _1_w;
        v1.w = (T)0.0;

        return v1;
    }

    /// <summary>
    /// Tests if vector is normalized.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="threshold">Threshold to vector magnitude of 1.0</param>
    /// <returns>True if vector is normalized, false if not.</returns>
    template<RealType T>
    FORCEINLINE bool IsNormalized(const TVector4<T, false>& v1, T threshold = P_FLT_INAC)
    {
        return (SqrMagnitude(v1) - (T)1.0) < threshold;
    }

    /// <summary>
    /// Tests if vectors are parallel.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="v2">Vector</param>
    /// <param name="threshold">Allowed T inaccuracy from one (e.g. 0.98f)</param>
    /// <returns>True if parallel, false if not.</returns>
    template<RealType T>
    FORCEINLINE bool IsParallel(const TVector4<T, false>& v1, const TVector4<T, false>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (abs(DotP(v1, v2)) > threshold);
    }

    /// <summary>
    /// Tests whether two vectors are coincident (Parallel and point in same direction).
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="v2">Vector</param>
    /// <param name="threshold">Allowed T inaccuracy from one (e.g. 0.98f)</param>
    /// <returns>True if coincident, false if not.</returns>
    template<RealType T>
    FORCEINLINE bool IsCoincident(const TVector4<T, false>& v1, const TVector4<T, false>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (DotP(v1, v2) > threshold);
    }
}


#include "Core/public/Math/Vector4.inl"

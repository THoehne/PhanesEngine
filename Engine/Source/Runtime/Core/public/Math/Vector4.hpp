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
    template<RealType T, bool S = false>
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
                typename SIMD::Storage<4, Real, SIMD::use_simd<T, 4, S>::value>::type comp;
                typename SIMD::Storage<4, Real, SIMD::use_simd<T, 4, S>::value>::type data;
            };
            
        };

        /// Default constructor
        TVector4() = default;

        /// Copy constructor
        TVector4(const TVector4<Real, S>& v);

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
        TVector4(const TVector2<Real, S>& v1, const TVector2<Real, S>& v2);

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
    template<RealType T, bool S>
    TVector4<T, S>& operator+= (TVector4<T, S>& v1, const TVector4<T, S>& v2);
    
    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator+= (TVector4<T, S>& v1, T s);

    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator-= (TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Vector - scalar substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator-= (TVector4<T, S>& v1, T s);

    /// <summary>
    /// Vector - scalar multiplication.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator*= (TVector4<T, S>& v1, T s);

    /// <summary>
    /// Scale vector by another vector componentwise.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator*= (TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Vector - scalar division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator/= (TVector4<T, S>& v1, T s);

    /// <summary>
    /// Coponentwise vector division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator/= (TVector4<T, S>& v1, const TVector4<T, S>& v2);



    // Unary arithmetic operators

    /// <summary>
    /// Vector addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator+ (const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator+ (const TVector4<T, S>& v1, T s);

    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator- (const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Vector - scalar substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator- (const TVector4<T, S>& v1, T s);

    template<RealType T, bool S>
    TVector4<T, S> operator- (T s, const TVector4<T, S>& v1);

    /// <summary>
    /// Vector - scalar multiplication.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator* (const TVector4<T, S>& v1, T s);

    template<RealType T, bool S>
    FORCEINLINE TVector4<T, S> operator* (T s, const TVector4<T, S>& v1) { return v1 * s; };

    /// <summary>
    /// Scale vector by another vector componentwise.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator* (const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Vector - scalar division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator/ (const TVector4<T, S>& v1, T s);

    template<RealType T, bool S>
    FORCEINLINE TVector4<T, S> operator/ (T s, const TVector4<T, S>& v1);

    /// <summary>
    /// Componentwise vector division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator/ (const TVector4<T, S>& v1, const TVector4<T, S>& v2);



    // Comparison operators

    /// <summary>
    /// Test to vectors for equality.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns><code>True</code>, if equal and <code>false</code> if not.</returns>
    template<RealType T, bool S>
    bool operator==(const TVector4<T, S>& v1, const TVector4<T, S>& v2);


    /// <summary>
    /// Test to vectors for inequality.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns><code>True</code>, if inequal and <code>false</code> if equal.</returns>
    template<RealType T, bool S>
    bool operator!=(const TVector4<T, S>& v1, const TVector4<T, S>& v2);


    
    
    // Unaray increment operators


    /// <summary>
    /// Increment vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator++(TVector4<T, S>& v1);

    /// <summary>
    /// Decrement vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>v1</returns>
    template<RealType T, bool S>
    TVector4<T, S>& operator--(TVector4<T, S>& v1);

    /// <summary>
    /// Increment vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>v1</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator++(TVector4<T, S>& v1, int);

    /// <summary>
    /// Decrement vector by one
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S> operator--(TVector4<T, S>& v1, int);







    // ====================== //
    //   TVector4 functions   //
    // ====================== //

    template<RealType T, bool S>
    TVector4<T, S>& Set(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        v1 = v2;
        return v1;
    }

    /// <summary>
    /// Set vector to values.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="x">X Component</param>
    /// <param name="y">Y Component</param>
    /// <param name="z">Z Component</param>
    /// <param name="w">W Component</param>
    /// <returns></returns>
    template<RealType T, bool S>
    TVector4<T, S>& Set(TVector4<T, S>& v1, T x, T y, T z, T w);

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T, bool S>
    T Magnitude(const TVector4<T, S>& v);

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T, bool S>
    T SqrMagnitude(const TVector4<T, S>& v);

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T, bool S>
    constexpr T Length(const TVector4<T, S>& v)  {   return Magnitude(v);   }

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T, bool S>
    constexpr T SqrLength(const TVector4<T, S>& v) {   return SqrMagnitude(v);   }

    /// <summary>
    /// Angle between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns></returns>
    template<RealType T, bool S> 
    T Angle(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
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
    template<RealType T, bool S>
    T CosineAngle(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
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
    template<RealType T, bool S>
    TVector4<T, S> Normalize(const TVector4<T, S>& v1)
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
    template<RealType T, bool S>
    TVector4<T, S>& NormalizeV(TVector4<T, S>& v1)
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
    template<RealType T, bool S>
    TVector4<T, S> UnsafeNormalize(const TVector4<T, S>& v1)
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
    template<RealType T, bool S>
    TVector4<T, S>& UnsafeNormalizeV(TVector4<T, S>& v1)
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
    template<RealType T, bool S>
    T DotP(const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T, bool S>
    TVector4<T, S> Max(const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& MaxV(TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T, bool S>
    TVector4<T, S> Min(const TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& MinV(TVector4<T, S>& v1, const TVector4<T, S>& v2);

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Inverted vector</returns>
    template<RealType T, bool S>
    TVector4<T, S> Negate(const TVector4<T, S>& v1)
    {
        return (T)0.0 - v1;
    }

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& NegateV(TVector4<T, S>& v1)
    {
        return (v1 = (T)0.0 - v1);
    }

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Vector with reciprocal of components.</returns>
    template<RealType T, bool S>
    TVector4<T, S> CompInverse(const TVector4<T, S>& v1)
    {
        return (T)1.0 / v1;
    }

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& CompInverseV(TVector4<T, S>& v1)
    {
        return (v1 = (T)1.0 / v1);
    }

    /// <summary>
    /// Clamp the vectors length to a magnitude.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1"></param>
    /// <param name="s"></param>
    /// <returns>Vector with magnitude clamped to s.</returns>
    template<RealType T, bool S>
    TVector4<T, S> ClampToMagnitude(const TVector4<T, S>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        TVector4<T, S> unitVec;
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
    template<RealType T, bool S>
    TVector4<T, S>& ClampToMagnitudeV(TVector4<T, S>& v1, T min, T max)
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
    template<RealType T, bool S>
    TVector4<T, S> ScaleToMagnitude(const TVector4<T, S>& v1, T s)
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
    template<RealType T, bool S>
    TVector4<T, S>& ScaleToMagnitudeV(TVector4<T, S>& v1, T s)
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
    template<RealType T, bool S>
    TVector4<T, S> Reflect(const TVector4<T, S>& v1, const TVector4<T, S> normal)
    {
        return ((T)2.0 * DotP(v1, normal) * normal) - v1;
    }

    /// <summary>
    /// Reflect vector on plane.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="normal">Planes normal</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& ReflectV(TVector4<T, S>& v1, const TVector4<T, S> normal)
    {
        v1 = ((T)2.0 * DotP(v1, normal) * normal) - v1;
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
    template<RealType T, bool S>
    TVector4<T, S> Project(const TVector4<T, S>& v1, const TVector4<T, S> v2)
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
    template<RealType T, bool S>
    TVector4<T, S>& ProjectV(TVector4<T, S>& v1, const TVector4<T, S> v2)
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
    template<RealType T, bool S>
    TVector4<T, S> Reject(const TVector4<T, S>& v1, const TVector4<T, S> v2)
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
    template<RealType T, bool S>
    TVector4<T, S>& RejectV(TVector4<T, S>& v1, const TVector4<T, S> v2)
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
    template<RealType T, bool S>
    TVector4<T, S> PerspectiveDivide(const TVector4<T, S>& v1);

    /// <summary>
    /// Perspective divide vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    TVector4<T, S>& PerspectiveDivideV(TVector4<T, S>& v1);

    /// <summary>
    /// Tests if vector is normalized.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="threshold">Threshold to vector magnitude of 1.0</param>
    /// <returns>True if vector is normalized, false if not.</returns>
    template<RealType T, bool S>
    FORCEINLINE bool IsNormalized(const TVector4<T, S>& v1, T threshold = P_FLT_INAC)
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
    template<RealType T, bool S>
    FORCEINLINE bool IsParallel(const TVector4<T, S>& v1, const TVector4<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
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
    template<RealType T, bool S>
    FORCEINLINE bool IsCoincident(const TVector4<T, S>& v1, const TVector4<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (DotP(v1, v2) > threshold);
    }
}


#include "Core/public/Math/Vector4.inl"

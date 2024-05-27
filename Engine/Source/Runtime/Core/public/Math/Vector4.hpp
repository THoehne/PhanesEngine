#pragma once


#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/SIMD/Storage.h"

#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector2.hpp"

namespace Phanes::Core::Math
{

    /// 4D Vector defined with x, y, z, w.
    template<RealType T, bool IsAlgined = false>
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
                T x;

                /// <summary>
                /// X component of vector
                /// </summary>
                T y;

                /// <summary>
                /// Z component of vector
                /// </summary>
                T z;

                /// <summary>
                /// W component of vector
                /// </summary>
                T w;
                
            };
            /// <summary>
            /// Wraps components in one array / xmm register.
            /// </summary>
            union 
            {
                typename Phanes::Core::SIMD::Storage<4, T, IsAlgined>::type comp;
                typename Phanes::Core::SIMD::Storage<4, T, IsAlgined>::type data;
            };
            
        };

        /// Default constructor
        TVector4() = default;

        /// Copy constructor
        TVector4(const TVector4<Real, IsAlgined>& v);

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
        TVector4(const TVector2<Real>& v1, const TVector2<Real>& v2);

        /// <summary>
        /// Construct vector from array of components
        /// </summary>
        /// <param name="comp">Array of at least 4 components</param>
        TVector4(const Real* comp);

        /// <summary>
        /// Construct the vector, by calculating the way between two points.
        /// </summary>
        /// <param name="start">Starting point of the vector.</param>
        /// <param name="end">End point of the vector.</param>
        TVector4(const TPoint4<Real>& start, const TPoint4<Real>& end);

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
    TVector4<T, A> operator+ (TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator+ (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator- (TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator- (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Vector - scalar multiplication.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator* (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Scale vector by another vector componentwise.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator* (TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Vector - scalar division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Scalar</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/ (TVector4<T, A>& v1, T s);

    /// <summary>
    /// Componentwise vector division.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Computed vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> operator/ (TVector4<T, A>& v1, const TVector4<T, A>& v2);



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

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T, bool A>
    T Magnitude(const TVector4<T, A>& v);

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T, bool A>
    T SqrMagnitude(const TVector4<T, A>& v);

    /// <summary>
    /// Get magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Magnitude of vector.</returns>
    template<RealType T, bool A>
    constexpr T Length(const TVector4<T, A>& v)  {   return Magnitude(v);   }

    /// <summary>
    /// Get square of magnitude of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v">Vector</param>
    /// <returns>Square of magnitude of vector.</returns>
    template<RealType T, bool A>
    constexpr T SqrLength(const TVector4<T, A>& v) {   return SqrMagnitude(v);   }

    /// <summary>
    /// Angle between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns></returns>
    template<RealType T, bool A> 
    T Angle(const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Cosine of angle between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns></returns>
    template<RealType T, bool A>
    T CosineAngle(const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Normalized vector</returns>
    template<RealType T, bool A>
    TVector4<T, A> Normalize(const TVector4<T, A>& v1);

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> NormalizeV(TVector4<T, A>& v1);

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <remarks>Doesn't check for zero vector.</remarks>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Normalized vector</returns>
    template<RealType T, bool A>
    TVector4<T, A> UnsafeNormalize(const TVector4<T, A>& v1);

    /// <summary>
    /// Normalizes a vector.
    /// </summary>
    /// <remarks>Doesn't check for zero vector.</remarks>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> UnsafeNormalizeV(TVector4<T, A>& v1);

    /// <summary>
    /// Calculates the dot product between two vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Dot product between vectors.</returns>
    template<RealType T, bool A>
    T DotP(const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T, bool A>
    TVector4<T, A> Max(const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Gets componentwise max of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> MaxV(TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Vector with componentwise max of both vectors.</returns>
    template<RealType T, bool A>
    TVector4<T, A> Min(const TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Gets componentwise min of both vectors.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> MinV(TVector4<T, A>& v1, const TVector4<T, A>& v2);

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Inverted vector</returns>
    template<RealType T, bool A>
    TVector4<T, A> Negate(const TVector4<T, A>& v1);

    /// <summary>
    /// Inverses vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> NegateV(TVector4<T, A>& v1);

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Vector with reciprocal of components.</returns>
    template<RealType T, bool A>
    TVector4<T, A> CompInverse(const TVector4<T, A>& v1);

    /// <summary>
    /// Inverses the components of vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> CompInverseV(TVector4<T, A>& v1);

    /// <summary>
    /// Clamp the vectors length to a magnitude.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1"></param>
    /// <param name="s"></param>
    /// <returns>Vector with magnitude clamped to s.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ClampToMagnitude(const TVector4<T, A>& v1, T s);

    /// <summary>
    /// Clamp the vectors length to a magnitude.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ClampToMagnitudeV(TVector4<T, A>& v1, T s);

    /// <summary>
    /// Scale vector to a magnitude
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Vector with scaled magnitude.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ScaleToMagnitude(const TVector4<T, A>& v1, T s);
    
    /// <summary>
    /// Scale vector to a magnitude
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="s">Magnitude</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ScaleToMagnitudeV(TVector4<T, A>& v1, T s);

    /// <summary>
    /// Reflect vector on plane.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="normal">Planes normal</param>
    /// <returns>Reflected vector</returns>
    template<RealType T, bool A>
    TVector4<T, A> Reflect(const TVector4<T, A>& v1, const TVector4<T, A> normal);

    /// <summary>
    /// Reflect vector on plane.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <param name="normal">Planes normal</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ReflectV(TVector4<T, A>& v1, const TVector4<T, A> normal);

    /// <summary>
    /// Project vector v1 onto v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to project</param>
    /// <param name="v2">Vector to project on</param>
    /// <returns>Projected vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> Project(const TVector4<T, A>& v1, const TVector4<T, A> v2);

    /// <summary>
    /// Project vector v1 onto v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to project</param>
    /// <param name="v2">Vector to project on</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> ProjectV(const TVector4<T, A>& v1, const TVector4<T, A> v2);

    /// <summary>
    /// Reject vector v1 from v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to reject</param>
    /// <param name="v2">Vector to reject from</param>
    /// <returns>Rejected vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> Reject(const TVector4<T, A>& v1, const TVector4<T, A> v2);

    /// <summary>
    /// Reject vector v1 from v2.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector to reject</param>
    /// <param name="v2">Vector to reject from</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> RejectV(const TVector4<T, A>& v1, const TVector4<T, A> v2);

    /// <summary>
    /// Perspective divide vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Perspective divided vector.</returns>
    template<RealType T, bool A>
    TVector4<T, A> PrespectiveDivide(const TVector4<T, A>& v1);

    /// <summary>
    /// Perspective divide vector.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool A>
    TVector4<T, A> PrespectiveDivideV(TVector4<T, A>& v1);
}

// No SIMD
#include "Core/public/Math/Vector4.inl"

// SIMD
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"
#pragma once

// TODO: Slerp (using Quaternions)


#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/SIMD/Storage.h"

#include "Core/public/Math/Vector4.hpp"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

#ifndef VECTOR3_H
#define VECTOR3_H

#define PZeroVector3(type, aligned)			Phanes::Core::Math::TVector3<##type, ##aligned>(0,0,0)
#define PVectorForward3(type, aligned)		Phanes::Core::Math::TVector3<##type, ##aligned>(1,0,0)
#define PVectorBackward3(type, aligned)		Phanes::Core::Math::TVector3<##type, ##aligned>(-1,0,0)
#define PVectorEast3(type, aligned)			Phanes::Core::Math::TVector3<##type, ##aligned>(0,1,0)
#define PVectorWest3(type, aligned)			Phanes::Core::Math::TVector3<##type, ##aligned>(0,-1,0)
#define PVectorUp3(type, aligned)			Phanes::Core::Math::TVector3<##type, ##aligned>(0,0,1)
#define PVectorDown3(type, aligned)			Phanes::Core::Math::TVector3<##type, ##aligned>(0,0,-1)

namespace Phanes::Core::Math {


    // Basic 3D vector (x, y, z)

    template<RealType T, bool S>
    struct TVector3 : public TVector4<T, S> {
    public:

        using Real = T;

        /// <summary>
        /// Default constructor.
        /// </summary>
        TVector3() = default;

        /// <summary>
        /// Copy constructor.
        /// </summary>
        /// <param name="v"></param>
        TVector3(const TVector3<Real, S>& v);

        /// <summary>
        /// Broadcast s into x, y, z.
        /// </summary>
        /// <param name="s"></param>
        TVector3(const Real s);

        /// <summary>
        /// Construct from x, y, z.
        /// </summary>
        /// <param name="x">X component</param>
        /// <param name="y">Y component</param>
        /// <param name="z">Z component</param>
        TVector3(const Real x, const Real y, const Real z);

        /// <summary>
        /// Construct 3d vector from array of components
        /// </summary>
        /// <param name="comp"></param>
        TVector3(const Real* comp);

        /// <summary>
        /// Construct vector from 2d Vector and a scalar.
        /// </summary>
        /// <param name="v">Vector</param>
        /// <param name="s">Scalar</param>
        TVector3(const TVector2<Real, S>& v, Real s);

    };


    // ====================== //
    //   TVector3 operators   //
    // ====================== //

    /// <summary>
    /// Vector addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator+= (TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /// <summary>
    /// Vector - scalar addition.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator+= (TVector3<T, S>& v1, T s);

    /// <summary>
    /// Vector - scalar substraction
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator-= (TVector3<T, S>& v1, const TVector3<T, S>& v2);
       
    /// <summary>
    /// Vector substraction.
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1">Vector one</param>
    /// <param name="v2">Vector two</param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator-= (TVector3<T, S>& v1, T s);

    /// <summary>
    /// Componentwise multiplication
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator*=(TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Componentwise multiplication
     *
     * @param(v1) vector one
     * @param(s) floating point
     */

    template<RealType T, bool S>
    inline TVector3<T, S>& operator*= (TVector3<T, S>& v1, T s);

    /// <summary>
    /// Componentwise division
    /// </summary>
    /// <typeparam name="T">Type of vector</typeparam>
    /// <typeparam name="A">Vector is aligned?</typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>Copy of v1.</returns>
    template<RealType T, bool S>
    inline TVector3<T, S>& operator/=(TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Coponentwise division of 3D vector with floating point
     *
     * @param(v1) vector divide
     * @param(s) floating point to divide with
     */

    template<RealType T, bool S>
    inline TVector3<T, S>& operator/= (TVector3<T, S>& v1, T s);



    /**
     * Componentwise multiplication
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Dot product of Vectors
     */

    template<RealType T, bool S>
    TVector3<T, S> operator* (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Coponentwise multiplication of 3D Vectors with floating point
     *
     * @param(v1) vector one
     * @param(s) floating point
     * 
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator* (const TVector3<T, S>& v1, T s);


    /**
     * Componentwise division
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Dot product of Vectors
     */

    template<RealType T, bool S>
    TVector3<T, S> operator/ (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    template<RealType T, bool S>
    TVector3<T, S> operator/ (T s, const TVector3<T, S>& v1);


    /**
     * Coponentwise division of 3D Vectors with floating point
     *
     * @param(v1) vector one
     * @param(s) floating point
     *
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator/ (const TVector3<T, S>& v1, T s);

    /**
     * Coponentwise multiplication of 3D Vectors with floating point
     *
     * @param(s) floating point
     * @param(v2) vector
     *
     * @return Resulting vector
     */

    template<RealType T, bool S>
    FORCEINLINE TVector3<T, S> operator* (T s, const TVector3<T, S>& v1) 
    { 
        return v1 * s; 
    };

    /**
     * Coponentwise addition of floating point to 3D vector
     *
     * @param(v1) vector to add to
     * @param(s) floating point to add
     * 
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator+ (const TVector3<T, S>& v1, T s);

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     * 
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator+ (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Coponentwise substraction of floating point of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) floating point to substract
     * 
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator- (const TVector3<T, S>& v1, T s);

    template<RealType T, bool S>
    TVector3<T, S> operator- (T s, const TVector3<T, S>& v1);

    /**
     * Coponentwise substraction of floating point of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     *
     * @return Resulting vector
     */

    template<RealType T, bool S>
    TVector3<T, S> operator- (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Tests two 3D vectors for equality.
     *
     * @ref [FUNC]Equals
     * 
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @return True if equal, false if not.
     * 
     * @note Uses [MACRO]P_FLT_INAC
     */

    template<RealType T, bool S>
    inline bool operator== (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Tests two 3D vectors for inequality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @return True if inequal, false if not.
     */

    template<RealType T, bool S>
    inline bool operator!= (const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    template<RealType T, bool S>
    TVector3<T, S> operator++(TVector3<T, S>& v1);

    template<RealType T, bool S>
    TVector3<T, S> operator--(TVector3<T, S>& v1);

    template<RealType T, bool S>
    TVector3<T, S> operator++(TVector3<T, S>& v1, int);

    template<RealType T, bool S>
    TVector3<T, S> operator--(TVector3<T, S>& v1, int);

    // ==================================== //
    //    TVector3 function implementation	//
    // ==================================== //

    /**
     * Gets magnitude of vector
     * 
     * @param(v1) Vector
     * 
     * @return Magnitude of vector
     */

    template<RealType T, bool S>
    inline T Magnitude(const TVector3<T, S>& v1);

    /**
     * @see [FUNC]Magnitude
     */

    template<RealType T, bool S>
    FORCEINLINE T Length(const TVector3<T, S>& v1) { return Magnitude(v1); };

    /**
     * Gets square magnitude of vector
     *
     * @param(v1) Vector
     *
     * @return Square magnitude of vector
     */

    template<RealType T, bool S>
    inline T SqrMagnitude(const TVector3<T, S>& v1);

    /**
     * @see SqrMagnitude
     */

    template<RealType T, bool S>
    FORCEINLINE T SqrLength(const TVector3<T, S>& v1)
    {
        return SqrMagnitude(v1);
    }

    /**
     * Normalizes vector
     *
     * @param(v1) Vector
     *
     * @note Result is stored in v1
     */

    template<RealType T, bool S>
    TVector3<T, S>& NormalizeV(TVector3<T, S>& v1)
    {
        float vecNorm = Magnitude(v1);
        v1 /= (vecNorm < P_FLT_INAC) ? (T)1.0 : vecNorm;

        return v1;
    }

    /**
     * Normalizes vector
     *
     * @param(v1) Vector
     *
     * @note Does not test for zero vector
     */

    template<RealType T, bool S>
    TVector3<T, S>& UnsafeNormalizeV(TVector3<T, S>& v1)
    {
        v1 /= Magnitude(v1);

        return v1;
    }

    /**
     * Reflects a vector on a surface
     *
     * @param(v1) Vector one
     * @param(normal) Normal of surface
     */

    template<RealType T, bool S>
    TVector3<T, S>& ReflectV(TVector3<T, S>& v1, const TVector3<T, S>& normal)
    {
        v1 = ((T)2.0 * DotP(v1, normal) * normal) - v1;

        return v1;
    }

    /**
     * Gets angle between two vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Angle between vectors
     */

    template<RealType T, bool S>
    T Angle(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return acos(DotP(v1, v2) / (Magnitude(v1) * Magnitude(v2)));
    }

    /**
     * Dot product of two vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Dot product of vectors
     */

    template<RealType T, bool S>
    inline T DotP(const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Orthogonalizes three vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector two
     */

    template<RealType T, bool S>
    void Orthogonalize(TVector3<T, S>& v1, TVector3<T, S>& v2, TVector3<T, S>& v3)
    {
        Set(v2, Reject(v2, v1));
        Set(v3, Reject(Reject(v3, v1), v2));
    }

    /**
     * Orthogonalizes three vectors and turns them into unit vectors. Usefull for making sure coordinate axis are still orthogonal.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector two
     * 
     * @note Usefull for making sure coordinate axis are still orthogonal.
     */

    template<RealType T, bool S>
    void OrthoNormalize(TVector3<T, S>& v1, TVector3<T, S>& v2, TVector3<T, S>& v3)
    {
        Set(v2, Reject(v2, v1));
        Set(v3, Reject(Reject(v3, v1), v2));

        NormalizeV(v1);
        NormalizeV(v2);
        NormalizeV(v3);
    }


    /**
     * Tests two vectors for equality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Allowed T inaccuracy.
     * 
     * @return True if equal, false if not.
     */

    template<RealType T, bool S>
    inline bool Equals(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T threshold = P_FLT_INAC)
    {
        return (abs(v1.x - v2.x) < threshold && abs(v1.y - v2.y) < threshold && abs(v1.z - v2.z) < threshold);
    }

    /**
     * Performs perspective divide on vector.
     *
     * @param(v1) Vector
     */

    template<RealType T, bool S>
    TVector3<T, S>& PerspectiveDivideV(TVector3<T, S>& v1)
    {
        float _z = (T)1.0 / v1.z;
        v1.x *= _z;
        v1.y *= _z;
        v1.z = (T)0.0;
        return v1;
    }


    /// <summary>
    /// Calcualtes cross product of vectors
    /// </summary>
    /// <typeparam name="T"></typeparam>
    /// <typeparam name="S"></typeparam>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns>Copy of v1.</returns>

    template<RealType T, bool S>
    TVector3<T, S>& CrossPV(TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Gets the componentwise max of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& MaxV(TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Gets the componentwise min of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& MinV(TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& NegateV(TVector3<T, S>& v1)
    {
        return (v1 = (T)0.0 - v1);
    }


    /**
     * Projects vector v1 onto v2
     *
     * @param(v1) Vector to project
     * @param(v2) Vector to project on
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& ProjectV(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        float x = DotP(v1, v2) / DotP(v2, v2);
        v1 = x * v2;

        return v1;
    }

    /**
     * Rejects vector v1 from v2
     *
     * @param(v1) Vector to reject
     * @param(v2) Vector to reject from
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& RejectV(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        float x = DotP(v1, v2) / DotP(v2, v2);
        v1 -= x * v2;

        return v1;
    }

    /**
     * Copies v1 vector
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<RealType T, bool S>
    TVector3<T, S>& Set(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        v1 = v2;

        return v1;
    }

    /**
     * Sets vector.
     *
     * @param(v1) Vector to copy to
     * @param(x) X component
     * @param(y) Y component
     * @param(z) Z component
     */

    template<RealType T, bool S>
    TVector3<T, S>& Set(TVector3<T, S>& v1, T x, T y, T z);
    
    /**
     * Clamps vector to a range of magnitudes.
     * 
     * @param(v1) Vector to clamp
     * @param(min) Min magnitude
     * @param(max) Max magnitude
     * 
     * @note Result is stored in v1
     */

    template<RealType T, bool S>
    TVector3<T, S>& ClampToMagnitudeV(TVector3<T, S>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        v1 = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T, false);

        v1 *= Clamp(magnitude, min, max);

        return v1;
    }

    /**
     * Inverts the components of vector.
     *
     * @param(v1) Vector
     *
     * @note Result is stored in v1
     */

    template<RealType T, bool S>
    TVector3<T, S>& CompInverseV(TVector3<T, S>& v1)
    {
        return (v1 = (T)1.0 / v1);
    }


    /**
     * Clamps vector into cube.
     *
     * @param(v1) Vector to clamp
     * @param(cubeRadius) Radius of the cube
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& ClampToCubeV(TVector3<T, S> v1, T cubeRadius);

    /**
     * Rotates vector around axis
     *
     * @param(v1) Vector to mirror
     * @param(axisNormal) Axis to rotate around.
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S>& RotateAroundAxisV(TVector3<T, S>& v1, const TVector3<T, S>& axisNormal, T angle)
    {
        T sinAngle = sin(angle);
        T cosAngle = cos(angle);

        v1 = (1 - cosAngle) * DotP(axisNormal, v1) * axisNormal + cosAngle * v1 + sinAngle * CrossP(v1, axisNormal);
        return v1;
    }

    /**
     * Scales vector two specific magnitude.
     *
     * @param(v1) Vector
     *
     * @note It's faster to use operator* or operator*= for naturaly normalized vectors.
     */

    template<RealType T, bool S>
    TVector3<T, S>& ScaleToMagnitudeV(TVector3<T, S>& v1, T magnitude)
    {
        NormalizeV(v1);
        v1 *= magnitude;
        return v1;
    }

    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     */

    template<RealType T, bool S>
    TVector3<T, S>& SignVectorV(TVector3<T, S>& v1)
    {
        v1.x = (v1.x >= (T)0.0) ? (T)1.0 : (T)-1;
        v1.y = (v1.y >= (T)0.0) ? (T)1.0 : (T)-1;
        v1.z = (v1.z >= (T)0.0) ? (T)1.0 : (T)-1;

        return v1;
    }


    /**
     * Gets scalar triple product ((v1 x v2) * v3). (Volume of parallelepiped.)
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @return Vector triple product
     */

    template<RealType T, bool S>
    T ScalarTriple(const TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S>& v3)
    {
        return DotP(CrossP(v1, v2), v3);
    }

    /**
     * Gets the cosine of the angle between to vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Cosine of angle between vectors. 
     * @note Simply omits acos of angle.
     */

    template<RealType T, bool S>
    T CosineAngle(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return DotP(v1, v2) / ((Magnitude(v1) * Magnitude(v2)));
    }

    /**
     * Gets vector triple product ((v1 x v2) x v3).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @note result is stored in v1
     */

    template<RealType T, bool S>
    TVector3<T, S>& VectorTripleV(TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S>& v3)
    {
        CrossPV(CrossPV(v1, v2), v3);

        return v1;
    }

    /**
     * Tests whether two vectors are perpendicular.
     * 
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Allowed T inaccuracy
     * 
     * @return True if perpendicular, false if not.
     */

    template<RealType T, bool S>
    inline bool IsPerpendicular(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T threshold = P_FLT_INAC)
    {
        return (abs(DotP(v1, v2)) < threshold);
    }

    /**
     * Tests whether two vectors are parallel.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
     *
     * @return True if parallel, false if not.
     */

    template<RealType T, bool S>
    inline bool IsParallel(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (abs(DotP(v1, v2)) > threshold);
    }

    /**
     * Tests whether two vectors are coincident (Parallel and point in same direction).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
     *
     * @return True if coincident, false if not.
     */

    template<RealType T, bool S>
    inline bool IsCoincident(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (DotP(v1, v2) > threshold);
    }

    /**
     * Tests whether v1 vectors is v1 unit vector.
     *
     * @param(v1) Vector
     * @param(threshold) Allowed T inaccuracy
     *
     * @return True if unit vector, false if not.
     */

    template<RealType T, bool S>
    inline bool IsNormalized(const TVector3<T, S>& v1, T threshold = P_FLT_INAC)
    {
        return (SqrMagnitude(v1) - 1 < threshold);
    }

    /**
     * Tests if three vectors are coplanar
     *
     * @param(v1) Vector one 
     * @param(v2) Vector two
     * @param(v3) Vector three
     * @param(threshold) Allowed T inaccuracy
     *
     * @return True if coplanar, false if not.
     */

    template<RealType T, bool S>
    inline bool IsCoplanar(const TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S>& v3, T threshold = P_FLT_INAC)
    {
        return (ScalarTriple(v1, v2, v3) < threshold);
    }

    // ============ //
    // WITH RETURN: //
    // ============ //

    /**
     * Normalized vector
     * 
     * @param(v1) vector to normalize
     * 
     * @return Normalized vector
     */

    template<RealType T, bool S>
    TVector3<T, S> Normalize(const TVector3<T, S>& v1)
    {
        float vecNorm = Magnitude(v1);
        return (vecNorm < P_FLT_INAC) ? v1 : v1 / vecNorm;
    }

    /**
     * Normalizes vector
     *
     * @param(v1) Vector
     *
     * @note Does not test for zero vector
     */

    template<RealType T, bool S>
    TVector3<T, S> UnsafeNormalize(const TVector3<T, S>& v1)
    {
        return v1 / Magnitude(v1);
    }


    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     *
     * @return Vector with signs a components.
     */

    template<RealType T, bool S>
    TVector3<T, S> SignVector(const TVector3<T, S>& v1)
    {
        return TVector3<T, false>((v1.x >= (T)0) ? (T)1 : (T)-1,
            (v1.y >= (T)0) ? (T)1 : (T)-1,
            (v1.z >= (T)0) ? (T)1 : (T)-1);
    }

    /**
     * Reflects a vector on a surface
     *
     * @param(v1) Vector one
     * @param(normal) Normal of surface
     *
     * @return Reflected vector
     */

    template<RealType T, bool S>
    TVector3<T, S> Reflect(const TVector3<T, S>& v1, const TVector3<T, S>& normal)
    {
        return (2 * DotP(v1, normal) * normal) - v1;
    }


    /**
     * Performes perspective divide on vector.
     *
     * @param(v1) vector to perspective divide
     *
     * @return Perspective divided vector
     */

    template<RealType T, bool S>
    TVector3<T, S> PerspectiveDivide(const TVector3<T, S>& v1)
    {
        float _z = (T)1.0 / v1.z;
        return TVector3<T, false>(v1.x * _z, v1.y * _z, (T)0.0);
    }

    /**
     * Gets cross product between two vectors.
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Cross product of v1 and v2
     */

    template<RealType T, bool S>
    TVector3<T, S> CrossP(const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Linearly interpolates between two vectors.
     *
     * @param(start) Starting vector
     * @param(dest) Destination vector
     * @param(t) 0.0 to 1.0 interpolation value
     *
     * @return Cross product of v1 and v2
     */

    template<RealType T, bool S>
    TVector3<T, S> Lerp(const TVector3<T, S>& start, const TVector3<T, S>& dest, T t)
    {
        t = Clamp(t, (T)0.0, (T)1.0);
        return ((1 - t) * start) + (t * dest);
    }

    /**
     * Linearly interpolates between two vectors.
     *
     * @param(v1) Starting vector
     * @param(dest) Destination vector
     * @param(t) 0.0 to 1.0 interpolation value
     *
     * @return Cross product of v1 and v2
     * @note Does not clamp t between 0.0 and 1.0.
     */

    template<RealType T, bool S>
    TVector3<T, S> LerpUnclamped(const TVector3<T, S>& start, const TVector3<T, S>& dest, T t)
    {
        return (((T)1.0 - t) * start) + (t * dest);
    }

    /**
     * Creates a new Vector by the componentwise max of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise max
     */

    template<RealType T, bool S>
    TVector3<T, S> Max(const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Creates a new Vector by the componentwise min of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise min
     */

    template<RealType T, bool S>
    TVector3<T, S> Min(const TVector3<T, S>& v1, const TVector3<T, S>& v2);

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<RealType T, bool S>
    TVector3<T, S> Negate(const TVector3<T, S>& v1)
    {
        return (T)0.0 - v1;
    }

    /**
     * Clamps vector to a range of magnitudes.
     *
     * @param(v1) Vector to clamp
     * @param(min) Min magnitude
     * @param(max) Max magnitude
     *
     * @return Clamped vector
     */

    template<RealType T, bool S>
    TVector3<T, S> ClampToMagnitude(const TVector3<T, S>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        const TVector3<T, false> unitVec = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T, false);

        Clamp(magnitude, min, max);

        return unitVec * Clamp(magnitude, min, max);
    }

    /**
     * Clamps vector into cube.
     *
     * @param(v1) Vector to clamp
     * @param(cubeRadius) Radius of the cube
     *
     * @result Vector clamped in cube.
     */

    template<RealType T, bool S>
    TVector3<T, S> ClampToCube(const TVector3<T, S>& v1, T cubeRadius);

    /**
     * Scales vector two specific magnitude.
     *
     * @param(v1) Vector
     *
     * @note It's faster to use operator* or operator*= for naturaly normalized vectors.
     */

    template<RealType T, bool S>
    TVector3<T, S> ScaleToMagnitude(const TVector3<T, S>& v1, T magnitude)
    {
        return Normalize(v1) * magnitude;
    }

    /**
     * Clamps vector into cube.
     *
     * @param(v1) Vector
     *
     * @result Vector with inverted components.
     */

    template<RealType T, bool S>
    TVector3<T, S> CompInverse(const TVector3<T, S>& v1)
    {
        return (T)1.0 / v1;
    }

    /**
     * Rotates vector around axis
     *
     * @param(v1) Vector to mirror
     * @param(axisNormal) Axis to rotate around
     * 
     * @return Rotated vector
     * @note Calculates vector rotation with Rodrigues-Rotation 
     */

    template<RealType T, bool S>
    TVector3<T, S> RotateAroundAxis(const TVector3<T, S>& v1, const TVector3<T, S>& axisNormal, T angle)
    {
        T sinAngle = sin(angle);
        T cosAngle = cos(angle);

        return (1 - cosAngle) * DotP(v1, axisNormal) * axisNormal + cosAngle * v1 + sinAngle * CrossP(v1, axisNormal);
    }

    /**
     * Gets vector triple product ((v1 x v2) x v3).
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector three
     *
     * @return Vector triple product
     */

    template<RealType T, bool S>
    TVector3<T, S> VectorTriple(const TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S>& v3)
    {
        return CrossP(CrossP(v1, v2), v3);
    }
    
    /**
     * Projects vector v1 onto v2
     *
     * @param(v1) Vector to project
     * @param(v2) Vector to project on
     *
     * @return Projected vector
     */

    template<RealType T, bool S>
    TVector3<T, S> Project(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return (DotP(v1, v2) / DotP(v2, v2)) * v2;
    }

    /**
     * Rejects vector v1 from v2
     *
     * @param(v1) Vector to reject
     * @param(v2) Vector to reject from
     *
     * @return Rejected vector
     */

    template<RealType T, bool S>
    TVector3<T, S> Reject(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return v1 - (DotP(v1, v2) / DotP(v2, v2)) * v2;
    }

    /**
     * Interpolate vector v1 to desitnation v2 using v1 constant s. The magnitude of the vector stays the same throughout the interpolation.
     *
     * @param(v1) Starting vector
     * @param(v2) Destination vector
     * @param(t) 0.0 to 1.0 interpolation value
     *
     * @return Interpolated unit vector
     */

    template<RealType T, bool S>
    TVector3<T, S> Slerp(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T t) {};

    /**
     * Interpolate vector v1 to desitnation v2 using v1 constant s. The magnitude of the vector stays the same throughout the interpolation.
     *
     * @param(v1) Starting vector
     * @param(v2) Destination vector
     * @param(t) 0.0 to 1.0 interpolation value
     *
     * @return Interpolated unit vector.
     * @note Does not clamp s between 0.0 and 1.0.
     */

    template<RealType T, bool S>
    TVector3<T, S> SlerpUnclamped(const TVector3<T, S>& v1, const TVector3<T, S>& v2, T t) {};

} // phanes

#endif // !VECTOR3_H


#include "Core/public/Math/Vector3.inl"
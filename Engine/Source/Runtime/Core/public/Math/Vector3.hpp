#pragma once

// TODO: Slerp (using Quaternions)


#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/SIMD/Storage.h"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

#ifndef VECTOR3_H
#define VECTOR3_H

#define PZeroVector3(type)			TVector3<##type>(0,0,0)
#define PVectorForward3(type)		TVector3<##type>(1,0,0)
#define PVectorBackward3(type)		TVector3<##type>(-1,0,0)
#define PVectorEast3(type)			TVector3<##type>(0,1,0)
#define PVectorWest3(type)			TVector3<##type>(0,-1,0)
#define PVectorUp3(type)			TVector3<##type>(0,0,1)
#define PVectorDown3(type)			TVector3<##type>(0,0,-1)

namespace Phanes::Core::Math {


    // Basic 3D vector (x, y, z)

    template<RealType T>
    struct TVector3 {
    public:
        
        using Real = T;

        union 
        {
            struct
            {

                /** X component of vector
                 *
                 * @ref [FIELD]components
                 * @note x does not hold the component, but is v1 reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                Real x;

                /** Y component of vector
                 *
                 * @ref [FIELD]components
                 *
                 * @note y does not hold the component, but is v1 reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                Real y;

                /** Z component of vector
                 *
                 * @ref [FIELD]components
                 *
                 * @note Z does not hold the component, but is v1 reference two the second item in the components array. The varibale exists wholly for convenience.
                 */
                Real z;

            };

            /** Components array holding the data
             *
             * @ref [FIELD]x
             * @ref [FIELD]y
             * @ref [FIELD]z
             *
             * @note Components are split into x, y and z. Access and manipulation is possible by these variables.
             */

            Real comp[3];
        };

    public:
        
        /**
         * Default contructor without initialization 
         */

        TVector3() = default;


        /**
         * Copy contructor
         */

        TVector3(const TVector3<Real>& v)
        {
            memcpy(this->comp, comp, sizeof(T) * 3);
        }

        /**
         * Move contructor
         */

        TVector3(TVector3<Real>&& v)
        {
            this->comp = v.comp;
            v.comp = nullptr;
        }

        /**
         * Convert other type of vector
         */

        template<RealType FloatType>
        explicit TVector3(const TVector3<FloatType>& v) : x((T)v.x), y((T)v.y) {};

        /**
         * Construct vector from xy components.
         *
         * @param x X component
         * @param y Y component
         * @param z Z component
         */

        TVector3(const Real x, const Real y, const Real z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        /**
         * Contructor vector from two component array
         * 
         * @param comp Array of components
         */

        TVector3(const Real* comp)
        {
            memcpy(this->comp, comp, sizeof(T) * 3);
        }

        /**
         * Constructs a vector pointing from start to end.
         *
         * @param(start) Startingpoint
         * @param(end) Endpoint
         */

        TVector3(const TPoint3<T>& start, const TPoint3<T>& end)
        {
            this->x = end.x - start.x;
            this->y = end.y - start.y;
            this->z = end.z - start.z;
        };

    };


    // ====================== //
    //   TVector3 operators   //
    // ====================== //

    /**
     * Coponentwise addition of floating point to 3D vector
     * 
     * @param(v1) vector to add to
     * @param(s) floating point to add
     */

    template<RealType T>
    inline TVector3<T> operator+= (TVector3<T>& v1, T s)
    {
        v1.x += s;
        v1.y += s;
        v1.z += s;

        return v1;
    }
    
    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     */

    template<RealType T>
    inline TVector3<T> operator+= (TVector3<T>& v1, const TVector3<T>& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        v1.z += v2.z;

        return v1;
    }
                
    /**
     * Coponentwise substraction of floating point of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) floating point to substract
     */

    template<RealType T>
    inline TVector3<T> operator-= (TVector3<T>& v1, T s)
    {
        v1.x -= s;
        v1.y -= s;
        v1.z -= s;

        return v1;
    }

    /**
     * Coponentwise substraction of 3D vector to 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     */

    template<RealType T>
    inline TVector3<T> operator-= (TVector3<T>& v1, const TVector3<T>& v2)
    {
       v1.x -= v2.x;
       v1.y -= v2.y;
       v1.z -= v2.z;

       return v1;
    }

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(s) floating point
     */

    template<RealType T>
    inline TVector3<T> operator*= (TVector3<T>& v1, T s)
    {
         v1.x *= s;
         v1.y *= s;
         v1.z *= s;

         return v1;
    }

    /**
     * Coponentwise division of 3D vector with floating point
     *
     * @param(v1) vector divide
     * @param(s) floating point to divide with
     */

    template<RealType T>
    inline TVector3<T> operator/= (TVector3<T>& v1, T s)
    {
        s = (T)1.0 / s;
        v1.x *= s;
        v1.y *= s;
        v1.z *= s;

        return v1;
    }

    /**
     * Coponentwise multiplication of 3D Vectors with floating point
     *
     * @param(v1) vector one
     * @param(s) floating point
     * 
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator* (const TVector3<T>& v1, T s)
    {
        return TVector3<T>(v1.x * s, v1.y * s, v1.z * s);
    }

    /**
     * Coponentwise division of 3D Vectors with floating point
     *
     * @param(v1) vector one
     * @param(s) floating point
     *
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator/ (const TVector3<T>& v1, T s)
    {
        s = (T)1.0 / s;
        return TVector3<T>(v1.x * s, v1.y * s, v1.z * s);
    }

    /**
     * Coponentwise multiplication of 3D Vectors with floating point
     *
     * @param(s) floating point
     * @param(v2) vector
     *
     * @return Resultion vector
     */

    template<RealType T>
    FORCEINLINE TVector3<T> operator* (T s, const TVector3<T>& v1)
    {
        return v1 * s;
    }

    /**
     * Coponentwise multiplication of 3D Vectors with floating point
     *
     * @param(s) floating point
     * @param(v1) vector
     *
     * @return Resultion vector
     */

    template<RealType T>
    FORCEINLINE TVector3<T> operator/ (T s, const TVector3<T>& v1)
    {
        return v1 / s;
    }

    /**
     * Dot product between two 3D Vectors
     *
     * @param(v1) vector one
     * @param(v2) vector two
     * 
     * @return Dot product of Vectors
     */

    template<RealType T>
    inline T operator* (const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    /**
     * Coponentwise addition of floating point to 3D vector
     *
     * @param(v1) vector to add to
     * @param(s) floating point to add
     * 
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator+ (const TVector3<T>& v1, T s)
    {
        return TVector3<T>(v1.x + s, v1.y + s, v1.z + s);
    }

    /**
     * Coponentwise addition of 3D vector to 3D vector
     *
     * @param(v1) vector to add to
     * @param(v2) vector to add
     * 
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator+ (const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    /**
     * Coponentwise substraction of floating point of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(s) floating point to substract
     * 
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator- (const TVector3<T>& v1, T s)
    {
        return TVector3<T>(v1.x - s, v1.y - s, v1.z - s);
    }

    /**
     * Coponentwise substraction of floating point of 3D vector
     *
     * @param(v1) vector to substract from
     * @param(v2) vector to substract with
     *
     * @return Resulting vector
     */

    template<RealType T>
    TVector3<T> operator- (const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    }

    /**
     * Negates vector
     *
     * @param(v1) Vector to negate
     */

    template<RealType T>
    TVector3<T> operator- (const TVector3<T>& v1)
    {
        return TVector3<T>(-v1.x, -v1.y, -v1.z);
    }

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

    template<RealType T>
    inline bool operator== (const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return (abs(v1.x - v2.x) < P_FLT_INAC && abs(v1.y - v2.y) < P_FLT_INAC && abs(v1.z - v2.z) < P_FLT_INAC);
    }

    /**
     * Tests two 3D vectors for inequality.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @return True if inequal, false if not.
     */

    template<RealType T>
    inline bool operator!= (const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return (abs(v1.x - v2.x) > P_FLT_INAC || abs(v1.y - v2.y) > P_FLT_INAC || abs(v1.z - v2.z) > P_FLT_INAC);
    }


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

    template<RealType T>
    inline T Magnitude(const TVector3<T>& v1)
    {
        return sqrt(DotP(v1, v1));
    }

    /**
     * @see [FUNC]Magnitude
     */

    template<RealType T>
    FORCEINLINE T Length(const TVector3<T>& v1) { return Magnitude(v1); };

    /**
     * Gets square magnitude of vector
     *
     * @param(v1) Vector
     *
     * @return Square magnitude of vector
     */

    template<RealType T>
    inline T SqrMagnitude(const TVector3<T>& v1)
    {
        return DotP(v1, v1);
    }

    /**
     * @see SqrMagnitude
     */

    template<RealType T>
    FORCEINLINE T SqrLength(const TVector3<T>& v1)
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

    template<RealType T>
    TVector3<T> NormalizeV(TVector3<T>& v1)
    {
        float vecNorm = Magnitude(v1);
        v1 /= (vecNorm < P_FLT_INAC) ? 1 : vecNorm;

        return v1;
    }

    /**
     * Normalizes vector
     *
     * @param(v1) Vector
     *
     * @note Does not test for zero vector
     */

    template<RealType T>
    TVector3<T> UnsafeNormalizeV(TVector3<T>& v1)
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

    template<RealType T>
    TVector3<T> ReflectV(TVector3<T>& v1, const TVector3<T>& normal)
    {
        Set(v1, v1 - (2 * (v1 * normal) * normal));

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

    template<RealType T>
    T Angle(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return acos((v1 * v2) / (Magnitude(v1) * Magnitude(v2)));
    }

    /**
     * Dot product of two vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Dot product of vectors
     */

    template<RealType T>
    inline T DotP(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    /**
     * Orthogonalizes three vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * @param(v3) Vector two
     */

    template<RealType T>
    void Orthogonalize(TVector3<T>& v1, TVector3<T>& v2, TVector3<T>& v3)
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

    template<RealType T>
    void OrthoNormalize(TVector3<T>& v1, TVector3<T>& v2, TVector3<T>& v3)
    {
        Set(v2, Reject(v2, v1));
        Set(v3, Reject(Reject(v3, v1), v2));

        NormalizeV(v1);
        NormalizeV(v2);
        NormalizeV(v3);
    }

    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     * 
     * @return Vector with signs a components.
     */

    template<RealType T>
    TVector3<T> SignVector(const TVector3<T>& v1)
    {
        return TVector3<T>((v1.x >= 0) ? 1 : -1,
                           (v1.y >= 0) ? 1 : -1,
                           (v1.z >= 0) ? 1 : -1);
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

    template<RealType T>
    inline bool Equals(const TVector3<T>& v1, const TVector3<T>& v2, T threshold = P_FLT_INAC)
    {
        return (abs(v1.x - v2.x) < threshold && abs(v1.y - v2.y) < threshold && abs(v1.z - v2.z) < threshold);
    }

    /**
     * Performs perspective divide on vector.
     *
     * @param(v1) Vector
     */

    template<RealType T>
    TVector3<T> PerspectiveDivideV(TVector3<T>& v1)
    {
        float _z = (T)1.0 / v1.z;
        v1.x *= _z;
        v1.y *= _z;
        v1.z = (T)0.0;
        return v1;
    }

    /**
     * Calculates the cross product between two vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     * 
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> CrossPV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        float x = v1.x;
        float y = v1.y;
        float z = v1.z;

        v1.x = (y * v2.z) - (z * v2.y);
        v1.y = (z * v2.x) - (x * v2.z);
        v1.z = (x * v2.y) - (y * v2.x);

        return v1;
    }

    /**
     * Gets the componentwise max of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> MaxV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        v1.x = Max(v1.x, v2.x);
        v1.y = Max(v1.y, v2.y);
        v1.z = Max(v1.z, v2.z);

        return v1;
    }

    /**
     * Gets the componentwise min of both vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> MinV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        v1.x = Min(v1.x, v2.x);
        v1.y = Min(v1.y, v2.y);
        v1.z = Min(v1.z, v2.z);

        return v1;
    }

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> NegateV(TVector3<T>& v1)
    {
        v1.x = -v1.x;
        v1.y = -v1.y;
        v1.z = -v1.z;

        return v1;
    }

    /**
     * Performes componentwise multiplication of two vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> ScaleV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        v1.x *= v2.x;
        v1.y *= v2.y;
        v1.z *= v2.z;

        return v1;
    }

    /**
     * Projects vector v1 onto v2
     *
     * @param(v1) Vector to project
     * @param(v2) Vector to project on
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> ProjectV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        float x = (v1 * v2) / (v2 * v2);
        v1 = x * v2;
    }

    /**
     * Rejects vector v1 from v2
     *
     * @param(v1) Vector to reject
     * @param(v2) Vector to reject from
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> RejectV(TVector3<T>& v1, const TVector3<T>& v2)
    {
        float x = (v1 * v2) / (v2 * v2);
        v1 -= x * v2;

        return v1;
    }

    /**
     * Copies v1 vector
     *
     * @param(v1) Vector to copy to
     * @param(v2) Vector to copy
     */

    template<RealType T>
    TVector3<T> Set(TVector3<T>& v1, const TVector3<T>& v2)
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

    template<RealType T>
    TVector3<T> Set(TVector3<T>& v1, T x, T y, T z)
    {
        v1.x = x;
        v1.y = y;
        v1.z = z;

        return v1;
    }
    
    /**
     * Clamps vector to a range of magnitudes.
     * 
     * @param(v1) Vector to clamp
     * @param(min) Min magnitude
     * @param(max) Max magnitude
     * 
     * @note Result is stored in v1
     */

    template<RealType T>
    TVector3<T> ClampMagnitudeV(TVector3<T>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        v1 = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T);

        Clamp(magnitude, min, max);

        v1 *= magnitude;

        return v1;
    }

    /**
     * Inverts the components of vector.
     *
     * @param(v1) Vector
     *
     * @note Result is stored in v1
     */

    template<RealType T>
    TVector3<T> CompInverseV(TVector3<T>& v1)
    {
        v1.x = 1.0f / v1.x;
        v1.y = 1.0f / v1.y;
        v1.z = 1.0f / v1.z;

        return v1;
    }


    /**
     * Clamps vector into cube.
     *
     * @param(v1) Vector to clamp
     * @param(cubeRadius) Radius of the cube
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> ClampToCubeV(TVector3<T> v1, T cubeRadius)
    {
        v1.x = Clamp(v1.x, -cubeRadius, cubeRadius);
        v1.y = Clamp(v1.y, -cubeRadius, cubeRadius);
        v1.z = Clamp(v1.z, -cubeRadius, cubeRadius);

        return v1;
    };

    /**
     * Rotates vector around axis
     *
     * @param(v1) Vector to mirror
     * @param(axisNormal) Axis to rotate around.
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> RotateAroundAxisV(TVector3<T>& v1, const TVector3<T>& axisNormal, T angle)
    {
        T sinAngle = sin(angle);
        T cosAngle = cos(angle);

        v1 = ((T)1.0 - cosAngle) * DotP(axisNormal, v1) * axisNormal + cosAngle * v1 + sinAngle * CrossP(axisNormal, v1);

        return v1;
    }

    /**
     * Scales vector two specific magnitude.
     *
     * @param(v1) Vector
     *
     * @note It's faster to use operator* or operator*= for naturaly normalized vectors.
     */

    template<RealType T>
    TVector3<T> ScaleToMagnitudeV(TVector3<T>& v1, T magnitude)
    {
        NormalizeV(v1) *= magnitude;

        return v1;
    }

    /**
     * Returns signs of components in vector: -1 / +1 / 0.
     *
     * @param(v1) Vector one
     */

    template<RealType T>
    TVector3<T> SignVectorV(TVector3<T>& v1)
    {
        v1.x = (v1.x >= 0) ? 1 : -1;
        v1.y = (v1.y >= 0) ? 1 : -1;
        v1.z = (v1.z >= 0) ? 1 : -1;

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

    template<RealType T>
    T ScalarTriple(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
    {
        return CrossP(v1, v2) * v3;
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

    template<RealType T>
    T CosineAngle(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return (v1 * v2) / (Magnitude(v1) * Magnitude(v2));
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

    template<RealType T>
    TVector3<T> VectorTripleV(TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
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

    template<RealType T>
    inline bool IsPerpendicular(const TVector3<T>& v1, const TVector3<T>& v2, T threshold = P_FLT_INAC)
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

    template<RealType T>
    inline bool IsParallel(const TVector3<T>& v1, const TVector3<T>& v2, T threshold = 1.0f - P_FLT_INAC)
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

    template<RealType T>
    inline bool IsCoincident(const TVector3<T>& v1, const TVector3<T>& v2, T threshold = 1.0f - P_FLT_INAC)
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

    template<RealType T>
    inline bool IsNormalized(const TVector3<T>& v1, T threshold = P_FLT_INAC)
    {
        return (SqrMagnitude(v1) < threshold);
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

    template<RealType T>
    inline bool IsCoplanar(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3, T threshold = P_FLT_INAC)
    {
        return (ScalarTriple(v1, v2, v3) < threshold);
    }

    /**
     * Gets outer product of to vectors.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Resulting matrix
     */

     //
     //Matrix3<T> OuterProduct(const TVector3<T>& v1, const TVector3<T>& v2);

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

    template<RealType T>
    TVector3<T> Normalize(const TVector3<T>& v1)
    {
        float vecNorm = Magnitude(v1);
        return (vecNorm < P_FLT_INAC) ? PZeroVector3(T) : v1 / vecNorm;
    }

    /**
     * Normalizes vector
     *
     * @param(v1) Vector
     *
     * @note Does not test for zero vector
     */

    template<RealType T>
    TVector3<T> UnsafeNormalize(const TVector3<T>& v1)
    {
        return v1 / Magnitude(v1);
    }

    /**
     * Reflects a vector on a surface
     *
     * @param(v1) Vector one
     * @param(normal) Normal of surface
     *
     * @return Reflected vector
     */

    template<RealType T>
    TVector3<T> Reflect(const TVector3<T>& v1, const TVector3<T>& normal)
    {
        return v1 - (2 * (v1 * normal) * normal);
    }


    /**
     * Performes perspective divide on vector.
     *
     * @param(v1) vector to perspective divide
     *
     * @return Perspective divided vector
     */

    template<RealType T>
    TVector3<T> PerspectiveDivide(const TVector3<T>& v1)
    {
        float _z = (T)1.0 / v1.z;
        return TVector3<T>(v1.x * _z, v1.y * _z, (T)0.0);
    }

    /**
     * Gets cross product between two vectors.
     *
     * @param(v1) vector one
     * @param(v2) vector two
     *
     * @return Cross product of v1 and v2
     */

    template<RealType T>
    TVector3<T> CrossP(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>((v1.y * v2.z) - (v1.z * v2.y),
                           (v1.z * v2.x) - (v1.x * v2.z),
                           (v1.x * v2.y) - (v1.y * v2.x));
    }

    /**
     * Linearly interpolates between two vectors.
     *
     * @param(start) Starting vector
     * @param(dest) Destination vector
     * @param(t) 0.0 to 1.0 interpolation value
     *
     * @return Cross product of v1 and v2
     */

    template<RealType T>
    TVector3<T> Lerp(const TVector3<T>& start, const TVector3<T>& dest, T t)
    {
        t = Clamp(t, (T)0.0, (T), 1.0);
        return (1 - t) * start + t * dest;
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

    template<RealType T>
    TVector3<T> LerpUnclamped(const TVector3<T>& start, const TVector3<T>& dest, T t)
    {
        return (1 - t) * start + t * dest;
    }

    /**
     * Creates a new Vector by the componentwise max of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise max
     */

    template<RealType T>
    TVector3<T> Max(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>((v1.x > v2.x) ? v1.x : v2.x,
                           (v1.y > v2.y) ? v1.y : v2.y,
                           (v1.z > v2.z) ? v1.z : v2.z);
    }

    /**
     * Creates a new Vector by the componentwise min of both vectors
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector of componentwise min
     */

    template<RealType T>
    TVector3<T> Min(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>((v1.x < v2.x) ? v1.x : v2.x,
                           (v1.y < v2.y) ? v1.y : v2.y,
                           (v1.z < v2.z) ? v1.z : v2.z);
    }

    /**
     * Gets reversed vector.
     *
     * @param(v1) Vector one
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    TVector3<T> Negate(const TVector3<T>& v1)
    {
        return TVector3<T>(-v1.x, -v1.y, -v1.z);
    }

    /**
     * Multiplies vector componentwise.
     *
     * @param(v1) Vector one
     * @param(v2) Vector two
     *
     * @return Vector with componentwise products
     */

    template<RealType T>
    TVector3<T> Scale(const TVector3<T>& v1, const TVector3<T>& v2)
    {
        return TVector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
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

    template<RealType T>
    TVector3<T> ClampMagnitude(const TVector3<T>& v1, T min, T max)
    {
        T magnitude = Magnitude(v1);

        const TVector3<T> unitVec = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T);

        Clamp(magnitude, min, max);

        return unitVec * magnitude;
    }

    /**
     * Clamps vector into cube.
     *
     * @param(v1) Vector to clamp
     * @param(cubeRadius) Radius of the cube
     *
     * @result Vector clamped in cube.
     */

    template<RealType T>
    TVector3<T> ClampToCube(const TVector3<T>& v1, T cubeRadius) 
    {
        return TVector3<T>(
            Clamp(v1.x, -cubeRadius, cubeRadius),
            Clamp(v1.y, -cubeRadius, cubeRadius),
            Clamp(v1.z, -cubeRadius, cubeRadius),
        );
    };

    /**
     * Scales vector two specific magnitude.
     *
     * @param(v1) Vector
     *
     * @note It's faster to use operator* or operator*= for naturaly normalized vectors.
     */

    template<RealType T>
    TVector3<T> ScaleToMagnitude(const TVector3<T>& v1, T magnitude)
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

    template<RealType T>
    TVector3<T> CompInverse(const TVector3<T>& v1)
    {
        return TVector3<T>((T)1.0f / v1.x, (T)1.0f / v1.y, (T)1.0f / v1.z);
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

    template<RealType T>
    TVector3<T> RotateAroundAxis(const TVector3<T>& v1, const TVector3<T>& axisNormal, T angle)
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

    template<RealType T>
    TVector3<T> VectorTriple(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
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

    template<RealType T>
    TVector3<T> Project(const TVector3<T>& v1, const TVector3<T>& v2)
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

    template<RealType T>
    TVector3<T> Reject(const TVector3<T>& v1, const TVector3<T>& v2)
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

    template<RealType T>
    TVector3<T> Slerp(const TVector3<T>& v1, const TVector3<T>& v2, T t) {};

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

    template<RealType T>
    TVector3<T> SlerpUnclamped(const TVector3<T>& v1, const TVector3<T>& v2, T t) {};

} // phanes

#endif // !VECTOR3_H


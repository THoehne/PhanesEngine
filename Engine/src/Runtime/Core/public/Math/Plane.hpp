#pragma once

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector3.hpp"

namespace Phanes::Core::Math {

    // Plane in 3D space, defined as:  P: ax + by + cz = d;

    template<RealType T>
    struct TPlane
    {
    public:
        TVector3<T> normal;
        T d;

    public:

        /**
         * Default constructor.
         */

        TPlane() = default;

        /**
         * Copy constructor
         */

        TPlane(const TPlane<T>& plane) : normal(plane.normal), d(plane.d) {};

        /**
         * Move constructor 
         */

        TPlane(TPlane<T>&& plane) :
            normal(std::move(plane.normal)),
            d(std::move(plane.d))
        {}


        /**
         * Construct plane from normal and d 
         * 
         * @param(normal) Normal of plane
         * @param(d) Scalar component
         * 
         * @note Normal is NOT normalized, make sure to normalize [PARAM]normal, or use [FUNC]CreateFromVector. Otherwise unexpected results may occur using the plane.
         */
        
        TPlane(const TVector3<T>& normal, T d) :
            normal(normal),
            d(d)
        {}

        /**
         * Construct plane from normal and base point.
         * 
         * @param(normal) Normal of plane
         * @param(base) Base point
         */
       
        TPlane(const TVector3<T>& normal, const TVector3<T>& base) :
            normal(normal)
        {
            this->d = DotP(this->normal, base);
        }

        /**
         * Construct plane from coefficients
         * 
         * @param(x) X coefficient
         * @param(y) Y coefficient
         * @param(z) Z coefficient
         * @param(d) D coefficient
         */

        TPlane(T x, T y, T z, T d) :
            d(d)
        {
            this->normal = TVector3<T>(x, y, z);
        }

        /**
         * Construct plane from 3 points
         * 
         * @param(p1) Point one
         * @param(p2) Point two
         * @param(p3) Point three
         */

        TPlane(const TVector3<T>& p1, const TVector3<T>& p2, const TVector3<T>& p3)
        {
            this->normal = Normalize(CrossP(p1, p2));
            this->d = DotP(this->normal, p3);
        }
    };

    /**
     * Get dot product between two planes
     * 
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     */

    template<RealType T>
    FORCEINLINE T PlaneDotP(const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return DotP(pl1.normal, pl2.normal);
    }

    /**
     * Get angle between two planes
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     */

    template<RealType T>
    FORCEINLINE T PlaneAngle(const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return Angle(pl1.normal, pl2.normal);
    }

    /**
     * Get cosine of angle between two planes
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     */

    template<RealType T>
    FORCEINLINE T PlaneCosAngle(const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return CosineAngle(pl1.normal, pl2.normal);
    }

    /**
     * Flip plane.
     *
     * @param(pl1) Plane 
     */

    template<RealType T>
    TPlane<T> FlipV(const TPlane<T>& pl1)
    {
        pl1.normal = -pl1.normal;
        pl1.d      = -pl1.d;
    }


    /**
     * Get flipped plane.
     *
     * @param(pl1) Plane
     * 
     * @return Flipped plane
     */

    template<RealType T>
    TPlane<T> Flip(const TPlane<T>& pl1)
    {
        return TPlane<T>(-pl1.normal, -pl1.d);
    }

    /**
     * Transform plane with Transform
     * 
     * @param(pl) Plane
     * @param(tr) Transform
     */

    template<RealType T>
    FORCEINLINE TPlane<T> TransformV(TPlane<T>& pl, const TTransform<T>& tr)
    {
        // TODO: Do with operator*
    }


    /**
     * Transform plane with Transform
     *
     * @param(pl) Plane
     * @param(tr) Transform
     * 
     * @return Transformed plane.
     */

    template<RealType T>
    FORCEINLINE TPlane<T> Transform(const TPlane<T>& pl, const TTransform<T>& tr)
    {
        // TODO: Do with operator*
    }

    /**
     * Projects vector onto plane
     *
     * @param(v1) Vector to reject
     * @param(plane) Plane
     *
     * @note result is stored in v1.
     * @note Simply rejects v1 from normal
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ProjectOntoPlaneV(TVector3<T>& v1, const TPlane<T>& plane)
    {
        return RejectV(v1, plane.normal);
    }


    /**
     * Projects vector onto plane
     *
     * @param(v1) Vector to reject
     * @param(normal) Normal of the plane
     *
     * @note result is stored in v1.
     * @note Simply rejects v1 from normal
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ProjectOntoPlaneV(TVector3<T>& v1, const TVector3<T>& normal)
    {
        return RejectV(v1, normal);
    }

    /**
     * Reflect by plane
     *
     * @param(v1) Vector to mirror
     * @param(plane) Plane to mirror on
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ReflectFromPlaneV(TVector3<T>& v1, const TPlane<T>& plane)
    {
        return ReflectV(v1, plane.normal);
    }


    /**
     * Reflect from plane
     *
     * @param(v1) Vector to mirror
     * @param(plane) Plane to mirror on
     *
     * @return Reflected vector
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ReflectFromPlane(const TVector3<T>& v1, const TPlane<T>& plane)
    {
        return Reflect(v1, plane.normal);
    }

    /**
     * Reflect from plane
     *
     * @param(v1) Vector to mirror
     * @param(plane) Normal of plane
     *
     * @return Reflected vector
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ReflectFromPlane(const TVector3<T>& v1, const TVector3<T>& normal)
    {
        return Reflect(v1, normal);
    }

    /**
     * Projects vector onto plane
     *
     * @param(v1) Vector to reject
     * @param(normal) Normal of the plane
     *
     * @return Projected vector
     * @note Simply rejects the vector from normal
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ProjectOntoPlane(const TVector3<T>& v1, const TVector3<T>& normal)
    {
        return Reject(v1, normal);
    }


    /**
     * Projects vector onto plane
     *
     * @param(v1) Vector to reject
     * @param(plane) Plane
     *
     * @return Projected vector
     * @note Simply rejects the vector from normal
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ProjectOntoPlane(const TVector3<T>& v1, const TPlane<T>& plane)
    {
        return Reject(v1, plane.normal);
    }

} // Phanes::Core::Math

  
#pragma once

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector3.hpp"

namespace Phanes::Core::Math
{

    // Ray with origin and direction (L = p + t * v)

    template<RealType T>
    struct TRay
    {
    public:
        using Real = T;

        TVector3<Real> origin;
        TVector3<Real> direction;

    public:
        /** Default constructor */
        TRay() = default;

        /** Copy constructor */
        TRay(const TRay<Real>& r) : direction(r.direction), origin(r.origin) {};

        /** Move constructor */
        TRay(TRay<Real>&& r) : direction(std::move(r.direction)), origin(std::move(r.origin)) {};

        /**
         * Construct ray from origin and direction.
         *
         * @param(direction) Direction
         * @param(origin) Origin
         */

        TRay(const TVector3<Real>& direction, const TVector3<Real>& origin) : direction(direction), origin(origin) {};

    };

    // ================== //
    //   TRay operators   //
    // ================== //


    /**
     * Tests two rays for equality
     * 
     * @param(r1) Ray one
     * @param(r2) Ray two
     * 
     * @return True, if same and false, if not.
     */

    template<RealType T>
    FORCEINLINE bool operator== (const TRay<T>& r1, const TRay<T>& r2)
    {
        return (r1.origin == r2.origin && r1.direction == r2.direction);
    }

    /**
     * Tests two rays for inequality
     *
     * @param(r1) Ray one
     * @param(r2) Ray two
     *
     * @return True, if not same and false, if same.
     */

    template<RealType T>
    FORCEINLINE bool operator== (const TRay<T>& r1, const TRay<T>& r2)
    {
        return (r1.origin != r2.origin || r1.direction != r2.direction);
    }

    // ================== //
    //   TRay functions   //
    // ================== //


    /**
     * Gets the point of the ray at a given parameter
     *
     * @param(r1) Ray
     * @param(t) Parameter
     *
     * @return Point at t
     */

    template<RealType T>
    TVector3<T> PointAt(const TRay<T>& r1, T t)
    {
        return r1.origin + r1.direction * t;
    }

    /** 
     * Gets parameter necessary to travel to query point on line.
     * 
     * @param(r1) Ray
     * @param(p1) Query point
     * 
     * @return parameter t
     */

    template<RealType T>
    TVector3<T> GetParameter(const TRay<T>& r1, const TVector3<T>& p1)
    {
        return DotP((p1 - r1.origin), r1.direction);
    }

    /**
     * Tests wether two ray point in the same direction (Not if origin).
     * 
     * @param(r1) Ray one
     * @param(r2) Ray two
     * 
     * @return True, if both rays point in the same direction, false if not.
     */

    template<RealType T>
    inline bool SameDirection(const TRay<T>& r1, const TRay<T>& r2)
    {
        return (r1.direction == r1.direction);
    }
}
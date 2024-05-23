#pragma once


// TODO: Transform

#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Line.hpp"
#include "Core/public/Math/Ray.hpp"
#include "Core/public/Math/Vector3.hpp"

namespace Phanes::Core::Math {

    // Plane in 3D space, defined as:  P: ax + by + cz = d;

    template<RealType T>
    struct TPlane
    {
    public:
        using Real = T;

        union
        {
            struct
            {
                /** X Part of the normal. */
                Real x;
                
                /** Y Part of the normal. */
                Real y;

                /** Z Part of the normal. */
                Real z;
            };

            TVector3<Real> normal;
        };

        /** Scalar component of plane. */
        union 
        {
            Real d;
            Real w;
        };
        
    public:

        /**
         * Default constructor.
         */

        TPlane() = default;

        /**
         * Copy constructor
         */

        TPlane(const TPlane<Real>& plane) : normal(plane.normal), d(plane.d) {};

        /**
         * Move constructor 
         */

        TPlane(TPlane<Real>&& plane) :
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
        
        TPlane(const TVector3<Real>& normal, Real d) :
            normal(normal),
            d(d)
        {}

        /**
         * Construct plane from normal and base point.
         * 
         * @param(normal) Normal of plane
         * @param(base) Base point
         */
       
        TPlane(const TVector3<Real>& normal, const TVector3<Real>& base) :
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

        TPlane(Real x, Real y, Real z, Real d) :
            d(d)
        {
            this->normal = TVector3<Real>(x, y, z);
        }

        /**
         * Construct plane from 3 points
         * 
         * @param(p1) Point one
         * @param(p2) Point two
         * @param(p3) Point three
         */

        TPlane(const TVector3<Real>& p1, const TVector3<Real>& p2, const TVector3<Real>& p3)
        {
            this->normal = Normalize(CrossP(p1, p2));
            this->d = DotP(this->normal, p3);
        }
    };


    // ======================== //
    //   Operators for TPlane   //
    // ======================== //


    /**
     * Adds pl2 to pl1.
     * 
     * @param(pl1) Plane to add to
     * @param(pl2) Plane to add
     *
     * @note This leads to the plane not being normalized anymore. Use PlaneNormalizeV to normalize again.
     * @see [FUNC] PlaneNormalizeV
     */

    template<RealType T>
    TPlane<T> operator+= (TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        pl1.normal += pl2.normal; pl1.d += pl2.d;

        return pl1;
    }

    /**
     * Substracts pl2 from pl1.
     *
     * @param(pl1) Plane to substract from
     * @param(pl2) Plane to substract
     *
     * @note This leads to the plane not being normalized anymore. Use PlaneNormalizeV to normalize again.
     * @see [FUNC] PlaneNormalizeV
     */

    template<RealType T>
    TPlane<T> operator-= (TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        pl1.normal -= pl2.normal; pl1.d -= pl2.d;

        return pl1;
    }

    /**
     * Multiplies pl1 with pl2.
     *
     * @param(pl1) Plane to multiply
     * @param(pl2) Plane to multiply with
     *
     * @note This leads to the plane not being normalized anymore. Use PlaneNormalizeV to normalize again.
     * @see [FUNC] PlaneNormalizeV
     */

    template<RealType T>
    TPlane<T> operator*= (TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        pl1.x *= pl2.x; pl1.y *= pl2.y; pl1.z *= pl2.z; pl1.d *= pl2.d;

        return pl1;
    }

    /**
     * Multiplies pl1 with a scalar
     *
     * @param(pl1) Plane to multiply
     * @param(s) Scalar to multiply with
     */

    template<RealType T>
    TPlane<T> operator*= (TPlane<T>& pl1, T s)
    {
        pl1.normal *= s; pl1 *= s;

        return pl1;
    }

    /**
     * Divides pl1 with a scalar
     *
     * @param(pl1) Plane to divide
     * @param(s) Scalar to divide with
     */

    template<RealType T>
    TPlane<T> operator/= (TPlane<T>& pl1, T s)
    {
        T _1_s = (T)1.0 / s;

        pl1.normal *= _1_s; pl1 *= _1_s;

        return pl1;
    }


    /**
     * Add two planes.
     *
     * @param(pl1) Plane
     * @param(pl2) Plane
     *
     * @return Sum of planes
     */

    template<RealType T>
    TPlane<T> operator+ (const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return TPlane<T>(pl1.normal + pl2.normal, pl1.d + pl2.d);
    }

    /**
     * Substracts two planes.
     *
     * @param(pl1) Plane
     * @param(pl2) Plane 
     *
     * @return Difference of the planes
     */

    template<RealType T>
    TPlane<T> operator- (const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return TPlane<T>(pl1.normal - pl2.normal, pl1.d - pl2.d);
    }

    /**
     * Multiplies two planes.
     *
     * @param(pl1) Plane 
     * @param(pl2) Plane
     *
     * @return Product of planes
     */

    template<RealType T>
    TPlane<T> operator* (const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return TPlane<T>(pl1.x * pl2.x, pl1.y * pl2.y, pl1.z * pl2.z, pl1.d * pl2.d);
    }

    /**
     * Multiplies pl1 with a scalar
     *
     * @param(pl1) Plane to multiply
     * @param(s) Scalar to multiply with
     * 
     * @return Product of plane and scalar
     */

    template<RealType T>
    TPlane<T> operator*= (const TPlane<T>& pl1, T s)
    {
        return TPlane<T>(pl1.normal * s, pl1.d * s);
    }

    /**
     * Divides pl1 with a scalar
     *
     * @param(pl1) Plane to divide
     * @param(s) Scalar to divide with
     * 
     * @return Quotient of plane and scalar
     */

    template<RealType T>
    TPlane<T> operator/= (const TPlane<T>& pl1, T s)
    {
        T _1_s = (T)1.0 / s;

        return TPlane<T>(pl1.normal * _1_s, pl1.d * _1_s);
    }

    /**
     * Tests two planes for equality
     * 
     * @see [FUNC] Equals
     * 
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * 
     * @return True, if planes are equal, false, if not.
     */

    template<RealType T>
    bool operator== (const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return pl1.normal == pl2.normal && abs(pl1.d - pl2.d) < P_FLT_INAC;
    }

    /**
     * Tests two planes for inequality
     *
     * @see [FUNC] Equals
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     *
     * @return True, if planes are inequal, false, if not.
     */

    template<RealType T>
    bool operator!= (const TPlane<T>& pl1, const TPlane<T>& pl2)
    {
        return pl1.normal != pl2.normal || abs(pl1.d - pl2.d) >= P_FLT_INAC;
    }


    // ======================= //
    //   Functions of TPlane   //
    // ======================= //




    /**
     * Tests whether two planes are perpendicular.
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(threshold) Allowed T inaccuracy
     *
     * @return True if perpendicular, false if not.
     */

    template<RealType T>
    inline bool IsPerpendicular(const TPlane<T>& pl1, const TPlane<T>& pl2, T threshold = P_FLT_INAC)
    {
        return (abs(DotP(pl1.normal, pl2.normal)) < threshold);
    }

    /**
     * Tests whether two planes are parallel.
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
     *
     * @return True if parallel, false if not.
     */

    template<RealType T>
    inline bool IsParallel(const TPlane<T>& pl1, const TPlane<T>& pl2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (abs(DotP(pl1.normal, pl2.normal)) > threshold);
    }

    /**
     * Tests whether two planes are coincident (Parallel and point in same direction).
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(threshold) Allowed T inaccuracy from one (e.g. 0.98f)
     *
     * @return True if coincident, false if not.
     */

    template<RealType T>
    inline bool IsCoincident(const TPlane<T>& pl1, const TPlane<T>& pl2, T threshold = 1.0f - P_FLT_INAC)
    {
        return (DotP(pl1.normal, pl2.normal) > threshold);
    }

    /**
     * Tests whether pl1 plane is a unit vector.
     *
     * @param(pl1) Plane
     * @param(threshold) Allowed T inaccuracy
     *
     * @return True if unit vector, false if not.
     */

    template<RealType T>
    inline bool IsNormalized(const TPlane<T>& pl1, T threshold = P_FLT_INAC)
    {
        return (SqrMagnitude(pl1.normal) < threshold);
    }

    /**
     * Tests whether two planes are the same
     * 
     * @see [FUNC]Equals
     * 
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(threshold) Allowed T inaccuracy
     * 
     * @return True if same, false if not.
     * @note Planes must be normalized.
     */

    template<RealType T>
    inline bool IsSame(const TPlane<T>& pl1, const TPlane<T>& pl2, T threshold = P_FLT_INAC)
    {

        return DotP(pl1.normal, pl2.normal) > threshold && abs(pl1.d - pl2.d) < P_FLT_INAC;
    }

    /** 
     * Normalizes plane.
     * 
     * @param(pl1) Plane
     */

    template<RealType T>
    TPlane<T> PlaneNormalizeV(TPlane<T>& pl1)
    {
        T normVec = SqrMagnitude(pl1);

        T scale = (normVec > P_FLT_INAC) ? (T)1.0 / sqrt(normVec) : 1.0f;

        pl1.normal *= scale; pl1.d *= scale;

        return pl1;
    }

    /**
     * Normalizes plane.
     *
     * @param(pl1) Plane
     * 
     * @return Normalized plane
     */

    template<RealType T>
    TPlane<T> PlaneNormalize(TPlane<T>& pl1)
    {
        T normVec = SqrMagnitude(pl1);

        T scale = (normVec > P_FLT_INAC) ? (T)1.0 / sqrt(normVec) : 1.0f;

        return TPlane<T>(pl1.normal * scale, pl1.d * scale);
    }

    /**
     * Normalizes plane.
     *
     * @param(pl1) Plane
     * 
     * @note Does not check for zero vector pl1.normal.
     */

    template<RealType T>
    TPlane<T> PlaneUnsafeNormalizeV(TPlane<T>& pl1)
    {
        T scale = (T)1.0 / Magnitude(pl1);

        pl1.normal *= scale; pl1.d *= scale;

        return pl1;
    }

    /**
     * Normalizes plane.
     *
     * @param(pl1) Plane
     *
     * @return Normalized plane
     * 
     * @note Does not check for zero vector pl1.normal.
     */

    template<RealType T>
    TPlane<T> PlaneUnsafeNormalize(TPlane<T>& pl1)
    {
        T scale = (T)1.0 / Magnitude(pl1);

        return TPlane<T>(pl1.normal * scale, pl1.d * scale);
    }

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
     * Calculates distance bewteen point and plane.
     * 
     * @param(pl1) Plane
     * @param(p1) Point
     * 
     * @return Distance from point to plane
     * @note Distance is 0 if point is on plane, >0 if it's in front and <0 if it's on the backside.
     */

    template<RealType T>
    T PointDistance(const TPlane<T>& pl1, const TVector3<T>& p1)
    {
        return (pl1.x * p1.x + pl1.y * p1.y + pl1.z * p1.z) - pl1.d;
    }

    /**
     * Gets the origin point (base) of the plane
     * 
     * @param(pl1) Plane
     * 
     * @return Base of plane
     */

    template<RealType T>
    TVector3<T> GetOrigin(const TPlane<T>& pl1)
    {
        return TVector3<T>(pl1.normal * d);
    }

    /**
     * Translates plane by vector
     *
     * @param(pl1) Plane
     * @param(v1) Vector
     */

    template<RealType T>
    TPlane<T> TranslateV(TPlane<T>& pl1, const TVector3<T>& v1)
    {
        
        pl1.d = DotP(this->normal, GetOrigin(pl1) + v1);

        return pl1;
    }

    /**
     * Translates plane by vector
     *
     * @param(pl1) Plane
     * @param(v1) Vector
     */

    template<RealType T>
    TPlane<T> Translate(TPlane<T>& pl1, const TVector3<T>& v1)
    {
        return TPlane<T>(pl1.normal, GetOrigin(pl1) + v1);
    }

    /**
     * Returns the side a point is on.
     * 
     * @param(pl1) Plane
     * @param(p1) Point
     * 
     * @return True, if it's in the front and false, if it's on the back.
     */

    template<RealType T>
    bool GetSide(const TPlane<T>& pl1, const TVector3<T>& p1)
    {
        return (pl1.d <= DotP(pl1.normal, p1));
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
     * Reflect from plane
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
     * @param(normal) Normal of plane
     *
     * @note result is stored in v1.
     */

    template<RealType T>
    FORCEINLINE TVector3<T> ReflectFromPlaneV(TVector3<T>& v1, const TVector3<T>& normal)
    {
        return ReflectV(v1, normal);
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
     * @see [FUNC]PointProjectOntoPlane
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
     * @see [FUNC]PointProjectOntoPlane
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

    /**
     * Tests planes for equality
     * 
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(threshold) Allowed inaccuracy
     * 
     * @return True, if equal, false if not.
     */

    template<RealType T>
    inline bool Equals(const TPlane<T>& pl1, const TPlane<T>& pl2, T threshold = P_FLT_INAC)
    {
        return Equals(pl1.normal, pl2.normal, threshold) && abs(pl1.d - pl2.d) < threshold;
    }


    /** Tests whether a point is on a plane
     * 
     * @param(pl1) Plane
     * @param(p1) Point
     * 
     * @return True, if p1 on pl1, false if not.
     */
    template<RealType T>
    FORCEINLINE bool IsPointOnPlane(const TPlane<T>& pl1, const TVector3<T>& p1)
    {
        return (Equals(DotP(pl1.normal, p1), d));
    }

    /**
     * Tests whether two planes intersect. Sets line to intersection-line if true.
     * 
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(interLine) Line of intersection
     * @param(threshold) Threshold for parallel planes.
     * 
     * @return True, if planes intersect, false, if not.
     */

    template<RealType T>
    bool PlanesIntersect2(const TPlane<T>& pl1, const TPlane<T>& pl2, Ref<TLine<T>> interLine, T threshold = P_FLT_INAC)
    {
        TVector3<T> dirLine = CrossP(pl1.normal, pl2.normal);
        T det = SqrMagnitude(dirLine);

        if (abs(det) > P_FLT_INAC)
        {
            interLine = MakeRef<TLine<T>(dirLine, (CrossP(dirLine, pl2.normal) * pl1.d + CrossP(dirLine, pl1.normal) * pl2.d) / det);
            NormalizeV(interLine);
            return true;
        }
        
        return false;
    }

    /**
     * Tests whether three planes intersect. Sets line to intersection-line if true.
     *
     * @param(pl1) Plane one
     * @param(pl2) Plane two
     * @param(pl3) Plane three
     * @param(interPoint) Point of intersection
     * @param(threshold) Threshold for parallel planes.
     *
     * @return True, if all planes intersect, false, if not.
     */

    template<RealType T>
    bool PlanesIntersect3(const TPlane<T>& pl1, const TPlane<T>& pl2, const TPlane<T>& pl3, Ref<TVector3<T>> interPoint, T threshold = P_FLT_INAC)
    {
        T det = DotP(CrossP(pl1.normal, pl2.normal), pl3.normal);

        if (abs(det) > P_FLT_INAC)
        {
            interPoint = MakeRef<TVector3<T>>((CrossP(pl3.normal, pl2.normal) * pl1.d + CrossP(pl1.normal, pl3.normal) * pl2.d) / det);
            return true;
        }

        return false;
    }

    /**
     * Mirrors a point through plane
     * 
     * @param(p1) Point to mirror
     * @param(pl1) Plane
     * 
     * @return Mirrored point.
     */

    template<RealType T>
    TVector3<T> PlaneMirrorPoint(const TVector3<T>& p1, const TPlane<T>& pl1)
    {
        return p1 - pl1.normal * ((T)2.0 * PointDistance(pl1, p1));
    }

    /**
     * Projects point onto plane
     * 
     * @param(p1) Point to project
     * @param(pl1) Plane
     * 
     * @return Projected point.
     */

    template<RealType T>
    TVector3<T> PointProjectOntoPlane(const TVector3<T>& p1, const TPlane<T>& pl1)
    {
        p1 - PointDistance(pl1, p1) * pl1.normal;
    }

    /**
     * Calculates the intersection point, of a line with a plane, if there is one
     *
     * @param(pl1) Plane
     * @param(l1) Line
     * @param(p1) Point
     * 
     * @return True, if they intersect, false if not.
     */

    template<RealType T>
    bool LineIntersect(const TPlane<T>& pl1, const TLine<T>& l1, Ref<TVector3<T>> p1)
    {
        T dotProduct = DotP(l1.normal, pl1.normal);

        if (abs(dotProduct) > P_FLT_INAC)
        {
            p1 = MakeRef<TVector3<T>>(l1.base - l1.normal * (DotP(l1.normal * p1.base) / dotProduct));
            return true;
        }

        return false;
    }

    /**
     * Calculates, the intersection point, of a plane and a ray.
     * 
     * @param(pl1) Plane
     * @param(r1) Ray
     * @param(p1) Intersection point
     * 
     * @return True, if they intersect, false if not.
     */

    template<RealType T>
    bool RayIntersect(const TPlane<T>& pl1, const TRay<T>& r1, Ref<TVector3<T>> p1)
    {
        T pr = DotP(pl1.normal, Normalize(r1.direction));
        T parameter = DotP((GetOrigin(pl1) - r1.origin), pl1.normal) / pr;

        if (p1 > P_FLT_INAC && parameter >= 0)
        {
            p1 = MakeRef<TVector3<T>>(PointAt(r1, parameter));
            return true;
        }

        return false;
    }

} // Phanes::Core::Math

  
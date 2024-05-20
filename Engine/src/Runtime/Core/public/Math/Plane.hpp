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
    };

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

  
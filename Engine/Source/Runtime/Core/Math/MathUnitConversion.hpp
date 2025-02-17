#pragma once

// ======================================= //
//   Contains functions to convert units   //
// ======================================= //

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"

namespace Phanes::Core::Math::UnitConversion 
{

    /**
      * Converts degrees to radians.
      *
      * @param(deg) Angle in degress (°)
      *
      * @return Angle in radians
      */

    template<RealType T>
    inline T DegToRad(T deg)
    {
        return deg * P_PI_180_FLT;
    }

    /**
      * Converts radians to degrees.
      *
      * @param(rad) Angle in radians (rad)
      *
      * @return Angle in degrees
      */

    template<RealType T>
    inline T RadToDeg(T rad)
    {
        return rad * P_180_PI_FLT;
    }

    /**
      * Converts degrees to gradian.
      *
      * @param(deg) Angle in degress (°)
      *
      * @return Angle in gradian
      */

    template<RealType T>
    inline T DegToGradian(T deg)
    {
        return deg * 1.111111f;
    }

    /**
      * Converts gradian to degrees.
      *
      * @param(rad) Angle in gradians (g)
      *
      * @return Angle in degrees
      */

    template<RealType T>
    inline T GradianToDeg(T g)
    {
        return g * 0.9f;
    }

    /**
      * Converts radians to gradians.
      *
      * @param(deg) Angle in radians (rad)
      *
      * @return Angle in gradians
      */

    template<RealType T>
    inline T RadToGradian(T rad)
    {
        return rad * 200 / P_PI_FLT;
    }

    /**
      * Converts gradian to radians.
      *
      * @param(rad) Angle in gradians (g)
      *
      * @return Angle in radians
      */

    template<RealType T>
    inline T GradianToRad(T g)
    {
        return g * P_PI_FLT / 200;
    }

} // phanes::core::math::typeconversion


namespace Phanes::Core::Math::UnitLiterals
{
    // ============================================== //
    //   unit conversion with user-defined literals   //
    // ============================================== //

    /**
     * Convert deg to rad.
     *
     * @param(_x) Angle in degress
     */

    double operator ""_deg(long double _x)
    {
        return _x * P_PI_180_FLT;
    }

    /**
     * Convert rad to rad.
     *
     * @param(_x) Angle in degress
     */

    double operator ""_rad(long double _x)
    {
        return _x;
    }

    /**
     * Convert gradian to rad.
     *
     * @param(_x) Angle in degress
     */

    double operator ""_g(long double _x)
    {
        return _x * P_PI_FLT / 200;
    }
}
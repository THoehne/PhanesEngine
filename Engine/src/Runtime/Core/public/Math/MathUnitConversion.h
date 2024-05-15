#pragma once

// ======================================= //
//   Contains functions to convert units   //
// ======================================= //

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.h"

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
  inline T DegToRad(T deg);

  /**
    * Converts radians to degrees.
    *
    * @param(rad) Angle in radians (rad)
    *
    * @return Angle in degrees
    */

  template<RealType T>
  inline T RadToDeg(T rad);

  /**
    * Converts degrees to gradian.
    *
    * @param(deg) Angle in degress (°)
    *
    * @return Angle in gradian
    */

  template<RealType T>
  inline T DegToGradian(T deg);

  /**
    * Converts gradian to degrees.
    *
    * @param(rad) Angle in gradians (g)
    *
    * @return Angle in degrees
    */

  template<RealType T>
  inline T GradianToDeg(T g);

  /**
    * Converts radians to gradians.
    *
    * @param(deg) Angle in radians (rad)
    *
    * @return Angle in gradians
    */

  template<RealType T>
  inline T RadToGradian(T rad);

  /**
    * Converts gradian to radians.
    *
    * @param(rad) Angle in gradians (g)
    *
    * @return Angle in radians
    */

  template<RealType T>
  inline T GradianToRad(T g);

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

  double operator ""_deg(long double _x);

  /**
   * Convert rad to rad.
   *
   * @param(_x) Angle in degress
   */

  double operator ""_rad(long double _x);

  /**
   * Convert gradian to rad.
   *
   * @param(_x) Angle in degress
   */

  double operator ""_g(long double _x);
}
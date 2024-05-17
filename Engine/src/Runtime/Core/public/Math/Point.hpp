#pragma once

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.hpp"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector2.hpp"
#include "Core/public/Math/Vector3.hpp"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

/**
 * The Point is the same as a vector. The type exists, to ensure
 * differentiation between the two types.
 */

#ifndef POINT_H
#define POINT_H

namespace Phanes::Core::Math {

  /**
   * A 2D Point with components x and y with float precision.
   */

  template<RealType T>
  struct TPoint2 : public TVector2<T> {
    static_assert(std::is_floating_point_v<T>, "T must be a floating point");

    using TVector2<T>::TVector2;

    using Real = T;

    /**
     * Creates Point2 from Point3's xy
     *
     * @param a Point3 one
     */

    TPoint2(const TPoint3<T>& p)
    {
      this->x = p.x;
      this->y = p.y;
    }

    /**
     * Creates Point2 from Point4's xy
     *
     * @param a Point4 one
     */

    TPoint2(const TPoint4<T>& p)
    {
      this->x = p.x;
      this->y = p.y;
    }
  };

  /**
   * Calculates distance between two points.
   * 
   * @param(p1) Point one
   * @param(p2) Point two
   * 
   * @return Distance between two points.
   */

  template<RealType T>
  T Distance(const TPoint2<T>& p1, const TPoint2<T>& p2)
  {
      return Magnitude(p2 - p1);
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /**
     * A 3D Point with components x and y with float precision.
     */


  template<RealType T>
  struct TPoint3 : public TVector3<T> {
    static_assert(std::is_floating_point_v(T), "T must be a floating point");

    using TVector3<T>::TVector3;

    using Real = T;

    /**
     * Creates Point3 from Point2's xy and zero
     *
     * @param a Point2 one
     */

    TPoint3(const TPoint2<T>& p)
    {
      this->x = p.x;
      this->y = p.y;
      this->z = 0;
    }

    /**
     * Creates Point3 from Point4's xyz
     *
     * @param a Point4 one
     */

    TPoint3(const TPoint4<T>& p)
    {
      this->x = p.x;
      this->y = p.y;
      this->z = p.z;
    }
  };

  /**
   * Calculates distance between two points.
   *
   * @param(p1) Point one
   * @param(p2) Point two
   *
   * @return Distance between two points.
   */

  template<RealType T>
  T Distance(const TPoint3<T>& p1, const TPoint3<T>& p2)
  {
      return Magnitude(p2 - p1);
  }

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /**
     * A 4D Point with components x and y with float precision.
     */


  //template<RealType T>
  //struct TPoint4 : public TVector4<T> {
  //	static_assert(std::is_floating_point_v(T), "T must be a floating point");

  //	using TVector4<T>::TVector4;

  //	/**
  //	 * Creates Point4 from Point2's xy and the last two zero
  //	 *
  //	 * @param a Point2 one
  //	 */

  //	TPoint4(const TPoint2<T>& p)
  //	{
  //		this->x = p.x;
  //		this->y = p.y;
  //		this->z = 0;
  //		this->w = 0;
  //	}

  //	/**
  //	 * Creates Point4 from Point3's xyz and zero
  //	 *
  //	 * @param a Point3 one
  //	 */

  //	TPoint4(const TPoint3<T>& p)
  //	{
  //		this->x = p.x;
  //		this->y = p.y;
  //		this->z = p.z;
  //		this->w = 0;
  //	}
  //};

  ///**
  // * Calculates distance between two points.
  // *
  // * @param(p1) Point one
  // * @param(p2) Point two
  // *
  // * @return Distance between two points.
  // */

  //template<RealType T>
  //T Distance(const TPoint4<T>& p1, const TPoint4<T>& p2);

} // phanes::core::math::coretypes

#endif // !POINT_H
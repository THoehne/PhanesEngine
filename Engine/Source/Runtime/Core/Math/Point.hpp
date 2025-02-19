#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathCommon.hpp"
#include "Core/Math/MathAbstractTypes.h"
#include "Core/Math/MathFwd.h"

#include "Core/Math/Vector2.hpp"
#include "Core/Math/Vector3.hpp"

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
  struct TPoint2 : public TVector2<T, false> {

    using TVector2<T, false>::TVector2;

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

    /// @brief Creates Point2 from Vector2
    /// @param v
    TPoint2(const TVector2<T, false>& v)
    {
      this->x = v.x;
      this->y = v.y;
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
  struct TPoint3 : public TVector3<T, false> {

    using TVector3<T, false>::TVector3;

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

    /// @brief Creates Point3 from Vector3
    /// @param v 
    TPoint3(const TVector3<T, false>& v)
    {
      this->x = v.x;
      this->y = v.y;
      this->z = v.z;
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


    template<RealType T>
    struct TPoint4 : public TVector4<T, false> {
    
    	using TVector4<T, false>::TVector4;
    
    	/**
    	 * Creates Point4 from Point2's xy and the last two zero
    	 *
    	 * @param a Point2 one
    	 */
    
    	TPoint4(const TPoint2<T>& p)
    	{
    		this->x = p.x;
    		this->y = p.y;
    		this->z = 0;
    		this->w = 0;
    	}
    
    	/**
    	 * Creates Point4 from Point3's xyz and zero
    	 *
    	 * @param a Point3 one
    	 */
    
    	TPoint4(const TPoint3<T>& p)
    	{
    		this->x = p.x;
    		this->y = p.y;
    		this->z = p.z;
    		this->w = 0;
    	}
      
      TPoint4(const TVector4<T, false>& v)
      {
          this->x = v.x;
          this->y = v.y;
          this->z = v.z;
          this->w = v.w;
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
    T Distance(const TPoint4<T>& p1, const TPoint4<T>& p2)
    {
        return Magnitude(p2 - p1);
    }

} // phanes::core::math::coretypes

#endif // !POINT_H
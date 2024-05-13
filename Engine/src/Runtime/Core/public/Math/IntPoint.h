#pragma once

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathCommon.h"
#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/IntVector2.h"
#include "Core/public/Math/IntVector3.h"
// #include "Core/public/Math/IntVector4.h"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

/** 
 * General annonation: The Point is the same as a vector. The type exists, to ensure a
 * easy differentiation between the two.
 */

#ifndef INTPOINT_H
#define INTPOINT_H

namespace Phanes::Core::Math {

  /**
   * A 2D Point with components x and y with integer precision.
   */

  template<IntType T>
  struct TIntPoint2 : public TIntVector2<T> {

    using TIntVector2<T>::TIntVector2;

    /** 
     * Creates IntPoint2 from IntPoint3's xy
     * 
     * @param a IntPoint3 one
     */

    TIntPoint2(const TIntPoint3<T>& a)
    {
      this->x = a.x;
      this->y = a.y;
    }

    /**
     * Creates IntPoint2 from IntPoint4's xy
     *
     * @param a IntPoint4 one
     */

    //TIntPoint2(const TIntPoint4<T>& a)
    //{
    //	this->x = a.x;
    //	this->y = a.y;

    //}
  };

  template<IntType T, RealType Rt>
  Rt Distance(const TIntPoint2<T>& p1, const TIntPoint2<T>& p2);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  /**
   * A 3D Point with components x and y with integer precision.
   */


  template<IntType T>
  struct TIntPoint3 : public TIntVector3<T> {

    using TIntVector3<T>::TIntVector3;

    /**
     * Creates IntPoint3 from IntPoint2's xy and zero
     *
     * @param a IntPoint2 one
     */

    TIntPoint3(const TIntPoint2<T>& a)
    {
      this->x = a.x;
      this->y = a.y;
      this->z = 0;
    }

    /**
     * Creates IntPoint3 from IntPoint4's xyz
     *
     * @param a IntPoint4 one
     */

    //TIntPoint3(const TIntPoint4<T>& a) 
    //{
    //	this->components[0] = a.components[0];
    //	this->components[1] = a.components[1];
    //	this->components[2] = a.components[2];
    //}
  };

  template<IntType T, RealType Rt>
  Rt Distance(const TIntPoint3<T>& p1, const TIntPoint3<T>& p2);


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  /**
   * A 4D Point with components x and y with integer precision.
   */

  
  //template<typename T>
  //struct TIntPoint4 : public TIntVector4<T> {
  //	static_assert(std::is_integral_v(T), "T must be an integer type.");

  //	using IntVector4<T>::IntVector4;

  //	/**
  //	 * Creates IntPoint4 from IntPoint2's xy and the last two zero
  //	 *
  //	 * @param a IntPoint2 one
  //	 */

  //	PHANES_CORE_API IntPoint4(const IntPoint2<T>& a)
  //	{
  //		this->components[0] = a.components[0];
  //		this->components[1] = a.components[1];
  //		this->components[2] = 0;
  //		this->components[3] = 0;
  //	}

  //	/**
  //	 * Creates IntPoint4 from IntPoint3's xyz and zero
  //	 *
  //	 * @param a IntPoint3 one
  //	 */

  //	PHANES_CORE_API IntPoint4(const IntPoint3<T>& a)
  //	{
  //		this->components[0] = a.components[0];
  //		this->components[1] = a.components[1];
  //		this->components[2] = a.components[2];
  //		this->components[3] = 0;
  //	}
  //};


} // phanes::core::math::coretypes

#endif // !INTPOINT_H

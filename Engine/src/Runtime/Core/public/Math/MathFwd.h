#pragma once

#include "Core/Core.h"

#include "Core/public/OSAL/PlatformTypes.h"

#ifndef MATH_FWD_H
#define MATH_FWD_H

#include "Core/public/Misc/Boilerplate.h"

/**
 * Includes forward declarations, as well as certain useful typedefs.
 * 
 * @ref OSAL/PlatformTypes.h
 */


namespace Phanes::Core::Math {

  /**
   * Template forward declarations.
   */

  template<RealType T>			struct TColor;
  template<RealType T>			struct TLinearColor;
    template<RealType T>			struct TVector2;
  template<RealType T>			struct TVector3;
  template<RealType T>			struct TVector4;
  template<RealType T>			struct TRay;
  template<RealType T>			struct TPlane;
  template<RealType T>			struct TMatrix2;
  template<RealType T>			struct TMatrix3;
  template<RealType T>			struct TMatrix4;
  template<RealType T>			struct TQuaternion;
  template<RealType T>			struct TTransform;
  template<RealType T>			struct TPoint2;
  template<RealType T>			struct TPoint3;
  template<RealType T>			struct TPoint4;
  template<IntType T>				struct TIntVector2;
  template<IntType T>				struct TIntVector3;
  template<IntType T>				struct TIntVector4;
  template<IntType T>				struct TIntPoint2;
  template<IntType T>				struct TIntPoint3;
  template<IntType T>				struct TIntPoint4;

  /**
   * Specific instantiation of forward declarations.
   */

  // TVector2 
  typedef TVector2<float>				Vector2;
  typedef TVector2<double>			Vector2d;

  typedef std::vector<Vector2>		Vector2List;
  typedef std::vector<Vector2d>		Vector2Listd;

  // TVector3
  typedef TVector3<float>				Vector3;
  typedef TVector3<double>			Vector3d;

  typedef std::vector<Vector3>		Vector3List;
  typedef std::vector<Vector3d>		Vector3Listd;



  // TIntVector2
  typedef TIntVector2<int>			IntVector2;
  typedef TIntVector2<long>			IntVector2l;

  typedef std::vector<IntVector2>		IntVector2List;
  typedef std::vector<IntVector2l>	IntVector2Listl;

  // TIntVector3
  typedef TIntVector3<int>			IntVector3;
  typedef TIntVector3<long>			IntVector3l;

  typedef std::vector<IntVector3>		IntVector3List;
  typedef std::vector<IntVector3l>	IntVector3Listl;



  // TMatrix2
  typedef TMatrix2<float>				Matrix2;
  typedef TMatrix2<double>			Matrix2d;

  typedef std::vector<Matrix2>		Matrix2List;
  typedef std::vector<Matrix2d>		Matrix2Listd;

} // Phanes::Core::Math::coretypes

namespace Phanes::Core::Math::Internal
{

  // Internal types

  template <typename T, unsigned int D> struct AVector;

  template <typename T, unsigned int n, unsigned int> struct AMatrix;
}


#endif // !MATH_FWD_H
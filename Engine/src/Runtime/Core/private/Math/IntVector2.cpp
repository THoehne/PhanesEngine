// ============================== //
//   TIntVector2 implementation   //
// ============================== //


#include "PhanesEnginePCH.h"

#include "Core/public/Math/IntVector2.h"

#include "Core/public/Math/IntPoint.h"

//#include "Math/Matrix2.h"
//#include "Math/Matrix2.h"
//#include "Math/Vector3.h"
//#include "Math/Vector4.h"
//#include "Math/IntVector2.h"
//#include "Math/IntVector3.h"
//#include "Math/IntVector4.h"


// ============================ //
//   TIntVector2 constructors   //
// ============================ //

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(const T x, const T y)
{
  this->x = x;
  this->y = y;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(const T* comp)
{
  static_assert(sizeof(comp) > 2 * sizeof(T), "PHANES_CORE (IntVector2.cpp): Setting 2D vector coordinates by an array, comp must have a size of at least 2 components.");
  memcpy(this->comp, comp, sizeof(T) * 2);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(const TIntPoint2<T>& start, const TIntPoint2<T>& end)
{
  this->x = end.x - start.x;
  this->y = end.y - start.y;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(const TIntVector3<T>& v)
{
  this->x = v.x;
  this->y = v.y;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(const TIntVector2<T>& v)
{
  memcpy(this->comp, comp, sizeof(T) * 2);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T>::TIntVector2(TIntVector2<T>&& v)
{
  this->comp = v.comp;
  v.comp = nullptr;
}


// ========================= //
//   TIntVector2 operators   //
// ========================= //

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator+=(TIntVector2<T>& v1, T s)
{
  v1.x += s;
  v1.y += s;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator+=(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1.x += v2.x;
  v1.y += v2.y;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator-=(TIntVector2<T>& v1, T s)
{
  v1.x -= s;
  v1.y -= s;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator-=(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1.x -= v2.x;
  v1.y -= v2.y;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator*=(TIntVector2<T>& v1, T s)
{
  v1.x *= s;
  v1.y *= s;

  return v1;
}
template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator*(const TIntVector2<T>& v1, T s)
{
  return TIntVector2<T>(v1.x * s, v1.y * s);
}

template<IntType T>
inline Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator*(T s, const TIntVector2<T>& v1)
{
  return v1 * s;
}

template<IntType T, IntType Rt>
Rt Phanes::Core::Math::operator* (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return v1.x * v2.x + v1.y * v2.y;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator+(const TIntVector2<T>& v1, T s)
{
  return TIntVector2<T>(v1.x + s, v1.y + s);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator+(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return TIntVector2<T>(v1.x + v2.x, v1.y + v2.y);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator-(const TIntVector2<T>& v1, T s)
{
  return TIntVector2<T>(v1.x - s, v1.y - s);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::operator-(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return TIntVector2<T>(v1.x - v2.x, v1.y - v2.y);
}

template<IntType T>
void Phanes::Core::Math::operator-(TIntVector2<T>& v1)
{
  v1.x = -v1.x;
  v1.y = -v1.y;
}

template<IntType T>
bool Phanes::Core::Math::operator== (const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (abs(v1.x - v1.x) < P_FLT_INAC && abs(v1.y - v1.y) < P_FLT_INAC);
}

template<IntType T>
bool Phanes::Core::Math::operator!=(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (abs(v1.x - v1.x) > P_FLT_INAC || abs(v1.y - v1.y) > P_FLT_INAC);
}

template<IntType T, IntType Rt>
Rt Phanes::Core::Math::Magnitude(const TIntVector2<T>& v1)
{
  return sqrtf(v1.x * v1.x + v1.y * v1.y);
}

template<IntType T>
T Phanes::Core::Math::SqrMagnitude(const TIntVector2<T>& v1)
{
  return v1.x * v1.x + v1.y * v1.y;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::DivideTruncV(TIntVector2<T>& v1, T s)
{
  Rt _s = (Rt)1.0 / s;

  v1.x = trunc(v1.x * s);
  v1.y = trunc(v1.y * s);

  return v1;
}

template<IntType T, RealType Rt>
Rt Phanes::Core::Math::Angle(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return acos((v1 * v2) / Magnitude(v1) * Magnitude(v2));
}


template<IntType T, RealType Rt>
Rt Phanes::Core::Math::CosineAngle(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (v1 * v2) / Magnitude(v1) * Magnitude(v2);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::SignVectorV(TIntVector2<T>& v1)
{
  v1.x = (v1.x > 0) ? 1 : -1;
  v1.y = (v1.y > 0) ? 1 : -1;

  return v1;
}

template<IntType T>
T Phanes::Core::Math::DotP(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return v1.x * v2.x + v1.y * v2.y;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::MaxV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1.x = Phanes::Core::Math::Max(v1.x, v2.x);
  v1.y = Phanes::Core::Math::Max(v1.y, v2.y);

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::MinV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1.x = Phanes::Core::Math::Min(v1.x, v2.x);
  v1.y = Phanes::Core::Math::Min(v1.y, v2.y);

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::GetPerpendicularV(TIntVector2<T>& v1)
{
  T x = v1.x;
  v1.x = v1.y;
  v1.y = -v1.x;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::GetReversePerpendicularV(TIntVector2<T>& v1)
{
  T x = v1.x;
  v1.x = -v1.y;
  v1.y = v1.x;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::ScaleV(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1.x *= v2.x;
  v1.y *= v2.y;

  return v1;
}


template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Set(TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  v1 = v2;

  return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Set(TIntVector2<T>& v1, T x, T y)
{
  v1.x = x;
  v1.y = y;

  return v1;
}


template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::NegateV(TIntVector2<T>& v1)
{
  v1.x = -v1.x;
  v1.y = -v1.y;
}

template<IntType T>
inline bool Phanes::Core::Math::IsNormalized(const TIntVector2<T>& v1)
{
  return (SqrMagnitude(v1));
}

template<IntType T>
inline bool Phanes::Core::Math::IsPerpendicular(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (abs(DotP(v1, v2)) = 0);
}

template<IntType T>
inline bool Phanes::Core::Math::IsParallel(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (abs(DotP(v1, v2)) = 1);
}

template<IntType T>
inline bool Phanes::Core::Math::IsCoincident(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return (DotP(v1, v2) > 1);
}

//
//Phanes::Core::Math::Matrix2 Phanes::Core::Math::OuterProduct(const TIntVector2& v1, const TIntVector2& v2)
//{
//	return Matrix2(
//					v1.x * v2.x, v1.x * v2.y,
//					v1.y * v2.x, v1.y * v2.y
//				);
//}

// ================================================================= //
//   TIntVector2 static function implementation with return values   // 
// ================================================================= //

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::Reflect(const TIntVector2<T>& v1, const TVector2<Rt>& normal)
{
  return TVector2<Rt>(v1 - (2 * (v1 * normal) * normal));
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Scale(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return TIntVector2<T>(v1.x * v2.x, v1.y * v2.y);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::CompInverse(const TIntVector2<T>& v1)
{
  return TVector2<T>(1.0f / v1.x, 1.0f / v1.y);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Negate(const TIntVector2<T>& v1)
{
  return TIntVector2<T>(-v1.x, -v1.y);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::GetPerpendicular(const TIntVector2<T>& v1)
{
  return TIntVector2<T>(v1.y, -v1.x);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::GetReversePerpendicular(const TIntVector2<T>& v1)
{
  return TIntVector2<T>(-v1.y, v1.x);
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Min(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return TIntVector2<T>(Phanes::Core::Math::Min(v1.x, v2.x), Phanes::Core::Math::Min(v1.y, v2.y));
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::Max(const TIntVector2<T>& v1, const TIntVector2<T>& v2)
{
  return TIntVector2<T>(Phanes::Core::Math::Max(v1.x, v2.x), Phanes::Core::Math::Max(v1.y, v2.y));
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::Normalize(const TIntVector2<T>& v1)
{
  float vecNorm = Magnitude(v1);
  return (vecNorm < P_FLT_INAC) ? PIntZeroVector2(T) : (v1 / vecNorm);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::UnsafeNormalize(const TIntVector2<T>& v1)
{
  return TVector2(v1 / Magnitude(v1));
}

template<IntType T>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::SignVector(const TIntVector2<T>& v1)
{
  return TIntVector2<T>((v1.x > 0) ? 1 : -1, (v1.y > 0) ? 1 : -1);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::BindToSquare(const TIntVector2<T>& v1, T radius)
{
  float k = (abs(v1.x) > abs(v1.y)) ? abs(radius / v1.x) : abs(radius / v1.y);
  return v1 * k;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::ClampToSquare(const TIntVector2<T>& v1, T radius)
{
  float prime = (abs(v1.x) > abs(v1.y)) ? v1.x : v1.y;
  float k = (prime > radius) ? abs(radius / prime) : 1.0f;

  return 	TVector2(v1 * k);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::Lerp(const TIntVector2<T>& startVec, const TIntVector2<T>& destVec, Rt t)
{
  t = Phanes::Core::Math::Clamp(t, (T)0.0, (T)1.0);

  return ((Rt)t * destVec) + (((Rt)1.0 - t) * startVec);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::LerpUnclamped(const TIntVector2<T>& startVec, const TIntVector2<T>& destVec, Rt t)
{
  return ((Rt)t * destVec) + (((Rt)1.0 - t) * startVec);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::Rotate(const TIntVector2<T>& v1, Rt angle)
{
  float sinAngle = sin(angle);
  float cosAngle = cos(angle);

  return TVector2<Rt>((Rt)v1.x * cosAngle - (Rt)v1.y * sinAngle, (Rt)v1.y * cosAngle + (Rt)v1.x * sinAngle);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::ClockwiseRotate(const TIntVector2<T>& v1, Rt angle)
{
  return Rotate(v1, -angle);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TIntVector2<T> Phanes::Core::Math::DivideTrunc(const TIntVector2<T>& v1, T s)
{
  Rt _s = (Rt)1.0 / s;
  return TIntVector2<T>(trunc(v1.x * _s), trunc(v1.y * _s));
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector2<Rt> Phanes::Core::Math::DivideFloat(const TIntVector2<T>& v1, T s)
{
  Rt _s = (Rt)1.0 / s;
  return TIntVector2<T>((Rt)v1.x * _s, (Rt)v1.y * _s);
}

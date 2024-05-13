// =========================== //
//   TVector2 implementation   //
// =========================== //


#include "PhanesEnginePCH.h"

#include "Core/public/Math/Vector2.h"

#include "Core/public/Math/Point.h"

//#include "Math/Matrix2.h"
//#include "Math/Matrix2.h"
//#include "Math/Vector3.h"
//#include "Math/Vector4.h"
//#include "Math/IntVector2.h"
//#include "Math/IntVector3.h"
//#include "Math/IntVector4.h"


// ========================= //
//   TVector2 constructors   //
// ========================= //

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(const Real x, const Real y)
{
	this->x = x;
	this->y = y;
}

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(const Real* comp)
{
	static_assert(sizeof(comp) > 2 * sizeof(T), "PHANES_CORE (Vector2.cpp): Setting 2D vector coordinates by an array, comp must have a size of at least 2 components.");
	memcpy(this->comp, comp, sizeof(T) * 2);
}

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(const TPoint2<Real>& start, const TPoint2<Real>& end)
{
	this->x = end.x - start.x;
	this->y = end.y - start.y;
}

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(const TVector3<Real>& v)
{
	this->x = v.x;
	this->y = v.y;
}

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(const TVector2<Real>& v)
{
	memcpy(this->comp, comp, sizeof(T) * 2);
}

template<RealType T>
Phanes::Core::Math::TVector2<T>::TVector2(TVector2<Real>&& v)
{
	this->comp = v.comp;
	v.comp = nullptr;
}


//
//Phanes::Core::Math::TVector2::TVector2(const Vector3& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}
//
//
//Phanes::Core::Math::TVector2::TVector2(const Vector4& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}
//
//
//Phanes::Core::Math::TVector2::TVector2(const IntVector2& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}
//
//
//Phanes::Core::Math::TVector2::TVector2(const IntVector3& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}
//
//
//Phanes::Core::Math::TVector2::TVector2(const IntVector4& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}
//
//
//Phanes::Core::Math::TVector2::TVector2(const Point2& v)
//{
//	std::copy(v.components, v.components + 2, this->components);
//}

// ====================== //
//   TVector2 operators   //
// ====================== //

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator+=(TVector2<T>& v1, T s)
{
	v1.x += s;
	v1.y += s;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator+=(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator-=(TVector2<T>& v1, T s)
{
	v1.x -= s;
	v1.y -= s;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator-=(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator*=(TVector2<T>& v1, T s)
{
	v1.x *= s;
	v1.y *= s;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator/=(TVector2<T>& v1, T s)
{
	s = 1.0f / s;
	v1.x *= s;
	v1.y *= s;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator*(const TVector2<T>& v1, T s)
{
	return TVector2<T>(v1.x * s, v1.y * s);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator/(const TVector2<T>& v1, T s)
{
	s = 1.0f / s;
	return TVector2<T>(v1.x * s, v1.y * s);
}

template<RealType T>
inline Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator*(T s, const TVector2<T>& v1)
{
	return v1 * s;
}

template<RealType T>
inline Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator/(T s, const TVector2<T>& v1)
{
	s = 1.0f / s;
	return v1 * s;
}

template<RealType T>
T Phanes::Core::Math::operator* (const TVector2<T>& v1, const TVector2<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator+(const TVector2<T>& v1, T s)
{
	return TVector2<T>(v1.x + s, v1.y + s);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator+(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return TVector2<T>(v1.x + v2.x, v1.y + v2.y);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator-(const TVector2<T>& v1, T s)
{
	return TVector2<T>(v1.x - s, v1.y - s);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::operator-(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return TVector2<T>(v1.x - v2.x, v1.y - v2.y);
}

template<RealType T>
void Phanes::Core::Math::operator-(TVector2<T>& v1)
{
	v1.x = -v1.x;
	v1.y = -v1.y;
}

template<RealType T>
bool Phanes::Core::Math::operator== (const TVector2<T>& v1, const TVector2<T>& v2)
{
	return (abs(v1.x - v1.x) < P_FLT_INAC && abs(v1.y - v1.y) < P_FLT_INAC);
}

template<RealType T>
bool Phanes::Core::Math::operator!=(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return (abs(v1.x - v1.x) > P_FLT_INAC || abs(v1.y - v1.y) > P_FLT_INAC);
}

template<RealType T>
T Phanes::Core::Math::Magnitude(const TVector2<T>& v1)
{
	return sqrtf(v1.x * v1.x + v1.y * v1.y);
}

template<RealType T>
T Phanes::Core::Math::SqrMagnitude(const TVector2<T>& v1)
{
	return v1.x * v1.x + v1.y * v1.y;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::NormalizeV(TVector2<T>& v1)
{
	float vecNorm = Magnitude(v1);
	v1 /= (vecNorm < P_FLT_INAC) ? 1 : vecNorm;
	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::UnsafeNormalizeV(TVector2<T>& v1)
{
	v1 /= Magnitude(v1);

	return v1;
}

template<RealType T>
T Phanes::Core::Math::Angle(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return acos((v1 * v2) / Magnitude(v1) * Magnitude(v2));
}


template<RealType T>
T Phanes::Core::Math::CosineAngle(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return (v1 * v2) / Magnitude(v1) * Magnitude(v2);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::SignVectorV(TVector2<T>& v1)
{
	v1.x = (v1.x > 0) ? 1 : -1;
	v1.y = (v1.y > 0) ? 1 : -1;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::BindToSquareV(TVector2<T>& v1, T radius)
{
	float k = (abs(v1.x) > abs(v1.y)) ? abs(radius / v1.x) : abs(radius / v1.y);
	v1 *= k;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ClampToSquareV(TVector2<T>& v1, T radius)
{
	float prime = (abs(v1.x) > abs(v1.y)) ? v1.x : v1.y;
	float k = (prime > radius) ? abs(radius / prime) : 1.0f;
	v1 *= k;

	return v1;
}

template<RealType T>
T Phanes::Core::Math::DotP(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y; 
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::MaxV(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1.x = Phanes::Core::Math::Max(v1.x, v2.x);
	v1.y = Phanes::Core::Math::Max(v1.y, v2.y);

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::MinV(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1.x = Phanes::Core::Math::Min(v1.x, v2.x);
	v1.y = Phanes::Core::Math::Min(v1.y, v2.y);

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::GetPerpendicularV(TVector2<T>& v1)
{
	T x = v1.x;
	v1.x = v1.y;
	v1.y = -v1.x;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::GetReversePerpendicularV(TVector2<T>& v1)
{
	T x = v1.x;
	v1.x = -v1.y;
	v1.y = v1.x;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ScaleV(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::CompInverseV(TVector2<T>& v1)
{
	v1.x = 1.0f / v1.x;
	v1.y = 1.0f / v1.y;
	
	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ReflectV(TVector2<T>& v1, const TVector2<T>& normal)
{
	Set(v1, v1 - (2 * (v1 * normal) * normal));

	return v1;
}
template<RealType T>

Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Set(TVector2<T>& v1, const TVector2<T>& v2)
{
	v1 = v2;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Set(TVector2<T>& v1, T x, T y)
{
	v1.x = x;
	v1.y = y;

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::RotateV(TVector2<T>& v1, T angle)
{
	float sinAngle = sin(angle);
	float cosAngle = cos(angle);

	Set(v1,
		v1.x * cosAngle - v1.y * sinAngle,
		v1.y * cosAngle + v1.x * sinAngle
		);

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ClockwiseRotateV(TVector2<T>& v1, T angle)
{
	RotateV(v1, -angle);

	return v1;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::NegateV(TVector2<T>& v1)
{
	v1.x = -v1.x;
	v1.y = -v1.y;
}

template<RealType T>
inline bool Phanes::Core::Math::IsNormalized(const TVector2<T>& v1, T threshold)
{
	return (SqrMagnitude(v1) < threshold);
}

template<RealType T>
inline bool Phanes::Core::Math::IsPerpendicular(const TVector2<T>& v1, const TVector2<T>& v2, T threshold)
{
	return (abs(DotP(v1, v2)) < threshold);
}

template<RealType T>
inline bool Phanes::Core::Math::IsParallel(const TVector2<T>& v1, const TVector2<T>& v2, T threshold)
{
	return (abs(DotP(v1,v2)) > threshold);
}

template<RealType T>
inline bool Phanes::Core::Math::IsCoincident(const TVector2<T>& v1, const TVector2<T>& v2, T threshold)
{
	return (DotP(v1, v2) > threshold);
}

//
//Phanes::Core::Math::Matrix2 Phanes::Core::Math::OuterProduct(const TVector2& v1, const TVector2& v2)
//{
//	return Matrix2(
//					v1.x * v2.x, v1.x * v2.y,
//					v1.y * v2.x, v1.y * v2.y
//				);
//}

// ============================================================== //
//   TVector2 static function implementation with return values   // 
// ============================================================== //

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Reflect(const TVector2<T>& v1, const TVector2<T>& normal)
{
	return TVector2<T>(v1 - (2 * (v1 * normal) * normal));
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Scale(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return TVector2<T>(v1.x * v2.x, v1.y * v2.y);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::CompInverse(const TVector2<T>& v1)
{
	return TVector2<T>(1.0f / v1.x, 1.0f / v1.y);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Negate(const TVector2<T>& v1)
{
	return TVector2<T>(-v1.x, -v1.y);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::GetPerpendicular(const TVector2<T>& v1)
{
	return TVector2<T>(v1.y, -v1.x);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::GetReversePerpendicular(const TVector2<T>& v1)
{
	return TVector2<T>(-v1.y, v1.x);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Min(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return TVector2<T>(Phanes::Core::Math::Min(v1.x, v2.x), Phanes::Core::Math::Min(v1.y, v2.y));
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Max(const TVector2<T>& v1, const TVector2<T>& v2)
{
	return TVector2<T>(Phanes::Core::Math::Max(v1.x, v2.x), Phanes::Core::Math::Max(v1.y, v2.y));
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Normalize(const TVector2<T>& v1)
{
	float vecNorm = Magnitude(v1);
	return (vecNorm < P_FLT_INAC) ? PZeroVector2(T) : (v1 / vecNorm);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::UnsafeNormalize(const TVector2<T>& v1)
{
	return (v1 / Magnitude(v1));
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::SignVector(const TVector2<T>& v1)
{
	return TVector2<T>((v1.x > 0) ? 1 : -1, (v1.y > 0) ? 1 : -1);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::BindToSquare(const TVector2<T>& v1, T radius)
{
	float k = (abs(v1.x) > abs(v1.y)) ? abs(radius / v1.x) : abs(radius / v1.y);
	return v1 * k;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ClampToSquare(const TVector2<T>& v1, T radius)
{
	float prime = (abs(v1.x) > abs(v1.y)) ? v1.x : v1.y;
	float k = (prime > radius) ? abs(radius / prime) : 1.0f;

	return 	v1 * k;
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Lerp(const TVector2<T>& startVec, const TVector2<T>& destVec, T t)
{
	t = Phanes::Core::Math::Clamp(t, (T)0.0, (T)1.0);
	
	return (t * destVec) + ((1 - t) * startVec);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::LerpUnclamped(const TVector2<T>& startVec, const TVector2<T>& destVec, T t)
{
	return (t * destVec) + ((1 - t) * startVec);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::Rotate(const TVector2<T>& v1, T angle)
{
	float sinAngle = sin(angle);
	float cosAngle = cos(angle);

	return TVector2<T>(v1.x * cosAngle - v1.y * sinAngle, 
					   v1.y * cosAngle + v1.x * sinAngle);
}

template<RealType T>
Phanes::Core::Math::TVector2<T> Phanes::Core::Math::ClockwiseRotate(const TVector2<T>& v1, T angle)
{
	return Rotate(v1, -angle);
}
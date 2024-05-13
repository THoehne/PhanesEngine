// ============================== //
//   TIntVector2 implementation   //
// ============================== //


#include "PhanesEnginePCH.h"

#include "Core/public/Math/IntVector3.h"

#include "Core/public/Math/IntPoint.h"
#include "Core/public/Math/Plane.h"


template<IntType T>
inline Phanes::Core::Math::TIntVector3<T>::TIntVector3(const T x, const T y, const T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T>::TIntVector3(const T* comp)
{
	static_assert(sizeof(comp) > 2 * sizeof(T), "PHANES_CORE (IntVector3.cpp): Setting 3D vector coordinates by an array, comp must have a size of at least 3 components.");
	memcpy(this->comp, comp, sizeof(T) * 3);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T>::TIntVector3(const TIntVector2<T>& v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = (T)0;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T>::TIntVector3(const TIntPoint3<T>& start, const TIntPoint3<T>& end)
{
	this->x = end.x - start.x;
	this->y = end.y - start.y;
	this->z = end.z - start.z;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T>::TIntVector3(const TIntVector3<T>& v)
{
	memcpy(this->comp, comp, sizeof(T) * 3);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T>::TIntVector3(TIntVector3<T>&& v)
{
	this->comp = v.comp;
	v.comp = nullptr;
}

// ========================= //
//   TIntVector3 operators	 //
// ========================= //

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator+=(TIntVector3<T>& v1, T s)
{
	v1.x += s;
	v1.y += s;
	v1.z += s;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator+=(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator-=(TIntVector3<T>& v1, T s)
{
	v1.x -= s;
	v1.y -= s;
	v1.z -= s;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator-=(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator*=(TIntVector3<T>& v1, T s)
{
	v1.x *= s;
	v1.y *= s;
	v1.z *= s;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator*(const TIntVector3<T>& v1, T s)
{
	return TIntVector3<T>(v1.x * s.v1.y * s, v1.z * s);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator*(T s, const TIntVector3<T>& v1)
{
	return v1 * s;
}

template<IntType T>
T Phanes::Core::Math::operator*(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator+(const TIntVector3<T>& v1, T s)
{
	return TIntVector3<T>(v1.x + s.v1.y + s, v1.z + s);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator+(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator-(const TIntVector3<T>& v1, T s)
{
	return TIntVector3<T>(v1.x - s.v1.y - s, v1.z - s);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator-(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::operator-(TIntVector3<T>& v1)
{
	v1.x = -v1.x;
	v1.y = -v1.y;
	v1.z = -v1.z;

	return v1;
}

template<IntType T>
bool Phanes::Core::Math::operator==(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return (abs(v1.x - v2.x) < P_FLT_INAC && abs(v1.y - v2.y) < P_FLT_INAC && abs(v1.z - v2.z) < P_FLT_INAC);
}

template<IntType T>
bool Phanes::Core::Math::operator!=(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return (abs(v1.x - v2.x) > P_FLT_INAC || abs(v1.y - v2.y) > P_FLT_INAC || abs(v1.z - v2.z) > P_FLT_INAC);
}

// ======================================= //
//   TIntVector3 function implementation   //
// ======================================= //



template<IntType T, RealType Rt>
Rt Phanes::Core::Math::Magnitude(const TIntVector3<T>& v1)
{
	return sqrt(DotP(v1, v1));
}

template<IntType T>
T Phanes::Core::Math::SqrMagnitude(const TIntVector3<T>& v1)
{
	return DotP(v1, v1);
}

template<IntType T, RealType Rt>
Rt Phanes::Core::Math::Angle(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return acos((v1 * v2) / (Magnitude(v1) * Magnitude(v2)));
}

template<IntType T>
T Phanes::Core::Math::DotP(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::VectorTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
{
	return CrossP(CrossP(v1, v2), v3);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::SignVector(const TIntVector3<T>& v1)
{
	v1.x = (v1.x > 0) - (v1.x < 0);
	v1.y = (v1.y > 0) - (v1.y < 0);
	v1.z = (v1.z > 0) - (v1.z < 0);


	return v1;
}

template<IntType T>
bool Phanes::Core::Math::Equals(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold)
{
	return (abs(v1.x - v2.x) < threshold && abs(v1.y - v2.y) < threshold && abs(v1.z - v2.z) < threshold);
}


template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::CrossPV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	float x = v1.x;
	float y = v1.y;
	float z = v1.z;

	v1.x = (y * v2.z) - (z * v2.y);
	v1.y = (z * v2.x) - (x * v2.z);
	v1.z = (x * v2.y) - (y * v2.x);

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::MaxV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1.x = Max(v1.x, v2.x);
	v1.y = Max(v1.y, v2.y);
	v1.z = Max(v1.z, v2.z);

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::MinV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1.x = Min(v1.x, v2.x);
	v1.y = Min(v1.y, v2.y);
	v1.z = Min(v1.z, v2.z);

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::NegateV(TIntVector3<T>& v1)
{
	v1.x = -v1.x;
	v1.y = -v1.y;
	v1.z = -v1.z;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::ScaleV(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1.x *= v2.x;
	v1.y *= v2.y;
	v1.z *= v2.z;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Set(TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	v1 = v2;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Set(TIntVector3<T>& v1, T x, T y, T z)
{
	v1.x = x;
	v1.y = y;
	v1.z = z;

	return v1;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::SignVectorV(TIntVector3<T>& v1)
{
	v1.x = (v1.x > 0) ? 1 : 0;
	v1.y = (v1.y > 0) ? 1 : 0;
	v1.z = (v1.z > 0) ? 1 : 0;

	return v1;
}

template<IntType T>
T Phanes::Core::Math::ScalarTriple(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
{
	return CrossP(v1, v2) * v3;
}

template<IntType T>
T Phanes::Core::Math::CosineAngle(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return (v1 * v2) / (Magnitude(v1) * Magnitude(v2));
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::VectorTripleV(TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3)
{
	CrossPV(CrossPV(v1, v2), v3);

	return v1;
}

template<IntType T>
bool Phanes::Core::Math::IsPerpendicular(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold)
{
	return (abs(DotP(v1, v2)) < threshold);
}

template<IntType T>
bool Phanes::Core::Math::IsParallel(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold)
{
	return (abs(DotP(v1, v2)) > threshold);
}

template<IntType T>
bool Phanes::Core::Math::IsCoincident(const TIntVector3<T>& v1, const TIntVector3<T>& v2, T threshold)
{
	return (DotP(v1, v2) > threshold);
}

template<IntType T>
bool Phanes::Core::Math::IsNormalized(const TIntVector3<T>& v1, T threshold)
{
	return (SqrMagnitude(v1) < threshold);
}

template<IntType T>
bool Phanes::Core::Math::IsCoplanar(const TIntVector3<T>& v1, const TIntVector3<T>& v2, const TIntVector3<T>& v3, T threshold)
{
	return (ScalarTriple(v1, v2, v3) < threshold);
}



// =============== //
//   With Return   //
// =============== //



template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::Normalize(const TIntVector3<T>& v1)
{
	float vecNorm = Magnitude(v1);
	return (vecNorm < P_FLT_INAC) ? PZeroVector3(T) : v1 / vecNorm;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::UnsafeNormalize(const TIntVector3<T>& v1)
{
	return v1 / Magnitude(v1);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::Reflect(const TIntVector3<T>& v1, const TVector3<Rt>& normal)
{
	return v1 - (2 * (v1 * normal) * normal);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::PerspectiveDivide(const TIntVector3<T>& v1)
{
	float _z = (T)1.0 / v1.z;
	return TIntVector3<T>(v1.x * _z, v1.y * _z, (T)0.0);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::CrossP(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>((v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x));
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::Lerp(const TIntVector3<T>& start, const TIntVector3<T>& dest, Rt t)
{
	t = Clamp(t, (Rt)0.0, (Rt), 1.0);
	return ((Rt)1.0 - t) * start + t * dest;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::LerpUnclamped(const TIntVector3<T>& start, const TIntVector3<T>& dest, Rt t)
{
	return (1 - t) * start + t * dest;
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Max(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>((v1.x > v2.x) ? v1.x : v2.x,
		(v1.y > v2.y) ? v1.y : v2.y,
		(v1.z > v2.z) ? v1.z : v2.z);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Min(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>((v1.x < v2.x) ? v1.x : v2.x,
		(v1.y < v2.y) ? v1.y : v2.y,
		(v1.z < v2.z) ? v1.z : v2.z);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Negate(const TIntVector3<T>& v1)
{
	return TIntVector3<T>(-v1.x, -v1.y, -v1.z);
}

template<IntType T>
Phanes::Core::Math::TIntVector3<T> Phanes::Core::Math::Scale(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return TIntVector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ClampMagnitude(const TIntVector3<T>& v1, T min, T max)
{
	Rt magnitude = Magnitude(v1);

	const TVector3<Rt> unitVec = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T);

	Clamp(magnitude, min, max);

	return unitVec * magnitude;
}



template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ScaleToMagnitude(const TIntVector3<T>& v1, T magnitude)
{
	NormalizeV(v1) *= magnitude;

	return v1;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::CompInverse(const TIntVector3<T>& v1)
{
	return TIntVector3<T>((Rt)1.0 / v1.x, (Rt)1.0 / v1.y, (Rt)1.0 / v1.z);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ReflectFromPlane(const TIntVector3<T>& v1, const TPlane<Rt>& plane)
{
	return Reflect(v1, plane.normal);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ReflectFromPlane(const TIntVector3<T>& v1, const TVector3<Rt>& normal)
{
	return Reflect(v1, normal);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::RotateAroundAxis(const TIntVector3<T>& v1, const TVector3<Rt>& axisNormal, Rt angle)
{
	T sinAngle = sin(angle);
	T cosAngle = cos(angle);

	return ((Rt)1 - cosAngle) * DotP(v1, axisNormal) * axisNormal + cosAngle * v1 + sinAngle * CrossP(v1, axisNormal);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::Project(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return (DotP(v1, v2) / DotP(v2, v2)) * v2;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::Reject(const TIntVector3<T>& v1, const TIntVector3<T>& v2)
{
	return v1 - (DotP(v1, v2) / DotP(v2, v2)) * v2;
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ProjectOntoPlane(const TIntVector3<T>& v1, const TVector3<Rt>& normal)
{
	return Reject(v1, normal);
}

template<IntType T, RealType Rt>
Phanes::Core::Math::TVector3<Rt> Phanes::Core::Math::ProjectOntoPlane(const TIntVector3<T>& v1, const TPlane<Rt>& plane)
{
	return Reject(v1, plane.normal);
}
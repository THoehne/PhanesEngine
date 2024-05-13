// =========================== //
//   TVector3 implementation   //
// =========================== //

#include "PhanesEnginePCH.h"

#include "Core/public/Math/Vector3.h"

#include "Core/public/Math/Point.h"
#include "Core/public/Math/Plane.h"

template<RealType T>
inline Phanes::Core::Math::TVector3<T>::TVector3(const Real x, const Real y, const Real z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

template<RealType T>
Phanes::Core::Math::TVector3<T>::TVector3(const Real* comp)
{
  static_assert(sizeof(comp) > 2 * sizeof(T), "PHANES_CORE (Vector3.cpp): Setting 3D vector coordinates by an array, comp must have a size of at least 3 components.");
  memcpy(this->comp, comp, sizeof(T) * 3);
}

template<RealType T>
Phanes::Core::Math::TVector3<T>::TVector3(const TPoint3<T>& start, const TPoint3<T>& end)
{
  this->x = end.x - start.x;
  this->y = end.y - start.y;
  this->z = end.z - start.z;
}

template<RealType T>
Phanes::Core::Math::TVector3<T>::TVector3(const TVector3<Real>& v)
{
  memcpy(this->comp, comp, sizeof(T) * 3);
}

template<RealType T>
Phanes::Core::Math::TVector3<T>::TVector3(TVector3<Real>&& v)
{
  this->comp = v.comp;
  v.comp = nullptr;
}




// ====================== //
//   TVector3 operators	  //
// ====================== //

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator+=(TVector3<T>& v1, T s)
{
  v1.x += s;
  v1.y += s;
  v1.z += s;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator+=(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1.x += v2.x;
  v1.y += v2.y;
  v1.z += v2.z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator-=(TVector3<T>& v1, T s)
{
  v1.x -= s;
  v1.y -= s;
  v1.z -= s;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator-=(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1.x -= v2.x;
  v1.y -= v2.y;
  v1.z -= v2.z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator*=(TVector3<T>& v1, T s)
{
  v1.x *= s;
  v1.y *= s;
  v1.z *= s;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator/=(TVector3<T>& v1, T s)
{
  s = (T)1.0 / s;
  v1.x *= s;
  v1.y *= s;
  v1.z *= s;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator*(const TVector3<T>& v1, T s)
{
  return TVector3<T>(v1.x * s. v1.y * s, v1.z * s);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator/(const TVector3<T>& v1, T s)
{
  s = (T)1.0 / s;
  return TVector3<T>(v1.x * s.v1.y * s, v1.z * s);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator*(T s, const TVector3<T>& v1)
{
  return v1 * s;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator/(T s, const TVector3<T>& v1)
{
  return v1 / s;
}

template<RealType T>
T Phanes::Core::Math::operator*(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator+(const TVector3<T>& v1, T s)
{
  return TVector3<T>(v1.x + s.v1.y + s, v1.z + s);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator+(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator-(const TVector3<T>& v1, T s)
{
  return TVector3<T>(v1.x - s.v1.y - s, v1.z - s);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator-(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::operator-(TVector3<T>& v1)
{
  v1.x = -v1.x;
  v1.y = -v1.y;
  v1.z = -v1.z;

  return v1;
}

template<RealType T>
bool Phanes::Core::Math::operator==(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return (abs(v1.x - v2.x) < P_FLT_INAC && abs(v1.y - v2.y) < P_FLT_INAC && abs(v1.z - v2.z) < P_FLT_INAC);
}

template<RealType T>
bool Phanes::Core::Math::operator!=(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return (abs(v1.x - v2.x) > P_FLT_INAC || abs(v1.y - v2.y) > P_FLT_INAC || abs(v1.z - v2.z) > P_FLT_INAC);
}

// ==================================== //
//    TVector3 function implementation	//
// ==================================== //

template<RealType T>
T Phanes::Core::Math::Magnitude(const TVector3<T>& v1)
{
  return sqrt(DotP(v1, v1));
}

template<RealType T>
T Phanes::Core::Math::SqrMagnitude(const TVector3<T>& v1)
{
  return DotP(v1, v1);
}

template<RealType T>
T Phanes::Core::Math::SqrLength(const TVector3<T>& v1)
{
  return SqrMagnitude(v1);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::NormalizeV(TVector3<T>& v1)
{
  float vecNorm = Magnitude(v1);
  v1 /= (vecNorm < P_FLT_INAC) ? 1 : vecNorm;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::UnsafeNormalizeV(TVector3<T>& v1)
{
  v1 /= Magnitude(v1);

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ReflectV(TVector3<T>& v1, const TVector3<T>& normal)
{
  Set(v1, v1 - (2 * (v1 * normal) * normal));

  return v1;
}

template<RealType T>
T Phanes::Core::Math::Angle(const TVector3<T>& v1, const TVector3<T>& v2) 
{
  return acos((v1 * v2) / (Magnitude(v1) * Magnitude(v2)));
}

template<RealType T>
T Phanes::Core::Math::DotP(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template<RealType T>
void Phanes::Core::Math::Orthogonalize(TVector3<T>& v1, TVector3<T>& v2, TVector3<T>& v3)
{
  Set(v2, Reject(v2, v1));
  Set(v3, Reject(Reject(v3, v1), v2));
}

template<RealType T>
void Phanes::Core::Math::OrthoNormalize(TVector3<T>& v1, TVector3<T>& v2, TVector3<T>& v3)
{
  Set(v2, Reject(v2, v1));
  Set(v3, Reject(Reject(v3, v1), v2));

  NormalizeV(v1);
  NormalizeV(v2);
  NormalizeV(v3);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ScaleToMagnitude(const TVector3<T>& v1, T magnitude)
{
  NormalizeV(v1) *= magnitude;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::CompInverse(const TVector3<T>& v1)
{
  return TVector3<T>((T)1.0f / v1.x, (T)1.0f / v1.y, (T)1.0f / v1.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ReflectFromPlane(const TVector3<T>& v1, const TPlane<T>& plane)
{
  return Reflect(v1, plane.normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ReflectFromPlane(const TVector3<T>& v1, const TVector3<T>& normal)
{
  return Reflect(v1, normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::RotateAroundAxis(const TVector3<T>& v1, const TVector3<T>& axisNormal, T angle)
{
  T sinAngle = sin(angle);
  T cosAngle = cos(angle);

  return (1 - cosAngle) * DotP(v1, axisNormal) * axisNormal + cosAngle * v1 + sinAngle * CrossP(v1, axisNormal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::VectorTriple(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
{
  return CrossP(CrossP(v1, v2), v3);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Project(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return (DotP(v1, v2) / DotP(v2, v2)) * v2;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Reject(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return v1 - (DotP(v1, v2) / DotP(v2, v2)) * v2;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ProjectOntoPlane(const TVector3<T>& v1, const TVector3<T>& normal)
{
  return Reject(v1, normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ProjectOntoPlane(const TVector3<T>& v1, const TPlane<T>& plane)
{
  return Reject(v1, plane.normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::SignVector(const TVector3<T>& v1)
{
  v1.x = (v1.x > 0) - (v1.x < 0);
  v1.y = (v1.y > 0) - (v1.y < 0);
  v1.z = (v1.z > 0) - (v1.z < 0);


  return v1;
}

template<RealType T>
bool Phanes::Core::Math::Equals(const TVector3<T>& v1, const TVector3<T>& v2, T threshold)
{
  return (abs(v1.x - v2.x) < threshold && abs(v1.y - v2.y) < threshold && abs(v1.z - v2.z) < threshold);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::PerspectiveDivideV(TVector3<T>& v1)
{
  float _z = (T)1.0 / v1.z;
  v1.x *= _z;
  v1.y *= _z;
  v1.z = (T)0.0;
  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::CrossPV(TVector3<T>& v1, const TVector3<T>& v2)
{
  float x = v1.x;
  float y = v1.y;
  float z = v1.z;

  v1.x = (y * v2.z) - (z * v2.y);
  v1.y = (z * v2.x) - (x * v2.z);
  v1.z = (x * v2.y) - (y * v2.x);

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::MaxV(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1.x = Max(v1.x, v2.x);
  v1.y = Max(v1.y, v2.y);
  v1.z = Max(v1.z, v2.z);

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::MinV(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1.x = Min(v1.x, v2.x);
  v1.y = Min(v1.y, v2.y);
  v1.z = Min(v1.z, v2.z);

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::NegateV(TVector3<T>& v1)
{
  v1.x = -v1.x;
  v1.y = -v1.y;
  v1.z = -v1.z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ScaleV(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1.x *= v2.x;
  v1.y *= v2.y;
  v1.z *= v2.z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ProjectV(TVector3<T>& v1, const TVector3<T>& v2)
{
  float x = (v1 * v2) / (v2 * v2);
  v1 = x * v2;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::RejectV(TVector3<T>& v1, const TVector3<T>& v2)
{
  float x = (v1 * v2) / (v2 * v2);
  v1 -= x * v2;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ProjectOntoPlaneV(TVector3<T>& v1, const TVector3<T>& normal)
{
  return RejectV(v1, normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ProjectOntoPlaneV(TVector3<T>& v1, const TPlane<T>& plane)
{
  return RejectV(v1, plane.normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Set(TVector3<T>& v1, const TVector3<T>& v2)
{
  v1 = v2;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Set(TVector3<T>& v1, T x, T y, T z)
{
  v1.x = x;
  v1.y = y;
  v1.z = z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ClampMagnitudeV(TVector3<T>& v1, T min, T max)
{
  T magnitude = Magnitude(v1);

  v1 = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T);

  Clamp(magnitude, min, max);

  v1 *= magnitude;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::CompInverseV(TVector3<T>& v1)
{
  v1.x = 1.0f / v1.x;
  v1.y = 1.0f / v1.y;
  v1.z = 1.0f / v1.z;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ReflectFromPlaneV(TVector3<T>& v1, const TPlane<T>& plane)
{
  return ReflectV(v1, plane.normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ReflectFromPlaneV(TVector3<T>& v1, const TVector3<T>& normal)
{
  return ReflectV(v1, normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::RotateAroundAxisV(TVector3<T>& v1, const TVector3<T>& axisNormal, T angle)
{
  T sinAngle = sin(angle);
  T cosAngle = cos(angle);

  v1 = ((T)1.0 - cosAngle) * DotP(axisNormal, v1) * axisNormal + cosAngle * v1 + sinAngle * CrossP(axisNormal, v1);

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ScaleToMagnitudeV(TVector3<T>& v1, T magnitude)
{
  NormalizeV(v1) *= magnitude;

  return v1;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::SignVectorV(TVector3<T>& v1)
{
  v1.x = (v1.x > 0) ? 1 : 0;
  v1.y = (v1.y > 0) ? 1 : 0;
  v1.z = (v1.z > 0) ? 1 : 0;

  return v1;
}

template<RealType T>
T Phanes::Core::Math::ScalarTriple(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
{
  return CrossP(v1, v2) * v3;
}

template<RealType T>
T Phanes::Core::Math::CosineAngle(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return (v1 * v2) / (Magnitude(v1) * Magnitude(v2));
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::VectorTripleV(TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3)
{
  CrossPV(CrossPV(v1, v2), v3);

  return v1;
}

template<RealType T>
bool Phanes::Core::Math::IsPerpendicular(const TVector3<T>& v1, const TVector3<T>& v2, T threshold)
{
  return (abs(DotP(v1, v2)) < threshold);
}

template<RealType T>
bool Phanes::Core::Math::IsParallel(const TVector3<T>& v1, const TVector3<T>& v2, T threshold)
{
  return (abs(DotP(v1, v2)) > threshold);
}

template<RealType T>
bool Phanes::Core::Math::IsCoincident(const TVector3<T>& v1, const TVector3<T>& v2, T threshold)
{
  return (DotP(v1, v2) > threshold);
}

template<RealType T>
bool Phanes::Core::Math::IsNormalized(const TVector3<T>& v1, T threshold)
{
  return (SqrMagnitude(v1) < threshold);
}

template<RealType T>
bool Phanes::Core::Math::IsCoplanar(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T>& v3, T threshold)
{
  return (ScalarTriple(v1, v2, v3) < threshold);
}


// ================ //
//   With return:   //
// ================ //


template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Normalize(const TVector3<T>& v1)
{
  float vecNorm = Magnitude(v1);
  return (vecNorm < P_FLT_INAC) ? PZeroVector3(T) : v1 / vecNorm;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::UnsafeNormalize(const TVector3<T>& v1)
{
  return v1 / Magnitude(v1);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Reflect(const TVector3<T>& v1, const TVector3<T>& normal)
{
  return v1 - (2 * (v1 * normal) * normal);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::PerspectiveDivide(const TVector3<T>& v1)
{
  float _z = (T)1.0 / v1.z;
  return TVector3<T>(v1.x * _z, v1.y * _z, (T)0.0);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::CrossP(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>((v1.y * v2.z) - (v1.z * v2.y), 
             (v1.z * v2.x) - (v1.x * v2.z), 
             (v1.x * v2.y) - (v1.y * v2.x));
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Lerp(const TVector3<T>& start, const TVector3<T>& dest, T t)
{
  t = Clamp(t, (T)0.0, (T), 1.0);
  return (1 - t) * start + t * dest;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::LerpUnclamped(const TVector3<T>& start, const TVector3<T>& dest, T t)
{
  return (1 - t) * start + t * dest;
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Max(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>((v1.x > v2.x) ? v1.x : v2.x,
             (v1.y > v2.y) ? v1.y : v2.y, 
             (v1.z > v2.z) ? v1.z : v2.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Min(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>((v1.x < v2.x) ? v1.x : v2.x,
             (v1.y < v2.y) ? v1.y : v2.y,
             (v1.z < v2.z) ? v1.z : v2.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Negate(const TVector3<T>& v1)
{
  return TVector3<T>(-v1.x, -v1.y, -v1.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::Scale(const TVector3<T>& v1, const TVector3<T>& v2)
{
  return TVector3<T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template<RealType T>
Phanes::Core::Math::TVector3<T> Phanes::Core::Math::ClampMagnitude(const TVector3<T>& v1, T min, T max)
{
  T magnitude = Magnitude(v1);

  const TVector3<T> unitVec = (magnitude > P_FLT_INAC) ? v1 / magnitude : PZeroVector3(T);

  Clamp(magnitude, min, max);

  return unitVec * magnitude;
}


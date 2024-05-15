// =========================== //
//   Matrix2D implementation   //
// =========================== //

#include "PhanesEnginePCH.h"

#include "Core/public/Math/Matrix2.h"
#include "Core/public/Math/Vector2.h"


template<RealType T>
inline Phanes::Core::Math::TMatrix2<T>::TMatrix2(const TMatrix2<T>& m1)
{
  memcpy(this->m, m1.m, sizeof(T) * 2);
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T>::TMatrix2(TMatrix2<T>&& m)
{
  this->comp = m.comp;
  m.comp = nullptr;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T>::TMatrix2(T fields[2][2])
{
  this->m[0][0] = fields[0][0]; this->m[1][0] = fields[0][1];
  this->m[1][0] = fields[1][0]; this->m[1][1] = fields[1][1];
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T>::TMatrix2(T n00, T n10, T n01, T n11)
{
  this->m[0][0] = n00; this->m[1][0] = n01;
  this->m[1][0] = n10; this->m[1][1] = n11;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T>::TMatrix2(const TVector2<T>& v1, const TVector2<T>& v2)
{
  this->m[0][0] = v1.x; this->m[1][0] = v1.y;
  this->m[0][1] = v2.x; this->m[1][1] = v2.y;
}

template<RealType T>
T& Phanes::Core::Math::TMatrix2<T>::operator()(int n, int m)
{
  return this->m[m][n];
}

// ================================= //
//   Class Methods for easy access   //
// ================================= //

template<RealType T>
Phanes::Core::Math::TVector2<T>& Phanes::Core::Math::TMatrix2<T>::operator[](int m)
{
  return reinterpret_cast<TVector2*>(this->m[m]);
}

template<RealType T>
const T& Phanes::Core::Math::TMatrix2<T>::operator()(int n, int m) const
{
  return this->m[m][n];
}

template<RealType T>
const Phanes::Core::Math::TVector2<T>& Phanes::Core::Math::TMatrix2<T>::operator[](int m) const
{
  return reinterpret_cast<const TVector2*>(this->m[m]);
}

// ===================== //
//   TMatrix2 operator   //
// ===================== //


template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator+=(TMatrix2<T>& m1, T s)
{
  m1->m[0][0] += s;
  m1->m[0][1] += s;
  m1->m[1][0] += s;
  m1->m[1][1] += s;

  return m1;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator+=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
{
  m1->m[0][0] += m2.m[0][0];
  m1->m[0][1] += m2.m[0][1];
  m1->m[1][0] += m2.m[1][0];
  m1->m[1][1] += m2.m[1][1];

  return m1;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator-=(TMatrix2<T>& m1, T s)
{
  m1->m[0][0] -= s;
  m1->m[0][1] -= s;
  m1->m[1][0] -= s;
  m1->m[1][1] -= s;

  return m1;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator-=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
{
  m1->m[0][0] -= m2.m[0][0];
  m1->m[0][1] -= m2.m[0][1];
  m1->m[1][0] -= m2.m[1][0];
  m1->m[1][1] -= m2.m[1][1];

  return m1;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator*=(TMatrix2<T>& m1, T s)
{
  m1->m[0][0] *= s;
  m1->m[0][1] *= s;
  m1->m[1][0] *= s;
  m1->m[1][1] *= s;

  return m1;
}

template<RealType T>
Phanes::Core::Math::TMatrix2<T> Phanes::Core::Math::operator*=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
{
  Matrix2 c = m1;

  m1(0, 0) = c(0, 0) * m2(0, 0) + c(0, 1) * m2(1, 0);
  m1(0, 1) = c(0, 0) * m2(0, 1) + c(0, 1) * m2(1, 1);

  m1(1, 0) = c(1, 0) * m2(0, 0) + c(1, 1) * m2(1, 0);
  m1(1, 1) = c(1, 0) * m2(0, 1) + c(1, 1) * m2(1, 1); 

  return m1;
}

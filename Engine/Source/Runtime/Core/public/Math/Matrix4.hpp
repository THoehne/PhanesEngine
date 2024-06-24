#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/Vector4.hpp"

#ifndef MATRIX4_H
#define MATRIX4_H

namespace Phanes::Core::Math {

	// 4x4 Matrix defined in column-major order.

	template<RealType T, bool S>
	struct TMatrix4
	{
	public:

		union
		{
			struct
			{
				TVector4<T, S> c0;
				TVector4<T, S> c1;
				TVector4<T, S> c2;
				TVector4<T, S> c3;
			};

			T data[4][4];
		};

	public:

		FORCEINLINE T& operator() (int n, int m)
		{
			return this->data[m][n];
		}
		FORCEINLINE TVector4<T, S>& operator[] (int m)
		{
			return (*reinterpret_cast<TVector4<T, S>*>(this->m[m]));
		}

		FORCEINLINE const T& operator() (int n, int m) const
		{
			return this->data[m][n];
		}
		FORCEINLINE const TVector4<T, S>& operator[] (int m) const
		{
			return (*reinterpret_cast<TVector4<T, S>*>(this->m[m]));
		}
	};

	// ==================== //
	//   Matrix4 operator   //
	// ==================== //

	template<RealType T, bool S>
	TMatrix4<T, S> operator+= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 += s;
		m1.c1 += s;
		m1.c2 += s;
		m1.c3 += s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator+= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 += m2.c0;
		m1.c1 += m2.c1;
		m1.c2 += m2.c2;
		m1.c3 += m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator-= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 -= s;
		m1.c1 -= s;
		m1.c2 -= s;
		m1.c3 -= s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator-= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 -= m2.c0;
		m1.c1 -= m2.c1;
		m1.c2 -= m2.c2;
		m1.c3 -= m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator*= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 *= s;
		m1.c1 *= s;
		m1.c2 *= s;
		m1.c3 *= s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator*= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 *= m2.c0;
		m1.c1 *= m2.c1;
		m1.c2 *= m2.c2;
		m1.c3 *= m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator/= (TMatrix4<T, S>& m1, T s)
	{
		s = (T)1.0 / s;
		m1.c0 *= s;
		m1.c1 *= s;
		m1.c2 *= s;
		m1.c3 *= s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator/= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 /= m2.c0;
		m1.c1 /= m2.c1;
		m1.c2 /= m2.c2;
		m1.c3 /= m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator+ (const TMatrix4<T, S>& m1, T s)
	{
		return TMatrix4<T, S>(m1.c0 + s,
							  m1.c1 + s,
							  m1.c2 + s,
							  m1.c3 + s
						      );
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator+ (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return TMatrix4<T, S>(m1.c0 + m2.c0,
							  m1.c1 + m2.c1,
							  m1.c2 + m2.c2,
							  m1.c3 + m2.c3
					);
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator- (const TMatrix4<T, S>& m1, T s)
	{
		return TMatrix4<T, S>(m1.c0 - s,
							  m1.c1 - s,
							  m1.c2 - s,
							  m1.c3 - s
			);
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator- (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return TMatrix4<T, S>(m1.c0 - m2.c0,
							  m1.c1 - m2.c1,
							  m1.c2 - m2.c2,
							  m1.c3 - m2.c3
		);
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator* (const TMatrix4<T, S>& m1, T s)
	{
		return TMatrix4<T, S>(m1.c0 * s,
						      m1.c1 * s,
						      m1.c2 * s,
						      m1.c3 * s
						      );
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator* (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return TMatrix4<T, S>(m1.c0 * m2.c0,
							  m1.c1 * m2.c1,
							  m1.c2 * m2.c2,
							  m1.c3 * m2.c3
		);
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator/ (const TMatrix4<T, S>& m1, T s)
	{
		s = (T)1.0 / s;
		return TMatrix4<T, S>(m1.c0 * s,
							  m1.c1 * s,
							  m1.c2 * s,
							  m1.c3 * s
		);
	}

	template<RealType T, bool S>
	TMatrix4<T, S> operator/ (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return TMatrix4<T, S>(m1.c0 / m2.c0,
						      m1.c1 / m2.c1,
						      m1.c2 / m2.c2,
						      m1.c3 / m2.c3
		);
	}

	template<RealType T, bool S>
	TVector4<T, S> operator* (const TMatrix4<T, S>& m1, const TVector4<T, S>& v)
	{
		return TVector4<T, S>(DotP(m1.c0, v),
						      DotP(m1.c1, v),
						      DotP(m1.c2, v),
						      DotP(m1.c3, v)
							  );
	}

	template<RealType T, bool S>
	bool operator== (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return (m1.c0 == m2.c0 && m1.c1 == m2.c1 && m1.c2 == m2.c2 && m1.c3 == m2.c3);
	}

	template<RealType T, bool S>
	bool operator!= (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		return (m1.c0 != m2.c0 || m1.c1 != m2.c1 || m1.c2 != m2.c2 || m1.c3 != m2.c3);
	}


	// ================================ //
	//   Matrix4 function definition    //
	// ================================ //

	template<RealType T, bool S>
	T Determinant(const TMatrix4<T, S>& m);

	template<RealType T, bool S>
	bool InverseV(TMatrix4<T, S>& a);

	template<RealType T, bool S>
	TMatrix4<T, S> TransposeV(TMatrix4<T, S>& a);


	// =============== //
	//   WITH RETURN   //
	// =============== //


	template<RealType T, bool S>
	bool Inverse(TMatrix4<T, S>& a);

	template<RealType T, bool S>
	TMatrix4<T, S> Transpose(const TMatrix4<T, S>& a);

	template<RealType T, bool S>
	FORCEINLINE bool IsIndentityMatrix(const TMatrix4<T, S>& m1)
	{
		return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC && abs(m1(0, 1) - (T)0.0) < P_FLT_INAC && abs(m1(0, 2) - (T)0.0) < P_FLT_INAC && abs(m1(0, 3) - (T)0.0) < P_FLT_INAC && 
				abs(m1(1, 0) - (T)0.0) < P_FLT_INAC && abs(m1(1, 1) - (T)1.0) < P_FLT_INAC && abs(m1(1, 2) - (T)0.0) < P_FLT_INAC && abs(m1(1, 3) - (T)0.0) < P_FLT_INAC && 
				abs(m1(2, 0) - (T)0.0) < P_FLT_INAC && abs(m1(2, 1) - (T)0.0) < P_FLT_INAC && abs(m1(2, 2) - (T)1.0) < P_FLT_INAC && abs(m1(2, 3) - (T)0.0) < P_FLT_INAC && 
				abs(m1(3, 0) - (T)0.0) < P_FLT_INAC && abs(m1(3, 1) - (T)0.0) < P_FLT_INAC && abs(m1(3, 2) - (T)1.0) < P_FLT_INAC && abs(m1(3, 3) - (T)0.0) < P_FLT_INAC);
	}


} // Phanes::Core::Math


#endif // !MATRIX4_H

#include "Core/public/Math/Matrix4.inl"
#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathAbstractTypes.h"
#include "Core/Math/MathFwd.h"
#include "Core/Math/Vector4.hpp"

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

		/// <summary>
		/// Default constructor.
		/// </summary>
		TMatrix4() = default;

		/// <summary>
		/// Move constructor
		/// </summary>
		/// <param name="v"></param>
		TMatrix4(TMatrix4<T, S>&& m)
			: c0(std::move(m.c0)), c1(std::move(m.c1)), c2(std::move(m.c2)), c3(std::move(m.c3))
		{};

		/// <summary>
		/// Copy constructor
		/// </summary>
		/// <param name="v"></param>
		TMatrix4(const TMatrix4<T, S>& m)
			: c0(m.c0), c1(m.c1), c2(m.c2), c3(m.c3)
		{};

		/// <summary>
		/// Construct matrix with values.
		/// </summary>
		TMatrix4(float n00, float n01, float n02, float n03,
				 float n10, float n11, float n12, float n13,
				 float n20, float n21, float n22, float n23,
				 float n30, float n31, float n32, float n33)
		{
			this->c0 = TVector4<T, S>(n00, n10, n20, n30);
			this->c1 = TVector4<T, S>(n01, n11, n21, n31);
			this->c2 = TVector4<T, S>(n02, n12, n22, n32);
			this->c3 = TVector4<T, S>(n03, n13, n23, n33);
		}

		/// <summary>
		/// Construct matrix from columns.
		/// </summary>
		TMatrix4(const TVector4<T, S>& v0, const TVector4<T, S>& v1, const TVector4<T, S>& v2, const TVector4<T, S>& v3)
		{
			this->c0 = v0;
			this->c1 = v1;
			this->c2 = v2;
			this->c3 = v3;
		}

		/// <summary>
		/// Construct matrix from field of values.
		/// </summary>
		/// <param name="field"></param>
		TMatrix4(T field[4][4])
		{
			this->c0 = TVector4(field[0]);
			this->c1 = TVector4(field[1]);
			this->c2 = TVector4(field[2]);
			this->c3 = TVector4(field[3]);
		}

		TMatrix4<T, S>& operator= (TMatrix4<T, S>&& m)
		{
			if (this != &m)
			{
				this->c0 = std::move(m.c0);
				this->c1 = std::move(m.c1);
				this->c2 = std::move(m.c2);
				this->c3 = std::move(m.c3);
			}
			return *this;
		}

		TMatrix4<T, S>& operator= (const TMatrix4<T, S>& m)
		{
			if (this != &m)
			{
				this->c0 = m.c0;
				this->c1 = m.c1;
				this->c2 = m.c2;
				this->c3 = m.c3;
			}
			return *this;
		}

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
			return (*reinterpret_cast<const TVector4<T, S>*>(this->data[m]));
		}
	};

	// ==================== //
	//   Matrix4 operator   //
	// ==================== //

	template<RealType T, bool S>
	TMatrix4<T, S>& operator+= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 += s;
		m1.c1 += s;
		m1.c2 += s;
		m1.c3 += s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S>& operator+= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 += m2.c0;
		m1.c1 += m2.c1;
		m1.c2 += m2.c2;
		m1.c3 += m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S>& operator-= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 -= s;
		m1.c1 -= s;
		m1.c2 -= s;
		m1.c3 -= s;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S>& operator-= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2)
	{
		m1.c0 -= m2.c0;
		m1.c1 -= m2.c1;
		m1.c2 -= m2.c2;
		m1.c3 -= m2.c3;

		return m1;
	}

	template<RealType T, bool S>
	TMatrix4<T, S>& operator*= (TMatrix4<T, S>& m1, T s)
	{
		m1.c0 *= s;
		m1.c1 *= s;
		m1.c2 *= s;
		m1.c3 *= s;

		return m1;
	}

	// Matrix multiplication
	template<RealType T, bool S>
	TMatrix4<T, S>& operator*= (TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2);

	template<RealType T, bool S>
	TMatrix4<T, S>& operator/= (TMatrix4<T, S>& m1, T s)
	{
		s = (T)1.0 / s;
		m1.c0 *= s;
		m1.c1 *= s;
		m1.c2 *= s;
		m1.c3 *= s;

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
	TMatrix4<T, S> operator* (const TMatrix4<T, S>& m1, const TMatrix4<T, S>& m2);

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
	TVector4<T, S> operator* (const TMatrix4<T, S>& m1, const TVector4<T, S>& v);

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
	TMatrix4<T, S>& TransposeV(TMatrix4<T, S>& a);


	// =============== //
	//   WITH RETURN   //
	// =============== //


	template<RealType T, bool S>
	bool Inverse(const TMatrix4<T, S>& m, Ref<TMatrix4<T, S>> r);

	template<RealType T, bool S>
	TMatrix4<T, S> Transpose(const TMatrix4<T, S>& a);

	template<RealType T, bool S>
	FORCEINLINE bool IsIdentityMatrix(const TMatrix4<T, S>& m1)
	{
		return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC && abs(m1(0, 1))          < P_FLT_INAC && abs(m1(0, 2))          < P_FLT_INAC && abs(m1(0, 3))          < P_FLT_INAC && 
				abs(m1(1, 0))          < P_FLT_INAC && abs(m1(1, 1) - (T)1.0) < P_FLT_INAC && abs(m1(1, 2))          < P_FLT_INAC && abs(m1(1, 3))          < P_FLT_INAC && 
				abs(m1(2, 0))          < P_FLT_INAC && abs(m1(2, 1))          < P_FLT_INAC && abs(m1(2, 2) - (T)1.0) < P_FLT_INAC && abs(m1(2, 3))          < P_FLT_INAC && 
				abs(m1(3, 0))          < P_FLT_INAC && abs(m1(3, 1))          < P_FLT_INAC && abs(m1(3, 2))          < P_FLT_INAC && abs(m1(3, 3) - (T)0.0) < P_FLT_INAC);
	}


} // Phanes::Core::Math


#endif // !MATRIX4_H

#include "Core/Math/Matrix4.inl"
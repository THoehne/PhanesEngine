#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathFwd.h"

#include "Core/Math/Vector2.hpp"

#ifndef MATRIX2_H
#	define MATRIX2_H

namespace Phanes::Core::Math
{

	// 2x2 Matrix defined in column-major order.
	// Accessed by M[Col][Row].

	template <RealType T>
	struct TMatrix2
	{
	public:
		union
		{
			struct
			{
				/// <summary>
				/// Column one.
				/// </summary>
				TVector2<T, false> c0;

				/// <summary>
				/// Column two
				/// </summary>
				TVector2<T, false> c1;
			};

			T data[2][2];
		};

	public:
		TMatrix2() = default;

		/**
         * Copy constructor.
         */

		TMatrix2(const TMatrix2<T>& m1)
		{
			this->c0 = m1.c0;
			this->c1 = m1.c1;
		}

		/**
         * Construct Matrix from 2d array.
         * 
         * @param(fields) 2D Array with column major order.
         */

		TMatrix2(T fields[2][2])
		{
			this->data[0][0] = fields[0][0];
			this->data[1][0] = fields[1][0];
			this->data[0][1] = fields[0][1];
			this->data[1][1] = fields[1][1];
		}

		/**
         * Construct Matrix from parameters.
         *
         * @param(n00) M[0][0]
         * @param(n10) M[1][0]
         * @param(n01) M[0][1]
         * @param(n11) M[1][1]
         * 
         * @note nXY = n[Row][Col]
         */

		TMatrix2(T n00, T n01, T n10, T n11)
		{
			this->data[0][0] = n00;
			this->data[1][0] = n01;
			this->data[0][1] = n10;
			this->data[1][1] = n11;
		}

		/**
         * Construct Matrix from two 2d vector columns.
         * 
         * @param(v1) Column zero
         * @param(v2) Column one
         */

		TMatrix2(const TVector2<T, false>& v1, const TVector2<T, false>& v2)
		{
			this->c0 = v1;
			this->c1 = v2;
		}

	public:
		T& operator()(int n, int m)
		{
			return this->data[m][n];
		}

		T operator()(int n, int m) const
		{
			return this->data[m][n];
		}

		TVector2<T, false>& operator[](int m)
		{
			switch(m)
			{
			case 0:
				return this->c0;
			case 1:
				return this->c1;
			}

			throw std::invalid_argument("m is outside valid range.");
		}

		TVector2<T, false> operator[](int m) const
		{
			switch(m)
			{
			case 0:
				return this->c0;
			case 1:
				return this->c1;
			}

			throw std::invalid_argument("m is outside valid range.");
		}
	};

	// ====================== //
	//    TMatrix2 operator   //
	// ====================== //

	template <RealType T>
	TMatrix2<T>& operator+=(TMatrix2<T>& m1, T s)
	{
		m1(0, 0) += s;
		m1(0, 1) += s;
		m1(1, 0) += s;
		m1(1, 1) += s;

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator+=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		m1(0, 0) += m2(0, 0);
		m1(0, 1) += m2(0, 1);
		m1(1, 0) += m2(1, 0);
		m1(1, 1) += m2(1, 1);

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator-=(TMatrix2<T>& m1, T s)
	{
		m1(0, 0) -= s;
		m1(0, 1) -= s;
		m1(1, 0) -= s;
		m1(1, 1) -= s;

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator-=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		m1(0, 0) -= m2(0, 0);
		m1(0, 1) -= m2(0, 1);
		m1(1, 0) -= m2(1, 0);
		m1(1, 1) -= m2(1, 1);

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator*=(TMatrix2<T>& m1, T s)
	{
		m1.data[0][0] *= s;
		m1.data[0][1] *= s;
		m1.data[1][0] *= s;
		m1.data[1][1] *= s;

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator*=(TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		TMatrix2<T> c = m1;

		m1(0, 0) = c(0, 0) * m2(0, 0) + c(0, 1) * m2(1, 0);
		m1(0, 1) = c(0, 0) * m2(0, 1) + c(0, 1) * m2(1, 1);

		m1(1, 0) = c(1, 0) * m2(0, 0) + c(1, 1) * m2(1, 0);
		m1(1, 1) = c(1, 0) * m2(0, 1) + c(1, 1) * m2(1, 1);

		return m1;
	}

	template <RealType T>
	TMatrix2<T>& operator/=(TMatrix2<T>& m1, T s)
	{
		s = (T)1.0 / s;
		m1.data[0][0] *= s;
		m1.data[0][1] *= s;
		m1.data[1][0] *= s;
		m1.data[1][1] *= s;

		return m1;
	}

	template <RealType T>
	TMatrix2<T> operator+(const TMatrix2<T>& m1, T s)
	{
		return TMatrix2<T>(m1(0, 0) + s, m1(0, 1) + s, m1(1, 0) + s, m1(1, 1) + s);
	}

	template <RealType T>
	TMatrix2<T> operator+(const TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		return TMatrix2<T>(
			m1(0, 0) + m2(0, 0), m1(0, 1) + m2(0, 1), m1(1, 0) + m2(1, 0), m1(1, 1) + m2(1, 1));
	}

	template <RealType T>
	TMatrix2<T> operator-(const TMatrix2<T>& m1, T s)
	{
		return TMatrix2<T>(m1(0, 0) - s, m1(0, 1) - s, m1(1, 0) - s, m1(1, 1) - s);
	}

	template <RealType T>
	TMatrix2<T> operator-(const TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		return TMatrix2<T>(
			m1(0, 0) - m2(0, 0), m1(0, 1) - m2(0, 1), m1(1, 0) - m2(1, 0), m1(1, 1) - m2(1, 1));
	}

	template <RealType T>
	TMatrix2<T> operator*(const TMatrix2<T>& m1, T s)
	{
		return TMatrix2<T>(m1(0, 0) * s, m1(0, 1) * s, m1(1, 0) * s, m1(1, 1) * s);
	}

	template <RealType T>
	TMatrix2<T> operator/(const TMatrix2<T>& m1, T s)
	{
		s = (T)1.0 / s;
		return TMatrix2<T>(m1(0, 0) * s, m1(0, 1) * s, m1(1, 0) * s, m1(1, 1) * s);
	}

	template <RealType T>
	TMatrix2<T> operator*(const TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		return TMatrix2<T>(m1(0, 0) * m2(0, 0) + m1(0, 1) * m2(1, 0),
						   m1(0, 0) * m2(0, 1) + m1(0, 1) * m2(1, 1),
						   m1(1, 0) * m2(0, 0) + m1(1, 1) * m2(1, 0),
						   m1(1, 0) * m2(0, 1) + m1(1, 1) * m2(1, 1));
	}

	template <RealType T>
	TVector2<T, false> operator*(const TMatrix2<T>& m1, const TVector2<T, false>& v)
	{
		return TVector2<T, false>(m1(0, 0) * v.x + m1(0, 1) * v.y, m1(1, 0) * v.x + m1(1, 1) * v.y);
	}

	template <RealType T>
	bool operator==(const TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		return m1[0] == m2[0] && m1[1] == m2[1];
	}

	template <RealType T>
	bool operator!=(const TMatrix2<T>& m1, const TMatrix2<T>& m2)
	{
		return m1[0] != m2[0] || m1[1] != m2[1];
	}

	// ============================== //
	//   Matrix function definition   //
	// ============================== //

	template <RealType T>
	T Determinant(const TMatrix2<T>& m1)
	{
		return m1(0, 0) * m1(1, 1) - m1(0, 1) * m1(1, 0);
	}

	template <RealType T>
	TMatrix2<T>& InverseV(TMatrix2<T>& m1)
	{
		float _1_det = 1.0f / Determinant(m1);
		float m00 = m1(0, 0);

		m1(0, 0) = m1(1, 1);
		m1(0, 1) = -m1(0, 1);
		m1(1, 0) = -m1(1, 0);
		m1(1, 1) = m00;

		m1 *= _1_det;
		return m1;
	}

	template <RealType T>
	TMatrix2<T>& TransposeV(TMatrix2<T>& m1)
	{
		Swap(m1(0, 1), m1(1, 0));

		return m1;
	}

	// =============== //
	//   WITH RETURN   //
	// =============== //

	template <RealType T>
	TMatrix2<T> Inverse(TMatrix2<T>& m1)
	{
		float _1_det = 1.0f / Determinant(m1);

		return TMatrix2<T>(
			m1(1, 1) * _1_det, -m1(0, 1) * _1_det, -m1(1, 0) * _1_det, m1(0, 0) * _1_det);
	}

	template <RealType T>
	TMatrix2<T> Transpose(const TMatrix2<T>& m1)
	{
		return TMatrix2<T>(m1(0, 0), m1(1, 0), m1(0, 1), m1(1, 1));
	}

	template <RealType T>
	bool IsIdentityMatrix(const TMatrix2<T>& m1, T threshold = P_FLT_INAC)
	{
		return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC && abs(m1(0, 1)) < P_FLT_INAC &&
				abs(m1(1, 0)) < P_FLT_INAC && abs(m1(1, 1) - (T)1.0) < P_FLT_INAC);
	}

} // namespace Phanes::Core::Math

#endif // !MATRIX2_H

#include "Core/Math/SIMD/SIMDIntrinsics.h"

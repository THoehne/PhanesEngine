#pragma once

#include "Core/Core.h"
#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/Vector2.h"

#ifndef MATRIX2_H
#define MATRIX2_H

namespace Phanes::Core::Math {
				
	// 2x2 Matrix defined in column-major order.
	// Accessed by M[Row][Col].

	template<RealType T>
	struct alignas(4) TMatrix2
	{
	public:

		alignas(4) T m[2][2];

	public:

		TMatrix2() = default;

		/**
		 * Copy constructor.
		 */

		TMatrix2(const TMatrix2<T>& m);

		/**
		 * Move constructor.
		 */

		TMatrix2(TMatrix2<T>&& m);

		/**
		 * Construct Matrix from 2d array.
		 * 
		 * @param(fields) 2D Array with column major order.
		 */

		TMatrix2(T fields[2][2]);

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

		TMatrix2(T n00, T n10, T n01, T n11);

		/**
		 * Construct Matrix from two 2d vector columns.
		 * 
		 * @param(v1) Column zero
		 * @param(v2) Column one
		 */

		TMatrix2(const TVector2<T>& v1, const TVector2<T>& v2);

	public:

		FORCEINLINE T& operator() (int n, int m);
		FORCEINLINE TVector2<T>& operator[] (int m);

		FORCEINLINE const T& operator() (int n, int m) const;
		FORCEINLINE const TVector2<T>& operator[] (int m) const;
	};

	// ==================== //
	//   Matrix2 operator   //
	// ==================== //
			
	template<RealType T>
	void operator+= (TMatrix2<T>& m1, T s);

	template<RealType T>
	void operator+= (TMatrix2<T>& m1, const TMatrix2<T>& m2);
				
	template<RealType T>
	void operator-= (TMatrix2<T>& m1, T s);
	
	template<RealType T>
	void operator-= (TMatrix2<T>& m1, const TMatrix2<T>& m2);
				
	template<RealType T>
	void operator*= (TMatrix2<T>& m1, T s);
	
	template<RealType T>
	void operator*= (TMatrix2<T>& m1, const TMatrix2<T>& m2);

	template<RealType T>
	TMatrix2<T> operator+ (const TMatrix2<T>& m1, T s);
	
	template<RealType T>
	TMatrix2<T> operator+ (const TMatrix2<T>& m1, const TMatrix2<T>& m2);

	template<RealType T>
	TMatrix2<T> operator- (const TMatrix2<T>& m1, T s);
	
	template<RealType T>
	TMatrix2<T> operator- (const TMatrix2<T>& m1, const TMatrix2<T>& m2);

	template<RealType T>
	TMatrix2<T> operator* (const TMatrix2<T>& m1, T s);
	
	template<RealType T>
	TMatrix2<T> operator* (const TMatrix2<T>& m1, const TMatrix2<T>& m2);
	
	template<RealType T>
	TVector2<T> operator* (const TMatrix2<T>& m1, const TVector2<T>& v);

	template<RealType T>
	bool operator== (const TMatrix2<T>& m1, const TMatrix2<T>& m2);


	// =============================== //
	//   Matrix function definition    //
	// =============================== //

	template<RealType T>
	T Determinant(const Matrix2& m1);

	template<RealType T>
	void InverseV(TMatrix2<T>& m1);

	template<RealType T>
	void TransposeV(TMatrix2<T>& m1);

	// =============== //
	//   WITH RETURN   //
	// =============== //

	template<RealType T>
	TMatrix2<T> Inverse(TMatrix2<T>& m1);

	template<RealType T>
	TMatrix2<T> Transpose(const TMatrix2<T>& m1);

	template<RealType T>
	bool IsIndentityMatrix(const TMatrix2<T>& m1, T threshold = P_FLT_INAC);

} // Phanes::Core::Math


#endif // !MATRIX2_H
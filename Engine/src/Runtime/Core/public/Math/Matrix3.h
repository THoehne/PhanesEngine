#pragma once

#include "Misc/BoilerplateHeader.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/MathAbstractTypes.h"
#include "Math/Vector3.h"

#ifndef MATRIX3_H
#define MATRIX3_H

namespace phanes {

	namespace core {

		namespace math {

			namespace coretypes {

				// 3x3 Matrix defined in column-major order.

				struct Matrix3 : public phanes::core::math::abstract::coretypes::AMatrix<float, 3, 3>
				{
				public:

					FORCEINLINE PHANES_CORE_API float& operator() (int n, int m);
					FORCEINLINE PHANES_CORE_API Vector3& operator[] (int m);

					FORCEINLINE PHANES_CORE_API const float& operator() (int n, int m) const;
					FORCEINLINE PHANES_CORE_API const Vector3& operator[] (int m) const;

				};

				// List of Matrices for  DoP and ECS
				typedef std::vector<Matrix3> Matrix3List;

				// Matrix3 constructor 
				PHANES_CORE_API Matrix3 createMatrix(float fields[3][3]);

				PHANES_CORE_API Matrix3 createMatrix(float f00, float f01, float f02,
												float f10, float f11, float f12,
												float f20, float f21, float f22);

				PHANES_CORE_API Matrix3 createMatrix(const Vector3& a, const Vector3& b, const Vector3& c);


				// ==================== //
				//   Matrix3 operator   //
				// ==================== //

				PHANES_CORE_API void operator+= (Matrix3& a, float s);
				PHANES_CORE_API void operator+= (Matrix3& a, const Matrix3& b);

				PHANES_CORE_API void operator-= (Matrix3& a, float s);
				PHANES_CORE_API void operator-= (Matrix3& a, const Matrix3& b);

				PHANES_CORE_API void operator*= (Matrix3& a, float s);
				PHANES_CORE_API void operator*= (Matrix3& a, const Matrix3& b);

				PHANES_CORE_API Matrix3 operator+ (const Matrix3& a, float s);
				PHANES_CORE_API Matrix3 operator+ (const Matrix3& a, const Matrix3& b);

				PHANES_CORE_API Matrix3 operator- (const Matrix3& a, float s);
				PHANES_CORE_API Matrix3 operator- (const Matrix3& a, const Matrix3& b);

				PHANES_CORE_API Matrix3 operator* (const Matrix3& a, float s);
				PHANES_CORE_API Matrix3 operator* (const Matrix3& a, const Matrix3& b);
				PHANES_CORE_API Vector3 operator* (const Matrix3& a, const Vector3& v);

				PHANES_CORE_API bool operator== (const Matrix3& a, const Matrix3& b);



				// =============================== //
				//   Matrix function definition    //
				// =============================== //

				PHANES_CORE_API float determinant(const Matrix3& a);


				PHANES_CORE_API void inverseNR(Matrix3& a);

				PHANES_CORE_API void transposeNR(Matrix3& a);


				// =============== //
				//   WITH RETURN   //
				// =============== //

				PHANES_CORE_API Matrix3 inverse(Matrix3& a);

				PHANES_CORE_API Matrix3 transpose(const Matrix3& a);

				PHANES_CORE_API bool isIndentityMatrix(const Matrix3& a);

			} // phanes::core::math::coretypes

		} // phanes::core::math

	} // phanes::core

} // phanes


#endif // !MATRIX3_H

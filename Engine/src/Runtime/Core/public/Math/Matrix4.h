#pragma once

#include "Misc/BoilerplateHeader.h"
#include PHANES_CORE_PCH_DEFAULT_PATH

#include "Math/MathAbstractTypes.h"
#include "Math/Vector4.h"

#ifndef MATRIX4_H
#define MATRIX4_H

namespace phanes {

	namespace core {

		namespace math {

			namespace coretypes {

				// 4x4 Matrix defined in column-major order.

				struct Matrix4 : public phanes::core::math::abstract::coretypes::AMatrix<float, 4, 4>
				{
				public:

					FORCEINLINE PHANES_CORE_API float& operator() (int n, int m);
					FORCEINLINE PHANES_CORE_API Vector4& operator[] (int m);

					FORCEINLINE PHANES_CORE_API const float& operator() (int n, int m) const;
					FORCEINLINE PHANES_CORE_API const Vector4& operator[] (int m) const;
				};

				// List of Matrices for  DoP and ECS
				typedef std::vector<Matrix4> Matrix4List;

				// Matrix4 constructor 
				PHANES_CORE_API Matrix4 createMatrix(float fields[4][4]);

				PHANES_CORE_API Matrix4 createMatrix(float f00, float f01, float f02, float f03,
												float f10, float f11, float f12, float f13,
												float f20, float f21, float f22, float f23,
												float f30, float f31, float f32, float f33
				);

				PHANES_CORE_API Matrix4 createMatrix(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d);

				// ==================== //
				//   Matrix4 operator   //
				// ==================== //

				PHANES_CORE_API void operator+= (Matrix4& a, float s);
				PHANES_CORE_API void operator+= (Matrix4& a, const Matrix4& b);

				PHANES_CORE_API void operator-= (Matrix4& a, float s);
				PHANES_CORE_API void operator-= (Matrix4& a, const Matrix4& b);

				PHANES_CORE_API void operator*= (Matrix4& a, float s);
				PHANES_CORE_API void operator*= (Matrix4& a, const Matrix4& b);

				PHANES_CORE_API Matrix4 operator+ (const Matrix4& a, float s);
				PHANES_CORE_API Matrix4 operator+ (const Matrix4& a, const Matrix4& b);

				PHANES_CORE_API Matrix4 operator- (const Matrix4& a, float s);
				PHANES_CORE_API Matrix4 operator- (const Matrix4& a, const Matrix4& b);

				PHANES_CORE_API Matrix4 operator* (const Matrix4& a, float s);
				PHANES_CORE_API Matrix4 operator* (const Matrix4& a, const Matrix4& b);
				PHANES_CORE_API Vector4 operator* (const Matrix4& a, const Vector4& v);

				PHANES_CORE_API bool operator== (const Matrix4& a, const Matrix4& b);


				// ================================ //
				//   Matrix4 function definition    //
				// ================================ //

				PHANES_CORE_API float determinant(const Matrix4& a);

				PHANES_CORE_API void inverseNR(Matrix4& a);

				PHANES_CORE_API void transposeNR(Matrix4& a);

				// =============== //
				//   WITH RETURN   //
				// =============== //

				PHANES_CORE_API Matrix4 inverse(Matrix4& a);

				PHANES_CORE_API Matrix4 transpose(const Matrix4& a);

				PHANES_CORE_API bool isIndentityMatrix(const Matrix4& a);


			} // phanes::core::math::coretypes

		} // phanes::core::math

	} // phanes::core

} // phanes


#endif // !MATRIX4_H
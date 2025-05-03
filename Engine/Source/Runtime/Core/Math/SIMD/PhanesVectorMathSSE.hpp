#pragma once

#include <nmmintrin.h>

#include "Core/Math/Boilerplate.h"
#include "Core/Math/SIMD/PhanesSIMDTypes.h"

#include "Core/Math/Vector2.hpp"
#include "Core/Math/Vector3.hpp"
#include "Core/Math/Vector4.hpp"

#include "Core/Math/Plane.hpp"

#include "Core/Math/IntVector2.hpp"
#include "Core/Math/IntVector3.hpp"
#include "Core/Math/IntVector4.hpp"

#include "Core/Math/Matrix3.hpp"
#include "Core/Math/Matrix4.hpp"

// ========== //
//   Common   //
// ========== //

#ifndef PHANES_VECTOR_MATH_SSE_HPP
#	define PHANES_VECTOR_MATH_SSE_HPP

namespace Phanes::Core::Math::SIMD
{
	Phanes::Core::Types::Vec4f32Reg vec4_cross_p(const Phanes::Core::Types::Vec4f32Reg v1,
												 const Phanes::Core::Types::Vec4f32Reg v2)
	{
		__m128 tmp0 = _mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 0, 2, 1));
		__m128 tmp1 = _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp2 = _mm_shuffle_ps(v1, v1, _MM_SHUFFLE(3, 1, 0, 2));
		__m128 tmp3 = _mm_shuffle_ps(v2, v2, _MM_SHUFFLE(3, 0, 2, 1));
		return _mm_sub_ps(_mm_mul_ps(tmp0, tmp1), _mm_mul_ps(tmp2, tmp3));
	}

	/// <summary>
	/// Adds all scalars of the vector.
	/// </summary>
	/// <param name="v">Vector</param>
	/// <returns>Sum stored in v[0:31].</returns>
	Phanes::Core::Types::Vec4f32Reg vec4_hadd(const Phanes::Core::Types::Vec4f32Reg v)
	{
		__m128 t = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 3, 0, 1));
		t = _mm_add_ps(t, v);
		t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(1, 0, 3, 2));
		return _mm_add_ps(t, v);
	}

	/// <summary>
	/// Adds all scalars of the vector.
	/// </summary>
	/// <param name="v">Vector</param>
	/// <returns>Sum of components.</returns>
	float vec4_hadd_cvtf32(const Phanes::Core::Types::Vec4f32Reg v)
	{
		__m128 t = _mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 3, 0, 1));
		t = _mm_add_ps(t, v);
		t = _mm_shuffle_ps(t, t, _MM_SHUFFLE(1, 0, 3, 2));
		t = _mm_add_ps(t, v);
		return _mm_cvtss_f32(t);
	}

	/// <summary>
	/// Gets the absolute value of each scalar in the vector.
	/// </summary>
	/// <param name="v">Vector</param>
	/// <returns>Vector with all components positive.</returns>
	Phanes::Core::Types::Vec4f32Reg vec4_abs(const Phanes::Core::Types::Vec4f32Reg v)
	{
		return _mm_and_ps(v, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
	}

	/// <summary>
	/// Gets the dot product of the
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	Phanes::Core::Types::Vec4f32Reg vec4_dot(const Phanes::Core::Types::Vec4f32Reg v1,
											 const Phanes::Core::Types::Vec4f32Reg v2)
	{
		return vec4_hadd(_mm_mul_ps(v1, v2));
	}

	/// <summary>
	/// Gets the dot product of the
	/// </summary>
	/// <param name="v1"></param>
	/// <param name="v2"></param>
	/// <returns></returns>
	float vec4_dot_cvtf32(const Phanes::Core::Types::Vec4f32Reg v1,
						  const Phanes::Core::Types::Vec4f32Reg v2)
	{
		return vec4_hadd_cvtf32(_mm_mul_ps(v1, v2));
	}

	Phanes::Core::Types::Vec2f64Reg vec2_eq(const Phanes::Core::Types::Vec2f64Reg v1,
											const Phanes::Core::Types::Vec2f64Reg v2)
	{
		return _mm_cmpeq_pd(v1, v2);
	}

	/// <summary>
	/// Sets the last component of the register to zero. <br>
	/// The last component could hold unexpected values.
	/// </summary>
	/// <param name="v1"></param>
	void vec3_fix(Phanes::Core::Types::Vec4f32Reg v1)
	{
		v1 = _mm_and_ps(
			v1, _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000)));
	}
} // namespace Phanes::Core::Math::SIMD

// ============ //
//   TVector4   //
// ============ //

namespace Phanes::Core::Math::Detail
{
	// Template class has already been defined and is included through: Storage.h -> Vector4.hpp -> SIMDIntrinsics.h -> PhanesVectorMathSEE.hpp

	template <>
	struct construct_vec4<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1,
									const TVector4<float, true>& v2)
		{
			v1.comp = v2.comp;
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, float s)
		{
			v1.comp = _mm_set_ps1(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TVector4<float, true>& v1, float x, float y, float z, float w)
		{
			v1.comp = _mm_setr_ps(x, y, z, w);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector2<float, false>& v2,
									const Phanes::Core::Math::TVector2<float, false>& v3)
		{
			v1.comp = _mm_set_ps(v2.x, v2.y, v3.x, v3.y);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& v1, const float* s)
		{
			v1.comp = _mm_loadu_ps(s);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector3<float, true>& v,
									float w)
		{
			r.comp = _mm_set_ps(w, v.z, v.y, v.x);
		}
	};

	template <>
	struct move_vec4<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									Phanes::Core::Math::TVector4<float, true>&& v)
		{
			r.data = v.data;
			v.data = _mm_setzero_ps();
		}
	};

	template <>
	struct compute_vec4_add<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.comp = _mm_add_ps(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									float s)
		{
			r.comp = _mm_add_ps(v1.comp, _mm_set_ps1(s));
		}
	};

	template <>
	struct compute_vec4_sub<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.comp = _mm_sub_ps(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									float s)
		{
			r.comp = _mm_sub_ps(v1.comp, _mm_set_ps1(s));
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									float s,
									const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			r.comp = _mm_sub_ps(_mm_set_ps1(s), v1.comp);
		}
	};

	template <>
	struct compute_vec4_mul<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.comp = _mm_mul_ps(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									float s)
		{
			r.comp = _mm_mul_ps(v1.comp, _mm_set_ps1(s));
		}
	};

	template <>
	struct compute_vec4_div<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.comp = _mm_div_ps(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									float s)
		{
			r.comp = _mm_div_ps(v1.comp, _mm_set_ps1(s));
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									float s,
									const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			r.comp = _mm_div_ps(_mm_set_ps1(s), v1.comp);
		}
	};

	template <>
	struct compute_vec4_inc<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			r.comp = _mm_add_ps(v1.comp, _mm_set_ps1(1.0f));
		}
	};

	template <>
	struct compute_vec4_dec<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			r.comp = _mm_sub_ps(v1.comp, _mm_set_ps1(1.0f));
		}
	};

	template <>
	struct compute_vec4_mag<float, true>
	{
		static FORCEINLINE float map(const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			__m128 tmp = _mm_mul_ps(v1.data, v1.data);
			return _mm_cvtss_f32(_mm_sqrt_ps(SIMD::vec4_hadd(tmp)));
		}
	};

	template <>
	struct compute_vec4_dotp<float, true>
	{
		static FORCEINLINE float map(const Phanes::Core::Math::TVector4<float, true>& v1,
									 const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			return SIMD::vec4_dot_cvtf32(v1.data, v2.data);
		}
	};

	template <>
	struct compute_vec4_set<float, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TVector4<float, true>& v1, float x, float y, float z, float w)
		{
			v1.data = _mm_setr_ps(x, y, z, w);
		}
	};

	template <>
	struct compute_vec4_max<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.data = _mm_max_ps(v1.data, v2.data);
		}
	};

	template <>
	struct compute_vec4_min<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1,
									const Phanes::Core::Math::TVector4<float, true>& v2)
		{
			r.data = _mm_min_ps(v1.data, v2.data);
		}
	};

	template <>
	struct compute_vec4_pdiv<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector4<float, true>& r,
									const Phanes::Core::Math::TVector4<float, true>& v1)
		{
			r.data = _mm_div_ps(v1.data, _mm_set_ps1(v1.w));
			r.w = 0.0f;
		}
	};

	// ============ //
	//   TVector3   //
	// ============ //

	template <>
	struct construct_vec3<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1,
									const TVector3<float, true>& v2)
		{
			v1.comp = _mm_setr_ps(v2.x, v2.y, v2.z, 0.0f);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, float s)
		{
			v1.comp = _mm_set_ps1(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TVector3<float, true>& v1, float x, float y, float z)
		{
			v1.comp = _mm_setr_ps(x, y, z, 0.0f);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1,
									const Phanes::Core::Math::TVector2<float, true>& v2,
									float s)
		{
			v1.comp = _mm_set_ps(v2.x, v2.y, s, 0.0f);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& v1, const float* s)
		{
			v1.comp = _mm_setr_ps(s[0], s[1], s[2], 0.0f);
		}
	};

	template <>
	struct move_vec3<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& r,
									Phanes::Core::Math::TVector3<float, true>&& v)
		{
			r.data = v.data;
			v.data = _mm_setzero_ps();
		}
	};

	template <>
	struct compute_vec3_set<float, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TVector3<float, true>& v1, float x, float y, float z)
		{
			v1.data = _mm_setr_ps(x, y, z, 0.0f);
		}
	};

	template <>
	struct compute_vec3_add<float, true> : public compute_vec4_add<float, true>
	{ };
	template <>
	struct compute_vec3_sub<float, true> : public compute_vec4_sub<float, true>
	{ };
	template <>
	struct compute_vec3_mul<float, true> : public compute_vec4_mul<float, true>
	{ };
	template <>
	struct compute_vec3_div<float, true> : public compute_vec4_div<float, true>
	{ };
	template <>
	struct compute_vec3_inc<float, true> : public compute_vec4_inc<float, true>
	{ };
	template <>
	struct compute_vec3_dec<float, true> : public compute_vec4_dec<float, true>
	{ };
	template <>
	struct compute_vec3_mag<float, true> : public compute_vec4_mag<float, true>
	{ };
	template <>
	struct compute_vec3_dotp<float, true> : public compute_vec4_dotp<float, true>
	{ };
	template <>
	struct compute_vec3_max<float, true> : public compute_vec4_max<float, true>
	{ };
	template <>
	struct compute_vec3_min<float, true> : public compute_vec4_min<float, true>
	{ };

	template <>
	struct compute_vec3_cross_p<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& r,
									const Phanes::Core::Math::TVector3<float, true>& v1,
									const Phanes::Core::Math::TVector3<float, true>& v2)
		{
			r.data = Phanes::Core::Math::SIMD::vec4_cross_p(v1.data, v2.data);
		}
	};

	// ============ //
	//   TVector2   //
	// ============ //

	template <>
	struct construct_vec2<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1,
									const TVector2<double, true>& v2)
		{
			v1.comp = _mm_setr_pd(v2.x, v2.y);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, double s)
		{
			v1.comp = _mm_set_pd1(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TVector2<double, true>& v1, double x, double y)
		{
			v1.comp = _mm_setr_pd(x, y);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& v1, const double* s)
		{
			v1.comp = _mm_loadu_pd(s);
		}
	};

	template <>
	struct compute_vec2_add<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.comp = _mm_add_pd(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									double s)
		{
			r.comp = _mm_add_pd(v1.comp, _mm_set1_pd(s));
		}
	};

	template <>
	struct compute_vec2_sub<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.comp = _mm_sub_pd(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									double s)
		{
			r.comp = _mm_sub_pd(v1.comp, _mm_set1_pd(s));
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									double s,
									const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			r.comp = _mm_sub_pd(_mm_set1_pd(s), v1.comp);
		}
	};

	template <>
	struct compute_vec2_mul<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.comp = _mm_mul_pd(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									double s)
		{
			r.comp = _mm_mul_pd(v1.comp, _mm_set1_pd(s));
		}
	};

	template <>
	struct compute_vec2_div<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.comp = _mm_div_pd(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									double s)
		{
			r.comp = _mm_div_pd(v1.comp, _mm_set1_pd(s));
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									double s,
									const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			r.comp = _mm_div_pd(_mm_set1_pd(s), v1.comp);
		}
	};

	template <>
	struct compute_vec2_inc<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			r.comp = _mm_add_pd(v1.comp, _mm_set1_pd(1.0f));
		}
	};

	template <>
	struct compute_vec2_dec<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			r.comp = _mm_sub_pd(v1.comp, _mm_set1_pd(1.0f));
		}
	};

	// Magnitude
	template <RealType T>
	struct compute_vec2_mag<T, true>
	{
		static FORCEINLINE double map(const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			__m128d tmp = _mm_mul_pd(v1.data, v1.data);
			return _mm_cvtsd_f64(_mm_sqrt_pd(_mm_hadd_pd(tmp, tmp)));
		}
	};

	// Dot product
	template <>
	struct compute_vec2_dotp<double, true>
	{
		static FORCEINLINE double map(const Phanes::Core::Math::TVector2<double, true>& v1)
		{
			__m128d tmp = _mm_mul_pd(v1.data, v1.data);
			return _mm_cvtsd_f64(_mm_hadd_pd(tmp, tmp));
		}
	};

	// Max
	template <>
	struct compute_vec2_max<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.data = _mm_max_pd(v1.data, v2.data);
		}
	};

	// Min
	template <>
	struct compute_vec2_min<double, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TVector2<double, true>& r,
									const Phanes::Core::Math::TVector2<double, true>& v1,
									const Phanes::Core::Math::TVector2<double, true>& v2)
		{
			r.data = _mm_min_pd(v1.data, v2.data);
		}
	};

	// Set
	template <>
	struct compute_vec2_set<double, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TVector2<double, true>& v1, double x, double y)
		{
			v1.data = _mm_setr_pd(x, y);
		}
	};

	// ========= //
	//   Plane   //
	// ========= //

	template <>
	struct construct_plane<float, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TPlane<float, true>& pl, const TVector3<float, true>& v1, float d)
		{
			pl.comp.data = v1.data;
			pl.comp.w = d;
		}

		static FORCEINLINE void map(Phanes::Core::Math::TPlane<float, true>& pl,
									const TVector3<float, true>& normal,
									const TVector3<float, true>& base)
		{
			pl.comp.data = normal.data;
			pl.comp.w = DotP(normal, base);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TPlane<float, true>& pl, float x, float y, float z, float d)
		{

			pl.comp.data = _mm_set_ps(x, y, z, d);
		}

		// TODO: Create SSE constructor with 3 Points
	};

	template <>
	struct compute_plane_add<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TPlane<float, true>& r,
									Phanes::Core::Math::TPlane<float, true>& pl1,
									Phanes::Core::Math::TPlane<float, true>& pl2)
		{
			r.comp.data = _mm_add_ps(pl1.comp.data, pl2.comp.data);
		}
	};

	template <>
	struct compute_plane_sub<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TPlane<float, true>& r,
									Phanes::Core::Math::TPlane<float, true>& pl1,
									Phanes::Core::Math::TPlane<float, true>& pl2)
		{
			r.comp.data = _mm_sub_ps(pl1.comp.data, pl2.comp.data);
		}
	};

	template <>
	struct compute_plane_mul<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TPlane<float, true>& r,
									Phanes::Core::Math::TPlane<float, true>& pl1,
									Phanes::Core::Math::TPlane<float, true>& pl2)
		{
			r.comp.data = _mm_mul_ps(pl1.comp.data, pl2.comp.data);
		}
	};

	template <>
	struct compute_plane_div<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TPlane<float, true>& r,
									Phanes::Core::Math::TPlane<float, true>& pl1,
									Phanes::Core::Math::TPlane<float, true>& pl2)
		{
			r.comp.data = _mm_div_ps(pl1.comp.data, pl2.comp.data);
		}
	};

	// =============== //
	//   TIntVector4   //
	// =============== //

	template <>
	struct construct_ivec4<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1,
									const TIntVector4<int, true>& v2)
		{
			v1.comp = _mm_setr_epi32(v2.x, v2.y, v2.z, v2.w);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, int s)
		{
			v1.comp = _mm_set1_epi32(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector4<int, true>& v1, int x, int y, int z, int w)
		{
			v1.comp = _mm_setr_epi32(x, y, z, w);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& v1, const int* comp)
		{
			v1.comp = _mm_set_epi32(comp[3], comp[2], comp[1], comp[0]);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector2<int, true>& v1,
									const Phanes::Core::Math::TIntVector2<int, true>& v2)
		{
			r.comp = _mm_setr_epi32(v1.x, v1.y, v2.x, v2.y);
		}
	};

	template <>
	struct compute_ivec4_add<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_add_epi32(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_add_epi32(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_sub<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_sub_epi32(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_sub_epi32(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_mul<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_mul_epi32(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_mul_epi32(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_inc<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1)
		{
			r.comp = _mm_add_epi32(v1.comp, _mm_set1_epi32(1));
		}
	};

	template <>
	struct compute_ivec4_dec<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1)
		{
			r.comp = _mm_sub_epi32(v1.comp, _mm_set1_epi32(1));
		}
	};

	template <>
	struct compute_ivec4_and<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_and_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_and_si128(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_or<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_or_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_or_si128(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_xor<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_xor_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_xor_si128(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_left_shift<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_sll_epi32(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_sll_epi32(v1.comp, _mm_set1_epi32(s));
		}
	};

	template <>
	struct compute_ivec4_right_shift<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									const Phanes::Core::Math::TIntVector4<int, true>& v2)
		{
			r.comp = _mm_srl_epi32(v1.comp, v2.comp);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector4<int, true>& r,
									const Phanes::Core::Math::TIntVector4<int, true>& v1,
									int s)
		{
			r.comp = _mm_srl_epi32(v1.comp, _mm_set1_epi32(s));
		}
	};

	// =============== //
	//   TIntVector3   //
	// =============== //

	template <>
	struct construct_ivec3<int, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1,
									const TIntVector3<int, true>& v2)
		{
			v1.comp = _mm_setr_epi32(v2.x, v2.y, v2.z, v2.w);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, int s)
		{
			v1.comp = _mm_set1_epi32(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector3<int, true>& v1, int x, int y, int z)
		{
			v1.comp = _mm_setr_epi32(x, y, z, 0);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& v1, const int* comp)
		{
			v1.comp = _mm_setr_epi32(comp[0], comp[1], comp[2], 0);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TIntVector3<int, true>& r,
									const Phanes::Core::Math::TIntVector2<int, true>& v1,
									const int s)
		{
			r.comp = _mm_setr_epi32(v1.x, v1.y, s, 0);
		}
	};

	template <>
	struct compute_ivec3_add<int, true> : public compute_ivec4_add<int, true>
	{ };
	template <>
	struct compute_ivec3_sub<int, true> : public compute_ivec4_sub<int, true>
	{ };
	template <>
	struct compute_ivec3_mul<int, true> : public compute_ivec4_mul<int, true>
	{ };
	template <>
	struct compute_ivec3_div<int, true> : public compute_ivec4_div<int, true>
	{ };
	template <>
	struct compute_ivec3_inc<int, true> : public compute_ivec4_inc<int, true>
	{ };
	template <>
	struct compute_ivec3_dec<int, true> : public compute_ivec4_dec<int, true>
	{ };

	template <>
	struct compute_ivec3_and<int, true> : public compute_ivec4_and<int, true>
	{ };
	template <>
	struct compute_ivec3_or<int, true> : public compute_ivec4_or<int, true>
	{ };
	template <>
	struct compute_ivec3_xor<int, true> : public compute_ivec4_xor<int, true>
	{ };
	template <>
	struct compute_ivec3_left_shift<int, true> : public compute_ivec4_left_shift<int, true>
	{ };
	template <>
	struct compute_ivec3_right_shift<int, true> : public compute_ivec4_right_shift<int, true>
	{ };

	// =============== //
	//   TIntVector2   //
	// =============== //

	template <>
	struct construct_ivec2<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			v1.comp = _mm_set_epi64x(v2.y, v2.x);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			v1.comp = _mm_set1_epi64x(s);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 x,
			Phanes::Core::Types::int64 y)
		{
			v1.comp = _mm_set_epi64x(y, x);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Types::int64* comp)
		{
			v1.comp = _mm_set_epi64x(comp[1], comp[0]);
		}
	};

	template <>
	struct compute_ivec2_add<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_add_epi64(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_add_epi64(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_sub<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_sub_epi64(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_sub_epi64(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_inc<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1)
		{
			r.comp = _mm_add_epi64(v1.comp, _mm_set1_epi64x(1));
		}
	};

	template <>
	struct compute_ivec2_dec<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1)
		{
			r.comp = _mm_sub_epi64(v1.comp, _mm_set1_epi64x(1));
		}
	};

	template <>
	struct compute_ivec2_and<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_and_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_and_si128(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_or<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_or_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_or_si128(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_xor<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_xor_si128(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_xor_si128(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_left_shift<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_sll_epi64(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_sll_epi64(v1.comp, _mm_set1_epi64x(s));
		}
	};

	template <>
	struct compute_ivec2_right_shift<Phanes::Core::Types::int64, true>
	{
		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v2)
		{
			r.comp = _mm_srl_epi64(v1.comp, v2.comp);
		}

		static FORCEINLINE void
		map(Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& r,
			const Phanes::Core::Math::TIntVector2<Phanes::Core::Types::int64, true>& v1,
			Phanes::Core::Types::int64 s)
		{
			r.comp = _mm_srl_epi64(v1.comp, _mm_set1_epi64x(s));
		}
	};

	// =========== //
	//   Matrix3   //
	// =========== //

	template <>
	struct compute_mat3_transpose<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TMatrix3<float, true>& r,
									const TMatrix3<float, true>& m1)
		{
			__m128 tmp0 = _mm_shuffle_ps(m1.c0.data, m1.c1.data, 0x44);
			__m128 tmp2 = _mm_shuffle_ps(m1.c0.data, m1.c1.data, 0xEE);
			__m128 tmp1 = _mm_shuffle_ps(m1.c2.data, m1.c2.data, 0x44);
			__m128 tmp3 = _mm_shuffle_ps(m1.c2.data, m1.c2.data, 0xEE);

			r.c0.data = _mm_shuffle_ps(tmp0, tmp1, 0x88);
			r.c1.data = _mm_shuffle_ps(tmp0, tmp1, 0xDD);
			r.c2.data = _mm_shuffle_ps(tmp2, tmp3, 0x88);
		}
	};

	template <>
	struct compute_mat3_mul<float, true>
	{
		static FORCEINLINE void map(Phanes::Core::Math::TMatrix3<float, true>& r,
									const TMatrix3<float, true>& m1,
									const TMatrix3<float, true>& m2)
		{

			// First column
			__m128 tmp0 = _mm_mul_ps(m1.c0.data, m2.c0.data);
			__m128 tmp1 = _mm_mul_ps(m1.c1.data, m2.c0.data);
			__m128 tmp2 = _mm_mul_ps(m1.c2.data, m2.c0.data);

			r.c0.data = _mm_add_ps(_mm_add_ps(tmp0, tmp1), tmp2);

			// Second column
			tmp0 = _mm_mul_ps(m1.c0.data, m2.c1.data);
			tmp1 = _mm_mul_ps(m1.c1.data, m2.c1.data);
			tmp2 = _mm_mul_ps(m1.c2.data, m2.c1.data);

			r.c1.data = _mm_add_ps(_mm_add_ps(tmp0, tmp1), tmp2);

			// Third column
			tmp0 = _mm_mul_ps(m1.c0.data, m2.c2.data);
			tmp1 = _mm_mul_ps(m1.c1.data, m2.c2.data);
			tmp2 = _mm_mul_ps(m1.c2.data, m2.c2.data);

			r.c2.data = _mm_add_ps(_mm_add_ps(tmp0, tmp1), tmp2);
		}

		static FORCEINLINE void map(Phanes::Core::Math::TVector3<float, true>& r,
									const TMatrix3<float, true>& m1,
									const TVector3<float, true>& v)
		{
			__m128 tmp0 = _mm_mul_ps(m1.c0.data, v.data);
			__m128 tmp1 = _mm_mul_ps(m1.c1.data, v.data);
			__m128 tmp2 = _mm_mul_ps(m1.c2.data, v.data);

			r.data = _mm_add_ps(_mm_add_ps(tmp0, tmp1), tmp2);
		}
	};

	// =========== //
	//   Matrix4   //
	// =========== //

	template <>
	struct compute_mat4_det<float, true>
	{

		// From: GLM: https://github.com/g-truc/glm/blob/master/glm/simd/matrix.h (MIT License)
		static FORCEINLINE float map(const TMatrix4<float, true>& m1)
		{
			__m128 Fac0;
			{
				//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				//	valType SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
				//	valType SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac0 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac1;
			{
				//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				//	valType SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
				//	valType SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac1 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac2;
			{
				//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				//	valType SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
				//	valType SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac2 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac3;
			{
				//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				//	valType SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
				//	valType SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac3 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac4;
			{
				//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				//	valType SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
				//	valType SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac4 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac5;
			{
				//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
				//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
				//	valType SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
				//	valType SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac5 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 SignA = _mm_set_ps(1.0f, -1.0f, 1.0f, -1.0f);
			__m128 SignB = _mm_set_ps(-1.0f, 1.0f, -1.0f, 1.0f);

			// m[1][0]
			// m[0][0]
			// m[0][0]
			// m[0][0]
			__m128 Temp0 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Vec0 = _mm_shuffle_ps(Temp0, Temp0, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][1]
			// m[0][1]
			// m[0][1]
			// m[0][1]
			__m128 Temp1 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(1, 1, 1, 1));
			__m128 Vec1 = _mm_shuffle_ps(Temp1, Temp1, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][2]
			// m[0][2]
			// m[0][2]
			// m[0][2]
			__m128 Temp2 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(2, 2, 2, 2));
			__m128 Vec2 = _mm_shuffle_ps(Temp2, Temp2, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][3]
			// m[0][3]
			// m[0][3]
			// m[0][3]
			__m128 Temp3 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(3, 3, 3, 3));
			__m128 Vec3 = _mm_shuffle_ps(Temp3, Temp3, _MM_SHUFFLE(2, 2, 2, 0));

			// col0
			// + (Vec1[0] * Fac0[0] - Vec2[0] * Fac1[0] + Vec3[0] * Fac2[0]),
			// - (Vec1[1] * Fac0[1] - Vec2[1] * Fac1[1] + Vec3[1] * Fac2[1]),
			// + (Vec1[2] * Fac0[2] - Vec2[2] * Fac1[2] + Vec3[2] * Fac2[2]),
			// - (Vec1[3] * Fac0[3] - Vec2[3] * Fac1[3] + Vec3[3] * Fac2[3]),
			__m128 Mul00 = _mm_mul_ps(Vec1, Fac0);
			__m128 Mul01 = _mm_mul_ps(Vec2, Fac1);
			__m128 Mul02 = _mm_mul_ps(Vec3, Fac2);
			__m128 Sub00 = _mm_sub_ps(Mul00, Mul01);
			__m128 Add00 = _mm_add_ps(Sub00, Mul02);
			__m128 Inv0 = _mm_mul_ps(SignB, Add00);

			// col1
			// - (Vec0[0] * Fac0[0] - Vec2[0] * Fac3[0] + Vec3[0] * Fac4[0]),
			// + (Vec0[0] * Fac0[1] - Vec2[1] * Fac3[1] + Vec3[1] * Fac4[1]),
			// - (Vec0[0] * Fac0[2] - Vec2[2] * Fac3[2] + Vec3[2] * Fac4[2]),
			// + (Vec0[0] * Fac0[3] - Vec2[3] * Fac3[3] + Vec3[3] * Fac4[3]),
			__m128 Mul03 = _mm_mul_ps(Vec0, Fac0);
			__m128 Mul04 = _mm_mul_ps(Vec2, Fac3);
			__m128 Mul05 = _mm_mul_ps(Vec3, Fac4);
			__m128 Sub01 = _mm_sub_ps(Mul03, Mul04);
			__m128 Add01 = _mm_add_ps(Sub01, Mul05);
			__m128 Inv1 = _mm_mul_ps(SignA, Add01);

			// col2
			// + (Vec0[0] * Fac1[0] - Vec1[0] * Fac3[0] + Vec3[0] * Fac5[0]),
			// - (Vec0[0] * Fac1[1] - Vec1[1] * Fac3[1] + Vec3[1] * Fac5[1]),
			// + (Vec0[0] * Fac1[2] - Vec1[2] * Fac3[2] + Vec3[2] * Fac5[2]),
			// - (Vec0[0] * Fac1[3] - Vec1[3] * Fac3[3] + Vec3[3] * Fac5[3]),
			__m128 Mul06 = _mm_mul_ps(Vec0, Fac1);
			__m128 Mul07 = _mm_mul_ps(Vec1, Fac3);
			__m128 Mul08 = _mm_mul_ps(Vec3, Fac5);
			__m128 Sub02 = _mm_sub_ps(Mul06, Mul07);
			__m128 Add02 = _mm_add_ps(Sub02, Mul08);
			__m128 Inv2 = _mm_mul_ps(SignB, Add02);

			// col3
			// - (Vec1[0] * Fac2[0] - Vec1[0] * Fac4[0] + Vec2[0] * Fac5[0]),
			// + (Vec1[0] * Fac2[1] - Vec1[1] * Fac4[1] + Vec2[1] * Fac5[1]),
			// - (Vec1[0] * Fac2[2] - Vec1[2] * Fac4[2] + Vec2[2] * Fac5[2]),
			// + (Vec1[0] * Fac2[3] - Vec1[3] * Fac4[3] + Vec2[3] * Fac5[3]));
			__m128 Mul09 = _mm_mul_ps(Vec0, Fac2);
			__m128 Mul10 = _mm_mul_ps(Vec1, Fac4);
			__m128 Mul11 = _mm_mul_ps(Vec2, Fac5);
			__m128 Sub03 = _mm_sub_ps(Mul09, Mul10);
			__m128 Add03 = _mm_add_ps(Sub03, Mul11);
			__m128 Inv3 = _mm_mul_ps(SignA, Add03);

			__m128 Row0 = _mm_shuffle_ps(Inv0, Inv1, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Row1 = _mm_shuffle_ps(Inv2, Inv3, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Row2 = _mm_shuffle_ps(Row0, Row1, _MM_SHUFFLE(2, 0, 2, 0));

			//	valType Determinant = m[0][0] * Inverse[0][0]
			//						+ m[0][1] * Inverse[1][0]
			//						+ m[0][2] * Inverse[2][0]
			//						+ m[0][3] * Inverse[3][0];
			__m128 Det0 = Phanes::Core::Math::SIMD::vec4_dot(m1.c0.data, Row2);
			return _mm_cvtss_f32(Det0);
		}
	};

	template <>
	struct compute_mat4_inv<float, true>
	{
		// From: GLM: https://github.com/g-truc/glm/blob/master/glm/simd/matrix.h (MIT License)
		static FORCEINLINE bool map(Phanes::Core::Math::TMatrix4<float, true>& r,
									const Phanes::Core::Math::TMatrix4<float, true>& m1)
		{
			__m128 Fac0;
			{
				//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				//	valType SubFactor00 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
				//	valType SubFactor06 = m[1][2] * m[3][3] - m[3][2] * m[1][3];
				//	valType SubFactor13 = m[1][2] * m[2][3] - m[2][2] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac0 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac1;
			{
				//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				//	valType SubFactor01 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
				//	valType SubFactor07 = m[1][1] * m[3][3] - m[3][1] * m[1][3];
				//	valType SubFactor14 = m[1][1] * m[2][3] - m[2][1] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac1 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac2;
			{
				//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				//	valType SubFactor02 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
				//	valType SubFactor08 = m[1][1] * m[3][2] - m[3][1] * m[1][2];
				//	valType SubFactor15 = m[1][1] * m[2][2] - m[2][1] * m[1][2];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac2 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac3;
			{
				//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				//	valType SubFactor03 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
				//	valType SubFactor09 = m[1][0] * m[3][3] - m[3][0] * m[1][3];
				//	valType SubFactor16 = m[1][0] * m[2][3] - m[2][0] * m[1][3];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(3, 3, 3, 3));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(3, 3, 3, 3));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac3 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac4;
			{
				//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				//	valType SubFactor04 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
				//	valType SubFactor10 = m[1][0] * m[3][2] - m[3][0] * m[1][2];
				//	valType SubFactor17 = m[1][0] * m[2][2] - m[2][0] * m[1][2];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(2, 2, 2, 2));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(2, 2, 2, 2));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac4 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 Fac5;
			{
				//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
				//	valType SubFactor05 = m[2][0] * m[3][1] - m[3][0] * m[2][1];
				//	valType SubFactor12 = m[1][0] * m[3][1] - m[3][0] * m[1][1];
				//	valType SubFactor18 = m[1][0] * m[2][1] - m[2][0] * m[1][1];

				__m128 Swp0a = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(1, 1, 1, 1));
				__m128 Swp0b = _mm_shuffle_ps(m1.c3.data, m1.c2.data, _MM_SHUFFLE(0, 0, 0, 0));

				__m128 Swp00 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(0, 0, 0, 0));
				__m128 Swp01 = _mm_shuffle_ps(Swp0a, Swp0a, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp02 = _mm_shuffle_ps(Swp0b, Swp0b, _MM_SHUFFLE(2, 0, 0, 0));
				__m128 Swp03 = _mm_shuffle_ps(m1.c2.data, m1.c1.data, _MM_SHUFFLE(1, 1, 1, 1));

				__m128 Mul00 = _mm_mul_ps(Swp00, Swp01);
				__m128 Mul01 = _mm_mul_ps(Swp02, Swp03);
				Fac5 = _mm_sub_ps(Mul00, Mul01);
			}

			__m128 SignA = _mm_set_ps(1.0f, -1.0f, 1.0f, -1.0f);
			__m128 SignB = _mm_set_ps(-1.0f, 1.0f, -1.0f, 1.0f);

			// m[1][0]
			// m[0][0]
			// m[0][0]
			// m[0][0]
			__m128 Temp0 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Vec0 = _mm_shuffle_ps(Temp0, Temp0, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][1]
			// m[0][1]
			// m[0][1]
			// m[0][1]
			__m128 Temp1 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(1, 1, 1, 1));
			__m128 Vec1 = _mm_shuffle_ps(Temp1, Temp1, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][2]
			// m[0][2]
			// m[0][2]
			// m[0][2]
			__m128 Temp2 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(2, 2, 2, 2));
			__m128 Vec2 = _mm_shuffle_ps(Temp2, Temp2, _MM_SHUFFLE(2, 2, 2, 0));

			// m[1][3]
			// m[0][3]
			// m[0][3]
			// m[0][3]
			__m128 Temp3 = _mm_shuffle_ps(m1.c1.data, m1.c0.data, _MM_SHUFFLE(3, 3, 3, 3));
			__m128 Vec3 = _mm_shuffle_ps(Temp3, Temp3, _MM_SHUFFLE(2, 2, 2, 0));

			// col0
			// + (Vec1[0] * Fac0[0] - Vec2[0] * Fac1[0] + Vec3[0] * Fac2[0]),
			// - (Vec1[1] * Fac0[1] - Vec2[1] * Fac1[1] + Vec3[1] * Fac2[1]),
			// + (Vec1[2] * Fac0[2] - Vec2[2] * Fac1[2] + Vec3[2] * Fac2[2]),
			// - (Vec1[3] * Fac0[3] - Vec2[3] * Fac1[3] + Vec3[3] * Fac2[3]),
			__m128 Mul00 = _mm_mul_ps(Vec1, Fac0);
			__m128 Mul01 = _mm_mul_ps(Vec2, Fac1);
			__m128 Mul02 = _mm_mul_ps(Vec3, Fac2);
			__m128 Sub00 = _mm_sub_ps(Mul00, Mul01);
			__m128 Add00 = _mm_add_ps(Sub00, Mul02);
			__m128 Inv0 = _mm_mul_ps(SignB, Add00);

			// col1
			// - (Vec0[0] * Fac0[0] - Vec2[0] * Fac3[0] + Vec3[0] * Fac4[0]),
			// + (Vec0[0] * Fac0[1] - Vec2[1] * Fac3[1] + Vec3[1] * Fac4[1]),
			// - (Vec0[0] * Fac0[2] - Vec2[2] * Fac3[2] + Vec3[2] * Fac4[2]),
			// + (Vec0[0] * Fac0[3] - Vec2[3] * Fac3[3] + Vec3[3] * Fac4[3]),
			__m128 Mul03 = _mm_mul_ps(Vec0, Fac0);
			__m128 Mul04 = _mm_mul_ps(Vec2, Fac3);
			__m128 Mul05 = _mm_mul_ps(Vec3, Fac4);
			__m128 Sub01 = _mm_sub_ps(Mul03, Mul04);
			__m128 Add01 = _mm_add_ps(Sub01, Mul05);
			__m128 Inv1 = _mm_mul_ps(SignA, Add01);

			// col2
			// + (Vec0[0] * Fac1[0] - Vec1[0] * Fac3[0] + Vec3[0] * Fac5[0]),
			// - (Vec0[0] * Fac1[1] - Vec1[1] * Fac3[1] + Vec3[1] * Fac5[1]),
			// + (Vec0[0] * Fac1[2] - Vec1[2] * Fac3[2] + Vec3[2] * Fac5[2]),
			// - (Vec0[0] * Fac1[3] - Vec1[3] * Fac3[3] + Vec3[3] * Fac5[3]),
			__m128 Mul06 = _mm_mul_ps(Vec0, Fac1);
			__m128 Mul07 = _mm_mul_ps(Vec1, Fac3);
			__m128 Mul08 = _mm_mul_ps(Vec3, Fac5);
			__m128 Sub02 = _mm_sub_ps(Mul06, Mul07);
			__m128 Add02 = _mm_add_ps(Sub02, Mul08);
			__m128 Inv2 = _mm_mul_ps(SignB, Add02);

			// col3
			// - (Vec1[0] * Fac2[0] - Vec1[0] * Fac4[0] + Vec2[0] * Fac5[0]),
			// + (Vec1[0] * Fac2[1] - Vec1[1] * Fac4[1] + Vec2[1] * Fac5[1]),
			// - (Vec1[0] * Fac2[2] - Vec1[2] * Fac4[2] + Vec2[2] * Fac5[2]),
			// + (Vec1[0] * Fac2[3] - Vec1[3] * Fac4[3] + Vec2[3] * Fac5[3]));
			__m128 Mul09 = _mm_mul_ps(Vec0, Fac2);
			__m128 Mul10 = _mm_mul_ps(Vec1, Fac4);
			__m128 Mul11 = _mm_mul_ps(Vec2, Fac5);
			__m128 Sub03 = _mm_sub_ps(Mul09, Mul10);
			__m128 Add03 = _mm_add_ps(Sub03, Mul11);
			__m128 Inv3 = _mm_mul_ps(SignA, Add03);

			__m128 Row0 = _mm_shuffle_ps(Inv0, Inv1, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Row1 = _mm_shuffle_ps(Inv2, Inv3, _MM_SHUFFLE(0, 0, 0, 0));
			__m128 Row2 = _mm_shuffle_ps(Row0, Row1, _MM_SHUFFLE(2, 0, 2, 0));

			//	valType Determinant = m[0][0] * Inverse[0][0]
			//						+ m[0][1] * Inverse[1][0]
			//						+ m[0][2] * Inverse[2][0]
			//						+ m[0][3] * Inverse[3][0];
			__m128 Det0 = Phanes::Core::Math::SIMD::vec4_dot(m1.c0.data, Row2);
			__m128 Rcp0 = _mm_div_ps(_mm_set1_ps(1.0f), Det0);
			//__m128 Rcp0 = _mm_rcp_ps(Det0);

			//	Inverse /= Determinant;
			r.c0.data = _mm_mul_ps(Inv0, Rcp0);
			r.c1.data = _mm_mul_ps(Inv1, Rcp0);
			r.c2.data = _mm_mul_ps(Inv2, Rcp0);
			r.c3.data = _mm_mul_ps(Inv3, Rcp0);

			return true;
		}
	};
} // namespace Phanes::Core::Math::Detail

#endif

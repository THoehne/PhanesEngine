#pragma once

// This file includes the necessary header for vectorization intrinsics. If no specifics are defined SSE4.2 is used.
//
// ARM is not supported.

#include "Core/Math/MathTypes.h"
#include "Core/Math/SIMD/Platform.h"

#if P_INTRINSICS == P_INTRINSICS_AVX2
#	include <immintrin.h>
#elif P_INTRINSICS == P_INTRINSICS_AVX
#	include <immintrin.h>
#elif P_INTRINSICS == P_INTRINSICS_SSE
#	include <nmmintrin.h>
#elif P_INTRINSICS == P_INTRINSICS_NEON
#	include "neon.h" // <- Not supported
#endif

// use_simd for metaprogramming
namespace Phanes::Core::Math::SIMD
{

	/// <summary>
	/// This decides, whether simd operations should be used, based on the vector type, it's size, the vector alignment and whether the right extension can be loaded during compiletime.
	/// </summary>
	/// <typeparam name="T">Type of vector</typeparam>
	/// <typeparam name="L">Length of vector</typeparam>
	/// <typeparam name="IsAligned">Whether the vector is aligned for simd usage.</typeparam>
	template <typename T, size_t L, bool IsAligned>
	struct use_simd
	{
		static const bool value = false;
	};

	// SSE / NEON

	template <>
	struct use_simd<float, 4, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	template <>
	struct use_simd<float, 3, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	template <>
	struct use_simd<int, 4, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	template <>
	struct use_simd<int, 3, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	template <>
	struct use_simd<unsigned int, 4, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	template <>
	struct use_simd<unsigned int, 3, true>
	{
		static const bool value = (P_SSE__ || P_NEON__);
	};

	// SSE

	template <>
	struct use_simd<double, 2, true>
	{
		static const bool value = P_SSE__;
	};

	template <>
	struct use_simd<Phanes::Core::Types::int64, 2, true>
	{
		static const bool value = P_SSE__;
	};

	template <>
	struct use_simd<Phanes::Core::Types::uint64, 2, true>
	{
		static const bool value = P_SSE__;
	};

	// AVX

	template <>
	struct use_simd<double, 4, true>
	{
		static const bool value = P_AVX__;
	};

	template <>
	struct use_simd<double, 3, true>
	{
		static const bool value = P_AVX__;
	};

	template <>
	struct use_simd<float, 8, true>
	{
		static const bool value = P_AVX__;
	};

	// AVX2

	template <>
	struct use_simd<Phanes::Core::Types::int64, 4, true>
	{
		static const bool value = P_AVX2__;
	};

	template <>
	struct use_simd<Phanes::Core::Types::int64, 3, true>
	{
		static const bool value = P_AVX2__;
	};

	template <>
	struct use_simd<Phanes::Core::Types::uint64, 4, true>
	{
		static const bool value = P_AVX2__;
	};

	template <>
	struct use_simd<Phanes::Core::Types::uint64, 3, true>
	{
		static const bool value = P_AVX2__;
	};

	template <>
	struct use_simd<int, 8, true>
	{
		static const bool value = P_AVX2__;
	};

	template <>
	struct use_simd<unsigned int, 8, true>
	{
		static const bool value = P_AVX2__;
	};
} // namespace Phanes::Core::Math::SIMD

// Register aliases
namespace Phanes::Core::Types
{

#if P_INTRINSICS >= 1

	using Vec4f32Reg = __m128;
	using Vec2f64Reg = __m128d;

	using Vec4i32Reg = __m128i;
	using Vec2i64Reg = __m128i;

	using Vec4u32Reg = __m128i;
	using Vec2u64Reg = __m128i;

#elif P_INTRINSICS != P_INTRINSICS_NEON

	using Vec4f32Reg = struct alignas(16) Vec4f32Reg
	{
		float data[4];
	};
	using Vec2f64Reg = struct alignas(16) Vec2f64Reg
	{
		double data[2];
	};
	using Vec4i32Reg = struct alignas(16) Vec4i32Reg
	{
		int data[4];
	};
	using Vec2i64Reg = struct alignas(16) Vec2i64Reg
	{
		Phanes::Core::Types::int64 data[2];
	};
	using Vec4u32Reg = struct alignas(16) Vec4u32Reg
	{
		unsigned int data[4];
	};
	using Vec2u64Reg = struct alignas(16) Vec2u64Reg
	{
		Phanes::Core::Types::uint64 data[4];
	};

#endif

#if P_INTRINSICS >= 2

	using Vec4x2f32Reg = __m256;
	using Vec8f32Reg = __m256;
	using Vec2x2f64Reg = __m256d;
	using Vec4f64Reg = __m256d;

#elif P_INTRINSICS != P_INTRINSICS_NEON

	using Vec4x2f32Reg = struct alignas(32) Vec4x2f32Reg
	{
		float data[8];
	};
	using Vec8f32Reg = struct alignas(32) Vec8f32Reg
	{
		float data[8];
	};
	using Vec2x2f64Reg = struct alignas(32) Vec2x2f64Reg
	{
		double data[4];
	};
	using Vec4f64Reg = struct alignas(32) Vec4f64Reg
	{
		double data[4];
	};

#endif

#if P_INTRINSICS == 3

	using Vec4x2i32Reg = __m256i;
	using Vec8i32Reg;
	= __m256i using Vec2x2i64Reg;
	= __m256i using Vec4i64Reg;
	= __m256i

		using Vec4x2u32Reg;
	= __m256i using Vec8u32Reg;
	= __m256i using Vec2x2u64Reg;
	= __m256i using Vec4u64Reg;
	= __m256i

#elif P_INTRINSICS != P_INTRINSICS_NEON

	using Vec4x2i32Reg = struct alignas(32) Vec4x2i32Reg
	{
		int data[8];
	};
	using Vec8i32Reg = struct alignas(32) Vec8i32Reg
	{
		int data[8];
	};
	using Vec2x2i64Reg = struct alignas(32) Vec2x2i64Reg
	{
		Phanes::Core::Types::int64 data[4];
	};
	using Vec4i64Reg = struct alignas(32) Vec4i64Reg
	{
		Phanes::Core::Types::int64 data[4];
	};

	using Vec4x2u32Reg = struct alignas(32) Vec4x2u32Reg
	{
		unsigned int data[8];
	};
	using Vec8u32Reg = struct alignas(32) Vec8u32Reg
	{
		unsigned int data[8];
	};
	using Vec2x2u64Reg = struct alignas(32) Vec2x2u64Reg
	{
		Phanes::Core::Types::uint64 data[4];
	};
	using Vec4u64Reg = struct alignas(32) Vec4u64Reg
	{
		Phanes::Core::Types::uint64 data[4];
	};

#endif

	// NEON ...
} // namespace Phanes::Core::Types

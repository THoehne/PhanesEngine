#pragma once

#include "Core/Math/MathPCH.h"

// ============================================= //
//   Turn os specific types into global types.   //
// ============================================= //

// TODO: include int128

namespace Phanes::Core::Types
{

#ifdef P_WIN_BUILD

	// MSVC specific types

	using float128 = _FLOAT128;

#elif defined(P_LINUX_BUILD)

	// Linux specific types

	using float128 = __float128;

#endif
	// Specific types size
	//
	// 8-Bit integer
	using int8 = int8_t;

	// 16-Bit integer
	using int16 = int16_t;

	// 32-Bit integer
	using int32 = int32_t;

	// 64-Bit integer
	using int64 = int64_t;

	// 8-Bit unsigned integer
	using uint8 = uint8_t;

	// 16-Bit unsigned integer
	using uint16 = uint16_t;

	// 32-Bit unsigned integer
	using uint32 = uint32_t;

	// 64-Bit unsigned integer
	using uint64 = uint64_t;

	// At least N bit types
	//
	// At least 8-Bit integer
	using lint8 = int_least8_t;

	// At least 16-Bit integer
	using lint16 = int_least16_t;

	// At least 32-Bit integer
	using lint32 = int_least32_t;

	// At least 64-Bit integer
	using lint64 = int_least64_t;

	// At least 8-Bit integer
	using ulint8 = uint_least8_t;

	// At least 16-Bit integer
	using ulint16 = uint_least16_t;

	// At least 32-Bit integer
	using ulint32 = uint_least32_t;

	// At least 64-Bit integer
	using ulint64 = uint_least64_t;

	// Fast N bit types
	//
	// Fast 8-bit integer
	using fint8 = int_fast8_t;

	// At least 16-Bit integer
	using fint16 = int_fast16_t;

	// At least 32-Bit integer
	using fint32 = int_fast32_t;

	// At least 64-Bit integer
	using fint64 = int_fast64_t;

	// At least 8-Bit integer
	using ufint8 = uint_fast8_t;

	// At least 16-Bit integer
	using ufint16 = uint_fast16_t;

	// At least 32-Bit integer
	using ufint32 = uint_fast32_t;

	// At least 64-Bit integer
	using ufint64 = uint_fast64_t;

} // namespace Phanes::Core::Types

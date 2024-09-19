#pragma once

// ============================================= //
//   Turn os specific types into global types.   //
// ============================================= // 


// TODO: include int128

namespace Phanes::Core::Types
{

#ifdef P_WIN_BUILD

  // MSCV++ specific types

  typedef FLOAT128			float128;

//#elif P_UNIX_BUILD
//
//	// GCC specific types
//
//	typedef __float128			float128;

#endif


  // Specific types size
  // 
  // 8-Bit integer
  typedef int8_t				int8;

  // 16-Bit integer
  typedef int16_t				int16;

  // 32-Bit integer
  typedef int32_t				int32;

  // 64-Bit integer
  typedef int64_t				int64;

  // 8-Bit unsigned integer
  typedef uint8_t				uint8;

  // 16-Bit unsigned integer
  typedef uint16_t			uint16;

  // 32-Bit unsigned integer
  typedef uint32_t			uint32;

  // 64-Bit unsigned integer
  typedef uint64_t			uint64;



  // At least N bit types
  // 
  // At least 8-Bit integer
  typedef int_least8_t		lint8;

  // At least 16-Bit integer
  typedef int_least16_t		lint16;

  // At least 32-Bit integer
  typedef int_least32_t		lint32;

  // At least 64-Bit integer
  typedef int_least64_t		lint64;

  // At least 8-Bit integer
  typedef uint_least8_t		ulint8;

  // At least 16-Bit integer
  typedef uint_least16_t		ulint16;

  // At least 32-Bit integer
  typedef uint_least32_t		ulint32;

  // At least 64-Bit integer
  typedef uint_least64_t		ulint64;



  // Fast N bit types
  //
  // Fast 8-bit integer
  typedef int_fast8_t			fint8;

  // At least 16-Bit integer
  typedef int_fast16_t		fint16;

  // At least 32-Bit integer
  typedef int_fast32_t		fint32;

  // At least 64-Bit integer
  typedef int_fast64_t		fint64;

  // At least 8-Bit integer
  typedef uint_fast8_t		ufint8;

  // At least 16-Bit integer
  typedef uint_fast16_t		ufint16;

  // At least 32-Bit integer
  typedef uint_fast32_t		ufint32;

  // At least 64-Bit integer
  typedef uint_fast64_t		ufint64;

}
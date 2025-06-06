// Platform / Compiler detection.

#pragma once

// Architecture MACRO
// Implicitly asumes x86 architecture
#ifndef P_ARM_ARCH
#   define P_x86_ARCH
#else
#   ifdef P_x86_ARCH
#       undef P_x86_ARCH
#   endif
#   error ARM architecture not supported.
#endif

// Set platform MACRO depending on defined build

#define P_PLATFORM_WIN      0
#define P_PLATFORM_LIN      1
#define P_PLATFORM_MAC      2
// #define P_PLATFORM_FBSD  3 -> Is planed for eventual PS5 support

// User defines build platform
#ifdef P_WIN_BUILD 
#   define P_PLATFORM P_PLATFORM_WIN
#   error Windows system is not yet supported.
#elif P_LINUX_BUILD
#   define P_PLATFORM P_PLATFORM_LIN
#elif P_MAC_BUILD
#   define P_PLATFORM P_PLATFORM_MAC
#   error Mac target system is not yet supported.
#elif P_PS5_BUILD || P_FBSD_BUILD
#   define P_PLATFORM P_PLATFORM_FBSD
#   error FreeBSD is not yet supported.
#else 
#   error Your target system is either not supported, or you have yet to define it.
#endif

// Set compiler depending on defined compiler 

// Compiler macro definition

// ID's defined like [0-9][0-x]
// First bracket defines compiler, second defines the version of the compiler.

// Visual C++
#define P_COMPILER_VC22         001
#define P_COMPILER_VC19         002
#define P_COMPILER_VC17         003
#define P_COMPILER_VC15         004
#define P_COMPILER_VC13         005
#define P_COMPILER_VC12         006
#define P_COMPILER_VC10         007
#define P_COMPILER_VC08         008
#define P_COMPILER_VC05         009
#define P_COMPILER_VC03         010
#define P_COMPILER_VC02         011
#define P_COMPILER_VCSP         012

// Clang
#define P_COMPILER_CLANG34      101
#define P_COMPILER_CLANG35      102
#define P_COMPILER_CLANG36      103
#define P_COMPILER_CLANG37      104
#define P_COMPILER_CLANG38      105
#define P_COMPILER_CLANG39      106
#define P_COMPILER_CLANG4       107
#define P_COMPILER_CLANG5       108
#define P_COMPILER_CLANG6       109
#define P_COMPILER_CLANG7       110
#define P_COMPILER_CLANG8       111
#define P_COMPILER_CLANG9       112
#define P_COMPILER_CLANG10      113
#define P_COMPILER_CLANG11      114
#define P_COMPILER_CLANG12      115
#define P_COMPILER_CLANG13      116
#define P_COMPILER_CLANG14      117
#define P_COMPILER_CLANG15      118
#define P_COMPILER_CLANG16      119
#define P_COMPILER_CLANG17      120
#define P_COMPILER_CLANG18      121
#define P_COMPILER_CLANG19      122


// G++
#define P_COMPILER_GCC46		201
#define P_COMPILER_GCC47		202
#define P_COMPILER_GCC48		203
#define P_COMPILER_GCC49		204
#define P_COMPILER_GCC5			205
#define P_COMPILER_GCC6			206
#define P_COMPILER_GCC61		207
#define P_COMPILER_GCC7			208
#define P_COMPILER_GCC8			209
#define P_COMPILER_GCC9			210
#define P_COMPILER_GCC10		211
#define P_COMPILER_GCC11		212
#define P_COMPILER_GCC12		213
#define P_COMPILER_GCC13		214
#define P_COMPILER_GCC14		215


// Intel C++ 
#define P_COMPILER_INTEL14		301
#define P_COMPILER_INTEL15		302
#define P_COMPILER_INTEL16		303
#define P_COMPILER_INTEL17		304
#define P_COMPILER_INTEL18		305
#define P_COMPILER_INTEL19		306
#define P_COMPILER_INTEL21		307

// Visual studio
#ifdef _MSC_VER 
#   if _MSC_VER >= 1930 
#       define P_COMPILER P_COMPILER_VC22
#   elif _MSC_VER >= 1920
#       define P_COMPILER P_COMPILER_VC19
#   elif _MSC_VER >= 1910
#       define P_COMPILER P_COMPILER_VC17
#   elif _MSC_VER >= 1900
#       define P_COMPILER P_COMPILER_VC15
#   elif _MSC_VER >= 1800
#       define P_COMPILER P_COMPILER_VC13
#   elif _MSC_VER >= 1700
#       define P_COMPILER P_COMPILER_VC12
#   elif _MSC_VER >= 1600
#       define P_COMPILER P_COMPILER_VC10
#   elif _MSC_VER >= 1500
#       define P_COMPILER P_COMPILER_VC08  
#   elif _MSC_VER >= 1400
#       define P_COMPILER P_COMPILER_VC05
#   elif _MSC_VER >= 1310
#       define P_COMPILER P_COMPILER_VC03
#   elif _MSC_VER >= 1300
#       define P_COMPILER P_COMPILER_VC02  
#   elif _MSC_VER >= 1200
#       define P_COMPILER P_COMPILER_VCSP
#   endif



// Clang

#elif (defined(__clang__))
#   if defined(__apple_build_version__)
#   
#	    if (__clang_major__ < 6)
#			error "GLM requires Clang 3.4 / Apple Clang 6.0 or higher"
#		elif __clang_major__ == 6 && __clang_minor__ == 0
#			define P_COMPILER P_COMPILER_CLANG35
#		elif __clang_major__ == 6 && __clang_minor__ >= 1
#			define P_COMPILER P_COMPILER_CLANG36
#		elif __clang_major__ >= 7
#			define P_COMPILER P_COMPILER_CLANG37
#		endif
#	else
#		if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
#			error "GLM requires Clang 3.4 or higher"
#		elif __clang_major__ == 3 && __clang_minor__ == 4
#			define P_COMPILER P_COMPILER_CLANG34
#		elif __clang_major__ == 3 && __clang_minor__ == 5
#			define P_COMPILER P_COMPILER_CLANG35
#		elif __clang_major__ == 3 && __clang_minor__ == 6
#			define P_COMPILER P_COMPILER_CLANG36
#		elif __clang_major__ == 3 && __clang_minor__ == 7
#			define P_COMPILER P_COMPILER_CLANG37
#		elif __clang_major__ == 3 && __clang_minor__ == 8
#			define P_COMPILER P_COMPILER_CLANG38
#		elif __clang_major__ == 3 && __clang_minor__ >= 9
#			define P_COMPILER P_COMPILER_CLANG39
#		elif __clang_major__ == 4 && __clang_minor__ == 0
#			define P_COMPILER P_COMPILER_CLANG4
#		elif __clang_major__ == 5
#			define P_COMPILER P_COMPILER_CLANG5
#		elif __clang_major__ == 6
#			define P_COMPILER P_COMPILER_CLANG6
#		elif __clang_major__ == 7
#			define P_COMPILER P_COMPILER_CLANG7
#		elif __clang_major__ == 8
#			define P_COMPILER P_COMPILER_CLANG8
#		elif __clang_major__ == 9
#			define P_COMPILER P_COMPILER_CLANG9
#		elif __clang_major__ == 10
#			define P_COMPILER P_COMPILER_CLANG10
#		elif __clang_major__ == 11
#			define P_COMPILER P_COMPILER_CLANG11
#		elif __clang_major__ == 12
#			define P_COMPILER P_COMPILER_CLANG12
#		elif __clang_major__ == 13
#			define P_COMPILER P_COMPILER_CLANG13
#		elif __clang_major__ == 14
#			define P_COMPILER P_COMPILER_CLANG14
#		elif __clang_major__ == 15
#			define P_COMPILER P_COMPILER_CLANG15
#		elif __clang_major__ == 16
#			define P_COMPILER P_COMPILER_CLANG16
#		elif __clang_major__ == 17
#			define P_COMPILER P_COMPILER_CLANG17
#		elif __clang_major__ == 18
#			define P_COMPILER P_COMPILER_CLANG18
#		elif __clang_major__ >= 19
#			define P_COMPILER P_COMPILER_CLANG19
#		endif
#	endif



// G++
#elif defined(__GNUC__) || defined(__MINGW32__)
#   if __GNUC__ >= 14
#		define P_COMPILER P_COMPILER_GCC14
#	elif __GNUC__ >= 13
#		define P_COMPILER P_COMPILER_GCC13
#	elif __GNUC__ >= 12
#		define P_COMPILER P_COMPILER_GCC12
#	elif __GNUC__ >= 11
#		define P_COMPILER P_COMPILER_GCC11
#	elif __GNUC__ >= 10
#		define P_COMPILER P_COMPILER_GCC10
#	elif __GNUC__ >= 9
#		define P_COMPILER P_COMPILER_GCC9
#	elif __GNUC__ >= 8
#		define P_COMPILER P_COMPILER_GCC8
#	elif __GNUC__ >= 7
#		define P_COMPILER P_COMPILER_GCC7
#	elif __GNUC__ >= 6
#		define P_COMPILER P_COMPILER_GCC6
#	elif __GNUC__ >= 5
#		define P_COMPILER P_COMPILER_GCC5
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 9
#		define P_COMPILER P_COMPILER_GCC49
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 8
#		define P_COMPILER P_COMPILER_GCC48
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 7
#		define P_COMPILER P_COMPILER_GCC47
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 6
#		define P_COMPILER P_COMPILER_GCC46
#	elif ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
#		error PhanesEngine does not support your compiler.
#	endif

#elif defined(__CUDACC__)
#   error CUDA C++ is not supported by PhanesEngine

#endif




// Vector instruction sets


// Define also supported instruction sets for Visual Studio, as it only defines the latest (e.g. only __AVX__ not __SSE4__ ...).

#ifdef P_FORCE_INTRINSICS
    
#   undef __AVX2__
#   undef __AVX__
#   undef __SSE__

#   ifndef P_INTRINSICS
#       error P_INTRINSICS must be defined by the user, when P_FORCE_INTRINSICS is used.
#   endif

#elif !defined(P_FORCE_FPU)
#   ifdef __AVX2__
#    define P_AVX2__ 1
#   elif defined(__AVX__)
#       define P_AVX__ 1
#   elif defined(__SSE__)
#       define P_SSE__ 1
#   endif

#endif // !P_FORCE_INTRINSICS

#ifdef P_AVX2__
#   define P_AVX__ 1
#endif

#ifdef P_AVX__
#   define P_SSE__ 1
#endif

// Deactivate unset SIMD
#ifndef P_AVX2__
#   define P_AVX2__ 0
#endif 

// Deactivate unset SIMD
#ifndef P_AVX__
#   define P_AVX__ 0
#endif 

#ifndef P_SSE__
#   define P_SSE__ 0
#endif 

#ifndef P_NEON__
#   define P_NEON__ 0
#endif

#define P_INTRINSICS_FPU    0
#define P_INTRINSICS_SSE    1
#define P_INTRINSICS_AVX    2
#define P_INTRINSICS_AVX2   3
#define P_INTRINSICS_NEON   4


#if defined(P_FORCE_FPU) // Force, that no intrinsics may be used.
#   define P_INTRINSICS P_INTRINSICS_FPU
#   define P_AVX2__ 0
#   define P_AVX__ 0
#   define P_SSE__ 0
#else
#   if (P_AVX__ == 1) && (P_AVX2__ == 0)
#       define P_INTRINSICS P_INTRINSICS_AVX
#   elif P_AVX2__ == 1
#       define P_INTRINSICS P_INTRINSICS_AVX2
#   elif P_SSE__ == 1
#       define P_INTRINSICS P_INTRINSICS_SSE
#   elif defined(P_ARM_ARCH)
#       define P_INTRINSICS P_INTRINSICS_NEON
#       define P_NEON__ 1
#   elif !defined(P_FORCE_INTRINSICS)
#       error No SIMD instruction set detected. Use P_FORCE_FPU to disable SIMD extensions.
#   endif
#endif

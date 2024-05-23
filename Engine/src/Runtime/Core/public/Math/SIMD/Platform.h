// Platform / Compiler detection.

#pragma once

// Set platform MACRO depending on defined build
// User defines build platform
#ifdef P_WIN_BUILD 
    #define P_PLATFORM 0
#elif P_LINUX_BUILD
    #define P_PLATFORM 1
#elif P_APPLE_BUILD
    #define P_PLATFORM 2
#elif P_PS5_BUILD
    #define P_PLATFORM 3
#else 
    #error Your target system is either not supported, or you have yet to define it.
#endif

// Set compiler depending on defined compiler 

// Compiler macro definition

// ID's defines like [0-9][0-x]
// First bracket is compiler, second is the version of the compiler.

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


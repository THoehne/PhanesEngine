#pragma once


#include "Core/Math/SIMD/Platform.h"

#if P_INTRINSICS == P_INTRINSICS_AVX2
#   include "Core/Math/SIMD/PhanesVectorMathAVX2.hpp"
#elif P_INTRINSICS == P_INTRINSICS_AVX
#   include "Core/Math/SIMD/PhanesVectorMathAVX.hpp"
#elif P_INTRINSICS == P_INTRINSICS_SSE
#   include "Core/Math/SIMD/PhanesVectorMathSSE.hpp"
#elif P_INTRINSICS == P_INTRINSICS_NEON
#   include "Core/Math/SIMD/PhanesVectorMathNeon.hpp"
#endif


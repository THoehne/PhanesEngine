#pragma once


#include "Core/public/Math/SIMD/Platform.h"

#if P_INTRINSICS == P_INTRINSICS_AVX2
#   include "PhanesVectorMathAVX2.hpp"
#elif P_INTRINSICS == P_INTRINSICS_AVX
#   include "PhanesVectorMathAVX.hpp"
#elif P_INTRINSICS == P_INTRINSICS_SSE
#   include "PhanesVectorMathSSE.hpp"
#elif P_INTRINSICS == P_INTRINSICS_NEON
#   include "PhanesVectorMathNeon.hpp"
#elif P_INTRINSICS == P_INTRINSICS_FPU 
#   include "PhanesVectorMathFPU.hpp"
#endif


// Math is independent from the rest of the library, to ensure seamless usage with other client.

#pragma once




#ifdef P_BUILD_LIB
    #include "PhanesEnginePCH.h"

#else 
    #include <type_traits>

#endif


#ifdef P_WIN_BUILD
    
    #ifdef P_DEBUG
    
        #define P_DEBUGBREAK DebugBreak();
    
    #else 
    
        #define P_DEBUGBREAK
    
    #endif // P_DEBUG
    
    #define FORCEINLINE __forceinline
    
#elif defined(P_UNIX_BUILD)
    
    #error Only Windows is supported at the moment.	
    
#elif defined(P_ARM_BUILD)
    
    #error Only Windows is supported at the moment.
    
#else
    
    #error The target system must be defined. (See https://github.com/scorpioblood/PhanesEngine for more information)

#endif // P_WIN_BUILD






// Typenames with RealType constrain have to be floating point numbers.
template<typename T>
concept RealType = std::is_floating_point_v<T>;

// Typenames with IntType constrain have to be integer number.
template<typename T>
concept IntType = std::is_integral_v<T>;
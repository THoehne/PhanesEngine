#pragma once



// Contains precompiled headers used throught PhanesEngine //
#define NOMAXMIN

#ifndef PHANES_CORE_PCH_H
    

    // STL

#   include <cmath>
#   include <stdint.h>
#   include <vector>	
#   include <concepts>
#   include <type_traits>
#   include <string>
#   include <memory>
#
#   include <iostream>
#   include <stdio.h>
#
#
#   include <chrono>
#   include <thread>
#
#   ifdef P_WIN_BUILD 
#
#       include <windows.h>
#
#   endif
#
#
#
#   // spdlog
#   include <spdlog/sinks/stdout_color_sinks.h>
#   include <spdlog/spdlog.h>
#
#   // Local PCH
#   // #include "Core/public/Math/MathPCH.h"
#
#endif // !PHANES_CORE_PCH_H


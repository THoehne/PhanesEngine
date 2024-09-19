#pragma once

// Contains precompiled headers used throught PhanesEngine //
#define NOMAXMIN
    // STL

#   include <cmath>
#   include <stdint.h>
#   include <vector>	
#   include <string>
#   include <concepts>
#   include <type_traits>
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
#   include "Core/public/Math/MathPCH.h"
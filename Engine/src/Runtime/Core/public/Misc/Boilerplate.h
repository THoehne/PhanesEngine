#pragma once

#include "PhanesEnginePCH.h"

// Typenames with RealType constrain have to be floating point numbers.
template<typename T>
concept RealType = std::is_floating_point_v<T>;

// Typenames with IntType constrain have to be integer number.
template<typename T>
concept IntType = std::is_integral_v<T>;
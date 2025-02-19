// Math is independent from the rest of the library, to ensure seamless usage with other client.

#pragma once

#include "Core/Math/MathPCH.h"

#include "Core/Core.h"


namespace Phanes::Core::Math
{

    // Typenames with RealType constrain have to be floating point numbers.
    template<typename T>
    concept RealType = std::is_floating_point_v<T>;

    // Typenames with IntType constrain have to be integer number.
    template<typename T>
    concept IntType = std::is_integral_v<T>;

    // Typenames with Arithmethic constrain have to be number.
    template<typename T>
    concept Arithmethic = std::is_arithmetic_v<T>;
}
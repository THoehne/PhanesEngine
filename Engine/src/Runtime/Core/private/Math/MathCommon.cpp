#include "PhanesEnginePCH.h"

#include "Core/public/Math/MathCommon.h"

#include "Core/public/OSAL/PlatformTypes.h"

// NOTE: oneline if statments are much faster than the max / min algorithm or expanded if's (64.519 ms per 1 000 000 operations)

template<typename T>
T Phanes::Core::Math::Clamp(T value, T low, T high)
{
    if (value < low) value = low;
    if (value > high) value = high;
    return value;
}

template<typename T>
T Phanes::Core::Math::Max(T x, T y)
{
    return (x > y) ? x : y;
}

template<typename T>
T Phanes::Core::Math::Min(T x, T y)
{
    return (x < y) ? x : y;
}

template<typename T>
void Phanes::Core::Math::Swap(T& x, T& y)
{
    float z = x;
    x = y;
    y = z;
}

template<typename T>
bool Phanes::Core::Math::Equals(T x, T y, T threshold)
{
    if (abs(x - y) < threshold) {
        return true;
    }
    return false;
}

template<typename T>
float Phanes::Core::Math::FastInvSqrt(T n)
{
    Phanes::Core::Types::int32 i = * ( int * ) &n;
    float x2 = n * 0.5f;

    i = 0x5f3759df - (i >> 1);
    n = * ( float * ) &i;
    n = n * (1.5f - (x2 * n * n));
    
    return n;
}
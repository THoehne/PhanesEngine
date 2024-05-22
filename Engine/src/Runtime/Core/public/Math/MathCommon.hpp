#pragma once

#define P_FLT_INAC_LARGE		0.0001f						// large float inaccuracy (1*10^-4);
#define P_FLT_INAC				0.00001f					// float inaccuracy (1*10^-5);
#define P_FLT_INAC_SMALL		0.000001f					// small float inaccuracy (1*10^-6);

#define P_180_PI				57.29577951308232			// (double) 180°/pi;
#define P_180_PI_FLT			57.29577951308232f			// (float) 180°/pi;

#define P_PI_180				0.0174532925199432			// double pi/180°
#define P_PI_180_FLT			0.0174532925199432f			// (float) pi/180°

#define P_PI					3.1415926535897932			// PI 
#define P_PI_FLT				3.1415926535897932f			// PI 


#ifndef MATH_COMMON_H
#define MATH_COMMON_H

namespace Phanes::Core::Math {

    /**
     * Clamps a value between minimum and maximum
     *
     * @param value Value to clamp
     * @param low Minimum
     * @param high Maximum
     *
     * @return Minimum, if value is to small / Maximum, if value is to large / value, if value is in range.
     */

    template<typename T>
    T Clamp(T value, T low, T high)
    {
        if (value < low) value = low;
        if (value > high) value = high;
        return value;
    }


    /**
     * Gets the larger of two values
     *
     * @param x
     * @param y
     *
     * @return Larger value
     */

    template<typename T>
    inline T Max(T x, T y)
    {
        return (x > y) ? x : y;
    }


    /**
     * Gets the smaller of two values
     * 
     * @param x
     * @param y
     * 
     * @return Smaller value
     */

    template<typename T>
    inline T Min(T x, T y)
    {
        return (x < y) ? x : y;
    }

    /**
     * Swaps the values of two variables
     * 
     * @param x 
     * @param y
     */

    template<typename T>	
    inline void Swap(T& x, T& y)
    {
        float z = x;
        x = y;
        y = z;
    }

    /**
     * Test two numbers for equality
     * 
     * @param(x)
     * @param(y)
     * @param(threshold) Allowed inaccuracy
     * 
     * @return True, if equal, false if not
     */
    template<typename T>
    bool Equals(T x, T y, T threshold = P_FLT_INAC)
    {
        return (abs(x - y) < threshold);
    }

    /**
     * Calculates the reciprocal of the square root of n using the algorithm of A Quake III
     * 
     * @param n Number to calculate
     * 
     * @return Inverse square root of n 
     * 
     * @note a simple 1.0f / sqrtf(x) is faster than this algorithm. Use for research purpose only.
     */


    template<typename T>
    float FastInvSqrt(T n)
    {
        int i = *(int*)&n;
        float x2 = n * 0.5f;

        i = 0x5f3759df - (i >> 1);
        n = *(float*)&i;
        n = n * (1.5f - (x2 * n * n));

        return n;
    }


} // phanes

#endif // !MATH_COMMON_H
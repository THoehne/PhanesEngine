#pragma once

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"
#include "Core/public/Math/MathCommon.hpp"


namespace Phanes::Core::Math::SIMD
{
    /// <summary>
    /// Adds all scalars of the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Sum stored in v[0:31].</returns>
    Phanes::Core::Types::Vec4f32Reg vec4_hadd(const Phanes::Core::Types::Vec4f32Reg v)
    {
        Phanes::Core::Types::Vec4f32Reg r;
        r.data[0] = v.data[0] + v.data[1] + v.data[2] + v.data[3];
    }
    
    /// <summary>
    /// Adds all scalars of the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Sum of components.</returns>
    float vec4_hadd_cvtf32(const Phanes::Core::Types::Vec4f32Reg v)
    {
        return v.data[0] + v.data[1] + v.data[2] + v.data[3];
    }
    
    /// <summary>
    /// Gets the absolute value of each scalar in the vector.
    /// </summary>
    /// <param name="v">Vector</param>
    /// <returns>Vector with all components positive.</returns>
    Phanes::Core::Types::Vec4f32Reg vec4_abs(const Phanes::Core::Types::Vec4f32Reg v)
    {
        Phanes::Core::Types::Vec4f32Reg r;

        r.data[0] = Abs(v.data[0]);
    }
    
    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    Phanes::Core::Types::Vec4f32Reg vec4_dot(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        Phanes::Core::Types::Vec4f32Reg r;
        r.data[0] = v1.data[0] * v1.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2] + v1.data[3] * v2.data[3];

        return r;
    }
    
    /// <summary>
    /// Gets the dot product of the 
    /// </summary>
    /// <param name="v1"></param>
    /// <param name="v2"></param>
    /// <returns></returns>
    float vec4_dot_cvtf32(const Phanes::Core::Types::Vec4f32Reg v1, const Phanes::Core::Types::Vec4f32Reg v2)
    {
        return v1.data[0] * v1.data[0] + v1.data[1] * v2.data[1] + v1.data[2] * v2.data[2] + v1.data[3] * v2.data[3];
    }
}
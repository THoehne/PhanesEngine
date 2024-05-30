#pragma once

#include "Core/public/Math/Boilerplate.h"


namespace Phanes::Core::Math::SIMD
{

    // Structure to conveniently align arrays.
    template<typename T, size_t L>
    struct alignas(sizeof(T) * 4) AlignedVec
    {
    public:
        T data[L];

        AlignedVec(const T* n_aligned_data)
        {
            for (size_t i = 0; i < L; ++i)
            {
                data[i] = n_aligned_data[i];
            }
        }

        const T* Get()
        {
            return data;
        }
    };

}

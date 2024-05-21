#pragma once


#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector3.hpp"


namespace Phanes::Core::Math
{

    // Line with direction and moment

    template<RealType T>
    struct TLine
    {
    public:
        using Real = T;
        union
        {
            struct
            {
                /** X component of line */
                Real x;
                
                /** Y component of line */
                Real y;
                
                /** Z component of line */
                Real z;
            };
            TVector3<Real> normal;
        };

        /** Moment of line */

        Real m;

    public:

        /** Construct line from base and normal 
         * 
         * @param(normal) Normal of line
         * @param(p) Base of line 
         */

        TLine(const TVector3<T>& normal, const TVector3<T>& p) {};

    };

}
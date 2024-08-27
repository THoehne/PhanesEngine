#pragma once


#include "Core/public/Math/Boilerplate.h"
#include "Core/public/Math/MathFwd.h"

#include "Core/public/Math/Vector3.hpp"

#include <any>


namespace Phanes::Core::Math
{

    // Line with direction and moment

    template<RealType T>
    struct TLine
    {
    public:
        using Real = T;

        /** Direction of line */

        TVector3<Real, false> direction;

        /** Base point of line */

        TVector3<Real, false> base;

    public:

        /** Construct line from base and direction 
         * 
         * @param(direction) Direction of line
         * @param(p) Base of line 
         */

        TLine(const TVector3<T, false>& direction, const TVector3<T, false>& p) : direction(direction), base(p) {};

    };

    /** 
     * Normalizes the direction of the line
     * 
     * @param(l1) Line 
     */

    template<RealType T>
    TLine<T> NormalizeV(TLine<T>& l1)
    {
        std::any

        NormalizeV(l1.direction);
        return l1;
    }


    /**
     * Normalizes the direction of the line
     *
     * @param(l1) Line
     * 
     * @return Line with normalized direction.
     */

    template<RealType T>
    TLine<T> NormalizeV(const TLine<T>& l1)
    {
        return TLine<T>(Normalize(l1.direction), l1.base);
    }
}
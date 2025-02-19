#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/MathCommon.hpp"
#include "Core/Math/MathAbstractTypes.h"
#include "Core/Math/MathFwd.h"

#include "Core/Math/IntVector2.hpp"
#include "Core/Math/IntVector3.hpp"
#include "Core/Math/IntVector4.hpp"

#ifndef P_DEBUG
#pragma warning(disable : 4244)
#endif

/** 
 * General annonation: The Point is the same as a vector. The type exists, to ensure a
 * easy differentiation between the two.
 */

#ifndef INTPOINT_H
#define INTPOINT_H

namespace Phanes::Core::Math {

    /**
     * A 2D Point with components x and y with integer precision.
     */

    template<IntType T>
    struct TIntPoint2 : public TIntVector2<T, false> {

        using TIntVector2<T, false>::TIntVector2;

        /** 
         * Creates IntPoint2 from IntPoint3's xy
         * 
         * @param a IntPoint3 one
         */

        TIntPoint2(const TIntPoint3<T>& a)
        {
            this->x = a.x;
            this->y = a.y;
        }

        /**
         * Creates IntPoint2 from IntPoint4's xy
         *
         * @param a IntPoint4 one
         */

        //TIntPoint2(const TIntPoint4<T>& a)
        //{
        //	this->x = a.x;
        //	this->y = a.y;

        //}
    };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /**
     * A 3D Point with components x and y with integer precision.
     */


    template<IntType T>
    struct TIntPoint3 : public TIntVector3<T, false> {

        using TIntVector3<T, false>::TIntVector3;

        /**
         * Creates IntPoint3 from IntPoint2's xy and zero
         *
         * @param a IntPoint2 one
         */

        TIntPoint3(const TIntPoint2<T>& a)
        {
            this->x = a.x;
            this->y = a.y;
            this->z = 0;
        }

        /**
         * Creates IntPoint3 from IntPoint4's xyz
         *
         * @param a IntPoint4 one
         */

        //TIntPoint3(const TIntPoint4<T>& a) 
        //{
        //	this->components[0] = a.components[0];
        //	this->components[1] = a.components[1];
        //	this->components[2] = a.components[2];
        //}
    };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    /**
     * A 4D Point with components x and y with integer precision.
     */

    
    template<IntType T>
    struct TIntPoint4 : public TIntVector4<T, false> {

    	using TIntVector4<T, false>::TIntVector4;

    	/**
    	 * Creates IntPoint4 from IntPoint2's xy and the last two zero
    	 *
    	 * @param a IntPoint2 one
    	 */

    	TIntPoint4(const TIntPoint2<T>& a)
    	{
    		this->data[0] = a.data[0];
    		this->data[1] = a.data[1];
    		this->data[2] = 0;
    		this->data[3] = 0;
    	}

    	/**
    	 * Creates IntPoint4 from IntPoint3's xyz and zero
    	 *
    	 * @param a IntPoint3 one
    	 */

    	TIntPoint4(const TIntPoint3<T>& a)
    	{
    		this->data[0] = a.data[0];
    		this->data[1] = a.data[1];
    		this->data[2] = a.data[2];
    		this->data[3] = 0;
    	}
    };

} // phanes::core::math::coretypes

#endif // !INTPOINT_H

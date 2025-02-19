#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/Detail/IntVector3Decl.inl"
#include "Core/Math/SIMD/SIMDIntrinsics.h"

#include "Core/Math/SIMD/PhanesSIMDTypes.h"


namespace Phanes::Core::Math
{
    template<IntType T, bool S>
    TIntVector3<T, S>::TIntVector3(const TIntVector3<T, S>& v)
    {
        Detail::construct_ivec3<T, S>::map(*this, v);
    }

    template<IntType T, bool S>
    TIntVector3<T, S>::TIntVector3(const T _x, const T _y, const T _z)
    {
        Detail::construct_ivec3<T, S>::map(*this, _x, _y, _z);
    }

    template<IntType T, bool S>
    TIntVector3<T, S>::TIntVector3(const T s)
    {
        Detail::construct_ivec3<T, S>::map(*this, s);
    }

    template<IntType T, bool S>
    TIntVector3<T, S>::TIntVector3(const T* comp)
    {
        Detail::construct_ivec3<T, S>::map(*this, comp);
    }

    template<IntType T, bool S>
    TIntVector3<T, S>::TIntVector3(const TIntVector2<T, S>& v1, const T s)
    {
        Detail::construct_ivec3<T, S>::map(*this, v1, s);
    }




    template<IntType T, bool S>
    TIntVector3<T, S>& operator+=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator+=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator-=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator-=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator*=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator*=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator/=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator/=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_div<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator%=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_mod<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator%=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_mod<T, S>::map(v1, v1, s);
        return v1;
    }


    template<IntType T, bool S>
    TIntVector3<T, S> operator+(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_add<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator+(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_add<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator-(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_sub<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator-(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_sub<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator*(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_mul<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator*(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_mul<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator/(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_div<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator/(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_div<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator%(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_mod<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator%(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_mod<T, S>::map(r, v1, s);
        return r;
    }




    // Bitwise operators

    template<IntType T, bool S>
    TIntVector3<T, S>& operator&=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_and<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator&=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_and<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator|=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_or<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator|=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_or<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator^=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_xor<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator^=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_xor<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator<<=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_left_shift<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator<<=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_left_shift<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator>>=(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        Detail::compute_ivec3_right_shift<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator>>=(TIntVector3<T, S>& v1, T s)
    {
        Detail::compute_ivec3_right_shift<T, S>::map(v1, v1, s);
        return v1;
    }



    template<IntType T, bool S>
    TIntVector3<T, S> operator&(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_and<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator&(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_and<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator|(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_or<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator|(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_or<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator^(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_xor<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator^(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_xor<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator<<(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_left_shift<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator<<(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_left_shift<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator>>(TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_right_shift<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator>>(TIntVector3<T, S>& v1, T s)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_right_shift<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector3<T, S> operator~(TIntVector3<T, S>& v1)
    {
        TIntVector3<T, S> r;
        Detail::compute_ivec3_bnot<T, S>::map(r, v1);
        return r;
    }



    // Comparision

    template<IntType T, bool S>
    bool operator==(const TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        return Detail::compute_ivec3_eq<T, S>::map(v1, v2);
    }

    template<IntType T, bool S>
    bool operator!=(const TIntVector3<T, S>& v1, const TIntVector3<T, S>& v2)
    {
        return Detail::compute_ivec3_ieq<T, S>::map(v1, v2);
    }



    // Inc- / Decrement


    template<IntType T, bool S>
    TIntVector3<T, S>& operator++(TIntVector3<T, S>& v1)
    {
        Detail::compute_ivec3_inc<T, S>::map(v1);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator--(TIntVector3<T, S>& v1)
    {
        Detail::compute_ivec3_inc<T, S>::map(v1);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator++(TIntVector3<T, S>& v1, int)
    {
        return ++v1;
    }

    template<IntType T, bool S>
    TIntVector3<T, S>& operator--(TIntVector3<T, S>& v1, int)
    {
        return --v1;
    }
}
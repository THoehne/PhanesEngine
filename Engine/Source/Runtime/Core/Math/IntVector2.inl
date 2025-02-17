#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/IntVector2Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<IntType T, bool S>
    TIntVector2<T, S>::TIntVector2(const TIntVector2<T, S>& v)
    {
        Detail::construct_ivec2<T, S>::map(*this, v);
    }

    template<IntType T, bool S>
    TIntVector2<T, S>::TIntVector2(const T _x, const T _y)
    {
        Detail::construct_ivec2<T, S>::map(*this, _x, _y);
    }

    template<IntType T, bool S>
    TIntVector2<T, S>::TIntVector2(const T s)
    {
        Detail::construct_ivec2<T, S>::map(*this, s);
    }

    template<IntType T, bool S>
    TIntVector2<T, S>::TIntVector2(const T* comp)
    {
        Detail::construct_ivec2<T, S>::map(*this, comp);
    }




    template<IntType T, bool S>
    TIntVector2<T, S>& operator+=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator+=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator-=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator-=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator*=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator*=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator/=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator/=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_div<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator%=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_mod<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator%=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_mod<T, S>::map(v1, v1, s);
        return v1;
    }


    template<IntType T, bool S>
    TIntVector2<T, S> operator+(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_add<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator+(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_add<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator-(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_sub<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator-(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_sub<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator*(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_mul<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator*(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_mul<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator/(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_div<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator/(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_div<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator%(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_mod<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator%(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_mod<T, S>::map(r, v1, s);
        return r;
    }




    // Bitwise operators

    template<IntType T, bool S>
    TIntVector2<T, S>& operator&=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_and<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator&=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_and<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator|=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_or<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator|=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_or<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator^=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_xor<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator^=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_xor<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator<<=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_left_shift<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator<<=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_left_shift<T, S>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator>>=(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        Detail::compute_ivec2_right_shift<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator>>=(TIntVector2<T, S>& v1, T s)
    {
        Detail::compute_ivec2_right_shift<T, S>::map(v1, v1, s);
        return v1;
    }



    template<IntType T, bool S>
    TIntVector2<T, S> operator&(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_and<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator&(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_and<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator|(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_or<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator|(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_or<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator^(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_xor<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator^(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_xor<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator<<(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_left_shift<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator<<(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_left_shift<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator>>(TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_right_shift<T, S>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator>>(TIntVector2<T, S>& v1, T s)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_right_shift<T, S>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool S>
    TIntVector2<T, S> operator~(TIntVector2<T, S>& v1)
    {
        TIntVector2<T, S> r;
        Detail::compute_ivec2_bnot<T, S>::map(r, v1);
        return r;
    }



    // Comparision

    template<IntType T, bool S>
    bool operator==(const TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        return Detail::compute_ivec2_eq<T, S>::map(v1, v2);
    }

    template<IntType T, bool S>
    bool operator!=(const TIntVector2<T, S>& v1, const TIntVector2<T, S>& v2)
    {
        return Detail::compute_ivec2_ieq<T, S>::map(v1, v2);
    }



    // Inc- / Decrement


    template<IntType T, bool S>
    TIntVector2<T, S>& operator++(TIntVector2<T, S>& v1)
    {
        Detail::compute_ivec2_inc<T, S>::map(v1, v1);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator--(TIntVector2<T, S>& v1)
    {
        Detail::compute_ivec2_dec<T, S>::map(v1, v1);
        return v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator++(TIntVector2<T, S>& v1, int)
    {
        return ++v1;
    }

    template<IntType T, bool S>
    TIntVector2<T, S>& operator--(TIntVector2<T, S>& v1, int)
    {
        return --v1;
    }
}
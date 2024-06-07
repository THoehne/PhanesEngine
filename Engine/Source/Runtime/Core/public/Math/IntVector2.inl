#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/IntVector2Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<IntType T, bool A>
    TIntVector2<T, A>::TIntVector2(const TIntVector2<T, A>& v)
    {
        Detail::construct_ivec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, v);
    }

    template<IntType T, bool A>
    TIntVector2<T, A>::TIntVector2(const T _x, const T _y)
    {
        Detail::construct_ivec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, _x, _y);
    }

    template<IntType T, bool A>
    TIntVector2<T, A>::TIntVector2(const T s)
    {
        Detail::construct_ivec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, s);
    }

    template<IntType T, bool A>
    TIntVector2<T, A>::TIntVector2(const T* comp)
    {
        Detail::construct_ivec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, comp);
    }




    template<IntType T, bool A>
    TIntVector2<T, A> operator+=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator+=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator-=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator-=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator*=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator*=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator/=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator/=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator%=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_mod<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator%=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_mod<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }


    template<IntType T, bool A>
    TIntVector2<T, A> operator+(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator+(TIntVector2<T, A>& v1, T s)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator-(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator-(TIntVector2<T, A>& v1, T s)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator*(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator*(TIntVector2<T, A>& v1, T s)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator/(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator/(TIntVector2<T, A>& v1, T s)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator%(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_mod<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator%(TIntVector2<T, A>& v1, T s)
    {
        TIntVector2<T, A> r;
        Detail::compute_ivec2_mod<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }




    // Bitwise operators

    template<IntType T, bool A>
    TIntVector2<T, A> operator&=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_and<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator&=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_and<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator|=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_or<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator|=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_or<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator^=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_xor<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator^=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_xor<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator<<=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_left_shift<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator<<=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_left_shift<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator>>=(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::compute_ivec2_right_shift<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator>>=(TIntVector2<T, A>& v1, T s)
    {
        Detail::compute_ivec2_right_shift<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }



    template<IntType T, bool A>
    TIntVector2<T, A> operator&(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_and<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator&(TIntVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_and<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator|(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_or<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator|(TIntVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_or<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator^(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_xor<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator^(TIntVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_xor<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator<<(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_left_shift<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator<<(TIntVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_left_shift<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator>>(TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_right_shift<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator>>(TIntVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_right_shift<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector2<T, A> operator~(TIntVector2<T, A>& v1)
    {
        TVector2<T, A> r;
        Detail::compute_ivec2_bnot<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1);
        return r;
    }



    // Comparision

    template<IntType T, bool A>
    bool operator==(const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        return Detail::compute_ivec2_eq<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v2);
    }

    template<IntType T, bool A>
    bool operator!=(const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        return Detail::compute_ivec2_ieq<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v2);
    }



    // Inc- / Decrement


    template<IntType T, bool A>
    TIntVector2<T, A>& operator++(TIntVector2<T, A>& v1)
    {
        Detail::compute_ivec2_inc<T, SIMD::use_simd<T, 2, A>::value>::map(v1);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A>& operator--(TIntVector2<T, A>& v1)
    {
        Detail::compute_ivec2_inc<T, SIMD::use_simd<T, 2, A>::value>::map(v1);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A>& operator++(TIntVector2<T, A>& v1, int)
    {
        return ++v1;
    }

    template<IntType T, bool A>
    TIntVector2<T, A>& operator--(TIntVector2<T, A>& v1, int)
    {
        return --v1;
    }
}
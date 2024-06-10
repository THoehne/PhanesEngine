#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/IntVector4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<IntType T, bool A>
    TIntVector4<T, A>::TIntVector4(const TIntVector4<T, A>& v)
    {
        Detail::construct_ivec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, v);
    }

    template<IntType T, bool A>
    TIntVector4<T, A>::TIntVector4(const T _x, const T _y, const T _z, const T _w)
    {
        Detail::construct_ivec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, _x, _y, _z, _w);
    }

    template<IntType T, bool A>
    TIntVector4<T, A>::TIntVector4(const T s)
    {
        Detail::construct_ivec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, s);
    }

    template<IntType T, bool A>
    TIntVector4<T, A>::TIntVector4(const T* comp)
    {
        Detail::construct_ivec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, comp);
    }

    template<IntType T, bool A>
    TIntVector4<T, A>::TIntVector4(const TIntVector2<T, A>& v1, const TIntVector2<T, A>& v2)
    {
        Detail::construct_ivec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, v1, v2);
    }




    template<IntType T, bool A>
    TIntVector4<T, A> operator+=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator+=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator-=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator-=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator*=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator*=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator/=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator/=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator%=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_mod<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator%=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_mod<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }


    template<IntType T, bool A>
    TIntVector4<T, A> operator+(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator+(TIntVector4<T, A>& v1, T s)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator-(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator-(TIntVector4<T, A>& v1, T s)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator*(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator*(TIntVector4<T, A>& v1, T s)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator/(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator/(TIntVector4<T, A>& v1, T s)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator%(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_mod<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator%(TIntVector4<T, A>& v1, T s)
    {
        TIntVector4<T, A> r;
        Detail::compute_ivec4_mod<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }




    // Bitwise operators

    template<IntType T, bool A>
    TIntVector4<T, A> operator&=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_and<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator&=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_and<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator|=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_or<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator|=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_or<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator^=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_xor<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator^=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_xor<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator<<=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_left_shift<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator<<=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_left_shift<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator>>=(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        Detail::compute_ivec4_right_shift<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator>>=(TIntVector4<T, A>& v1, T s)
    {
        Detail::compute_ivec4_right_shift<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }



    template<IntType T, bool A>
    TIntVector4<T, A> operator&(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_and<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator&(TIntVector4<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_and<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator|(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_or<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator|(TIntVector4<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_or<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator^(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_xor<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator^(TIntVector4<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_xor<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator<<(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_left_shift<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator<<(TIntVector4<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_left_shift<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator>>(TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_right_shift<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator>>(TIntVector4<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_right_shift<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<IntType T, bool A>
    TIntVector4<T, A> operator~(TIntVector4<T, A>& v1)
    {
        TVector2<T, A> r;
        Detail::compute_ivec4_bnot<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1);
        return r;
    }



    // Comparision

    template<IntType T, bool A>
    bool operator==(const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        return Detail::compute_ivec4_eq<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v2);
    }

    template<IntType T, bool A>
    bool operator!=(const TIntVector4<T, A>& v1, const TIntVector4<T, A>& v2)
    {
        return Detail::compute_ivec4_ieq<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v2);
    }



    // Inc- / Decrement


    template<IntType T, bool A>
    TIntVector4<T, A>& operator++(TIntVector4<T, A>& v1)
    {
        Detail::compute_ivec4_inc<T, SIMD::use_simd<T, 4, A>::value>::map(v1);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A>& operator--(TIntVector4<T, A>& v1)
    {
        Detail::compute_ivec4_inc<T, SIMD::use_simd<T, 4, A>::value>::map(v1);
        return v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A>& operator++(TIntVector4<T, A>& v1, int)
    {
        return ++v1;
    }

    template<IntType T, bool A>
    TIntVector4<T, A>& operator--(TIntVector4<T, A>& v1, int)
    {
        return --v1;
    }
}
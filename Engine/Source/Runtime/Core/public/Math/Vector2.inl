#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector2Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"



namespace Phanes::Core::Math
{
    template<RealType T, bool A>
    TVector2<T, A>::TVector2(const TVector2<Real, A>& v)
    {
        Detail::construct_vec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, v);
    }

    template<RealType T, bool A>
    TVector2<T, A>::TVector2(Real _x, Real _y)
    {
        Detail::construct_vec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, _x, _y);
    }

    template<RealType T, bool A>
    TVector2<T, A>::TVector2(Real s)
    {
        Detail::construct_vec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, s);
    }

    template<RealType T, bool A>
    TVector2<T, A>::TVector2(const Real* comp)
    {
        Detail::construct_vec2<T, SIMD::use_simd<T, 2, A>::value>::map(*this, comp);
    }




    template<RealType T, bool A>
    TVector2<T, A> operator+=(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        Detail::compute_vec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator+=(TVector2<T, A>& v1, T s)
    {
        Detail::compute_vec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator-=(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        Detail::compute_vec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator-=(TVector2<T, A>& v1, T s)
    {
        Detail::compute_vec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator*=(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        Detail::compute_vec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator*=(TVector2<T, A>& v1, T s)
    {
        Detail::compute_vec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator/=(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        Detail::compute_vec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator/=(TVector2<T, A>& v1, T s)
    {
        Detail::compute_vec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator+(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator+(TVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_add<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator-(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator-(TVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_sub<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator*(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator*(TVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_mul<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator/(TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector2<T, A> operator/(TVector2<T, A>& v1, T s)
    {
        TVector2<T, A> r;
        Detail::compute_vec2_div<T, SIMD::use_simd<T, 2, A>::value>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool A>
    bool operator==(const TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        return Detail::compute_vec2_eq<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v2);
    }

    template<RealType T, bool A>
    bool operator!=(const TVector2<T, A>& v1, const TVector2<T, A>& v2)
    {
        return Detail::compute_vec2_ieq<T, SIMD::use_simd<T, 2, A>::value>::map(v1, v2);
    }



    // Inc- / Decrement


    template<RealType T, bool A>
    TVector2<T, A>& operator++(TVector2<T, A>& v1)
    {
        Detail::compute_vec2_inc<T, SIMD::use_simd<T, 2, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A>& operator--(TVector2<T, A>& v1)
    {
        Detail::compute_vec2_inc<T, SIMD::use_simd<T, 2, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector2<T, A>& operator++(TVector2<T, A>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool A>
    TVector2<T, A>& operator--(TVector2<T, A>& v1, int)
    {
        return --v1;
    }
}
#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"


#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<RealType T, bool A>
    TVector4<T, A>::TVector4(const TVector4<Real, A>& v)
    {
        Detail::construct_vec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, v);
    }

    template<RealType T, bool A>
    TVector4<T, A>::TVector4(Real _x, Real _y, Real _z, Real _w) 
    {
        Detail::construct_vec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, _x, _y, _z, _w);
    }

    template<RealType T, bool A>
    Phanes::Core::Math::TVector4<T, A>::TVector4(Real s)
    {
        Detail::construct_vec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, s);
    }

    template<RealType T, bool A>
    Phanes::Core::Math::TVector4<T, A>::TVector4(const TVector2<Real, A>& v1, const TVector2<Real, A>& v2)
    {
        Detail::construct_vec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, v1, v2);
    }

    template<RealType T, bool A>
    Phanes::Core::Math::TVector4<T, A>::TVector4(const Real* comp)
    {
        Detail::construct_vec4<T, SIMD::use_simd<T, 4, A>::value>::map(*this, comp);
    }


    template<RealType T, bool A>
    TVector4<T, A> operator+=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r; 
        Detail::compute_vec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_add<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_sub<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_mul<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_div<T, SIMD::use_simd<T, 4, A>::value>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool A>
    bool operator==(const TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        return Detail::compute_vec4_eq<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v2);
    }

    template<RealType T, bool A>
    bool operator!=(const TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        return Detail::compute_vec4_ieq<T, SIMD::use_simd<T, 4, A>::value>::map(v1, v2);
    }

    
    
    // Inc- / Decrement


    template<RealType T, bool A>
    TVector4<T, A>& operator++(TVector4<T, A>& v1)
    {
        Detail::compute_vec4_inc<T, SIMD::use_simd<T, 4, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A>& operator--(TVector4<T, A>& v1)
    {
        Detail::compute_vec4_dec<T, SIMD::use_simd<T, 4, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A>& operator++(TVector4<T, A>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool A>
    TVector4<T, A>& operator--(TVector4<T, A>& v1, int)
    {
        return --v1;
    }
}
#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector4Decl.inl"
#include "Core/public/Math/Vector4.hpp"

#include <stdio.h>

namespace Phanes::Core::Math
{
    template<RealType T, bool A>
    TVector4<T, A>::TVector4(const TVector4<Real, A>& v) :
        x(v.x),
        y(v.y),
        z(v.z),
        w(v.w)
    {}

    template<RealType T, bool A>
    TVector4<T, A>::TVector4(Real _x, Real _y, Real _z, Real _w) :
        x(_x),
        y(_y),
        z(_z),
        w(_w)
    {}

    template<RealType T, bool A>
    TVector4<T, A> operator+=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_add<T, A>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_add<T, A>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_sub<T, A>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_sub<T, A>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_mul<T, A>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_mul<T, A>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/=(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        Detail::compute_vec4_div<T, A>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/=(TVector4<T, A>& v1, T s)
    {
        Detail::compute_vec4_div<T, A>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r; 
        Detail::compute_vec4_add<T, A>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator+(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_add<T, A>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_sub<T, A>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator-(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_sub<T, A>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_mul<T, A>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator*(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_mul<T, A>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/(TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_div<T, A>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector4<T, A> operator/(TVector4<T, A>& v1, T s)
    {
        TVector4<T, A> r;
        Detail::compute_vec4_div<T, A>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool A>
    TVector4<T, A> operator==(const TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        return Detail::compute_vec4_eq<T, A>::map(v1, v2);
    }

    template<RealType T, bool A>
    TVector4<T, A> operator!=(const TVector4<T, A>& v1, const TVector4<T, A>& v2)
    {
        return Detail::compute_vec4_ieq<T, A>::map(v1, v2);
    }




    // SIMD


    template<>
    TVector4<float, true>::TVector4(Real _x, Real _y, Real _z, Real _w) :
        x(_x),
        y(_y),
        z(_z),
        w(_w)
    {
        this->comp = _mm_load_ps(reinterpret_cast<float*>(&x));
    }
}
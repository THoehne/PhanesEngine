#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/Vector4.hpp"


#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

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
    Phanes::Core::Math::TVector4<T, A>::TVector4(Real s) :
        x(s),
        y(s),
        z(s),
        w(s)
    {}

    template<RealType T, bool A>
    Phanes::Core::Math::TVector4<T, A>::TVector4(const TVector2<Real>& v1, const TVector2<Real>& v2) :
        x(v1.x),
        y(v1.y),
        z(v2.x),
        w(v2.y)
    {}

    template<RealType T, bool A>
    Phanes::Core::Math::TVector4<T, A>::TVector4(const Real* comp) :
        x(comp[0]),
        y(comp[1]),
        z(comp[2]),
        w(comp[3])
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

    
    
    // Inc- / Decrement


    template<RealType T, bool A>
    TVector4<T, A>& operator++(TVector4<T, A>& v1)
    {
        ++v1.x;
        ++v1.y;
        ++v1.z;
        ++v1.w;

        return v1;
    }

    template<RealType T, bool A>
    TVector4<T, A>& operator--(TVector4<T, A>& v1)
    {
        --v1.x;
        --v1.y;
        --v1.z;
        --v1.w;

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


    // SIMD constructor

    template<>
    TVector4<float, true>::TVector4(const TVector4<float, true>& v)
    {
        this->comp = _mm_load_ps(reinterpret_cast<const float*>(&v));
    }

    template<>
    TVector4<float, true>::TVector4(float _x, float _y, float _z, float _w) :
        x(_x),
        y(_y),
        z(_z),
        w(_w)
    {
        this->comp = _mm_load_ps(reinterpret_cast<float*>(&this->x));
    }

    template<>
    TVector4<float, true>::TVector4(float s)
    {
        this->comp = _mm_load_ps1(&s);
    }

    template<>
    TVector4<float, true>::TVector4(const TVector2<float>& v1, const TVector2<float>& v2) :
        x(v1.x),
        y(v1.y),
        z(v2.x),
        w(v2.y)
    {
        this->comp = _mm_load_ps(reinterpret_cast<float*>(&this->x));
    }

    template<>
    TVector4<float, true>::TVector4(const float* comp) :
        x(comp[0]),
        y(comp[1]),
        z(comp[2]),
        w(comp[3])
    {
        this->comp = _mm_load_ps(reinterpret_cast<float*>(&this->x));
    }
}
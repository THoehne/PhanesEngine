#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"


#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    TVector4<T, S>::TVector4(const TVector4<Real, S>& v)
    {
        Detail::construct_vec4<T, S>::map(*this, v);
    }

    template<RealType T, bool S>
    TVector4<T, S>::TVector4(Real _x, Real _y, Real _z, Real _w) 
    {
        Detail::construct_vec4<T, S>::map(*this, _x, _y, _z, _w);
    }

    template<RealType T, bool S>
    Phanes::Core::Math::TVector4<T, S>::TVector4(Real s)
    {
        Detail::construct_vec4<T, S>::map(*this, s);
    }

    template<RealType T, bool S>
    Phanes::Core::Math::TVector4<T, S>::TVector4(const TVector2<Real, S>& v1, const TVector2<Real, S>& v2)
    {
        Detail::construct_vec4<T, S>::map(*this, v1, v2);
    }

    template<RealType T, bool S>
    Phanes::Core::Math::TVector4<T, S>::TVector4(const Real* comp)
    {
        Detail::construct_vec4<T, S>::map(*this, comp);
    }


    template<RealType T, bool S>
    TVector4<T, S> operator+=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator+=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator-=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator-=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator*=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator*=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator/=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator/=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_div<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator+(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r; 
        Detail::compute_vec4_add<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator+(const TVector4<T, S>& v1, T s)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_add<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator-(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_sub<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator-(const TVector4<T, S>& v1, T s)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_sub<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator*(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_mul<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator*(const TVector4<T, S>& v1, T s)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_mul<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator/(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_div<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S> operator/(const TVector4<T, S>& v1, T s)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_div<T, S>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool S>
    bool operator==(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        return Detail::compute_vec4_eq<T, S>::map(v1, v2);
    }

    template<RealType T, bool S>
    bool operator!=(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        return Detail::compute_vec4_ieq<T, S>::map(v1, v2);
    }

    
    
    // Inc- / Decrement


    template<RealType T, bool S>
    TVector4<T, S>& operator++(TVector4<T, S>& v1)
    {
        Detail::compute_vec4_inc<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator--(TVector4<T, S>& v1)
    {
        Detail::compute_vec4_dec<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator++(TVector4<T, S>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator--(TVector4<T, S>& v1, int)
    {
        return --v1;
    }

    template<RealType T>
    T DotP(const TVector4<T, true>& v1, const TVector4<T, true>& v2)
    {
        return vec4_dot_cvtf32(v1.data, v2.data);
    }
}
#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"


#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
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
        static_assert(sizeof(comp) >= sizeof(T) * 4, "Size of comp has to be of at least four (4) components.");
        Detail::construct_vec4<T, S>::map(*this, comp);
    }

    template<RealType T, bool S>
    Phanes::Core::Math::TVector4<T, S>::TVector4(const TVector3<T, S>& v, T w)
    {
        Detail::construct_vec4<T, S>::map(*this, v, w);
    }


    template<RealType T, bool S>
    TVector4<T, S>& operator+=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator+=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator-=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator-=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator*=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator*=(TVector4<T, S>& v1, T s)
    {
        Detail::compute_vec4_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator/=(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S>& operator/=(TVector4<T, S>& v1, T s)
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
    TVector4<T, S> operator-(T s, const TVector4<T, S>& v1)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_sub<T, S>::map(r, s, v1);
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

    template<RealType T, bool S>
    TVector4<T, S> operator/(T s, const TVector4<T, S>& v1)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_div<T, S>::map(r, s, v1);
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

    template<RealType T, bool S>
    T DotP(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        return Detail::compute_vec4_dotp<T, S> ::map(v1, v2);
    }

    template<RealType T, bool S>
    TVector4<T, S>& Set(TVector4<T, S>& v1, T x, T y, T z, T w)
    {
        Detail::compute_vec4_set<T, S>::map(v1, x, y, z, w);
    }

    template<RealType T, bool S>
    T Magnitude(const TVector4<T, S>& v)
    {
        return Detail::compute_vec4_mag<T, S>::map(v);
    }

    template<RealType T, bool S>
    T SqrMagnitude(const TVector4<T, S>& v)
    {
        return Detail::compute_vec4_dotp<T, S>::map(v, v);
    }

    template<RealType T, bool S>
    TVector4<T, S> Max(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_max<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S>& MaxV(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_max<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> Min(const TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_min<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S>& MinV(TVector4<T, S>& v1, const TVector4<T, S>& v2)
    {
        Detail::compute_vec4_min<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector4<T, S> PerspectiveDivide(const TVector4<T, S>& v1)
    {
        TVector4<T, S> r;
        Detail::compute_vec4_pdiv<T, S>::map(r, v1);
        return r;
    }

    template<RealType T, bool S>
    TVector4<T, S>& PerspectiveDivideV(TVector4<T, S>& v1)
    {
        Detail::compute_vec4_pdiv<T, S>::map(v1, v1);
        return v1;
    }
}
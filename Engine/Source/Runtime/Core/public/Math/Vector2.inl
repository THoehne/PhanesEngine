#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector2Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"



namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    TVector2<T, S>::TVector2(const TVector2<Real, S>& v)
    {
        Detail::construct_vec2<T, S>::map(*this, v);
    }

    template<RealType T, bool S>
    TVector2<T, S>::TVector2(Real _x, Real _y)
    {
        Detail::construct_vec2<T, S>::map(*this, _x, _y);
    }

    template<RealType T, bool S>
    TVector2<T, S>::TVector2(Real s)
    {
        Detail::construct_vec2<T, S>::map(*this, s);
    }

    template<RealType T, bool S>
    TVector2<T, S>::TVector2(const Real* comp)
    {
        Detail::construct_vec2<T, S>::map(*this, comp);
    }




    template<RealType T, bool S>
    TVector2<T, S> operator+=(TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        Detail::compute_vec2_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator+=(TVector2<T, S>& v1, T s)
    {
        Detail::compute_vec2_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator-=(TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        Detail::compute_vec2_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator-=(TVector2<T, S>& v1, T s)
    {
        Detail::compute_vec2_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator*=(TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        Detail::compute_vec2_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator*=(TVector2<T, S>& v1, T s)
    {
        Detail::compute_vec2_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator/=(TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        Detail::compute_vec2_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator/=(TVector2<T, S>& v1, T s)
    {
        Detail::compute_vec2_div<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator+(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_add<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator+(const TVector2<T, S>& v1, T s)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_add<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator-(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_sub<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator-(const TVector2<T, S>& v1, T s)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_sub<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator*(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_mul<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator*(const TVector2<T, S>& v1, T s)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_mul<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator/(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_div<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector2<T, S> operator/(const TVector2<T, S>& v1, T s)
    {
        TVector2<T, S> r;
        Detail::compute_vec2_div<T, S>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool S>
    bool operator==(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        return Detail::compute_vec2_eq<T, S>::map(v1, v2);
    }

    template<RealType T, bool S>
    bool operator!=(const TVector2<T, S>& v1, const TVector2<T, S>& v2)
    {
        return Detail::compute_vec2_ieq<T, S>::map(v1, v2);
    }



    // Inc- / Decrement


    template<RealType T, bool S>
    TVector2<T, S>& operator++(TVector2<T, S>& v1)
    {
        Detail::compute_vec2_inc<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S>& operator--(TVector2<T, S>& v1)
    {
        Detail::compute_vec2_inc<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector2<T, S>& operator++(TVector2<T, S>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool S>
    TVector2<T, S>& operator--(TVector2<T, S>& v1, int)
    {
        return --v1;
    }



}
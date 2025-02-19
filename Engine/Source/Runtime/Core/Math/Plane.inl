#pragma once

#include "Core/Math/Boilerplate.h"

#include "Core/Math/Detail/PlaneDecl.inl"
#include "Core/Math/SIMD/SIMDIntrinsics.h"

#include "Core/Math/SIMD/PhanesSIMDTypes.h"



namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    TPlane<T, S>::TPlane(const TVector3<T, S>& normal, Real d)
    {
        Detail::construct_plane<T, S>::map(*this, normal, d);
    }

    template<RealType T, bool S>
    TPlane<T, S>::TPlane(const TVector3<T, S>& normal, const TVector3<T, S>& base)
    {
        Detail::construct_plane<T, S>::map(*this, normal, base);
    }

    template<RealType T, bool S>
    TPlane<T, S>::TPlane(Real x, Real y, Real z, Real d)
    {
        Detail::construct_plane<T, S>::map(*this, x, y, z, d);
    }

    template<RealType T, bool S>
    TPlane<T, S>::TPlane(const TVector3<T, S>& p1, const TVector3<T, S>& p2, const TVector3<T, S>& p3)
    {
        Detail::construct_plane<T, S>::map(*this, p1, p2, p3);
    }



    template<RealType T, bool S>
    TPlane<T, S> operator+=(TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        Detail::compute_plane_add(pl1, pl1, pl2);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator+=(TPlane<T, S>& pl1, T s)
    {
        Detail::compute_plane_add(pl1, pl1, s);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator+(const TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        TPlane<T, S> r;
        Detail::compute_plane_add(r, pl1, pl2);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator+(const TPlane<T, S>& pl1, T s)
    {
        TPlane<T, S> r;
        Detail::compute_plane_add(r, pl1, s);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator-=(TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        Detail::compute_plane_sub(pl1, pl1, pl2);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator-=(TPlane<T, S>& pl1, T s)
    {
        Detail::compute_plane_sub(pl1, pl1, s);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator-(const TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        TPlane<T, S> r;
        Detail::compute_plane_sub(r, pl1, pl2);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator-(const TPlane<T, S>& pl1, T s)
    {
        TPlane<T, S> r;
        Detail::compute_plane_sub(r, pl1, s);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator*=(TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        Detail::compute_plane_mul(pl1, pl1, pl2);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator*=(TPlane<T, S>& pl1, T s)
    {
        Detail::compute_plane_mul(pl1, pl1, s);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator*(const TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        TPlane<T, S> r;
        Detail::compute_plane_mul(r, pl1, pl2);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator*(const TPlane<T, S>& pl1, T s)
    {
        TPlane<T, S> r;
        Detail::compute_plane_mul(r, pl1, s);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator/=(TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        Detail::compute_plane_div(pl1, pl1, pl2);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator/=(TPlane<T, S>& pl1, T s)
    {
        Detail::compute_plane_div(pl1, pl1, s);
        return pl1;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator/(const TPlane<T, S>& pl1, const TPlane<T, S>& pl2)
    {
        TPlane<T, S> r;
        Detail::compute_plane_sub(r, pl1, pl2);
        return r;
    }

    template<RealType T, bool S>
    TPlane<T, S> operator/(const TPlane<T, S>& pl1, T s)
    {
        TPlane<T, S> r;
        Detail::compute_plane_sub(r, pl1, s);
        return r;
    }
}
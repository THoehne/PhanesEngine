#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector3Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"



namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    TVector3<T, S>::TVector3(const TVector3<Real, S>& v)
    {
        Detail::construct_vec3<T, S>::map(*this, v);
    }

    template<RealType T, bool S>
    TVector3<T, S>::TVector3(Real _x, Real _y, Real _z)
    {
        Detail::construct_vec3<T, S>::map(*this, _x, _y, _z);
    }

    template<RealType T, bool S>
    TVector3<T, S>::TVector3(Real s)
    {
        Detail::construct_vec3<T, S>::map(*this, s);
    }

    template<RealType T, bool S>
    TVector3<T, S>::TVector3(const TVector2<Real, S>& v1, Real s)
    {
        Detail::construct_vec3<T, S>::map(*this, v1, s);
    }

    template<RealType T, bool S>
    TVector3<T, S>::TVector3(const Real* comp)
    {
        Detail::construct_vec3<T, S>::map(*this, comp);
    }




    template<RealType T, bool S>
    TVector3<T, S> operator+=(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        Detail::compute_vec3_add<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator+=(TVector3<T, S>& v1, T s)
    {
        Detail::compute_vec3_add<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator-=(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        Detail::compute_vec3_sub<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator-=(TVector3<T, S>& v1, T s)
    {
        Detail::compute_vec3_sub<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator*=(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        Detail::compute_vec3_mul<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator*=(TVector3<T, S>& v1, T s)
    {
        Detail::compute_vec3_mul<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator/=(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        Detail::compute_vec3_div<T, S>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator/=(TVector3<T, S>& v1, T s)
    {
        Detail::compute_vec3_div<T, S>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator+(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_add<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator+(const TVector3<T, S>& v1, T s)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_add<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator-(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_sub<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator-(const TVector3<T, S>& v1, T s)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_sub<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator*(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_mul<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator*(const TVector3<T, S>& v1, T s)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_mul<T, S>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator/(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_div<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator/(const TVector3<T, S>& v1, T s)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_div<T, S>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool S>
    bool operator==(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return Detail::compute_vec3_eq<T, S>::map(v1, v2);
    }

    template<RealType T, bool S>
    bool operator!=(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        return Detail::compute_vec3_ieq<T, S>::map(v1, v2);
    }



    // Inc- / Decrement


    template<RealType T, bool S>
    TVector3<T, S>& operator++(TVector3<T, S>& v1)
    {
        Detail::compute_vec3_inc<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S>& operator--(TVector3<T, S>& v1)
    {
        Detail::compute_vec3_inc<T, S>::map(v1);
        return v1;
    }

    template<RealType T, bool S>
    TVector3<T, S>& operator++(TVector3<T, S>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool S>
    TVector3<T, S>& operator--(TVector3<T, S>& v1, int)
    {
        return --v1;
    }


    // Other

    template<RealType T, bool S>
    TVector3<T, S> CrossP(const TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        TVector3<T, S> r;
        Detail::compute_vec3_cross_p<T, S>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> CrossPV(TVector3<T, S>& v1, const TVector3<T, S>& v2)
    {
        Detail::compute_vec3_cross_p<T, S>::map(v1, v1, v2);
        return v1;
    }
}
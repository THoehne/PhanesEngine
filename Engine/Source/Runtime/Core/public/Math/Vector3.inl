#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Vector3Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"



namespace Phanes::Core::Math
{
    template<RealType T, bool A>
    TVector3<T, A>::TVector3(const TVector3<Real, A>& v)
    {
        Detail::construct_vec3<T, SIMD::use_simd<T, 3, A>::value>::map(*this, v);
    }

    template<RealType T, bool A>
    TVector3<T, A>::TVector3(Real _x, Real _y, Real _z)
    {
        Detail::construct_vec3<T, SIMD::use_simd<T, 3, A>::value>::map(*this, _x, _y, _z);
    }

    template<RealType T, bool A>
    TVector3<T, A>::TVector3(Real s)
    {
        Detail::construct_vec3<T, SIMD::use_simd<T, 3, A>::value>::map(*this, s);
    }

    template<RealType T, bool A>
    TVector3<T, A>::TVector3(const TVector2<Real, A>& v1, Real s)
    {
        Detail::construct_vec3<T, SIMD::use_simd<T, 3, A>::value>::map(*this, v1, s);
    }

    template<RealType T, bool A>
    TVector3<T, A>::TVector3(const Real* comp)
    {
        Detail::construct_vec3<T, SIMD::use_simd<T, 3, A>::value>::map(*this, comp);
    }




    template<RealType T, bool A>
    TVector3<T, A> operator+=(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        Detail::compute_vec3_add<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator+=(TVector3<T, A>& v1, T s)
    {
        Detail::compute_vec3_add<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator-=(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        Detail::compute_vec3_sub<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator-=(TVector3<T, A>& v1, T s)
    {
        Detail::compute_vec3_sub<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator*=(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        Detail::compute_vec3_mul<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator*=(TVector3<T, A>& v1, T s)
    {
        Detail::compute_vec3_mul<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator/=(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        Detail::compute_vec3_div<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, v2);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator/=(TVector3<T, A>& v1, T s)
    {
        Detail::compute_vec3_div<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v1, s);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator+(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_add<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator+(TVector3<T, A>& v1, T s)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_add<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator-(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_sub<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator-(TVector3<T, A>& v1, T s)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_sub<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator*(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_mul<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator*(TVector3<T, A>& v1, T s)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_mul<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, s);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator/(TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_div<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, v2);
        return r;
    }

    template<RealType T, bool A>
    TVector3<T, A> operator/(TVector3<T, A>& v1, T s)
    {
        TVector3<T, A> r;
        Detail::compute_vec3_div<T, SIMD::use_simd<T, 3, A>::value>::map(r, v1, s);
        return r;
    }

    // Comparision

    template<RealType T, bool A>
    bool operator==(const TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        return Detail::compute_vec3_eq<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v2);
    }

    template<RealType T, bool A>
    bool operator!=(const TVector3<T, A>& v1, const TVector3<T, A>& v2)
    {
        return Detail::compute_vec3_ieq<T, SIMD::use_simd<T, 3, A>::value>::map(v1, v2);
    }



    // Inc- / Decrement


    template<RealType T, bool A>
    TVector3<T, A>& operator++(TVector3<T, A>& v1)
    {
        Detail::compute_vec3_inc<T, SIMD::use_simd<T, 3, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A>& operator--(TVector3<T, A>& v1)
    {
        Detail::compute_vec3_inc<T, SIMD::use_simd<T, 3, A>::value>::map(v1);
        return v1;
    }

    template<RealType T, bool A>
    TVector3<T, A>& operator++(TVector3<T, A>& v1, int)
    {
        return ++v1;
    }

    template<RealType T, bool A>
    TVector3<T, A>& operator--(TVector3<T, A>& v1, int)
    {
        return --v1;
    }
}
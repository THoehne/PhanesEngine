#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Matrix3Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"

namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    TMatrix3<T, S> TransposeV(TMatrix3<T, S>& m)
    {
        Detail::compute_mat3_transpose<T, S>::map(m, m);
        return m;
    }

    template<RealType T, bool S>
    TMatrix3<T, S> Transpose(const TMatrix3<T, S>& m)
    {
        TMatrix3<T, S> r;
        Detail::compute_mat3_transpose<T, S>::map(r, m);
        return r;
        
    }

    template<RealType T, bool S>
    TMatrix3<T, S> operator*= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        TMatrix3<T, S> r;
        Detail::compute_mat3_mul<T, S>::map(r, m1, m2);
        return (m1 = r);
    }

    template<RealType T, bool S>
    TMatrix3<T, S> operator* (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        TMatrix3<T, S> r;
        Detail::compute_mat3_mul<T, S>::map(r, m1, m2);
        return r;
    }

    template<RealType T, bool S>
    TVector3<T, S> operator* (const TMatrix3<T, S>& m1, const TVector3<T, S>& v)
    {
        TVector3<T, S> r;
        Detail::compute_mat3_mul<T, S>::map(r, m1, v);
        return r;
    }
}
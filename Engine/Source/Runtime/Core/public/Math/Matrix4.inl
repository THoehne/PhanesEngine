#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/Detail/Matrix4Decl.inl"
#include "Core/public/Math/SIMD/SIMDIntrinsics.h"

#include "Core/public/Math/SIMD/PhanesSIMDTypes.h"


namespace Phanes::Core::Math
{
    template<RealType T, bool S>
    T Determinant(const TMatrix4<T, S>& m)
    {
        return Detail::compute_mat4_det<T, S>::map(m);
    }

    template<RealType T, bool S>
    bool InverseV(TMatrix4<T, S>& a)
    {
        return Detail::compute_mat4_inv<T, S>::map(a, a);
    }

    template<RealType T, bool S>
    TMatrix4<T, S> TransposeV(TMatrix4<T, S>& a)
    {
        return Detail::compute_mat4_transpose<T, S>::map(a, a);
    }

    template<RealType T, bool S>
    bool Inverse(TMatrix4<T, S>& a)
    {
        TMatrix4<T, S> r;
        return Detail::compute_mat4_inv<T, S>::map(r, a);
        return r;
    }

    template<RealType T, bool S>
    TMatrix4<T, S> Transpose(TMatrix4<T, S>& a)
    {
        TMatrix4<T, S> r;
        return Detail::compute_mat4_transpose<T, S>::map(r, a);
        return r;
    }
}
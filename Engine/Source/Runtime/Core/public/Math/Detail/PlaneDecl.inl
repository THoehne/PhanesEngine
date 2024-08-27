#pragma once

#include "Core/public/Math/Boilerplate.h"

namespace Phanes::Core::Math::Detail
{
    template<RealType T, bool S>
    struct construct_plane {};

    template<RealType T, bool S>
    struct compute_plane_add {};

    template<RealType T, bool S>
    struct compute_plane_sub {};

    template<RealType T, bool S>
    struct compute_plane_mul {};

    template<RealType T, bool S>
    struct compute_plane_div {};

    

    template<RealType T>
    struct construct_plane<T, false>
    {
        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1)
        {
            r.comp = std::copy(pl1.comp);
        }

        static constexpr void map(TPlane<T, false>& r, TPlane<T, false>&& pl1)
        {
            r.comp = std::move(pl1.comp);
        }

        static constexpr void map(TPlane<T, false>& r, const TVector3<T, false>& normal, T d)
        {
            r.normal = normal;
            r.d = d;
        }

        static constexpr void map(TPlane<T, false>& r, const TVector3<T, false>& normal, const TVector3<T, false>& base)
        {
            r.normal = std::copy(normal);
            r.d = DotP(r.normal, base);
        }

        static constexpr void map(TPlane<T, false>& r, T x, T y, T z, T d)
        {
            r.normal = TVector3<T, false>(x, y, z);
            r.d = d;
        }

        static constexpr void map(TPlane<T, false>& r, const TVector3<T, false>& v1, const TVector3<T, false>& v2, const TVector3<T, false>& v3)
        {
            r.normal = Normalize(CrossP(v1, v2));
            r.d = DotP(r.normal, v3);
        }
    };

    template<RealType T>
    struct compute_plane_add<T, false> 
    {
        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, const TPlane<T, false>& pl2)
        {
            r.comp = pl1.comp + pl2.comp;
        }

        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, T s)
        {
            r.comp = pl1.comp + s;
        }
    };

    template<RealType T>
    struct compute_plane_sub<T, false>
    {
        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, const TPlane<T, false>& pl2)
        {
            r.comp = pl1.comp - pl2.comp;
        }

        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, T s)
        {
            r.comp = pl1.comp - s;
        }
    };

    template<RealType T>
    struct compute_plane_mul<T, false>
    {
        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, const TPlane<T, false>& pl2)
        {
            r.comp = pl1.comp * pl2.comp;
        }

        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, T s)
        {
            r.comp = pl1.comp * s;
        }
    };
    template<RealType T>
    struct compute_plane_div<T, false>
    {
        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, const TPlane<T, false>& pl2)
        {
            r.comp = pl1.comp / pl2.comp;
        }

        static constexpr void map(TPlane<T, false>& r, const TPlane<T, false>& pl1, T s)
        {
            r.comp = pl1.comp / s;
        }
    };
}
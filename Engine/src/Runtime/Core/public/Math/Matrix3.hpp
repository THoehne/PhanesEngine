#pragma once

#include "Core/public/Misc/Boilerplate.h"

#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/Vector3.hpp"

#ifndef MATRIX3_H
#define MATRIX3_H

namespace Phanes::Core::Math {


    // 3x3 Matrix defined in column-major order.
    // Accessed by M[Row][Col].

    template<RealType T>
    struct alignas(9) TMatrix3
    {
    public:

        alignas(9) T m[3][3];


    public:

        TMatrix3() = default;

        /**
         * Copy constructor.
         */

        TMatrix3(const TMatrix3<T>& m1)
        {
            memcpy(this->m, m1.m, sizeof(T) * 9);
        }

        /**
         * Move constructor.
         */

        TMatrix3(TMatrix3<T>&& m)
        {
            this->m = m.m;
            m.m = nullptr;
        }

        /**
         * Construct Matrix from 2d array.
         *
         * @param(fields) 2D Array with column major order.
         */

        TMatrix3(T fields[2][2])
        {
            this->m[0][0] = fields[0][0]; this->m[1][0] = fields[1][0]; this->[2][0] = fields[2][0];
            this->m[0][1] = fields[0][1]; this->m[1][1] = fields[1][1]; this->[2][1] = fields[2][1];
            this->m[0][2] = fields[0][2]; this->m[1][2] = fields[1][2]; this->[2][2] = fields[2][2];
        }

        /**
         * Construct Matrix from parameters.
         *
         * @param(n00) M[0][0]
         * @param(n10) M[1][0]
         * @param(n01) M[0][1]
         * @param(n11) M[1][1]
         *
         * @note nXY = n[Row][Col]
         */

        TMatrix3(T n00, T n01, T n02,
                 T n10, T n11, T n12,
                 T n20, T n21, T n22)
        {
            this->m[0][0] = n00; this->m[1][0] = n01; this->[2][0] = n02;
            this->m[1][0] = n10; this->m[1][1] = n11; this->[2][1] = n12;
            this->m[1][2] = n20; this->m[1][2] = n21; this->[2][2] = n22;
        }

        /**
         * Construct Matrix from two 2d vector columns.
         *
         * @param(v1) Column zero
         * @param(v2) Column one
         */

        TMatrix3(const TVector3<T>& v1, const TVector3<T>& v2, const TVector3<T> v3)
        {
            this->m[0][0] = v1.x; this->m[1][0] = v2.x; this->[2][0] = v3.x;
            this->m[0][1] = v1.y; this->m[1][1] = v2.y; this->[2][1] = v3.y;
            this->m[0][2] = v1.z; this->m[1][2] = v2.z; this->[2][2] = v3.z;
        }

    public:

        FORCEINLINE T& operator() (int n, int m)
        {
            return this->[m][n];
        }

        FORCEINLINE TVector3<T>& operator[] (int m)
        {
            return reinterpret_cast<TVector2<T>*>(this->m[m]);
        }

        FORCEINLINE const T& operator() (int n, int m) const
        {
            return this->[m][n];
        }

        FORCEINLINE const TVector3<T>& operator[] (int m) const
        {
            return reinterpret_cast<const TVector2<T>*>(this->m[m]);
        }

    };


    // ==================== //
    //   Matrix3 operator   //
    // ==================== //

    /**
     * Adds scalar to matrix componentwise
     * 
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator+= (TMatrix3<T>& m, T s)
    {
        m(0, 0) += s; m(0, 1) += s; m(0, 2) += s;
        m(1, 0) += s; m(1, 1) += s; m(1, 2) += s;
        m(2, 0) += s; m(2, 1) += s; m(2, 2) += s;

        return m1;
    }

    /**
     * Adds matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TMatrix3<T> operator+= (TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        m1(0, 0) += m2(0, 0); m1(0, 1) += m2(0, 1); m1(0, 2) += m2(0, 2);
        m1(1, 0) += m2(1, 0); m1(1, 1) += m2(1, 1); m1(1, 2) += m2(1, 2);
        m1(2, 0) += m2(2, 0); m1(2, 1) += m2(2, 1); m1(2, 2) += m2(2, 2);

        return m1;
    }

    /**
     * Substract scalar from matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator-= (TMatrix3<T>& a, T s)
    {
        m(0, 0) -= s; m(0, 1) -= s; m(0, 2) -= s;
        m(1, 0) -= s; m(1, 1) -= s; m(1, 2) -= s;
        m(2, 0) -= s; m(2, 1) -= s; m(2, 2) -= s;

        return m1;
    }

    /**
     * Substract matrix from matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TMatrix3<T> operator-= (TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        m1(0, 0) -= m2(0, 0); m1(0, 1) -= m2(0, 1); m1(0, 2) -= m2(0, 2);
        m1(1, 0) -= m2(1, 0); m1(1, 1) -= m2(1, 1); m1(1, 2) -= m2(1, 2);
        m1(2, 0) -= m2(2, 0); m1(2, 1) -= m2(2, 1); m1(2, 2) -= m2(2, 2);

        return m1;
    }

    /**
     * Multiply matrix with scalar
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator*= (TMatrix3<T>& m, T s)
    {
        m(0, 0) *= s; m(0, 1) *= s; m(0, 2) *= s;
        m(1, 0) *= s; m(1, 1) *= s; m(1, 2) *= s;
        m(2, 0) *= s; m(2, 1) *= s; m(2, 2) *= s;

        return m1;
    }

    /**
     * Matrix on matrix multiplication
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TMatrix3<T> operator*= (TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        TMatrix3<T> c = a;
        m1(0, 0) = c(0, 0) * m2(0, 0) + c(0, 1) * m2(1, 0) + c(0, 2) * m2(2, 0);
        m1(0, 1) = c(0, 0) * m2(0, 1) + c(0, 1) * m2(1, 1) + c(0, 2) * m2(2, 1);
        m1(0, 2) = c(0, 0) * m2(0, 2) + c(0, 1) * m2(1, 2) + c(0, 2) * m2(2, 2);

        m1(1, 0) = c(1, 0) * m2(0, 0) + c(1, 1) * m2(1, 0) + c(1, 2) * m2(2, 0);
        m1(1, 1) = c(1, 0) * m2(0, 1) + c(1, 1) * m2(1, 1) + c(1, 2) * m2(2, 1);
        m1(1, 2) = c(1, 0) * m2(0, 2) + c(1, 1) * m2(1, 2) + c(1, 2) * m2(2, 2);

        m1(2, 0) = c(2, 0) * m2(0, 0) + c(2, 1) * m2(1, 0) + c(2, 2) * m2(2, 0);
        m1(2, 1) = c(2, 0) * m2(0, 1) + c(2, 1) * m2(1, 1) + c(2, 2) * m2(2, 1);
        m1(2, 2) = c(2, 0) * m2(0, 2) + c(2, 1) * m2(1, 2) + c(2, 2) * m2(2, 2);

        return m1;
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator+ (const TMatrix3<T>& m, T s)
    {
        return TMatrix3<T>(m(0, 0) + s, m(0, 1) + s, m(0, 2) + s,
                           m(1, 0) + s, m(1, 1) + s, m(1, 2) + s,
                           m(2, 0) + s, m(2, 1) + s, m(2, 2) + s);
    }

    /**
     * Add matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TMatrix3<T> operator+ (const TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        return TMatrix2<T>(m1(0, 0) + m2(0, 0), m1(0, 1) + m2(0, 1), m1(0, 2) + m2(0, 2),
                           m1(1, 0) + m2(1, 0), m1(1, 1) + m2(1, 1), m1(1, 2) + m2(1, 2),
                           m1(2, 0) + m2(2, 0), m1(2, 1) + m2(2, 1), m1(2, 2) + m2(2, 2));
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator- (const TMatrix3<T>& m, T s)
    {
        return TMatrix3<T>(m(0, 0) - s, m(0, 1) - s, m(0, 2) - s,
                           m(1, 0) - s, m(1, 1) - s, m(1, 2) - s,
                           m(2, 0) - s, m(2, 1) - s, m(2, 2) - s);
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator- (const TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        return TMatrix3<T>(m1(0, 0) - m2(0, 0), m1(0, 1) - m2(0, 1), m1(0, 2) - m2(0, 2),
                           m1(1, 0) - m2(1, 0), m1(1, 1) - m2(1, 1), m1(1, 2) - m2(1, 2),
                           m1(2, 0) - m2(2, 0), m1(2, 1) - m2(2, 1), m1(2, 2) - m2(2, 2));
    }

    /**
     * Multiply scalar with matrix
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T>
    TMatrix3<T> operator* (const TMatrix3<T>& m, float s)
    {
        return TMatrix3<T>(m(0, 0) * s, m(0, 1) * s, m(0, 2) * s,
                           m(1, 0) * s, m(1, 1) * s, m(1, 2) * s,
                           m(2, 0) * s, m(2, 1) * s, m(2, 2) * s);
    }

    /**
     * Multiplay matrix by matrix
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TMatrix3<T> operator* (const TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        return TMatrix3<T>(m1(0, 0) * m2(0, 0) + m1(0, 1) * m2(1, 0) + m1(0, 2) * m2(2, 0),
                           m1(0, 0) * m2(0, 1) + m1(0, 1) * m2(1, 1) + m1(0, 2) * m2(2, 1),
                           m1(0, 0) * m2(0, 2) + m1(0, 1) * m2(1, 2) + m1(0, 2) * m2(2, 2),

                           m1(1, 0) * m2(0, 0) + m1(1, 1) * m2(1, 0) + m1(1, 2) * m2(2, 0),
                           m1(1, 0) * m2(0, 1) + m1(1, 1) * m2(1, 1) + m1(1, 2) * m2(2, 1),
                           m1(1, 0) * m2(0, 2) + m1(1, 1) * m2(1, 2) + m1(1, 2) * m2(2, 2),

                           m1(2, 0) * m2(0, 0) + m1(2, 1) * m2(1, 0) + m1(2, 2) * m2(2, 0),
                           m1(2, 0) * m2(0, 1) + m1(2, 1) * m2(1, 1) + m1(2, 2) * m2(2, 1),
                           m1(2, 0) * m2(0, 2) + m1(2, 1) * m2(1, 2) + m1(2, 2) * m2(2, 2));
    }

    /**
     * Add matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    TVector3<T> operator* (const TMatrix3<T>& m1, const TVector3<T>& v)
    {
        return TVector3<T>(m1(0, 0) * v.x + m1(0, 1) * v.y + m1(0, 2) * v.z,
                           m1(1, 0) * v.x + m1(1, 1) * v.y + m1(1, 2) * v.z,
                           m1(2, 0) * v.x + m1(2, 1) * v.y + m1(2, 2) * v.z);
    }

    /**
     * Compare matrix with other matrix.
     * 
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    bool operator== (const TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        return (m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2]);
    }

    /**
     * Compare matrix with other matrix.
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T>
    bool operator!= (const TMatrix3<T>& m1, const TMatrix3<T>& m2)
    {
        return (m1[0] != m2[0] || m1[1] != m2[1] || m1[2] != m2[2]);
    }


    // =============================== //
    //   Matrix function definition    //
    // =============================== //

    /**
     * Calculate determinant of 3x3 Matrix
     * 
     * @param(m1) Matrix
     */
    
    template<RealType T>
    T Determinant(const TMatrix3<T>& m1)
    {
        return   m1(0, 0) * (m1(1, 1) * m1(2, 2) - m1(1, 2) * m1(2, 1))
               - m1(0, 1) * (m1(1, 0) * m1(2, 2) - m1(1, 2) * m1(2, 0))
               + m1(0, 2) * (m1(1, 0) * m1(2, 1) - m1(1, 1) * m1(2, 0));
    }

    /**
     * Calculate inverse of 3x3 Matrix
     *
     * @see [FUNC]Inverse
     * 
     * @param(m1) Matrix
     * 
     * @note Stores result in m1.
     */

    template<RealType T>
    TMatrix3<T> InverseV(TMatrix3<T>& m1)
    {
        const TVector3<T>& v0 = m1[0];
        const TVector3<T>& v1 = m1[1];
        const TVector3<T>& v2 = m1[2];

        TVector3<T> r0 = CrossP(v1, v2);
        TVector3<T> r1 = CrossP(v2, v0);
        TVector3<T> r2 = CrossP(v0, v1);

        T _1_det = (T)1.0 / determinant(m1);

        m1 = TMatrix3<T>(r0.x, r0.y, r0.z,
                        r1.x, r1.y, r1.z,
                        r2.x, r2.y, r2.z);

        m1 *= _1_det;

        return m1;
    }

    /**
     * Get transpose of matrix.
     * 
     * @param(m1) Matrix
     * 
     * @note Result is stored in m1;
     */

    template<RealType T>
    TMatrix3<T> TransposeV(TMatrix3<T>& m1)
    {
        Swap(m1(0, 1), m1(1, 0));
        Swap(m1(0, 2), m1(2, 0));
        Swap(m1(1, 2), m1(2, 1));

        return m1;
    }


    // =============== //
    //   WITH RETURN   //
    // =============== //

    /**
     * Calculate inverse of 3x3 Matrix
     *
     * @param(m1) Matrix
     */

    template<RealType T>
    TMatrix3<T> Inverse(TMatrix3<T>& m1)
    {
        const TVector3<T>& v0 = m1[0];
        const TVector3<T>& v1 = m1[1];
        const TVector3<T>& v2 = m1[2];

        TVector3<T> r0 = CrossP(v1, v2);
        TVector3<T> r1 = CrossP(v2, v0);
        TVector3<T> r2 = CrossP(v0, v1);

        T _1_det = (T)1.0 / determinant(m1);

        TMatrix3<T> inverse(r0.x, r0.y, r0.z,
            r1.x, r1.y, r1.z,
            r2.x, r2.y, r2.z);

        inverse *= _1_det;

        return inverse;
    }

    /**
     * Get transpose of matrix.
     *
     * @param(m1) Matrix
     *
     * @note Result is stored in m1;
     */

    template<RealType T>
    TMatrix3<T> Transpose(const TMatrix3<T>& m1)
    {
        return TMatrix3<T>(m1(0, 0), m1(1, 0), m1(2, 0),
                           m1(0, 1), m1(1, 1), m1(2, 1),
                           m1(0, 2), m1(1, 2), m1(2, 2));
    }
    
    /**
     * Checks if matrix is an identity matrix.
     */

    template<RealType T>
    bool IsIndentityMatrix(const TMatrix3<T>& m1)
    {
        return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC && abs(m1(0, 1) - (T)1.0) < P_FLT_INAC && abs(m1(0, 2) - (T)1.0) < P_FLT_INAC &&
                abs(m1(1, 0) - (T)1.0) < P_FLT_INAC && abs(m1(1, 1) - (T)1.0) < P_FLT_INAC && abs(m1(1, 2) - (T)1.0) < P_FLT_INAC &&
                abs(m1(2, 0) - (T)1.0) < P_FLT_INAC && abs(m1(2, 1) - (T)1.0) < P_FLT_INAC && abs(m1(2, 2) - (T)1.0) < P_FLT_INAC);
    }

} // Phanes::Core::Math


#endif // !MATRIX3_H

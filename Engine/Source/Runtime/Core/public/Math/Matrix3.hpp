#pragma once

#include "Core/public/Math/Boilerplate.h"

#include "Core/public/Math/MathAbstractTypes.h"
#include "Core/public/Math/MathFwd.h"
#include "Core/public/Math/Vector3.hpp"

#ifndef MATRIX3_H
#define MATRIX3_H

namespace Phanes::Core::Math {


    // 3x3 Matrix defined in column-major order.
    // Accessed by M[Row][Col].


    template<RealType T, bool S>
    struct TMatrix3
    {
    public:

        union
        {
            struct
            {
                /// <summary>
                /// Column one.
                /// </summary>
                TVector3<T, S> c0;

                /// <summary>
                /// Column two.
                /// </summary>
                TVector3<T, S> c1;

                /// <summary>
                /// Column three.
                /// </summary>
                TVector3<T, S> c2;
            };
            
            T data[3][4];
        };



    public:

        TMatrix3() = default;
        
        TMatrix3(TMatrix3<T, S>&& m)
            : c0(std::move(m.c0)), c1(std::move(m.c1)), c2(std::move(m.c2))
        {};

        TMatrix3(const TMatrix3<T, S>& m)
            : c0(m.c0), c1(m.c1), c2(m.c2)
        {};

        /**
         * Construct Matrix from 2d array.
         *
         * @param(fields) 2D Array with row major order.
         */

        TMatrix3(T fields[3][3])
        {
            this->c0 = TVector3<T, S>(fields[0][0], fields[1][0], fields[2][0]);
            this->c1 = TVector3<T, S>(fields[0][1], fields[1][1], fields[2][1]);
            this->c2 = TVector3<T, S>(fields[0][2], fields[1][2], fields[2][2]);
        }

        /**
         * Construct Matrix from parameters.
         *
         * @param(n00) M[0][0]
         * @param(n10) M[0][1]
         * @param(n20) M[0][2]
         * @param(n01) M[1][0]
         * ...
         *
         * @note nXY = n[Row][Col]
         */

        TMatrix3(T n00, T n01, T n02,
                 T n10, T n11, T n12,
                 T n20, T n21, T n22)
        {
            this->c0 = TVector3<T, S>(n00,n10,n20);
            this->c1 = TVector3<T, S>(n01,n11,n21);
            this->c2 = TVector3<T, S>(n02,n12,n22);
        }

        /**
         * Construct Matrix from two 2d vector columns.
         *
         * @param(v1) Column zero
         * @param(v2) Column one
         */

        TMatrix3(const TVector3<T, S>& v1, const TVector3<T, S>& v2, const TVector3<T, S> v3)
        {
            this->c0 = v1;
            this->c1 = v2;
            this->c2 = v3;
        }

        TMatrix3<T, S>& operator= (TMatrix3<T, S>&& m)
        {
            if (this != &m)
            {
                this->c0 = std::move(m.c0);
                this->c1 = std::move(m.c1);
                this->c2 = std::move(m.c2);
            }
            return *this;
        }

        TMatrix3<T, S>& operator= (const TMatrix3<T, S>& m)
        {
            if (this != &m)
            {
                this->c0 = m.c0;
                this->c1 = m.c1;
                this->c2 = m.c2;
            }
            return *this;
        }

    public:

        FORCEINLINE T operator() (int n, int m) const
        {
            return this->data[m][n];
        }

        FORCEINLINE T& operator() (int n, int m)
        {
            return this->data[m][n];
        }

        FORCEINLINE TVector3<T, S>& operator[] (int m)
        {
            return (*reinterpret_cast<TVector3<T, S>*>(this->data[m]));
        }

        FORCEINLINE const TVector3<T, S> operator[] (int m) const
        {
            return (*reinterpret_cast<TVector3<T, S>*>(this->data[m]));
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

    template<RealType T, bool S>
    TMatrix3<T, S>& operator+= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 += s;
        m1.c1 += s;
        m1.c2 += s;

        return m1;
    }

    /**
     * Adds matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator+= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 += m2.c0;
        m1.c1 += m2.c1;
        m1.c2 += m2.c2;

        return m1;
    }

    /**
     * Substract scalar from matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator-= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 -= s;
        m1.c1 -= s;
        m1.c2 -= s;

        return m1;
    }

    /**
     * Substract matrix from matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator-= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 -= m2.c0;
        m1.c1 -= m2.c1;
        m1.c2 -= m2.c2;

        return m1;
    }

    /**
     * Multiply matrix with scalar
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator*= (TMatrix3<T, S>& m1, T s)
    {
        m1.c0 *= s;
        m1.c1 *= s;
        m1.c2 *= s;

        return m1;
    }

    /**
     * Matrix on matrix (componentwise)
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator*= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2);

    /**
     * Multiply matrix with scalar
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator/= (TMatrix3<T, S>& m1, T s)
    {
        s = (T)1.0 / s;
        m1.c0 *= s;
        m1.c1 *= s;
        m1.c2 *= s;

        return m1;
    }

    /**
     * Matrix on matrix (componentwise)
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S>& operator/= (TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        m1.c0 /= m2.c0;
        m1.c1 /= m2.c1;
        m1.c2 /= m2.c2;

        return m1;
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+ (const TMatrix3<T, S>& m, T s)
    {
        return TMatrix3<T, S>(m.c0 + s,
                              m.c1 + s,
                              m.c2 + s);
    }

    /**
     * Add matrix to matrix componentwise
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator+ (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return TMatrix3<T, S>(m1.c0 + m2.c0,
                              m1.c1 + m2.c1,
                              m1.c2 + m2.c2);
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator- (const TMatrix3<T, S>& m, T s)
    {
        return TMatrix3<T, S>(m.c0 - s,
                              m.c1 - s,
                              m.c2 - s);
    }

    /**
     * Add scalar to matrix componentwise
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator- (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return TMatrix3<T, S>(m1.c0 - m2.c0,
                              m1.c1 - m2.c1,
                              m1.c2 - m2.c2);
    }

    /**
     * Multiply scalar with matrix
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator* (const TMatrix3<T, S>& m, float s)
    {
        return TMatrix3<T, S>(m.c0 * s,
                              m.c1 * s,
                              m.c2 * s);
    }

    /**
     * Multiply scalar with matrix
     *
     * @param(m) Matrix
     * @param(s) Scalar
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator/ (const TMatrix3<T, S>& m, float s)
    {
        s = (T)1.0 / s;
        return TMatrix3<T, S>(m.c0 * s,
                              m.c1 * s,
                              m.c2 * s);
    }

    /**
     * Multiplay matrix by matrix (componentwise)
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    TMatrix3<T, S> operator* (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2);

    template<RealType T, bool S>
    TVector3<T, S> operator* (const TMatrix3<T, S>& m1, const TVector3<T, S>& v);

    /**
     * Compare matrix with other matrix.
     * 
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    bool operator== (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return (m1.c0 == m2.c0 && m1.c1 == m2.c1 && m1.c2 == m2.c2);
    }

    /**
     * Compare matrix with other matrix.
     *
     * @param(m1) Matrix
     * @param(m2) Matrix
     */

    template<RealType T, bool S>
    bool operator!= (const TMatrix3<T, S>& m1, const TMatrix3<T, S>& m2)
    {
        return (m1.c0 != m2.c0 || m1.c1 != m2.c1 || m1.c2 != m2.c2);
    }


    // =============================== //
    //   Matrix function definition    //
    // =============================== //

    /**
     * Calculate determinant of 3x3 Matrix
     * 
     * @param(m1) Matrix
     */
    
    template<RealType T, bool S>
    T Determinant(const TMatrix3<T, S>& m1)
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

    template<RealType T, bool S>
    bool InverseV(TMatrix3<T, S>& m1)
    {
        // Rows of inversed matrix
        TVector3<T, S> r0 = CrossP(m1.c1, m1.c2);
        TVector3<T, S> r1 = CrossP(m1.c2, m1.c0);
        TVector3<T, S> r2 = CrossP(m1.c0, m1.c1);

        T _1_det = (T)1.0 / Determinant(m1);

        if (_1_det == (T)0.0)
        {
            return false;
        }

        // Store matrix transposed
        m1 = TMatrix3<T, S>(r0.x, r0.y, r0.z,
                            r1.x, r1.y, r1.z,
                            r2.x, r2.y, r2.z);

        m1 *= _1_det;

        return true;
    }

    /**
     * Get transpose of matrix.
     * 
     * @param(m1) Matrix
     * 
     * @note Result is stored in m1;
     */

    template<RealType T, bool S>
    TMatrix3<T, S> TransposeV(TMatrix3<T, S>& m1);


    // =============== //
    //   WITH RETURN   //
    // =============== //

    /**
     * Calculate inverse of 3x3 Matrix
     *
     * @param(m1) Matrix
     */

    template<RealType T, bool S>
    bool Inverse(const TMatrix3<T, S>& m1, Ref<TMatrix3<T, S>> r)
    {
        // r is a row-major matrix.
        TMatrix3<T, S> row;
        row[0] = CrossP(m1.c1, m1.c2);
        row[1] = CrossP(m1.c2, m1.c0);
        row[2] = CrossP(m1.c0, m1.c1);

        T _1_det = (T)1.0 / Determinant(m1);

        if (Phanes::Core::Math::Equals(_1_det, (T)0.0))
        {
            return false;
        }

        row *= _1_det;

        // Store matrix transposed.
        (*r).data[0][0] = row.data[0][0]; (*r).data[1][0] = row.data[0][1]; (*r).data[2][0] = row.data[0][2];
        (*r).data[0][1] = row.data[1][0]; (*r).data[1][1] = row.data[1][1]; (*r).data[2][1] = row.data[1][2];
        (*r).data[0][2] = row.data[2][0]; (*r).data[1][2] = row.data[2][1]; (*r).data[2][2] = row.data[2][2];

        return true;
    }

    /**
     * Get transpose of matrix.
     *
     * @param(m1) Matrix
     *
     * @note Result is stored in m1;
     */

    template<RealType T, bool S>
    TMatrix3<T, S> Transpose(const TMatrix3<T, S>& m1);
    
    /**
     * Checks if matrix is an identity matrix.
     */

    template<RealType T, bool S>
    bool IsIdentityMatrix(const TMatrix3<T, S>& m1)
    {
        return (abs(m1(0, 0) - (T)1.0) < P_FLT_INAC &&       abs(m1(0, 1))          < P_FLT_INAC &&       abs(m1(0, 2))          < P_FLT_INAC &&
                abs(m1(1, 0))          < P_FLT_INAC &&       abs(m1(1, 1) - (T)1.0) < P_FLT_INAC &&       abs(m1(1, 2))          < P_FLT_INAC &&
                abs(m1(2, 0))          < P_FLT_INAC &&       abs(m1(2, 1))          < P_FLT_INAC &&       abs(m1(2, 2) - (T)1.0) < P_FLT_INAC);
    }

} // Phanes::Core::Math


#endif // !MATRIX3_H

#include "Core/public/Math/Matrix3.inl"
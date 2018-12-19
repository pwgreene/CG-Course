//
// Created by Parker Greene on 2018-12-19.
//

#include "Matrix4x4.h"
#include "Matrix3x3.h"

//////////////////////////////
// Accessors
const float& Matrix4x4::operator() (int i, int j) const
{
    //TODO
    return m_elems[0];
}
float& Matrix4x4::operator() (int i, int j)
{
    //TODO
    return m_elems[0];
}
Vector4 Matrix4x4::getRow(int row) const
{
    //TODO
    return Vector4();
}
Vector4 Matrix4x4::getColumn(int col) const
{
    //TODO
    return Vector4();
}

//////////////////////////////
// Matrix Operations
float Matrix4x4::determinant() const
{
    //TODO
    return 0;
}
Matrix4x4 Matrix4x4::inverse() const
{
    Matrix4x4 inv = Matrix4x4();
    inv(0, 0) = m_elems[5]  * m_elems[10] * m_elems[15] -
             m_elems[5]  * m_elems[11] * m_elems[14] -
             m_elems[9]  * m_elems[6]  * m_elems[15] +
             m_elems[9]  * m_elems[7]  * m_elems[14] +
             m_elems[13] * m_elems[6]  * m_elems[11] -
             m_elems[13] * m_elems[7]  * m_elems[10];

    inv(1, 0) = -m_elems[4]  * m_elems[10] * m_elems[15] +
             m_elems[4]  * m_elems[11] * m_elems[14] +
             m_elems[8]  * m_elems[6]  * m_elems[15] -
             m_elems[8]  * m_elems[7]  * m_elems[14] -
             m_elems[12] * m_elems[6]  * m_elems[11] +
             m_elems[12] * m_elems[7]  * m_elems[10];

    inv(2, 0) = m_elems[4]  * m_elems[9] * m_elems[15] -
             m_elems[4]  * m_elems[11] * m_elems[13] -
             m_elems[8]  * m_elems[5] * m_elems[15] +
             m_elems[8]  * m_elems[7] * m_elems[13] +
             m_elems[12] * m_elems[5] * m_elems[11] -
             m_elems[12] * m_elems[7] * m_elems[9];

    inv(3, 0) = -m_elems[4]  * m_elems[9] * m_elems[14] +
              m_elems[4]  * m_elems[10] * m_elems[13] +
              m_elems[8]  * m_elems[5] * m_elems[14] -
              m_elems[8]  * m_elems[6] * m_elems[13] -
              m_elems[12] * m_elems[5] * m_elems[10] +
              m_elems[12] * m_elems[6] * m_elems[9];

    inv(0, 1) = -m_elems[1]  * m_elems[10] * m_elems[15] +
             m_elems[1]  * m_elems[11] * m_elems[14] +
             m_elems[9]  * m_elems[2] * m_elems[15] -
             m_elems[9]  * m_elems[3] * m_elems[14] -
             m_elems[13] * m_elems[2] * m_elems[11] +
             m_elems[13] * m_elems[3] * m_elems[10];

    inv(1, 1) = m_elems[0]  * m_elems[10] * m_elems[15] -
             m_elems[0]  * m_elems[11] * m_elems[14] -
             m_elems[8]  * m_elems[2] * m_elems[15] +
             m_elems[8]  * m_elems[3] * m_elems[14] +
             m_elems[12] * m_elems[2] * m_elems[11] -
             m_elems[12] * m_elems[3] * m_elems[10];

    inv(2, 1) = -m_elems[0]  * m_elems[9] * m_elems[15] +
             m_elems[0]  * m_elems[11] * m_elems[13] +
             m_elems[8]  * m_elems[1] * m_elems[15] -
             m_elems[8]  * m_elems[3] * m_elems[13] -
             m_elems[12] * m_elems[1] * m_elems[11] +
             m_elems[12] * m_elems[3] * m_elems[9];

    inv(3, 1) = m_elems[0]  * m_elems[9] * m_elems[14] -
              m_elems[0]  * m_elems[10] * m_elems[13] -
              m_elems[8]  * m_elems[1] * m_elems[14] +
              m_elems[8]  * m_elems[2] * m_elems[13] +
              m_elems[12] * m_elems[1] * m_elems[10] -
              m_elems[12] * m_elems[2] * m_elems[9];

    inv(0, 2) = m_elems[1]  * m_elems[6] * m_elems[15] -
             m_elems[1]  * m_elems[7] * m_elems[14] -
             m_elems[5]  * m_elems[2] * m_elems[15] +
             m_elems[5]  * m_elems[3] * m_elems[14] +
             m_elems[13] * m_elems[2] * m_elems[7] -
             m_elems[13] * m_elems[3] * m_elems[6];

    inv(1, 2) = -m_elems[0]  * m_elems[6] * m_elems[15] +
             m_elems[0]  * m_elems[7] * m_elems[14] +
             m_elems[4]  * m_elems[2] * m_elems[15] -
             m_elems[4]  * m_elems[3] * m_elems[14] -
             m_elems[12] * m_elems[2] * m_elems[7] +
             m_elems[12] * m_elems[3] * m_elems[6];

    inv(2, 2) = m_elems[0]  * m_elems[5] * m_elems[15] -
              m_elems[0]  * m_elems[7] * m_elems[13] -
              m_elems[4]  * m_elems[1] * m_elems[15] +
              m_elems[4]  * m_elems[3] * m_elems[13] +
              m_elems[12] * m_elems[1] * m_elems[7] -
              m_elems[12] * m_elems[3] * m_elems[5];

    inv(3, 2) = -m_elems[0]  * m_elems[5] * m_elems[14] +
              m_elems[0]  * m_elems[6] * m_elems[13] +
              m_elems[4]  * m_elems[1] * m_elems[14] -
              m_elems[4]  * m_elems[2] * m_elems[13] -
              m_elems[12] * m_elems[1] * m_elems[6] +
              m_elems[12] * m_elems[2] * m_elems[5];

    inv(0, 3) = -m_elems[1] * m_elems[6] * m_elems[11] +
             m_elems[1] * m_elems[7] * m_elems[10] +
             m_elems[5] * m_elems[2] * m_elems[11] -
             m_elems[5] * m_elems[3] * m_elems[10] -
             m_elems[9] * m_elems[2] * m_elems[7] +
             m_elems[9] * m_elems[3] * m_elems[6];

    inv(1, 3) = m_elems[0] * m_elems[6] * m_elems[11] -
             m_elems[0] * m_elems[7] * m_elems[10] -
             m_elems[4] * m_elems[2] * m_elems[11] +
             m_elems[4] * m_elems[3] * m_elems[10] +
             m_elems[8] * m_elems[2] * m_elems[7] -
             m_elems[8] * m_elems[3] * m_elems[6];

    inv(2, 3) = -m_elems[0] * m_elems[5] * m_elems[11] +
              m_elems[0] * m_elems[7] * m_elems[9] +
              m_elems[4] * m_elems[1] * m_elems[11] -
              m_elems[4] * m_elems[3] * m_elems[9] -
              m_elems[8] * m_elems[1] * m_elems[7] +
              m_elems[8] * m_elems[3] * m_elems[5];

    inv(3, 3) = m_elems[0] * m_elems[5] * m_elems[10] -
              m_elems[0] * m_elems[6] * m_elems[9] -
              m_elems[4] * m_elems[1] * m_elems[10] +
              m_elems[4] * m_elems[2] * m_elems[9] +
              m_elems[8] * m_elems[1] * m_elems[6] -
              m_elems[8] * m_elems[2] * m_elems[5];


    float det = m_elems[0] * inv(0, 0)
              + m_elems[1] * inv(1, 0)
              + m_elems[2] * inv(2, 0)
              + m_elems[3] * inv(3, 0);

    float detinv = 1.0 / det;
    return inv * detinv;
}

Matrix4x4 Matrix4x4::transpose() const
{
    //TODO
    return Matrix4x4();
}

//////////////////////////////
// Common Math Operations
Matrix4x4 operator+ (const Matrix4x4 m0, const Matrix4x4 m1)
{
    Matrix4x4 res = Matrix4x4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res(i, j) = m0(i, j) + m1(i, j);
        }
    }
    return res;
}
Matrix4x4 operator- (const Matrix4x4 m0, const Matrix4x4 m1)
{
    Matrix4x4 res = Matrix4x4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res(i, j) = m0(i, j) - m1(i, j);
        }
    }
    return res;
}
Vector4 operator* (const Matrix4x4 m, const Vector4 v)
{
    //TODO
    return Vector4();
}
Matrix4x4 operator* (const Matrix4x4 m0, const Matrix4x4 m1)
{
    //TODO
    return Matrix4x4();
}
Matrix4x4 operator* (const Matrix4x4 m, float f)
{
    Matrix4x4 res = Matrix4x4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res(i, j) = m(i, j) * f;
        }
    }
    return res;
}
Matrix4x4 operator* (float f, const Matrix4x4 m)
{
    return m * f;
}
Matrix4x4 operator/ (const Matrix4x4 m, float f)
{
    Matrix4x4 res = Matrix4x4();
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            res(i, j) = m(i, j) / f;
        }
    }
    return res;
}
bool operator== (const Matrix4x4 m0, const Matrix4x4 m1)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (fabs(m0(i, j) - m1(i, j)) > 1e-6)
                return false;
        }
    }
    return true;
}
bool operator!= (const Matrix4x4 m0, const Matrix4x4 m1)
{
    return !(m0 == m1);
}
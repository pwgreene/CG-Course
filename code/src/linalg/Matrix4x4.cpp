//
// Created by Parker Greene on 2018-12-19.
//

#include "Matrix4x4.h"
#include "Matrix3x3.h"

//////////////////////////////
// Accessors
const float& Matrix4x4::operator() (int i, int j) const
{
    return m_elems[i*4 + j];
}
float& Matrix4x4::operator() (int i, int j)
{
    return m_elems[i*4 + j];
}
Vector4 Matrix4x4::getRow(int row) const
{
    return Vector4(m_elems[row*4], m_elems[row*4 + 1], m_elems[row*4 + 2], m_elems[row*4 + 3]);
}
Vector4 Matrix4x4::getColumn(int col) const
{
    return Vector4(m_elems[col], m_elems[col + 4], m_elems[col + 8], m_elems[col + 12]);
}

//////////////////////////////
// Matrix Operations
float Matrix4x4::determinant() const
{
    //determinants of minors * first row elems
    Matrix3x3 m0 = Matrix3x3(m_elems[5], m_elems[6], m_elems[7],
                             m_elems[9], m_elems[10],m_elems[11],
                             m_elems[13],m_elems[14],m_elems[15]);
    Matrix3x3 m1 = Matrix3x3(m_elems[4], m_elems[6], m_elems[7],
                             m_elems[8], m_elems[10],m_elems[11],
                             m_elems[12],m_elems[14],m_elems[15]);
    Matrix3x3 m2 = Matrix3x3(m_elems[4], m_elems[5], m_elems[7],
                             m_elems[8], m_elems[9],m_elems[11],
                             m_elems[12],m_elems[13],m_elems[15]);
    Matrix3x3 m3 = Matrix3x3(m_elems[4], m_elems[5],m_elems[6],
                             m_elems[8], m_elems[9],m_elems[10],
                             m_elems[12],m_elems[13],m_elems[14]);

    return m_elems[0]*m0.determinant()
         - m_elems[1]*m1.determinant()
         + m_elems[2]*m2.determinant()
         - m_elems[3]*m3.determinant();
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
    return Matrix4x4(m_elems[0], m_elems[4], m_elems[8], m_elems[12],
                     m_elems[1], m_elems[5], m_elems[9], m_elems[13],
                     m_elems[2], m_elems[6], m_elems[10],m_elems[14],
                     m_elems[3], m_elems[7], m_elems[11],m_elems[15]);
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
    return Vector4(Vector4::dot(m.getRow(0), v),
                   Vector4::dot(m.getRow(1), v),
                   Vector4::dot(m.getRow(2), v),
                   Vector4::dot(m.getRow(3), v));
}
Matrix4x4 operator* (const Matrix4x4 m0, const Matrix4x4 m1)
{
    Vector4 col0 = m0 * m1.getColumn(0);
    Vector4 col1 = m0 * m1.getColumn(1);
    Vector4 col2 = m0 * m1.getColumn(2);
    Vector4 col3 = m0 * m1.getColumn(3);
    return Matrix4x4(col0.x(), col1.x(), col2.x(), col3.x(),
                     col0.y(), col1.y(), col2.y(), col3.y(),
                     col0.z(), col1.z(), col2.z(), col3.z(),
                     col0.w(), col1.w(), col2.w(), col3.w());
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
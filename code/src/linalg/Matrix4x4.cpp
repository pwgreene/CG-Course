//
// Created by Parker Greene on 2018-12-19.
//

#include "Matrix4x4.h"

//////////////////////////////
// Accessors
const float& Matrix4x4::operator() (int i, int j) const
{
    //TODO: implement this
    return m_elems[0];
}
float& Matrix4x4::operator() (int i, int j)
{
    //TODO: implement this
    return m_elems[0];
}
Vector4 Matrix4x4::getRow(int row) const
{
    //TODO: implement this
    return Vector4();
}
Vector4 Matrix4x4::getColumn(int col) const
{
    //TODO: implement this
    return Vector4();
}

//////////////////////////////
// Matrix Operations
float Matrix4x4::determinant() const
{
    //TODO: implement this
    return 0;
}
Matrix4x4 Matrix4x4::inverse() const
{
    //TODO: implement this
    return Matrix4x4();
}
Matrix4x4 Matrix4x4::transpose() const
{
    //TODO: implement this
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
    //TODO: implement this
    return Vector4();
}
Matrix4x4 operator* (const Matrix4x4 m0, const Matrix4x4 m1)
{
    //TODO: implement this
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
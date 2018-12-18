#include "Matrix3x3.h"

//////////////////////////////
// Accessors
const float& Matrix3x3::operator() (int i, int j) const
{
    //TODO: return the element at Mij (matrix is row-major)
    return m_elems[0];
}
float& Matrix3x3::operator() (int i, int j)
{
    //TODO: return the element at Mij (matrix is row-major)
    return m_elems[0];
}
Vector3 Matrix3x3::getRow(int row) const
{
    //TODO
    return Vector3();
}
Vector3 Matrix3x3::getColumn(int col) const
{
    //TODO
    return Vector3();
}

//////////////////////////////
// Matrix Operations
float Matrix3x3::determinant() const
{
    //TODO
    return 0;
}
Matrix3x3 Matrix3x3::inverse() const
{
    //TODO
    return Matrix3x3();
}
Matrix3x3 Matrix3x3::transpose() const
{
    //TODO
    return Matrix3x3();
}

//////////////////////////////
// Common Math Operations
Matrix3x3 operator+ (const Matrix3x3 m0, const Matrix3x3 m1)
{
    Matrix3x3 res = Matrix3x3();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res(i, j) = m0(i, j) + m1(i, j);
        }
    }
    return res;
}
Matrix3x3 operator- (const Matrix3x3 m0, const Matrix3x3 m1)
{
    Matrix3x3 res = Matrix3x3();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res(i, j) = m0(i, j) - m1(i, j);
        }
    }
    return res;
}
Vector3 operator* (const Matrix3x3 m, const Vector3 v)
{
    //TODO: implement Matrix-Vector multiplication
    return Vector3();
}
Matrix3x3 operator* (const Matrix3x3 m0, const Matrix3x3 m1)
{
    //TODO: implement Matrix-Matrix multiplication
    //hint : there are 3x3x3=27 total multiplies
    return Matrix3x3();
}
Matrix3x3 operator* (const Matrix3x3 m, float f)
{
    Matrix3x3 res = Matrix3x3();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res(i, j) = m(i, j) * f;
        }
    }
    return res;
}
Matrix3x3 operator* (float f, const Matrix3x3 m)
{
    return m * f;
}
Matrix3x3 operator/ (const Matrix3x3 m, float f)
{
    Matrix3x3 res = Matrix3x3();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            res(i, j) = m(i, j) / f;
        }
    }
    return res;
}
bool operator== (const Matrix3x3 m0, const Matrix3x3 m1)
{
    bool eq = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (fabs(m0(i, j) - m1(i, j)) > 1e-6)
                eq = false;
        }
    }
    return eq;
}
bool operator!= (const Matrix3x3 m0, const Matrix3x3 m1)
{
    return !(m0 == m1);
}

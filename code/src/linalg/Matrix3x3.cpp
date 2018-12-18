#include "Matrix3x3.h"

//////////////////////////////
// Accessors
const float& Matrix3x3::operator() (int i, int j) const
{
    return m_elems[i*3 + j];
}
float& Matrix3x3::operator() (int i, int j)
{
    return m_elems[i*3 + j];
}
Vector3 Matrix3x3::getRow(int row) const
{
    return Vector3(m_elems[row*3], m_elems[row*3 + 1], m_elems[row*3 + 2]);
}
Vector3 Matrix3x3::getColumn(int col) const
{
    return Vector3(m_elems[col], m_elems[col + 3], m_elems[col + 6]);
}

//////////////////////////////
// Matrix Operations
float Matrix3x3::determinant() const
{
    return m_elems[0]*(m_elems[4]*m_elems[8] - m_elems[5]*m_elems[7])  //e00 * (e11*e22 - e12*e21)
         - m_elems[1]*(m_elems[3]*m_elems[8] - m_elems[5]*m_elems[6])  //e01 * (e10*e22 - e12*e20)
         + m_elems[2]*(m_elems[3]*m_elems[7] - m_elems[4]*m_elems[6]); //e02 * (e10*e21 - e11*e20)
}
Matrix3x3 Matrix3x3::inverse() const
{
    Matrix3x3 cofactors = Matrix3x3(m_elems[4]*m_elems[8] - m_elems[5]*m_elems[7],
                                    m_elems[5]*m_elems[6] - m_elems[3]*m_elems[8],
                                    m_elems[3]*m_elems[7] - m_elems[4]*m_elems[6],
                                    m_elems[2]*m_elems[7] - m_elems[1]*m_elems[8],
                                    m_elems[0]*m_elems[8] - m_elems[2]*m_elems[6],
                                    m_elems[1]*m_elems[6] - m_elems[0]*m_elems[7],
                                    m_elems[1]*m_elems[5] - m_elems[2]*m_elems[4],
                                    m_elems[2]*m_elems[3] - m_elems[0]*m_elems[5],
                                    m_elems[0]*m_elems[4] - m_elems[1]*m_elems[3]);

    return 1.0/determinant() * cofactors.transpose();
}
Matrix3x3 Matrix3x3::transpose() const
{
    return Matrix3x3(m_elems[0], m_elems[3], m_elems[6],
                     m_elems[1], m_elems[4], m_elems[7],
                     m_elems[2], m_elems[5], m_elems[8]);
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
    return Vector3(Vector3::dot(m.getRow(0), v), Vector3::dot(m.getRow(1), v), Vector3::dot(m.getRow(2), v));
}
Matrix3x3 operator* (const Matrix3x3 m0, const Matrix3x3 m1)
{
    Vector3 col0 = m0 * m1.getColumn(0);
    Vector3 col1 = m0 * m1.getColumn(1);
    Vector3 col2 = m0 * m1.getColumn(2);
    return Matrix3x3(col0.x(), col1.x(), col2.x(),
                     col0.y(), col1.y(), col2.y(),
                     col0.z(), col1.z(), col2.z());
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

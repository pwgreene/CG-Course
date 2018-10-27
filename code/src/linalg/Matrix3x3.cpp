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

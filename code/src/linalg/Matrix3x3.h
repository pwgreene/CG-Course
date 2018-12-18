#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "Vector3.h"

class Matrix3x3
{
public:
    Matrix3x3()
    {
        for (int i = 0; i < 9; i++)
        {
            m_elems[i] = 0;
        }
    }
    
    Matrix3x3(float e00, float e01, float e02,
              float e10, float e11, float e12,
              float e20, float e21, float e22)
    {
        m_elems[0] = e00; m_elems[1] = e01; m_elems[2] = e02;
        m_elems[3] = e10; m_elems[4] = e11; m_elems[5] = e12;
        m_elems[6] = e20; m_elems[7] = e21; m_elems[8] = e22;
    }
    
    //////////////////////////////
    // Accessors
    const float& operator() (int i, int j) const;
    float& operator() (int i, int j);
    Vector3 getRow(int row) const;
    Vector3 getColumn(int col) const;
    
    //////////////////////////////
    // Matrix Operations
    float determinant() const;
    Matrix3x3 inverse() const;
    Matrix3x3 transpose() const;
    
private:
    float m_elems[9];
};

//////////////////////////////
// Common Math Operations
Matrix3x3 operator+ (const Matrix3x3 m0, const Matrix3x3 m1);
Matrix3x3 operator- (const Matrix3x3 m0, const Matrix3x3 m1);
Vector3 operator* (const Matrix3x3 m, const Vector3 v);
Matrix3x3 operator* (const Matrix3x3 m0, const Matrix3x3 m1);
Matrix3x3 operator* (const Matrix3x3 m, float f);
Matrix3x3 operator* (float f, const Matrix3x3 m);
Matrix3x3 operator/ (const Matrix3x3 m, float f);

bool operator == (const Matrix3x3 m0, const Matrix3x3 m1);
bool operator != (const Matrix3x3 m0, const Matrix3x3 m1);

#endif //MATRIX3X3_H

//
// Created by Parker Greene on 2018-12-19.
//

#ifndef MATRIX4X4_H
#define MATRIX4X4_H

#include "Vector4.h"
#include <string.h>

class Matrix4x4
{
public:
    Matrix4x4()
    {
        memset(m_elems, 0, sizeof(m_elems));
    }

    Matrix4x4(float e00, float e01, float e02, float e03,
              float e10, float e11, float e12, float e13,
              float e20, float e21, float e22, float e23,
              float e30, float e31, float e32, float e33)
    {
        m_elems[0] = e00; m_elems[1] = e01; m_elems[2] = e02; m_elems[3] = e03;
        m_elems[4] = e10; m_elems[5] = e11; m_elems[6] = e12; m_elems[7] = e13;
        m_elems[8] = e20; m_elems[9] = e21; m_elems[10]= e22; m_elems[11]= e23;
        m_elems[12]= e30; m_elems[13]= e31; m_elems[14]= e32; m_elems[15]= e33;
    }

    //////////////////////////////
    // Accessors
    const float& operator() (int i, int j) const;
    float& operator() (int i, int j);
    Vector4 getRow(int row) const;
    Vector4 getColumn(int col) const;

    //////////////////////////////
    // Matrix Operations
    float determinant() const;
    Matrix4x4 inverse() const;
    Matrix4x4 transpose() const;

private:
    float m_elems[16];
};

//////////////////////////////
// Common Math Operations
Matrix4x4 operator+ (const Matrix4x4 m0, const Matrix4x4 m1);
Matrix4x4 operator- (const Matrix4x4 m0, const Matrix4x4 m1);
Vector4 operator* (const Matrix4x4 m, const Vector4 v);
Matrix4x4 operator* (const Matrix4x4 m0, const Matrix4x4 m1);
Matrix4x4 operator* (const Matrix4x4 m, float f);
Matrix4x4 operator* (float f, const Matrix4x4 m);
Matrix4x4 operator/ (const Matrix4x4 m, float f);

bool operator == (const Matrix4x4 m0, const Matrix4x4 m1);
bool operator != (const Matrix4x4 m0, const Matrix4x4 m1);

#endif //MATRIX4X4_H

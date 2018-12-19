//
// Created by Parker Greene on 2018-12-19.
//

#ifndef VECTOR4_H
#define VECTOR4_H

#include <cmath>
#include <assert.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
class Vector4
{
public:
    Vector4()
    {
        memset(m_elems, 0, sizeof(m_elems));
    }

    Vector4(float v1, float v2, float v3, float v4)
    {
        m_elems[0] = v1;
        m_elems[1] = v2;
        m_elems[2] = v3;
        m_elems[3] = v4;
    }

    //////////////////////////////
    // Accessing
    float& operator[](int idx)
    {
        assert(idx < 4 && idx >= 0);
        return m_elems[idx];
    }
    const float& operator[](int idx) const
    {
        assert(idx < 4 && idx >= 0);
        return m_elems[idx];
    }
    float& x() { return m_elems[0]; }
    float& y() { return m_elems[1]; }
    float& z() { return m_elems[2]; }
    float& w() { return m_elems[3]; }
    float x() const { return m_elems[0]; }
    float y() const { return m_elems[1]; }
    float z() const { return m_elems[2]; }
    float w() const { return m_elems[3]; }

    //////////////////////////////
    // Vector Operations
    float magnitude() const;
    void normalize();
    Vector4 normalized() const;

    static float dot( const Vector4& v0, const Vector4& v1);
    static float angle( const Vector4& v0, const Vector4& v1);

private:
    float m_elems[4];
};

//////////////////////////////
// Common Math Operations
Vector4 operator+ (const Vector4& v0, const Vector4& v1);
Vector4 operator- (const Vector4& v0, const Vector4& v1);
Vector4 operator* (const Vector4& v0, const Vector4& v1);
Vector4 operator/ (const Vector4& v0, const Vector4& v1);

// negate
Vector4 operator- (const Vector4& v0);

// multiply/divide by scalar
Vector4 operator* (float f, const Vector4& v0);
Vector4 operator* (const Vector4& v0, float f);
Vector4 operator/ (const Vector4& v0, float f);


#endif //VECTOR4_H

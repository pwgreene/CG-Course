//
// Created by Parker Greene on 2018-12-19.
//

#include "Vector4.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector4::magnitude() const
{
    return sqrtf(m_elems[0]*m_elems[0] + m_elems[1]*m_elems[1] + m_elems[2]*m_elems[2] + m_elems[3]*m_elems[3]);
}

////////////////////////////////////////////////////////////////////////////////
void Vector4::normalize()
{
    float mag = magnitude();
    m_elems[0] /= mag;
    m_elems[1] /= mag;
    m_elems[2] /= mag;
    m_elems[3] /= mag;
}

////////////////////////////////////////////////////////////////////////////////
Vector4 Vector4::normalized() const
{
    float mag = magnitude();
    return Vector4(m_elems[0]/mag, m_elems[1]/mag, m_elems[2]/mag, m_elems[3]/mag);
}

////////////////////////////////////////////////////////////////////////////////
float Vector4::dot( const Vector4& v0, const Vector4& v1)
{
    return v0.x()*v1.x() + v0.y()*v1.y() + v0.z()*v1.z() + v0.w()*v1.w();
}
////////////////////////////////////////////////////////////////////////////////
float Vector4::angle( const Vector4& v0, const Vector4& v1)
{
    return acosf(dot(v0, v1) / (v0.magnitude() * v1.magnitude()));
}

//////////////////////////////
// Common Math Operations

Vector4 operator+ (const Vector4& v0, const Vector4& v1)
{
    return Vector4(v0[0] + v1[0], v0[1] + v1[1], v0[2] + v1[2], v0[3] + v1[3]);
}
Vector4 operator- (const Vector4& v0, const Vector4& v1)
{
    return Vector4(v0[0] - v1[0], v0[1] - v1[1], v0[2] - v1[2], v0[3] - v1[3]);
}
Vector4 operator* (const Vector4& v0, const Vector4& v1)
{
    return Vector4(v0[0] * v1[0], v0[1] * v1[1], v0[2] * v1[2], v0[3] * v1[3]);
}
Vector4 operator/ (const Vector4& v0, const Vector4& v1)
{
    return Vector4(v0[0] / v1[0], v0[1] / v1[1], v0[2] / v1[2], v0[3] * v1[3]);
}

// negate
Vector4 operator- (const Vector4& v0)
{
    return Vector4(-v0[0], -v0[1], -v0[2], -v0[3]);
}

// multiply/divide by scalar
Vector4 operator* (float f, const Vector4& v0)
{
    return Vector4(v0[0] * f, v0[1] * f, v0[2] * f, v0[3] * f);
}
Vector4 operator* (const Vector4& v0, float f)
{
    return f * v0;
}
Vector4 operator/ (const Vector4& v0, float f)
{
    return Vector4(v0[0] / f, v0[1] / f, v0[2] / f, v0[3] / f);
}
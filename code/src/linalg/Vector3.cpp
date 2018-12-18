#include "Vector3.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector3::magnitude() const
{
    return sqrtf(m_elems[0]*m_elems[0] + m_elems[1]*m_elems[1] + m_elems[2]*m_elems[2]);
}

////////////////////////////////////////////////////////////////////////////////
void Vector3::normalize()
{
    float mag = magnitude();
    m_elems[0] /= mag;
    m_elems[1] /= mag;
    m_elems[2] /= mag;
}

////////////////////////////////////////////////////////////////////////////////
Vector3 Vector3::normalized() const
{
    float mag = magnitude();
    return Vector3(m_elems[0]/mag, m_elems[1]/mag, m_elems[2]/mag);
}

////////////////////////////////////////////////////////////////////////////////
float Vector3::dot( const Vector3& v0, const Vector3& v1)
{
    return v0.x() * v1.x() + v0.y() * v1.y() + v0.z() * v1.z();
}
////////////////////////////////////////////////////////////////////////////////
float Vector3::angle( const Vector3& v0, const Vector3& v1)
{
    return acosf(dot(v0, v1) / (v0.magnitude() * v1.magnitude()));
}

////////////////////////////////////////////////////////////////////////////////
Vector3 Vector3::cross( const Vector3& v0, const Vector3& v1)
{
    return Vector3(v0.y()*v1.z() - v0.z()*v1.y(),
                   v0.z()*v1.x() - v0.x()*v1.z(),
                   v0.x()*v1.y() - v0.y()*v1.x());
}

//////////////////////////////
// Common Math Operations

Vector3 operator+ (const Vector3& v0, const Vector3& v1)
{
    return Vector3(v0[0] + v1[0], v0[1] + v1[1], v0[2] + v1[2]);
}
Vector3 operator- (const Vector3& v0, const Vector3& v1)
{
    return Vector3(v0[0] - v1[0], v0[1] - v1[1], v0[2] - v1[2]);
}
Vector3 operator* (const Vector3& v0, const Vector3& v1)
{
    return Vector3(v0[0] * v1[0], v0[1] * v1[1], v0[2] * v1[2]);
}
Vector3 operator/ (const Vector3& v0, const Vector3& v1)
{
    return Vector3(v0[0] / v1[0], v0[1] / v1[1], v0[2] / v1[2]);
}

// negate
Vector3 operator- (const Vector3& v0)
{
    return Vector3(-v0[0], -v0[1], -v0[2]);
}

// multiply/divide by scalar
Vector3 operator* (float f, const Vector3& v0)
{
    return Vector3(v0[0] * f, v0[1] * f, v0[2] * f);
}
Vector3 operator* (const Vector3& v0, float f)
{
    return f * v0;
}
Vector3 operator/ (const Vector3& v0, float f)
{
    return Vector3(v0[0] / f, v0[1] / f, v0[2] / f);
}

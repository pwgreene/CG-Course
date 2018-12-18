#include "Vector2.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector2::magnitude() const
{
    return sqrtf(m_elems[0]*m_elems[0] + m_elems[1]*m_elems[1]);
}

////////////////////////////////////////////////////////////////////////////////
void Vector2::normalize()
{
    float mag = magnitude();
    m_elems[0] /= mag;
    m_elems[1] /= mag;
}

////////////////////////////////////////////////////////////////////////////////
Vector2 Vector2::normalized() const
{
    float mag = magnitude();
    return Vector2(m_elems[0]/mag, m_elems[1]/mag);
}

////////////////////////////////////////////////////////////////////////////////
float Vector2::dot( const Vector2& v0, const Vector2& v1)
{
    return v0.x() * v1.x() + v0.y() * v1.y();
}

////////////////////////////////////////////////////////////////////////////////
float Vector2::angle(const Vector2& v0, const Vector2& v1)
{
    return acosf(dot(v0, v1) / (v0.magnitude() * v1.magnitude()));
}

//////////////////////////////
// Common Math Operations
Vector2 operator+ (const Vector2& v0, const Vector2& v1)
{
    return Vector2(v0[0] + v1[0], v0[1] + v1[1]);
}
Vector2 operator- (const Vector2& v0, const Vector2& v1)
{
    return Vector2(v0[0] - v1[0], v0[1] - v1[1]);
}
Vector2 operator* (const Vector2& v0, const Vector2& v1)
{
    return Vector2(v0[0] * v1[0], v0[1] * v1[1]);
}
Vector2 operator/ (const Vector2& v0, const Vector2& v1)
{
    return Vector2(v0[0] / v1[0], v0[1] / v1[1]);
}

// negate
Vector2 operator- (const Vector2& v0)
{
    return Vector2(-v0[0], -v0[1]);
}

// multiply/divide by scalar
Vector2 operator* (float f, const Vector2& v0)
{
    return Vector2(v0[0] * f, v0[1] * f);
}
Vector2 operator* (const Vector2& v0, float f)
{
    return f * v0;
}
Vector2 operator/ (const Vector2& v0, float f)
{
    return Vector2(v0[0] / f, v0[1] / f );
}

#include "Vector3.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector3::magnitude() const
{
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void Vector3::normalize()
{
    // TODO
    return;
}

////////////////////////////////////////////////////////////////////////////////
Vector3 Vector3::normalized() const
{
    //TODO
    return Vector3();
}

////////////////////////////////////////////////////////////////////////////////
float Vector3::dot( const Vector3& v0, const Vector3& v1)
{
    // TODO
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
float Vector3::angle( const Vector3& v0, const Vector3& v1)
{
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
Vector3 Vector3::cross( const Vector3& v0, const Vector3& v1)
{
    // TODO
    return Vector3();
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

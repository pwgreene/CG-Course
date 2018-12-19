//
// Created by Parker Greene on 2018-12-19.
//

#include "Vector4.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector4::magnitude() const
{
    //TODO
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void Vector4::normalize()
{
    //TODO
}

////////////////////////////////////////////////////////////////////////////////
Vector4 Vector4::normalized() const
{
    //TODO
    return Vector4();
}

////////////////////////////////////////////////////////////////////////////////
float Vector4::dot( const Vector4& v0, const Vector4& v1)
{
    //TODO
    return 0;
}
////////////////////////////////////////////////////////////////////////////////
float Vector4::angle( const Vector4& v0, const Vector4& v1)
{
    //TODO
    return 0;
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
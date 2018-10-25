#include "Vector2.h"

//////////////////////////////
// Vector Operations

////////////////////////////////////////////////////////////////////////////////
float Vector2::magnitude() const
{
    // TODO
    return 0;
}

////////////////////////////////////////////////////////////////////////////////
void Vector2::normalize()
{
    // TODO
    return;
}

////////////////////////////////////////////////////////////////////////////////
Vector2 Vector2::normalized() const
{
    //TODO
    return Vector2();
}

////////////////////////////////////////////////////////////////////////////////
float Vector2::dot( const Vector2& v0, const Vector2& v1)
{
    // TODO
    return 0;
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

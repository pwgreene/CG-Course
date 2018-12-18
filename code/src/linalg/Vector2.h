#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////
class Vector2
{
public:
    Vector2()
    {
        m_elems[0] = 0;
        m_elems[1] = 0;
    }
    Vector2(float v1, float v2)
    {
        m_elems[0] = v1;
        m_elems[1] = v2;
    }
    
    //////////////////////////////
    // Accessing
    float& operator[](int idx)
    {
        assert(idx < 2 && idx >= 0);
        return m_elems[idx];
    }
    const float& operator[](int idx) const
    {
        assert(idx < 2 && idx >= 0);
        return m_elems[idx];
    }
    float& x() { return m_elems[0]; }
    float& y() { return m_elems[1]; }
    float x() const { return m_elems[0]; }
    float y() const { return m_elems[1]; }
    
    
    //////////////////////////////
    // Vector Operations
    float magnitude() const;
    void normalize();
    Vector2 normalized() const;
    
    static float dot(const Vector2& v0, const Vector2& v1);
    static float angle(const Vector2& v0, const Vector2& v1);
    
private:
    float m_elems[2];
};

//////////////////////////////
// Common Math Operations
Vector2 operator+ (const Vector2& v0, const Vector2& v1);
Vector2 operator- (const Vector2& v0, const Vector2& v1);
Vector2 operator* (const Vector2& v0, const Vector2& v1);
Vector2 operator/ (const Vector2& v0, const Vector2& v1);

// negate
Vector2 operator- (const Vector2& v0);

// multiply/divide by scalar
Vector2 operator* (float f, const Vector2& v0);
Vector2 operator* (const Vector2& v0, float f);
Vector2 operator/ (const Vector2& v0, float f);

#endif //VECTOR2_H

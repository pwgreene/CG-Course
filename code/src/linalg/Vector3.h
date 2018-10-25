#include <cmath>
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////
class Vector3
{
public:
    Vector3()
    {
        m_elems[0] = 0;
        m_elems[1] = 0;
        m_elems[2] = 0;
    }
    Vector3(float v1, float v2, float v3)
    {
        m_elems[0] = v1;
        m_elems[1] = v2;
        m_elems[2] = v3;
    }
    
    //////////////////////////////
    // Accessing
    float& operator[](int idx)
    {
        assert(idx < 3 && idx >= 0);
        return m_elems[idx];
    }
    const float& operator[](int idx) const
    {
        assert(idx < 3 && idx >= 0);
        return m_elems[idx];
    }
    float& x() { return m_elems[0]; }
    float& y() { return m_elems[1]; }
    float& z() { return m_elems[2]; }
    float x() const { return m_elems[0]; }
    float y() const { return m_elems[1]; }
    float z() const { return m_elems[2]; }
    
    //////////////////////////////
    // Vector Operations
    float magnitude() const;
    void normalize();
    Vector3 normalized() const;
    
    static float dot( const Vector3& v0, const Vector3& v1);
    static float angle( const Vector3& v0, const Vector3& v1);
    static Vector3 cross( const Vector3& v0, const Vector3& v1);
    
private:
    float m_elems[3];
    float m_eqEpsilon = 1e-6;
};

//////////////////////////////
// Common Math Operations
Vector3 operator+ (const Vector3& v0, const Vector3& v1);
Vector3 operator- (const Vector3& v0, const Vector3& v1);
Vector3 operator* (const Vector3& v0, const Vector3& v1);
Vector3 operator/ (const Vector3& v0, const Vector3& v1);

// negate
Vector3 operator- (const Vector3& v0);

// multiply/divide by scalar
Vector3 operator* (float f, const Vector3& v0);
Vector3 operator* (const Vector3& v0, float f);
Vector3 operator/ (const Vector3& v0, float f);

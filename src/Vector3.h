#ifndef __VECTOR_3_H__
#define __VECTOR_3_H__

#include <math.h>

class Vector3
{
public:
    float x, y, z;

    Vector3()
    {
        x = y = z = 0;
    }

    Vector3(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    void set(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }

    void normalize()
    {
        float norm = (float)sqrt(x * x + y * y + z * z);
        x = x / norm;
        y = y / norm;
        z = z / norm;
    }

    Vector3 operator-(const Vector3 &v)
    {
        Vector3 aux(x - v.x, y - v.y, z - v.z);
        return (aux);
    }

    Vector3 operator+(const Vector3 &v)
    {
        Vector3 aux(x + v.x, y + v.y, z + v.z);
        return (aux);
    }

    Vector3 operator*(float s)
    {
        Vector3 aux(x * s, y * s, z * s);
        return (aux);
    }
};

#endif

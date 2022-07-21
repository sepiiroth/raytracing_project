#ifndef VECTOR_H
#define VECTOR_H
#include "Point.h"

class Vector {
    private:
        float m_x, m_y, m_z;
        float getX() const;
        float getY() const;
        float getZ() const;
        float square();
    public:
        Vector();
        Vector(float x, float y, float z = 0);
        Vector(const Vector &vec);
        Vector(const Point &p);
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        Vector operator+(const Vector &vec);
        Vector &operator+=(const Vector &vec);
        const Vector operator-(const Vector &vec);
        Vector &operator-=(const Vector &vec);
        Vector operator*(float value);
        Vector &operator*=(float value);
        Vector operator/(float value);
        Vector &operator/=(float value);
        Vector &operator=(const Vector &vec);
        Vector &operator=(const Point &point);
        //float operator[](int value) const;
        float& operator[](int value);
        float operator[](int value) const;
        Vector operator-() const;
        Vector cross(const Vector& v1);
        float dot(const Vector &vec);
        float norm();
        Vector normalized();
        void display();


};

/*const Vector operator*(float value, Vector vec)
{
    return vec * value;
}

const Vector operator*=(float value, Vector vec)
{
    vec *= value;
    return vec;
}

const Vector operator-(const Vector &vec1, const Vector &vec2)
{
    Vector v1 = vec1;
    Vector v2 = vec2;
    return v1 - v2;
}*/


#endif // VECTOR_H

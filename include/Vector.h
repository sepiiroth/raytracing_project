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
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        Vector operator+(const Vector &vec);
        Vector &operator+=(const Vector &vec);
        Vector operator-(const Vector &vec);
        Vector &operator-=(const Vector &vec);
        Vector operator*(float value);
        Vector &operator*=(float value);
        Vector operator/(float value);
        Vector &operator/=(float value);
        Vector &operator=(const Vector &vec);
        Vector &operator=(const Point &point);
        float operator[](int value) const;
        Vector operator-();
        float dot(const Vector &vec);
        float norm();
        Vector normalized();
        void display();
};

#endif // VECTOR_H

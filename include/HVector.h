#ifndef HVECTOR_H
#define HVECTOR_H
#include "Vector.h"


class HVector {
    private:
        float m_x, m_y, m_z, m_w;
        float getX() const;
        float getY() const;
        float getZ() const;
        float square();
    public:
        HVector();
        HVector(const Vector& v);
        HVector(float x, float y, float z = 0);
        HVector(const HVector &vec);
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        HVector operator+(const HVector &vec);
        HVector &operator+=(const HVector &vec);
        HVector operator-(const HVector &vec);
        HVector &operator-=(const HVector &vec);
        HVector operator*(float value);
        HVector &operator*=(float value);
        HVector operator/(float value);
        HVector &operator/=(float value);
        HVector &operator=(const HVector &vec);
        float operator[](int value);
        HVector operator-();
        float dot(const HVector &vec);
        float norm();
        HVector normalized();
        void display();
};
#endif // HVECTOR_H

#ifndef VECTOR3_H
#define VECTOR3_H

/*Classe mère de: Point, Vector, Color, HPoint, HVector */
class Vector3 {
    protected:
        float m_x, m_y, m_z;
        float square();
    public:
        Vector3();
        Vector3(float x, float y, float z = 0);
        Vector3(const Vector3 &vec);

        Vector3 operator+(const Vector3 &vec);
        Vector3 &operator+=(const Vector3 &vec);
        Vector3 operator-(const Vector3 &vec);
        Vector3 &operator-=(const Vector3 &vec);
        Vector3 operator*(float value);
        Vector3 &operator*=(float value);
        Vector3 operator/(float value);
        Vector3 &operator/=(float value);
        Vector3 &operator=(const Vector3 &vec);
        float& operator[](int value);
        float operator[](int value) const;
        Vector3 operator-() const;

        float dot(const Vector3 &vec);
        float norm();
        Vector3 normalized();
        Vector3 cross(const Vector3& v1);
        void display();

        float distanceTo(const Vector3& B);

};

#endif

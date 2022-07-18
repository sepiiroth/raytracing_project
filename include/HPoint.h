#ifndef HPOINT_H
#define HPOINT_H

class HPoint {
    private:
        float m_x, m_y, m_z, m_w;
        float getX() const;
        float getY() const;
        float getZ() const;
    public:
        HPoint();
        HPoint(float x, float y, float z);
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        HPoint operator+(const HPoint &p);
        HPoint &operator+=(const HPoint &p);
        HPoint operator-(const HPoint &p);
        HPoint &operator-=(const HPoint &p);
        HPoint operator*(float value);
        HPoint &operator*=(float value);
        HPoint operator/(float value);
        HPoint &operator/=(float value);
        HPoint &operator=(const HPoint &p);
        float operator[](int value);
        HPoint operator-();
        float dot(const HPoint &p);
        float distanceTo(const HPoint& B);
        void display();
};
#endif // HPOINT_H

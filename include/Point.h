#ifndef POINT_H
#define POINT_H

class Point {
    private:
        float m_x, m_y, m_z;
        float getX() const;
        float getY() const;
        float getZ() const;
    public:
        Point();
        Point(float x, float y, float z);
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        Point operator+(const Point &p);
        Point &operator+=(const Point &p);
        Point operator-(const Point &p);
        Point &operator-=(const Point &p);
        Point operator*(float value);
        Point &operator*=(float value);
        Point operator/(float value);
        Point &operator/=(float value);
        Point &operator=(const Point &p);
        float operator[](int value) const;
        Point operator-();
        float dot(const Point &p);
        float distanceTo(const Point& B);
        void display();
};

#endif // POINT_H

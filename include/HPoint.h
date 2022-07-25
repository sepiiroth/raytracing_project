#ifndef HPOINT_H
#define HPOINT_H
#include "Point.h"

class HPoint : public Vector3 {
    private:
        float m_x, m_y, m_z, m_w;
    public:
        HPoint();
        HPoint(const Vector3& p);
        HPoint(float x, float y, float z);

        float operator[](int value);
        void display();
};
#endif

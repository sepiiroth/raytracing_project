#ifndef HVECTOR_H
#define HVECTOR_H
#include "Vector3.h"


class HVector : public Vector3 {
    protected:
        float m_w;
    public:
        HVector();
        HVector(const Vector3& v);
        HVector(float x, float y, float z = 0);

        float operator[](int value);
        void display();
};
#endif

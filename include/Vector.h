#ifndef VECTOR_H
#define VECTOR_H
#include "Vector3.h"

class Vector : public Vector3 {
    private:

    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(const Vector3 &vec);
};

#endif

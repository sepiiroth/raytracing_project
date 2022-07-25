#ifndef POINT_H
#define POINT_H
#include "Vector3.h"

class Point : public Vector3 {
    private:
    public:
        Point();
        Point(float x, float y, float z);
        Point(const Vector3 &vec);
};

#endif

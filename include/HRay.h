#ifndef HRAY_H
#define HRAY_H
#include"HVector.h"
#include"HPoint.h"

class HRay {
    private:
    public:
        HPoint origin;
        HVector vec;
        HRay(float ox, float oy, float oz, float vx, float vy, float vz);
        HRay(HPoint p, HVector v);
};

#endif // HRAY_H
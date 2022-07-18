#include "HRay.h"

HRay::HRay(float ox, float oy, float oz, float vx, float vy, float vz) {
    this->origin = HPoint(ox, oy, oz);
    this->vec = HVector(vx, vy, vz);
}

HRay::HRay(HPoint p, HVector v) {
    this->origin = p;
    this->vec = v;
}


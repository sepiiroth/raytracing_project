#include "HRay.h"

/*Initialisation*/
HRay::HRay(float ox, float oy, float oz, float vx, float vy, float vz) {
    this->origin = HPoint(ox, oy, oz);
    this->vec = HVector(vx, vy, vz);
}

HRay::HRay(HPoint p, HVector v) {
    this->origin = p;
    this->vec = v;
}

HRay::HRay(const Ray& r) {
    this->origin = r.origin;
    this->vec = r.vec;
}

/*Calculs*/
HRay HRay::normalized() {
    this->vec = this->vec.normalized();
    return (*this);
}


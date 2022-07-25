#include "Vector.h"

Vector::Vector() : Vector3() {}

Vector::Vector(float x, float y, float z) : Vector3(x, y, z) {}

Vector::Vector(const Vector3 &vec) : Vector3(vec) {}

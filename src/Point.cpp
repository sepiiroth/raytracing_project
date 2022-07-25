#include "Point.h"

Point::Point() : Vector3() {}

Point::Point(float x, float y, float z) : Vector3(x, y, z) {}

Point::Point(const Vector3 &vec) : Vector3(vec) {}

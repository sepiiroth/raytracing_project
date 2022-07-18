#include "Ray.h"
#include<iostream>
#include<math.h>

Ray::Ray(float ox, float oy, float oz, float vx, float vy, float vz) {
    this->origin = Point(ox, oy, oz);
    this->vec = Vector(vx, vy, vz);
}

Ray::Ray(Point p, Vector v) {
    this->origin = p;
    this->vec = v;
}

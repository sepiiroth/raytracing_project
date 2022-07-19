#include "../include/Light.h"

Ray Light::getRayToLight(const Point& p)const {
    Point o = Point(p);
    Vector vec = -o;
    return Ray(o, vec);

}
Ray Light::getRayFromLight(const Point& p)const {
    Point o = Point(0,0,0);
    Vector vec = p;
    return Ray(o, vec);
}

Vector Light::getVectorToLight(const Point& p)const {
    Vector vec = Point(-p);
    return vec;
}
Vector Light::getVectorFromLight(const Point& p)const {
    Vector vec = p;
    return vec;
}

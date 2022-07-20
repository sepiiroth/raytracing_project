#include "../include/Light.h"

Light::Light()
{
    this->id = Color(0.5, 0.5, 0.5);
    this->is = Color(0.2, 0.2, 0.2);
}

Ray Light::getRayToLight(const Point& p)const {
    Point o = globalToLocal(Point(p));
    Vector vec = globalToLocal(-o);
    return Ray(o, vec).normalized();

}
Ray Light::getRayFromLight(const Point& p)const {
    Point o = globalToLocal(Point(0,0,0));
    Vector vec = globalToLocal(p);
    return Ray(o, vec).normalized();
}

Vector Light::getVectorToLight(const Point& p)const {
    Vector vec = Point(0,0,0) - globalToLocal(p);
    //vec.display();
    return localToGlobal(vec).normalized();
}
Vector Light::getVectorFromLight(const Point& p)const {
    Vector vec = globalToLocal(p);
    return vec.normalized();
}

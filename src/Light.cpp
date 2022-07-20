#include "../include/Light.h"

Light::Light()
{
    this->id = Color(0.5, 0.5, 0.5);
    this->is = Color(0.2, 0.2, 0.2);
    this->origin = Point(0,0,0);
}

Ray Light::getRayToLight(const Point& p)const {
    Point o = globalToLocal(Point(p));
    Vector vec = Point(this->origin) - globalToLocal(o);
    return localToGlobal(Ray(o, vec)).normalized();

}
Ray Light::getRayFromLight(const Point& p)const {
    Point o = globalToLocal(this->origin);
    Vector vec = globalToLocal(p) - Point(this->origin);
    return localToGlobal(Ray(o, vec)).normalized();
}

Vector Light::getVectorToLight(const Point& p)const {
    Vector vec = Point(this->origin) - globalToLocal(p);
    //vec.display();
    return localToGlobal(vec).normalized();
}
Vector Light::getVectorFromLight(const Point& p)const {
    Vector vec = globalToLocal(p) - Point(this->origin);
    return localToGlobal(vec).normalized();
}

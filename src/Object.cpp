#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();
    this->trans(2, 3) = 30;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
}

Object::~Object()
{
    //dtor
}

bool Object::intersect(const Ray& ray, Point& impact) const {
    Ray lr = globalToLocal(ray);
    lr.vec = lr.vec.normalized();
    if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001) return false;
    if(lr.vec[2]*lr.origin[2]>0)return false;
    float t = -lr.origin[2]/lr.vec[2];
    Vector test = lr.vec * t;
    Point p(lr.origin[0]+test[0], lr.origin[1]+test[1], lr.origin[2]+test[2]);
    impact = localToGlobal(p);
    return true;
}

Ray Object::getNormal(const Point& p, const Point& o) const {
    Point lp = globalToLocal(p);
	Point lo = globalToLocal(o);
	float z = 1;
	if(lo[2]<0)z=-1;
	return localToGlobal(Ray(lp,Vector(0,0,z))).normalized();
}

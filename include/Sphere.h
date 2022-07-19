#ifndef SPHERE_H
#define SPHERE_H
#include "Object.h"
#include <math.h>

class Sphere : public virtual Object {
    public:
        Sphere();
        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray r = globalToLocal(ray).normalized();
            float a = r.vec.dot(r.vec);
            float b = 2*r.vec.dot(r.origin);
            float c = r.origin.dot(r.origin)-1.0;
            float delta = b*b-4*a*c;

            if(delta < 0)return false;

            float t;
            if(delta<0.0001){
                t = -b/(2*a);
            }else{
                t = (-b-sqrt(delta))/(2*a);
                if(t<0)t = (-b+sqrt(delta))/(2*a);
            }
            if(t < 0)return false;

            Vector v = r.vec * t;
            Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
            impact = localToGlobal(p);
            return true;
        }

        virtual Ray getNormal(const Point& p, const Point& o)const {
            Vector v(globalToLocal(p)[0], globalToLocal(p)[1], globalToLocal(p)[2]);
            if(globalToLocal(o)[0] < 1 && globalToLocal(o)[1] < 1 && globalToLocal(o)[2] < 1) {
                Ray r(p, -v.normalized());
                return r;

            } else {
                Ray r(p, v.normalized());
                return r;
            }
        }
    protected:

    private:
};

#endif // SPHERE_H

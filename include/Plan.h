#ifndef PLAN_H
#define PLAN_H
#include "Object.h"

class Plan : public virtual Object {
    private:
    public:
        Plan();
        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray lr = globalToLocal(ray).normalized();
            if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001)return false;
            if(lr.vec[2]*lr.origin[2]>0)return false;
            float t = -lr.origin[2]/lr.vec[2];
            Vector v = lr.vec * t;
            Point p(lr.origin[0]+v[0], lr.origin[1]+v[1], lr.origin[2]+v[2]);
            impact = localToGlobal(p);
            return true;
        }

        virtual Ray getNormal(const Point& p, const Point& o) const {
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            float z = 1;
            if(lo[2]<0)z=-1;
            return localToGlobal(Ray(lp,Vector(0,0,z))).normalized();
        }


    protected:
};

#endif // PLAN_H

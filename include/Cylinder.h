#ifndef CYLINDER_H
#define CYLINDER_H
#include "Object.h"
#include <math.h>

class Cylinder : public virtual Object {
    public:
        Cylinder();
        virtual bool intersect(const Ray& ray, Point& impact)const {
            Ray r = globalToLocal(ray).normalized();

            float a = r.vec[0]*r.vec[0]+r.vec[2]*r.vec[2];
            float b = 2*(r.vec[0]*r.origin[0]+r.vec[2]*r.origin[2]);
            float c = r.origin[0]*r.origin[0]+r.origin[2]*r.origin[2]-1.0;
            float delta = b*b-4*a*c;

            if(delta < 0)return false;

            float t;
            if(delta<0.0001){
                t = -b/(2*a);
            } else {
                t = (-b-sqrt(delta))/(2*a);
                if(t<0)t = (-b+sqrt(delta))/(2*a);
            }
            if(t < 0)return false;

            Vector v = r.vec * t;
            Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
            impact = localToGlobal(p);
            return true;
        }

        virtual Ray getNormal(const Point& p, const Point& observator)const {
            float x, y, z;

            if( 1.f - abs(globalToLocal(p)[0]) > 0.001f || 1.f - abs(globalToLocal(p)[1]) < 0.001f)
            {
                x = globalToLocal(p)[0];
                y = 0;
                z = globalToLocal(p)[2];
            }
            else
            {
                x = 1.f - abs(globalToLocal(p)[0]) > 0.001f ? 0 : globalToLocal(p)[0];
                y = 1.f - abs(globalToLocal(p)[1]) > 0.001f ? 0 : globalToLocal(p)[1];
                z = 1.f - abs(globalToLocal(p)[2]) > 0.001f ? 0 : globalToLocal(p)[2];
            }

            Vector v(x, y, z);
            Vector o(globalToLocal(observator));
            if(o.norm() < 1)
            {
                v = -v;
            }
            return Ray(p, localToGlobal(v)).normalized();
            //std::cout << v[0] << ", " << v[1] << ", " << v[2] << std::endl;
        }

    protected:

    private:
};

#endif // CYLINDER_H

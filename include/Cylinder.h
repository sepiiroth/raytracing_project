#ifndef CYLINDER_H
#define CYLINDER_H
#include "Object.h"
#include <math.h>

class Cylinder : public virtual Object {
    private:

    public:
        Point origin;
        float axis1, axis2, scale;

        Cylinder();

        Cylinder(Point o, float s, float a1, float a2, TextureMode textureMode, Material m = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f));

        virtual bool intersect(const Ray& ray, Point& impact)const {
            Ray r = globalToLocal(ray).normalized();

            float a = r.vec[axis1]*r.vec[axis1]+r.vec[axis2]*r.vec[axis2];
            float b = 2*(r.vec[axis1]*r.origin[axis1]+r.vec[axis2]*r.origin[axis2]);
            float c = r.origin[axis1]*r.origin[axis1]+r.origin[axis2]*r.origin[axis2] - scale*scale;
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

            Point p = r.origin + r.vec * t;
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
        }
};

#endif

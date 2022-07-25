#ifndef CONE_H
#define CONE_H
#include "Object.h"
#include <math.h>
#include <vector>

class Cone : public virtual Object {
     private:
        Point center;
        float radius;
        float height;
    public:
        Cone();
        Cone(Point c, float r, float h, Material m = Material(Color(1.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0, 0, 0), 0.0f));

        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray r = globalToLocal(ray).normalized();
            float A = r.origin[0] - this->center[0];
            float B = r.origin[2] - this->center[2];
            float D = this->height - r.origin[1] + this->center[1];

            float tan = (this->radius / this->height) * (this->radius / this->height);

            float a = (r.vec[0] * r.vec[0]) + (r.vec[2] * r.vec[2]) - (tan*(r.vec[1] * r.vec[1]));
            float b = (2*A*r.vec[0]) + (2*B*r.vec[2]) + (2*tan*D*r.vec[1]);
            float c = (A*A) + (B*B) - (tan*(D*D));

            float delta = b*b - 4*(a*c);
            if(fabs(delta) < 0.001) return false;
            if(delta < 0.0) return false;

            float t1 = (-b - sqrt(delta))/(2*a);
            float t2 = (-b + sqrt(delta))/(2*a);
            float t;

            if (t1>t2) t = t2;
            else t = t1;

            float res = r.origin[1] + r.vec[1] * t;
            if ((res > this->center[1]) && (res < this->center[1] + this->height)) {
                Vector v = r.vec * t;
                Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
                impact = localToGlobal(p);
                return true;
            } else {
                return false;
            }
        };

        virtual Ray getNormal(const Point& p, const Point& o) const {
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            if((lo-Point(0,0,0)).norm()<1)return localToGlobal(Ray(lp,-lp)).normalized();
            return localToGlobal (Ray(lp,lp)).normalized();
        };
};

#endif

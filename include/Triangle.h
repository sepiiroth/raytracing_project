#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Object.h"
#include <iostream>
#include <math.h>
constexpr float kEpsilon = 1e-8;

class Triangle : public virtual Object {
    public:
        Point A;
        Point B;
        Point C;
        Vector N;

        Triangle(Point p1, Point p2, Point p3);
        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray r = globalToLocal(ray).normalized();
            float  a = A[0]-B[0],     d = A[0]-C[0],     g = r.vec[0],
                   b = A[1]-B[1],     e = A[1]-C[1],     h = r.vec[1],
                   c = A[2]-B[2],     f = A[2]-C[2],     i = r.vec[2],
                   j = A[0]-r.origin[0],   k = A[1]-r.origin[1],   l = A[2]-r.origin[2];

            float M, W, Y, t;

            M = a*(e*i - h*f)   +  b*(g*f - d*i)  +  c*(d*h - e*g);
            W = (j*(e*i - h*f)  +  k*(g*f - d*i)  +  l*(d*h - e*g))  / M;
            Y = (i*(a*k - j*b)  +  h*(j*c - a*l)  +  g*(b*l - k*c))  / M;
            t = (f*(a*k - j*b)  +  e*(j*c - a*l)  +  d*(b*l - k*c))  / M;


            if (Y<0 || Y>1) {
              return false;
            }

            if (W<0 || W>1-Y) {
              return false;
            }

            Vector v = r.vec * t;
            Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
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

    private:
};

#endif // TRIANGLE_H

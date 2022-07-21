#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Object.h"
#include <iostream>
#include <math.h>
const float EPSILON = 0.0000001;

class Triangle : public virtual Object {
    public:
        Point A;
        Point B;
        Point C;

        Triangle(Point p1, Point p2, Point p3);
        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray r = globalToLocal(ray).normalized();
            Point ABis = this->A;
            Point BBis = this->B;
            Point CBis = this->C;
            Point edge1, edge2, h, s, q;
            float a,f,u,v;
            edge1 = BBis - ABis;
            edge2 = CBis - ABis;
            Vector cr = r.vec.cross(Vector(edge2[0], edge2[1], edge2[2]));
            h = Point(cr[0], cr[1], cr[2]);

            a = edge1.dot(h);
            if (a > -EPSILON && a < EPSILON)
                return false;    // Le rayon est parallèle au triangle.

            f = 1.0/a;
            s = r.origin - ABis;
            u = (s.dot(h)) * f;
            if (u < 0.0 || u > 1.0) {
                return false;
            }
            q = s.cross(edge1);
            //Vector cr1 = r.vec.dot(Vector(q[0], q[1], q[2]));
            v = r.vec.dot(Vector(q[0], q[1], q[2])) * f;
            if (v < 0.0 || u + v > 1.0) {
                return false;
            }

            // On calcule t pour savoir ou le point d'intersection se situe sur la ligne.
            float t = edge2.dot(q) * f;
            if (t > EPSILON) // Intersection avec le rayon
            {
                Vector v = r.vec * t;
                Point p(r.origin[0]+v[0], r.origin[1]+v[1], r.origin[2]+v[2]);
                impact = localToGlobal(p);
                return true;
            }
            else {
                return false;
                    }// On a bien une intersection de droite, mais pas de rayon.
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

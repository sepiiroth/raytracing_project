#ifndef SQUARE_H
#define SQUARE_H
#include "Object.h"

class Square : public virtual Object {
    private:

    public:
        Square();
        Square(Point origin, float scale, TextureMode textureMode, Material m = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f));

        virtual bool intersect(const Ray& ray, Point& impact) const {
            Ray lr = globalToLocal(ray).normalized();
            if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001)return false;
            if(lr.vec[2]*lr.origin[2]>0) return false;
            float t = -lr.origin[2]/lr.vec[2];
            Vector v = lr.vec * t;
            Point p(lr.origin[0]+v[0], lr.origin[1]+v[1], lr.origin[2]+v[2]);
            if(p[0]<-1 || p[0]>1 || p[1]<-1 || p[1]>1 ) return false;
            impact = localToGlobal(p);
            return true;
        }

        Ray getNormal(const Point& p, const Point& o) const {
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            float z = 1;
            if(lo[2]<0)z=-1;
            return localToGlobal(Ray(lp,Vector(0,0,z))).normalized();
        }

        virtual Point getTextureCoordinates(const Point& p) const {
            float x = globalToLocal(p)[0]/2 + .5f;
            float y = globalToLocal(p)[1]/2 + .5f;
            Point point = Point(x, y, 0);
            return point;
        }
};

#endif

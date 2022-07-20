#ifndef OBJECT_H
#define OBJECT_H
#include "Point.h"
#include "HPoint.h"
#include "Ray.h"
#include "HRay.h"
#include "Vector.h"
#include "HVector.h"
#include "Matrix.h"
#include "Entity.h"
#include "Material.h"
#include <math.h>

class Object : public Entity
{
    public:
        Object();
        virtual ~Object();
        Point texcoords;
        Color color;
        Material mat;
        Material* texture;

        //Point getTextureCoordinates(const Point& p) const;
        Material getMaterial(const Point& p) const;
        virtual bool intersect(const Ray& ray, Point& impact) const {
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

        virtual Ray getNormal(const Point& p, const Point& o) const {
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            float z = 1;
            if(lo[2]<0)z=-1;
            return localToGlobal(Ray(lp,Vector(0,0,z))).normalized();
        }

        virtual Point getTextureCoordinates(const Point& p)const{
            Point temp(globalToLocal(p));

            float x = temp[0] - floor(temp[0]);
            float y = temp[1] - floor(temp[1]);

            return Point(x, y, 0);
        }
    protected:

    private:
};

#endif // OBJECT_H

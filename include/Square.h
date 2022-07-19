#ifndef SQUARE_H
#define SQUARE_H
#include "Object.h"

class Square : public virtual Object {
    public:
        Square();
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

    protected:

    private:
};

#endif // SQUARE_H

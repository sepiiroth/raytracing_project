#ifndef OBJECT_H
#define OBJECT_H
#include "Point.h"
#include "HPoint.h"
#include "Ray.h"
#include "HRay.h"
#include "Vector.h"
#include "HVector.h"
#include "Matrix.h"

class Object
{
    public:
        Object();
        virtual ~Object();

        Point getTextureCoordinates(const Point& p) const;
        //Material getMaterial(const Point& p) const;
        Ray getNormal(const Point& p, const Point& o) const;
        bool intersect(const Ray& ray, Point& impact) const;

        /*Point globalToLocal(const Point& p) const;
        Ray globalToLocal(const Ray& r) const;
        Vector globalToLocal(const Vector v) const;

        Point localToGlobal(const Point& p) const;
        Ray localToGlobal(const Ray& r) const;
        Vector localToGlobal(const Vector v) const;*/

    protected:

    private:
        Point texcoords;
        Matrix trans, transInv;
};

#endif // OBJECT_H

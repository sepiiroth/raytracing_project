#ifndef ENTITY_H
#define ENTITY_H
#include "Point.h"
#include "Matrix.h"
#include "HPoint.h"
#include "Vector.h"
#include "HVector.h"
#include "Ray.h"
#include "HRay.h"

class Entity {
    private:
        Matrix transInv, trans;
    public:
        Entity();
        void translate(float x, float y, float z);
        void rotateX(float deg);
        void rotateY(float deg);
        void rotateZ(float deg);
        void scale(float factor);

        Point globalToLocal(const Point& p) const;
        Ray globalToLocal(const Ray& r) const;
        Vector globalToLocal(const Vector v) const;

        Point localToGlobal(const Point& p) const;
        Ray localToGlobal(const Ray& r) const;
        Vector localToGlobal(const Vector v) const;
};

#endif // ENTITY_H

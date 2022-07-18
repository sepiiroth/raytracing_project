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
};

#endif // ENTITY_H

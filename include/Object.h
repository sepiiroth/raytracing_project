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

class Object : public Entity
{
    public:
        Object();
        virtual ~Object();

        Point getTextureCoordinates(const Point& p) const;
        Material getMaterial(const Point& p) const;
        Ray getNormal(const Point& p, const Point& o) const;
        bool intersect(const Ray& ray, Point& impact) const;

    protected:

    private:
        Point texcoords;
};

#endif // OBJECT_H

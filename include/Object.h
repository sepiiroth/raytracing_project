#ifndef OBJECT_H

#define OBJECT_H

#include <math.h>
#include "Matrix.h"
#include "Entity.h"
#include "Material.h"
#include "Point.h"
#include "HPoint.h"
#include "Ray.h"
#include "HRay.h"
#include "Vector.h"
#include "HVector.h"

enum class TextureMode { Monochrome = 0, Damier = 1, Ligne = 2 };

class Object : public Entity {
    private:

    public:
        Material mat;
        Material* texture;
        TextureMode textureMode;

        Object();
        Object(Point origin, float scale, TextureMode textureMode, Material material);
        virtual ~Object();

        Material getMaterial(const Point& p) const; // Retourne le Material correspondant au point de la surface de l'objet passé en paramètre

        virtual bool intersect(const Ray& ray, Point& impact) const { // Calcule si le rayon passé en paramètre intersecte l'objet
            Ray lr = globalToLocal(ray).normalized();
            if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001)return false;
            if(lr.vec[2]*lr.origin[2]>0)return false;
            float t = -lr.origin[2]/lr.vec[2];
            Vector v = lr.vec * t;
            Point p(lr.origin[0]+v[0], lr.origin[1]+v[1], lr.origin[2]+v[2]);
            impact = localToGlobal(p);
            return true;
        }

        virtual Ray getNormal(const Point& p, const Point& o) const { // Retourne la normale correspondant au point de la surface de l'objet
            Point lp = globalToLocal(p);
            Point lo = globalToLocal(o);
            float z = 1;
            if(lo[2]<0)z=-1;
            return localToGlobal(Ray(lp,Vector(0,0,z))).normalized();
        }

        virtual Point getTextureCoordinates(const Point& p) const { // Retourne le point 2D de la texture correspondant au point de la surface de l'objet
            Point temp(globalToLocal(p));

            float x = temp[0] - floor(temp[0]);
            float y = temp[1] - floor(temp[1]);

            return Point(x, y, 0);
        }
};

#endif

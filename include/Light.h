#ifndef LIGHT_H

#define LIGHT_H

#include "Point.h"
#include "Ray.h"
#include "Vector.h"
#include "Color.h"
#include "Entity.h"

using namespace std;

class Light : public Entity {
    private:

    public:
        Color id, is;
        Point origin;

        Light();

        Ray getRayToLight(const Point& p) const; // Retourne un Ray partant du Point passé en paramètre et orienté vers la lumière
        Ray getRayFromLight(const Point& p) const; // Retourne un Ray partant de la lumière et orienté vers le Point passé en paramètre
        Vector getVectorToLight(const Point& p) const; // Retourne un Vector orienté du Point passé en paramètre vers la lumière
        Vector getVectorFromLight(const Point& p) const; // Retourne un Vector orienté de la lumière vers le Point passé en paramètre
};

#endif

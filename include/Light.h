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

        Ray getRayToLight(const Point& p) const; // Retourne un Ray partant du Point pass� en param�tre et orient� vers la lumi�re
        Ray getRayFromLight(const Point& p) const; // Retourne un Ray partant de la lumi�re et orient� vers le Point pass� en param�tre
        Vector getVectorToLight(const Point& p) const; // Retourne un Vector orient� du Point pass� en param�tre vers la lumi�re
        Vector getVectorFromLight(const Point& p) const; // Retourne un Vector orient� de la lumi�re vers le Point pass� en param�tre
};

#endif

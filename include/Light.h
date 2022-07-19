#ifndef LIGHT_H
#define LIGHT_H
#include "Point.h"
#include "Ray.h"
#include "Vector.h"
#include "Color.h"
#include "Entity.h"

using namespace std;

class Light : public Entity{
    private:
    public:
        Color id, is;
        Light();
        Ray getRayToLight(const Point& p)const;
        Ray getRayFromLight(const Point& p)const;
        Vector getVectorToLight(const Point& p)const;
        Vector getVectorFromLight(const Point& p)const;
};

#endif

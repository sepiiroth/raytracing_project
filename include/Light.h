#ifndef LIGHT_H
#define LIGHT_H
#include "Point.h"
#include "Ray.h"
#include "Vector.h"

using namespace std;

class Light {
    private:

    public:
        Ray getRayToLight(const Point& p)const;
        Ray getRayFromLight(const Point& p)const;
        Vector getVectorToLight(const Point& p)const;
        Vector getVectorFromLight(const Point& p)const;
};

#endif
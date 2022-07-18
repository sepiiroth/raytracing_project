#ifndef RAY_H
#define RAY_H
#include"Vector.h"
#include"Point.h"

class Ray
{
    private:
    public:
        Point origin;
        Vector vec;
        Ray(float ox, float oy, float oz, float vx, float vy, float vz);
        Ray(Point p, Vector v);

        Point getOrigin() const;
        Vector getVector() const;
};

#endif // RAY_H

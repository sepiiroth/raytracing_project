#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();

}

Object::~Object()
{
    //dtor
}

bool Object::intersect(const Ray& ray, Point& impact) const
{

    float oLocal, vLocal;
    oLocal = globalToLocal(ray.origin)[2];
    vLocal = globalToLocal(ray.vec)[2];

    float t = -(oLocal/vLocal);
    cout << oLocal << " " << vLocal << " = " << t << endl;

    if(t>0)
    {
        float ox, oy, oz, vx, vy, vz;
        ox = ray.origin[0];
        oy = ray.origin[1];
        oz = ray.origin[2];

        vx = ray.vec[0];
        vy = ray.vec[1];
        vz = ray.vec[2];

        Point temp = Point(ox + t * vx, oy + t * vy, oz + t * vz);
        //cout << "\n" << temp[0] << ", " << temp[1] << ", " << temp[2] << endl;

        if(globalToLocal(temp)[0] <= 1 && globalToLocal(temp)[0] >= -1 && globalToLocal(temp)[1] <= 1 && globalToLocal(temp)[1] >= -1)
        {
            impact = temp;
            return true;
        }

        return false;
    }

    return false;
}

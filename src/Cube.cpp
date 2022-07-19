#include "Cube.h"

Cube::Cube()
{
    //ctor
}

float Cube::interSide(const Ray& r, int dim, float offset)const {
    float t = -1;
    if(r.vec[dim]<0.00001 && r.vec[dim]>-0.00001)return -1;
    t = (offset-r.origin[dim])/r.vec[dim];
    if(t<0)return -1;
    for(int d = 0; d < 3; d++){
        if(d == dim)continue;
        float x = r.origin[d]+t*r.vec[d];
        if(x < -1 || x > 1)return -1;
    }
    return t;
}

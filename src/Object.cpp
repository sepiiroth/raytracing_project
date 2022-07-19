#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();
    this->trans(2, 3) = 30;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
}

Object::~Object()
{
    //dtor
}

bool Object::intersect(const Ray& ray, Point& impact) const
{
    // PLAN
    /*Ray lr = globalToLocal(ray);
    lr.vec = lr.vec.normalized();
    if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001) return false;
    if(lr.vec[2]*lr.origin[2]>0)return false;
    float t = -lr.origin[2]/lr.vec[2];
    Vector test = lr.vec * t;
    Point p(lr.origin[0]+test[0], lr.origin[1]+test[1], lr.origin[2]+test[2]);
    impact = localToGlobal(p);
    return true;*/
    Ray lr = globalToLocal(ray);
    lr.vec = lr.vec.normalized();
    if(lr.vec[2]<0.0001 && lr.vec[2]>-0.0001)return false;
    if(lr.vec[2]*lr.origin[2]>0) return false;
    float t = -lr.origin[2]/lr.vec[2];
    Vector test = lr.vec * t;
    Point p(lr.origin[0]+test[0], lr.origin[1]+test[1], lr.origin[2]+test[2]);
    if(p[0]<-1 || p[0]>1 || p[1]<-1 || p[1]>1 )return false;
    impact = localToGlobal(p);
    return true;
/*
    float oLocal, vLocal;
    oLocal = globalToLocal(ray.origin)[2];
    vLocal = globalToLocal(ray.vec)[2];
    printf("oLocal = %f et vLocal = %f \n", ray.origin[2], ray.origin[1]);
    float t = -(oLocal/vLocal);
    //cout << oLocal << " " << vLocal << " = " << t << endl;

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

    return false;*/
}

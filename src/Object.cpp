#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();
    this->trans = Matrix(4,4);
    this->transInv = Matrix(4,4);
}

Object::~Object()
{
    //dtor
}

bool Object::intersect(const Ray& ray, Point& impact) const
{

    float oLocal, vLocal;
    oLocal = /*globalToLocal*/(ray.origin)[2];
    vLocal = /*globalToLocal*/(ray.vec)[2];

    float t = -(oLocal/vLocal);

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

        if((temp)[0] <= 1 && (temp)[0] >= -1 && (temp)[1] <= 1 && (temp)[1] >= -1)
        {
            impact = temp;
            return true;
        }

        return false;
    }

    return false;
}

/*Point Object::globalToLocal(const Point& p) const
{
    HPoint temp(p);
	return trans*temp;
}

Ray Object::globalToLocal(const Ray& r) const{
    HRay temp(r);
  	return Ray(trans*temp.origin, trans*temp.vector);

}

Vector Object::globalToLocal(const Vector v) const{
    HVector temp(v);
	return trans*temp;
}

Point Object::localToGlobal(const Point& p) const{
    HPoint temp(p);
	return transInv*temp;
}

Ray Object::localToGlobal(const Ray& r) const{
    HRay temp(r);
  	return Ray(transInv*temp.origin, transInv*temp.vector);

}

Vector Object::localToGlobal(const Vector v) const{
    HVector temp(v);
	return transInv*temp;
}*/

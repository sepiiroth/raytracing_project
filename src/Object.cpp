#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();
    this->color = Color(1.0f, 0, 0);
    this->trans(2, 3) = 2;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material();
}

Object::~Object()
{
    //dtor
}

Material Object::getMaterial(const Point& p) const
{
    return this->mat;
}

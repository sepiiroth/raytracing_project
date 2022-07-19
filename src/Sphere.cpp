#include "Sphere.h"

Sphere::Sphere()
{
    this->texcoords = Point();
    this->color = Color(0.5, 0.1, 0.1);
    this->trans(0, 3) = 0;
    this->trans(2, 3) = 1;
    this->trans(0, 0) = 1;
    this->trans(1, 1) = 1;
    this->trans(2, 2) = 1;
    this->transInv = this->trans.inverse();
}

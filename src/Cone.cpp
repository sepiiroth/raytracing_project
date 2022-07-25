#include "Cone.h"

Cone::Cone() {
    this->center = Point(3.5f, 0, 80);
    this->radius = 2;
    this->height = 4;

    this->trans(2, 3) = 0;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material(Color(1.0, 1.0, 1.0), Color(0.0, 0.0, 0.0), Color(0, 0, 0), 0.0f);
}

Cone::Cone(Point c, float r, float h, Material m) {
    this->center = c;
    this->radius = r;
    this->height = h;

    this->trans(2, 3) = 0;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = m;
}

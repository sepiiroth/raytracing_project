#include "Triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3) {
    this->A = p1;
	this->B = p2;
	this->C = p3;
    this->N = ((B-A).cross(C-A));

    this->texcoords = Point();
    this->trans(2, 3) = 0;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material(Color(1.0, 1.0, 1.0), Color(0.0, 0.0, 0.0), Color(0, 0, 0), 0.0f);
}

#include "Square.h"

Square::Square()
{
    this->texcoords = Point();
    this->trans(2, 3) = 0;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f);
}

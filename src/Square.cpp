#include "Square.h"

Square::Square()
{
    this->texcoords = Point();
    this->trans(2, 3) = 50;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
}

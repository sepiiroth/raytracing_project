#include "Square.h"

Square::Square()
:Object(Point(0,0,0), 2, TextureMode::Monochrome, Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f))
{
    //this->mat = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f);
}

Square::Square(Point origin, float scale, TextureMode textureMode)
:Object(origin, scale, textureMode, Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f))
{
}

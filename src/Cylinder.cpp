#include "Cylinder.h"

Cylinder::Cylinder() {
    this->origin = Point(0, 0, 0);
    this->axis1 = 1;
    this->axis2 = 2;
    this->scale = 1;
    this->textureMode = TextureMode::Monochrome;
    this->mat = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f);
}

Cylinder::Cylinder(Point o, float s, float a1, float a2, TextureMode textureMode, Material m) {
    this->origin = o;
    this->axis1 = a1;
    this->axis2 = a2;
    this->scale = s;
    this->mat = m;
    this->textureMode = textureMode;
}


#include "Sphere.h"

Sphere::Sphere() : Object(Point(0,0,0), 2, TextureMode::Monochrome, Material()) {
    this->origin = Point(0, 0, 0);
    this->scale = 1;
    this->ma = Material();
}

Sphere::Sphere(Point o, float s, TextureMode textureMode, Material m) : Object(o, s, textureMode, m) {
    this->origin = o;
    this->scale = s;
    this->ma = m;
    this->textureMode = textureMode;
}

Material Sphere::getMaterial(const Point& p) const {
    Material m;
    Point tP;
    int i;
    switch(this->textureMode)
    {
        case TextureMode::Monochrome:
            return this->mat;
            break;
        case TextureMode::Ligne:
            tP = getTextureCoordinates(p);
            i = int(tP[1] * 10) * 10 + int(tP[0] * 10);
            m = texture[i];
            return m;
            break;
        default:
            tP = getTextureCoordinates(p);
            i = int(tP[0] * 10) * 10 + int(tP[1] * 10);
            m = texture[i];
            return m;
            break;
    }

}

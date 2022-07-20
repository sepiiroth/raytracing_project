#include "Sphere.h"

Sphere::Sphere()
:Object(Point(0,0,0), 2, TextureMode::Monochrome, Material())
{
}

Sphere::Sphere(Point origin, float scale, TextureMode textureMode)
:Object(origin, scale, textureMode, Material())
{

}

Material Sphere::getMaterial(const Point& p) const
{
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

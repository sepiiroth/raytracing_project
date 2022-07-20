#include "Material.h"

Material::Material()
{
    this->kd = Color(0.25, 0.25, 0.75);
    this->ka = Color(0.1, 0.1, 0.5);
    this->ks = Color(0.0, 0.0, 0.0);
    this->shininess = 0.0f;
}

Material::Material(Color ka, Color kd, Color ks, float shininess)
{
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->shininess = shininess;
}

Material::~Material()
{
    //dtor
}

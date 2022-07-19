#include "Material.h"

Material::Material()
{
    this->ka = Color();
    this->kd = Color();
    this->ks = Color();
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

#include "Color.h"

Color::Color()
{
    this->rgb[0] = 0;
    this->rgb[1] = 0;
    this->rgb[2] = 0;
}

Color::Color(float r, float g, float b)
{
    if(r < 0.0f || r > 1.0f)
    {
        cout << "La composante R doit être comprise entre 0 et 1 (inclus)\n";
        exit(-1);
    }
    if(g < 0.0f || g > 1.0f)
    {
        cout << "La composante G doit être comprise entre 0 et 1 (inclus)\n";
        exit(-1);
    }
    if(b < 0.0f || b > 1.0f)
    {
        cout << "La composante B doit être comprise entre 0 et 1 (inclus)\n";
        exit(-1);
    }

    this->rgb[0] = r;
    this->rgb[1] = g;
    this->rgb[2] = b;
}

Color::~Color()
{
    //dtor
}

float Color::operator[](int value) const
{
    return rgb[value];
}

Color* Color::mul(const Color& c) const
{
    float r = this->rgb[0] * c[0];
    float g = this->rgb[1] * c[1];
    float b = this->rgb[2] * c[2];

    return new Color(r, g, b);
}

Color Color::operator+(const Color &c) {
    return Color(this->rgb[0] + c[0], this->rgb[1] + c[1], this->rgb[2] + c[2]);
}

Color &Color::operator+=(const Color &c) {
    this->rgb[0] += c[0];
    this->rgb[1] += c[1];
    this->rgb[2] += c[2];
    return *this;
}

Color &Color::operator*(float value)
{
    *this *= value;
}

Color &Color::operator*=(float value)
{
    this->rgb[0] *= value;
    this->rgb[1] *= value;
    this->rgb[2] *= value;
    return *this;
}



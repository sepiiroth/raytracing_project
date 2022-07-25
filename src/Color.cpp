#include "Color.h"

/*Initialisation*/
Color::Color() : Vector3() {}

Color::Color(float r, float g, float b) {
    this->m_x = checkColor(r);
    this->m_y = checkColor(g);
    this->m_z = checkColor(b);
}

Color::Color(const Vector3 &vec) : Vector3(vec) {}

/*Calculs*/
float Color::checkColor(float c) {
    if(c < 0.0f) {
        return 0.0f;
    } else if(c > 1.0f) {
        return 1.0f;
    } else {
        return c;
    }
}

Color Color::mul(const Color& c) const {
    float r = this->m_x * c[0];
    float g = this->m_y * c[1];
    float b = this->m_z * c[2];

    return Color(r, g, b);
}


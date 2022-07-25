#ifndef COLOR_H
#define COLOR_H
#include "Vector3.h"

class Color : public Vector3 {
    private:
        float checkColor(float c); /*V�rifie si le float en param�tre est compris entre 0 et 1*/
    public:
        Color();
        Color(float r, float g, float b);
        Color(const Vector3 &vec);

        Color mul(const Color& c) const; /*Multiplication entre deux couleurs*/
};

#endif

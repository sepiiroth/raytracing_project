#ifndef COLOR_H
#define COLOR_H
#include <iostream>

using namespace std;

class Color
{
    public:
        float rgb[3];

        Color();
        Color(float r, float g, float b);
        virtual ~Color();

        float operator[](int value) const;
        Color* mul(const Color& c) const;

        Color operator+(const Color &c);
        Color &operator+=(const Color &c);

};



#endif // COLOR_H

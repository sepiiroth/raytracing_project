#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"

class Material
{
    public:
        Color ka, kd, ks;
        float shininess;

        Material();
        Material(Color ka, Color kd, Color ks, float shininess);
        virtual ~Material();

    protected:

    private:
};

#endif // MATERIAL_H

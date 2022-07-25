#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"

class Material {
    private:

    public:
        Color ka, kd, ks; // ka : composante ambiante, kd: composante diffuse, ks : composante sp�culaire
        float shininess; //Exposant de brillance du mat�riel, utilis� dans le mod�le de Phong

        Material();
        Material(Color ka, Color kd, Color ks, float shininess);
        virtual ~Material();
};

#endif

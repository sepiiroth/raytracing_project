#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"

class Material {
    private:

    public:
        Color ka, kd, ks; // ka : composante ambiante, kd: composante diffuse, ks : composante spéculaire
        float shininess; //Exposant de brillance du matériel, utilisé dans le modèle de Phong

        Material();
        Material(Color ka, Color kd, Color ks, float shininess);
        virtual ~Material();
};

#endif

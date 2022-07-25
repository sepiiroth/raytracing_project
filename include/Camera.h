#ifndef CAMERA_H
#define CAMERA_H
#include "Entity.h"
#include "Ray.h"

class Camera : public Entity {
    private:
        float focal;
    public:
        Camera();
        Camera(float f);

        void changeFocal(float f);
        Ray getRay(float x, float y) const; /*Permet de r�cup�rer le rayon depuis la cam�ra vers un point donn�*/
};

#endif

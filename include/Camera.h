#ifndef CAMERA_H
#define CAMERA_H
#include "Entity.h"
#include "Ray.h"

class Camera : public Entity {
    private:
        float focal;
    public:
        Camera();
        Ray getRay(float x, float y) const;
};

#endif // CAMERA_H

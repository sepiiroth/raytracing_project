#include "../include/Utils.h"

Color getImpactColor(const Ray& ray, const Object& obj, const Point& impact, const Scene& scene)
{
    Vector L = scene.getLight(0)->getVectorToLight(impact);
    Ray N = obj.getNormal(impact, ray.origin);
    Color ka = obj.getMaterial(impact).ka;
    Color kd = obj.getMaterial(impact).kd;

    Color Id ;
    for (int i = 0; i < scene.nbLights(); i++) {
        if(L.dot(N.vec) > 0)
        {
            Id += kd.mul(scene.getLight(i)->id) * L.dot(N.vec);
        }
    }

    return ka + Id ;
}

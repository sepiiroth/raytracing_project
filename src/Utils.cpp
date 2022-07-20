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

Color getImpactColorPhong(const Ray& ray, const Object& obj, const Point& impact, const Scene& scene)
{
    Vector L = scene.getLight(0)->getVectorToLight(impact);
    Point i = impact;
    //i.display();
    Ray N = obj.getNormal(impact, ray.origin);
    //N = Ray(impact, Vector(0,0,1));
    Color ka = obj.getMaterial(impact).ka;
    Color kd = obj.getMaterial(impact).kd;
    Color ks = obj.getMaterial(impact).ks;


    //N.origin.display();
    //N.vec.display();
    Color Id ;
    Color Is;
    for (int i = 0; i < scene.nbLights(); i++) {
        if(L.dot(N.vec) > 0)
        {
            Id += kd.mul(scene.getLight(i)->id) * L.dot(N.vec);
        }

        Vector V = -ray.vec;

        Vector step1 = N.vec.normalized() * L.normalized().dot(N.vec.normalized());
        step1 *= 2;

        Vector R = -L.normalized() +  step1 ;
        if(R.normalized().dot(V) > 0)
        {
            Is += ks.mul(scene.getLight(i)->is) * pow(R.normalized().dot(V), obj.getMaterial(impact).shininess);
        }
    }
    return ka.mul(scene.getAmbiant()) + Id + Is ;
}

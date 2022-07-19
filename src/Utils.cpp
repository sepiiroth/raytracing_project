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
    /*Vector L = scene.getLight(0)->getVectorToLight(impact);
    Ray N = obj.getNormal(impact, ray.origin);
    Color ka = Color(0.1f, 0.1f, 0.5f);//obj.getMaterial(impact).ka;
    Color kd = Color(0.25f, 0.25f, 0.25f);//obj.getMaterial(impact).kd;
    Color ks = Color(0.75f, 0.75f, 0.75f);//obj.getMaterial(impact).ks;



    Color Id ;
    Color Is;
    for (int i = 0; i < scene.nbLights(); i++) {
        if(L.dot(N.vec) > 0)
        {
            Id += kd.mul(scene.getLight(i)->id) * L.dot(N.vec);
        }

        Vector V = -ray.vec;
        Vector R = 2 * L.normalized().dot(N.vec.normalized()) * N.vec.normalized() - L.normalized();
        if(R.normalized().dot(V) > 0)
        {
            Is += ks.mul(scene.getLight(i)->is) * pow(R.normalized().dot(V), obj.getMaterial(impact).shininess);
        }
    }

    return ka.mul(scene.getAmbiant()) + Id + Is ;*/
}

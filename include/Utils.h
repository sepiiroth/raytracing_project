#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Object.h"
#include "Sphere.h"
#include "Plan.h"
#include "Point.h"
#include "Scene.h"

using namespace std;

Color getImpactColor(const Ray& ray, const Object& obj, const Point& impact, const Scene& scene); // LAMBERT Retourne la couleur au point d'intersection entre le rayon et l'objet passés en paramètre
Color getImpactColorPhong(const Ray& ray, const Object* obj, const Point& impact, const Scene& scene); // PHONG Retourne la couleur au point d'intersection entre le rayon et l'objet passés en paramètre
void getShadow(const Ray& ray, const Object* obj, const Point& impact, const Scene& scene, Color& color); // Retourne les ombres

#endif

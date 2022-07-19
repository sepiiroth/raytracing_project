#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Object.h"
#include "Point.h"
#include "Scene.h"

using namespace std;

Color getImpactColor(const Ray& ray, const Object& obj, const Point& impact, const Scene& scene);
Color getImpactColorPhong(const Ray& ray, const Object& obj, const Point& impact, const Scene& scene);

#endif // UTILS_H

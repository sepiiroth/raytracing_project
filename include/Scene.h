#ifndef SCENE_H
#define SCENE_H
#include <math.h>
#include <limits.h>
#include <vector>
#include "Light.h"
#include "Object.h"
#include "Plan.h"
#include "Square.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"


#include "Point.h"
#include "Ray.h"


using namespace std;

class Scene
{
    public:
        Scene();
        virtual ~Scene();

        //Color backgroundColor;
        //Color ambiantColor;

        vector<Light*> lights;
        vector<Object*> objects;

      //  Color getBackground() const;
       // Color getAmbiant() const;

        int nbLights() const;

        const Light* getLight(int index) const;

        Object* closer_intersected(const Ray& ray, Point& impact) const;

    protected:

    private:
};

#endif // SCENE_H

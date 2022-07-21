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
#include "Triangle.h"
#include "Cube.h"
#include "Cylinder.h"


#include "Point.h"
#include "Ray.h"

#include "Color.h"


using namespace std;

class Scene
{
    public:
        Scene();
        Scene(Color backgroundColor, Color ambiantColor, bool shadows);
        Scene(Color backgroundColor, Color ambiantColor, bool shadows, vector<Light*> lights, vector<Object*> objects);
        virtual ~Scene();

        Color backgroundColor;
        Color ambiantColor;

        bool hasShadows;

        vector<Light*> lights;
        vector<Object*> objects;

        Color getBackground() const;
        Color getAmbiant() const;

        int nbLights() const;

        const Light* getLight(int index) const;

        Object* closer_intersected(const Ray& ray, Point& impact) const;

    protected:

    private:
};

#endif // SCENE_H

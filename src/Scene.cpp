#include "Scene.h"


using namespace std;

Scene::Scene() {
    this->ambiantColor = Color(1,1,1);
    this->backgroundColor = Color(0.1,0.1,0.1);
    this->hasShadows = true;

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();
}


Scene::Scene(Color backgroundColor, Color ambiantColor, bool shadows) {
    this->ambiantColor = ambiantColor;
    this->backgroundColor = backgroundColor;
    this->hasShadows = shadows;

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();
}


Scene::Scene(Color backgroundColor, Color ambiantColor, bool shadows, vector<Light*> lights, vector<Object*> objects) {
    this->ambiantColor = ambiantColor;
    this->backgroundColor = backgroundColor;
    this->hasShadows = shadows;

    this->lights = lights;
    this->objects = objects;
}

Scene::~Scene() {
    //dtor
}

int Scene::nbLights() const{
    return this->lights.size();
}

const Light* Scene::getLight(int index) const {
    return this->lights[index];
}

Object* Scene::closer_intersected(const Ray& ray, Point& impact) const {
    Point impactTemp(0,0,0);

    float minDistance = INT_MAX * 1.0f;
    Object* temp = nullptr;

    for(int i = 0; i < this->objects.size(); i++) {
        if(this->objects[i]->intersect(ray, impactTemp))
        {
            float tempDistance = ray.getOrigin().distanceTo(impactTemp);
            if( tempDistance < minDistance)
            {
                minDistance = tempDistance;
                temp = this->objects[i];
                impact = impactTemp;
            }
        }
    }
    return temp;
}

Color Scene::getBackground() const {
    return this->backgroundColor;
}


Color Scene::getAmbiant() const {
    return this->ambiantColor;
}

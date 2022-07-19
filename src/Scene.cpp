#include "../include/Scene.h"

using namespace std;

Scene::Scene()
{
    this->ambiantColor = Color(0.1f, 0.2f, 0.5f);
    this->backgroundColor = Color(0.34f, 0.5f, 1.0f);

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();
    Cube *obj = new Cube();
    //obj->rotateY(1);

    objects.push_back(obj);
    lights.push_back(new Light());
}

Scene::~Scene()
{
    //dtor
}

int Scene::nbLights() const{
    return this->lights.size();
}

const Light* Scene::getLight(int index) const
{
    return this->lights[index];
}

Object* Scene::closer_intersected(const Ray& ray, Point& impact) const
{
    Point impactTemp(0,0,0);

    float minDistance = INT_MAX * 1.0f;
    Object* temp = nullptr;

    for(int i = 0; i < this->objects.size(); i++)
    {
        if(this->objects[i]->intersect(ray, impactTemp))
        {
            float tempDistance = ray.getOrigin().distanceTo(impactTemp);
            if( tempDistance < minDistance)
            {
                minDistance = tempDistance;
                temp = this->objects[i];
            }
        }
    }

    return temp;

}

Color Scene::getBackground() const
{
    return this->backgroundColor;
}


Color Scene::getAmbiant() const
{
    return this->ambiantColor;
}

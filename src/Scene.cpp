#include "../include/Scene.h"


using namespace std;

Scene::Scene()
{
    this->ambiantColor = Color(0.1f, 0.2f, 0.5f);
    this->backgroundColor = Color(0.34f, 0.5f, 1.0f);

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();
    Triangle *obj = new Triangle(Point(-1, 0, -15), Point(0, 1, -15), Point(1, 0, -15));
    //obj->translate(1.f, 0, -15.f);
    obj->rotateZ(10);
    objects.push_back(obj);
    /*Square *obj1 = new Square();
    obj1->translate(1,0,5.f);
    obj1->rotateZ(1);
    obj1->scale(1);
    objects.push_back(obj1);
    /*Plan *obj2 = new Plan();
    obj2->translate(0,-2,0);
    obj2->rotateX(90*M_PI/180);
    obj2->scale(-8);
    objects.push_back(obj2);
    Square *obj3 = new Square();
    obj3->translate(0,0,3.f);
    //obj3->rotateY(-1);
    obj3->scale(1);
    objects.push_back(obj3);*/
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
                impact = impactTemp;
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

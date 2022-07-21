#include "../include/Scene.h"


using namespace std;

Scene::Scene()
{
    this->ambiantColor = Color(1,1,1);
    this->backgroundColor = Color(0.1,0.1,0.1);
    this->hasShadows = true;

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();
    Triangle *obj = new Triangle(Point(1, 0, -10), Point(0, 1, -10), Point(-1, 0, -10));
    //obj->translate(1.f, 0, -5.f);
    obj->rotateX(0.25);
    objects.push_back(obj);
    /*Square *obj1 = new Square();
    obj1->translate(1,0,5.f);
    obj1->rotateZ(1);
    obj1->scale(1);
    objects.push_back(obj1);
    /*Plan *obj2 = new Plan();

    //Sphere
    Sphere *obj = new Sphere(Point(1.f,0,10.f), 1, TextureMode::Ligne);
    cout << obj->trans(2,3);
    obj->rotateY(1);
    objects.push_back(obj);

    //Plan
    Plan *obj2 = new Plan();
    obj2->translate(0,-2,0);
    obj2->rotateX(90*M_PI/180);
    obj2->scale(-8);
    objects.push_back(obj2);
    Square *obj3 = new Square();
    obj3->translate(0,0,3.f);
    //obj3->rotateY(-1);
    obj3->scale(1);
    objects.push_back(obj3);*/

    //Square
    //Square *obj3 = new Square(Point(0,0,3), 1, TextureMode::Ligne);
    //obj3->rotateY(0);
    //objects.push_back(obj3);

    //Light
    lights.push_back(new Light());
}


Scene::Scene(Color backgroundColor, Color ambiantColor, bool shadows)
{
    this->ambiantColor = ambiantColor;
    this->backgroundColor = backgroundColor;
    this->hasShadows = shadows;

    this->lights = vector<Light*>();
    this->objects = vector<Object*>();

    //Sphere
    Sphere *obj = new Sphere(Point(1.f,0,10.f), 1, TextureMode::Ligne);
    obj->rotateY(1);
    objects.push_back(obj);

    //Plan
    Plan *obj2 = new Plan();
    obj2->translate(0,-2,0);
    obj2->rotateX(90*M_PI/180);
    obj2->scale(-8);
    objects.push_back(obj2);

    //Square
    Cube *obj3 = new Cube(Point(0,0,10.f), 1, TextureMode::Damier);
    //obj3->rotateY(0);
    objects.push_back(obj3);

    //Light
    lights.push_back(new Light());
}


Scene::Scene(Color backgroundColor, Color ambiantColor, bool shadows, vector<Light*> lights, vector<Object*> objects)
{
    this->ambiantColor = ambiantColor;
    this->backgroundColor = backgroundColor;
    this->hasShadows = shadows;

    this->lights = lights;
    this->objects = objects;
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

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include"Application.h"

using namespace std;

int main(int argc, char **argv) {
    if(argc < 4) {
        cout << "Erreur : Pas assez d'arguments \n";
        cout << "main.exe 1:scene.txt 2:result.jpeg 3:hasShadow \n";
        cout << "1: Fichier qui contient la taille de la scene et de l'image \n";
        cout << "2: Nom de l'image a sauvegarder avec le format d'image voulue \n";
        cout << "3: Entier qui determine si la scene contient des ombres (0 = pas d'ombres, 1 = ombres) \n";
        return -1;
    }

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Impossible d'initialiser SDL: %sn", SDL_GetError());
        exit(1);
    }

    Application app = Application(argv[1], argv[2], stoi(argv[3]));

    app.initSDL();

    /*Sphere *obj = new Sphere(Point(0.f,10.f, 90.f), 10, TextureMode::Ligne);
    obj->rotateY(1);
    app.scene->objects.push_back(obj);
    Sphere *obj3 = new Sphere(Point(3.f, 5.f, 40.f), 5, TextureMode::Ligne);
    obj3->rotateY(1);
    app.scene->objects.push_back(obj3);
    Cone *obj1 = new Cone(Point(0.f, 0, 80), 2., 4.);
    obj1->rotateZ(0.25);
    app.scene->objects.push_back(obj1);


    //Triangle *obj2 = new Triangle(Point(1.f, 0, -5), Point(0.f, 1.0f, -5), Point(-1.f, 0, -5), TextureMode::Monochrome);
    //objects.push_back(obj2);
    Plan *obj2 = new Plan();
    j2->translate(0,-2,0);
    obj2->rotateX(90*M_PI/180);
    obj2->scale(-8);
    app.scene->objects.push_back(obj2);

    app.scene->lights.push_back(new Light());*/


    app.prepareScene();

    printf("Fin de lecture \n");

	app.image.save();

	while (1) {
		app.doInput();
		app.presentScene();
		SDL_Delay(16);
	}

    atexit(SDL_Quit);
    return 0;
}

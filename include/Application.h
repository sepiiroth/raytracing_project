#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include "Camera.h"
#include "Scene.h"
#include "Utils.h"
#include "Image.h"

class Application {
    private:

    public:
        SDL_Renderer *renderer;
        SDL_Window *window;
        Image image;

        Camera *camera;
        Scene *scene;

        int screen_width, screen_height;

        Application();
        Application(int w, int h);
        Application(const char* inputName);
        Application(const char* inputName, const char* imageName, bool hasShadows);
        virtual ~Application();

        void initSDL(); // Permet d'initialiser la fenetre de visualisation de la scène
        void doInput(); // Permet de gérer les inputs
        void prepareScene(); // Permet de charger les objets sur la scène avant l'affichage
        void presentScene(); // Afficher la scène
};

#endif

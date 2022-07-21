#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include <iostream>

#include <fstream>
#include "Camera.h"
#include "Scene.h"
#include "Utils.h"
#include "Image.h"

class Application
{
    public:
        Application();
        Application(int w, int h);
        Application(const char* inputName);
        Application(const char* inputName, const char* imageName, bool hasShadows);
        virtual ~Application();

        SDL_Renderer *renderer;
        SDL_Window *window;
        Image image;

        Camera *camera;
        Scene *scene;

        int screen_width, screen_height;

        void initSDL();
        void doInput();
        void prepareScene();
        void presentScene();

    protected:

    private:
};

#endif // APPLICATION_H

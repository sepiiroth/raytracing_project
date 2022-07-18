#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include <iostream>
#include "Camera.h"
#include "Scene.h"

class Application
{
    public:
        Application();
        Application(int w, int h);
        virtual ~Application();

        SDL_Renderer *renderer;
        SDL_Window *window;

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

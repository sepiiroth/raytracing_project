#ifndef APPLICATION_H
#define APPLICATION_H
#include <SDL2/SDL.h>
#include <iostream>


class Application
{
    public:
        Application();
        Application(int w, int h);
        virtual ~Application();

        SDL_Renderer *renderer;
        SDL_Window *window;

        int screen_width, screen_height;

        void initSDL();
        void doInput();
        void prepareScene();
        void presentScene();

    protected:

    private:
};

#endif // APPLICATION_H

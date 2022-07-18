#include "../include/Application.h"

Application::Application()
{
    //ctor
}

Application::Application(int w, int h)
{
    this->screen_width = w;
    this->screen_height = h;
}

Application::~Application()
{
    //dtor
}

void Application::initSDL()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
	}

	this->window = SDL_CreateWindow("Lancer de Rayon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->screen_width, this->screen_height, windowFlags);

	if (!this->window)
	{
		printf("Failed to open %d x %d window: %s\n", this->screen_width, this->screen_height, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	this->renderer = SDL_CreateRenderer(this->window, -1, rendererFlags);

	if (!this->renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}

void Application::doInput()
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			default:
				break;
		}
	}
}

void Application::prepareScene()
{
	SDL_SetRenderDrawColor(this->renderer, 96, 128, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_SetRenderDrawColor(this->renderer, 255, 128, 96, 255);

}

void Application::presentScene()
{
	SDL_RenderPresent(this->renderer);
}

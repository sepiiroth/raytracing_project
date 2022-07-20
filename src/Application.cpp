#include "../include/Application.h"

Application::Application()
{
    this->screen_width = 600;
    this->screen_height = 600;
    this->camera = new Camera();
    this->scene = new Scene();
    this->index = 0;
}

Application::Application(int w, int h)
{
    this->screen_width = w;
    this->screen_height = h;
    this->camera = new Camera();
    this->scene = new Scene();
    this->index = 0;
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

	for(float y = 0; y < this->screen_height; y++)
    {
        for(float x = 0; x < this->screen_width; x++)
        {
            Ray ray = camera->getRay(x / this->screen_width, y/this->screen_height);
            Point impact;
            auto inter = /*scene->objects[0]->intersect(ray, impact);*/ scene->closer_intersected(ray, impact);


            if(inter)
            {
                //impact.display();
                Object o = *(inter);
                Color c = getImpactColor(ray, o, impact, *scene);
                //exit(-1);

                SDL_SetRenderDrawColor(this->renderer, c[0] * 255, c[1] * 255, c[2] * 255, 255 );
            }else{
                SDL_SetRenderDrawColor(this->renderer, scene->getBackground()[0] * 255, scene->getBackground()[1] * 255, scene->getBackground()[2] * 255, 255);
            }
            SDL_RenderDrawPoint(this->renderer, x, y);
        }
    }

    index++;
    scene->objects[0]->rotateY((this->index%360) * M_PI / 180);

}

void Application::presentScene()
{
	SDL_RenderPresent(this->renderer);
}

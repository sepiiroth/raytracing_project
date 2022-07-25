#include "Application.h"

Application::Application() {
    this->screen_width = 600;
    this->screen_height = 600;
    this->camera = new Camera();
    this->scene = new Scene();
    this->image = Image(600,600);

    cout << "Taille de la scene : 600x600" << endl;
    cout << "Ombre : Active" << endl;
    cout << "Image de sortie : image.jpg" << endl;
}

Application::Application(int w, int h) {
    this->screen_width = w;
    this->screen_height = h;
    this->camera = new Camera();
    this->scene = new Scene();
    this->image = Image(h,w);

    cout << "Taille de la scene : " << h << "x" << w << endl;
    cout << "Ombre : Active" << endl;
    cout << "Image de sortie : image.jpg" << endl;
}

Application::Application(const char* inputName) {
    ifstream sceneFile(inputName);
    if (!sceneFile) {
        printf("Fichier scene non existante !");
        exit(-1);
    }
    sceneFile >> this->screen_width >> this->screen_height;
    this->camera = new Camera();
    this->scene = new Scene();
    this->image = Image(this->screen_height,this->screen_width);

    cout << "Taille de la scene : " << this->screen_height << "x" << this->screen_width << endl;
    cout << "Ombre : Active" << endl;
    cout << "Image de sortie : image.jpg" << endl;
}

Application::Application(const char* inputName, const char* imageName, bool hasShadows) {
    ifstream sceneFile(inputName);
    if (!sceneFile) {
        printf("Fichier scene non existante !");
        exit(-1);
    }
    sceneFile >> this->screen_width >> this->screen_height;
    this->camera = new Camera();
    vector<Material> materials = vector<Material>();
    vector<Object*> objects = vector<Object*>();
    vector<Light*> ligthss = vector<Light*>();
    printf("Chargement de la scene en cours...\n");
    char p;
    Object* obj = nullptr;
    float posX, posY, posZ, sca, x, y, z, rotX, rotY, rotZ, sc, matera, rad, hei;
    float posX1, posY1, posZ1, posX2, posY2, posZ2;
    int tex;
    Material m;

    while(!sceneFile.eof()) {
        sceneFile >> p;
        switch(p) {
            case 'M':
                float ka0, ka1, ka2, kd0, kd1, kd2, ks0, ks1, ks2, sh;
                sceneFile >> ka0 >> ka1 >> ka2 >> kd0 >> kd1 >> kd2 >> ks0 >> ks1 >> ks2 >> sh;
                m = Material(Color(ka0, ka1, ka2), Color(kd0, kd1, kd2), Color(ks0, ks1, ks2), sh);
                materials.push_back(m);
                break;
            case 'P':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                obj = new Plan((TextureMode)tex);
                objects.push_back(obj);
                break;
            case 'S':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                sceneFile >> posX >> posY >> posZ >> sca;
                obj = new Sphere(Point(posX, posY, posZ), sca, (TextureMode)tex);
                objects.push_back(obj);
                break;
            case 'C':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                sceneFile >> posX >> posY >> posZ >> sca;
                obj = new Cube(Point(posX, posY, posZ), sca, (TextureMode)tex);
                objects.push_back(obj);
                break;
            case 'T':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                sceneFile >> posX >> posY >> posZ >> posX1 >> posY1 >> posZ1 >> posX2 >> posY2 >> posZ2;
                obj = new Triangle(Point(posX, posY, posZ), Point(posX1, posY1, posZ1), Point(posX2, posY2, posZ2), (TextureMode)tex);
                objects.push_back(obj);
                break;
            case 'O':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                sceneFile >> posX >> posY >> posZ >> rad >> hei;
                obj = new Cone(Point(posX, posY, posZ), rad, hei);
                objects.push_back(obj);
                break;
            case 'Q':
                sceneFile >> x >> y >> z >> rotX >> rotY >> rotZ >> sc >> matera >> tex;
                sceneFile >> posX >> posY >> posZ >> sca;
                obj = new Square(Point(posX, posY, posZ), sca, (TextureMode)tex);
                objects.push_back(obj);
                break;
        }
        if(obj) {
            obj->translate(x,y,z);
            obj->rotateX(rotX*M_PI/180);
            obj->rotateY(rotY*M_PI/180);
            obj->rotateZ(rotZ*M_PI/180);
            obj->scale(sc);
            obj->mat = materials[matera];
            obj->textureMode = (TextureMode)tex;
        }
    }

    if(sceneFile.eof()) {
        sceneFile.close();
    }

    ligthss.push_back(new Light());

    this->scene = new Scene(Color(0.1,0.1,0.1), Color(1.0,1.0,1.0), hasShadows, ligthss, objects);
    this->image = Image(this->screen_height,this->screen_width, imageName);
    auto sO = "Active";
    if(!hasShadows)
        sO = "Desactive";
    cout << "Taille de la scene : " << this->screen_height << "x" << this->screen_width << endl;
    cout << "Ombre : " << sO << endl;
    cout << "Image de sortie : " << imageName << endl;
}

Application::~Application() {
    //dtor
}

void Application::initSDL() {
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

void Application::doInput() {
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

void Application::prepareScene() {

	SDL_SetRenderDrawColor(this->renderer, 96, 128, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_SetRenderDrawColor(this->renderer, 255, 128, 96, 255);

	for(float y = 0; y < this->screen_height; y++)
    {
        for(float x = 0; x < this->screen_width; x++)
        {
            Ray ray = camera->getRay(x / this->screen_width, y/this->screen_height);
            Point impact;
            auto inter = scene->closer_intersected(ray, impact);

            Color c;
            if(inter)
            {
                Object* o = inter;
                c = getImpactColorPhong(ray, o, impact, *scene);

                if(scene->hasShadows)
                    getShadow(ray, o, impact, *scene, c);
                SDL_SetRenderDrawColor(this->renderer, c[0] * 255, c[1] * 255, c[2] * 255, 255 );
            }else{
                c = Color(scene->getBackground()[0], scene->getBackground()[1],scene->getBackground()[2]);
                SDL_SetRenderDrawColor(this->renderer, scene->getBackground()[0] * 255, scene->getBackground()[1] * 255, scene->getBackground()[2] * 255, 255);
            }
            image(x, y, 0) = c[0] * 255;
            image(x, y, 1) = c[1] * 255;
            image(x, y, 2) = c[2] * 255;
            image(x, y, 3) = 255;
            SDL_RenderDrawPoint(this->renderer, x, y);
        }
    }
}

void Application::presentScene() {
	SDL_RenderPresent(this->renderer);
}

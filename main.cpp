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

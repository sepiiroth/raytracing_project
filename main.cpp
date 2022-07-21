#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include<math.h>
#include"Point.h"
#include"Vector.h"
#include"Ray.h"
#include"HPoint.h"
#include"HVector.h"
#include"HRay.h"
#include"Matrix.h"
#include"Application.h"
#include <SDL2/SDL.h>

using namespace std;

int main(int argc, char **argv) {
    if(argc < 4)
    {
        cout << "Pas assez d'arguments";
        return -1;
    }

    Matrix m;
	m(0, 0) = -1;
	m(0 ,1) = 0;
	m(0 ,2) = 1;
	m(0 ,3) = 1;
	m(1, 0) = 1;
	m(1, 1) = -2;
	m(1, 2) = 1;
	m(1, 3) = -1;
	m(2, 0) = 1;
	m(2, 1) = 0;
	m(2, 2) = -1;
	m(2, 3) = 1;
	m(3, 0) = 1;
	m(3, 1) = 0;
	m(3, 2) = 1;
	m(3, 3) = -1;
	Matrix m1;
	m1(0, 0) = 1;
	m1(0 ,1) = 0;
	m1(0 ,2) = 0;
	m1(0 ,3) = 1;
	m1(1, 0) = 0;
	m1(1, 1) = 1;
	m1(1, 2) = 0;
	m1(1, 3) = 1;
	m1(2, 0) = 0;
	m1(2, 1) = 0;
	m1(2, 2) = 1;
	m1(2, 3) = 1;
	m1(2, 3) = 1;
	m1(3, 0) = 0;
	m1(3, 1) = 0;
	m1(3, 2) = 0;
	m1(3, 3) = 1;
	/*Vector vec(1, 2, 3);
    Matrix result = m1.inverse();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%f ", result(i, j));
        }
        printf("\n");
    }*/


    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        fprintf(stderr, "Impossible d'initialiser SDL: %sn", SDL_GetError());
        exit(1);
    }

    Application app = Application(argv[1], argv[2], stoi(argv[3]));

    app.initSDL();

    app.prepareScene();
	app.image.save();
	while (1)
	{

		app.doInput();

		app.presentScene();

		SDL_Delay(16);
	}



    atexit(SDL_Quit);

    return 0;
}

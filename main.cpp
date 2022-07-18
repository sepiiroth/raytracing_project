#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"Point.h"
#include"Vector.h"
#include"Ray.h"
#include"HPoint.h"
#include"HVector.h"
#include"HRay.h"
#include"Matrix.h"


int main(int argc, char **argv) {
    Matrix m;
	m(0, 0) = 0;
	m(0 ,1) = -7;
	m(0 ,2) = 0;
	m(0 ,3) = -4;
	m(1, 0) = 0;
	m(1, 1) = 0;
	m(1, 2) = 1;
	m(1, 3) = 0;
	m(2, 0) = 0;
	m(2, 1) = 8/3;
	m(2, 2) = 0;
	m(2, 3) = -2;
	m(3, 0) = -5;
	m(3, 1) = 0;
	m(3, 2) = 6/5;
	m(3, 3) = -6;
    Matrix result = m.inverse();
    printf("%f \n", result(0, 0));
    /*for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("%f ", result(i, j));
        }
        printf("\n");
    }*/
    return 0;
}

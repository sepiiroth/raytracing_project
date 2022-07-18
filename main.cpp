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
	m1(0, 0) = -1;
	m1(0 ,1) = 1;
	m1(0 ,2) = 0;
	m1(0 ,3) = 1;
	m1(1, 0) = 1;
	m1(1, 1) = -1;
	m1(1, 2) = 0;
	m1(1, 3) = 1;
	m1(2, 0) = -1;
	m1(2, 1) = 1;
	m1(2, 2) = -2;
	m1(2, 3) = 1;
	m1(3, 0) = 1;
	m1(3, 1) = 1;
	m1(3, 2) = 0;
	m1(3, 3) = -1;
	HVector vec(1, 2, 3);
    Vector result = m * vec;
    for(int i = 0; i < 3; i++) {
        printf("%f ", result[i]);
    }
    return 0;
}

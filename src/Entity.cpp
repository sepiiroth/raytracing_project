#include "Entity.h"
#include <math.h>

Entity::Entity() {}

void Entity::translate(float x, float y, float z){
		Matrix m;
		m(0, 3) = x;
		m(1 ,3) = y;
		m(2, 3) = z;
		trans = m*trans;
		//transInv = trans.inverse();
}

void Entity::rotateX(float deg){
	Matrix m;
	m(0, 0) = 1;
	m(1 ,1) = cos(deg);
	m(1, 2) = -sin(deg);
	m(2, 1) = sin(deg);
	m(2, 2) = cos(deg);
	trans = m*trans;
	//transInv = trans.inverse();
}

void Entity::rotateY(float deg){
    Matrix m;
	m(0, 0) = cos(deg);
	m(0 ,2) = sin(deg);
	m(1, 1) = 1;
	m(2, 0) = -sin(deg);
	m(2, 2) = cos(deg);
	trans = m*trans;
	//transInv = trans.inverse();
}

void Entity::rotateZ(float deg){
	Matrix m;
	m(0, 0) = cos(deg);
	m(0 ,1) = -sin(deg);
	m(1, 0) = sin(deg);
	m(1, 1) = cos(deg);
	m(2, 2) = 1;
	trans = m*trans;
	//transInv = trans.inverse();
}

void Entity::scale(float factor){
    Matrix m;
	m(0, 0) = factor;
	m(1 ,1) = factor;
	m(2, 2) = factor;
	trans = m*trans;
	//transInv = trans.inverse();
}

/*Point Entity::localToGlobal(const Point& p) const {
    HPoint hpoint(p);

	return transInv*hpoint;
}

Vector Entity::localToGlobal(const Vector& v) const {
    HVector hpoint(v);

	return transInv*hpoint;
}

Ray Entity::localToGlobal(const Ray& r) const {
    HRay hray(r);
  	return Ray(transInv*hray.origin, transInv*hray.vec);
}*/

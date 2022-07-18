#include "Entity.h"
#include <math.h>

Entity::Entity() {
    this->trans = Matrix(4,4);
    trans(0,0) = 1.f;
    trans(1,1) = 1.f;
    trans(2,2) = 1.f;
    trans(3,3) = 1.f;
    this->transInv = Matrix(4,4);
    transInv(0,0) = 1.f;
    transInv(1,1) = 1.f;
    transInv(2,2) = 1.f;
    transInv(3,3) = 1.f;
}

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

Point Entity::globalToLocal(const Point& p) const
{
    HPoint temp(p);
    Point point = this->trans * temp;
    cout << "\n" << point[0] << ", " << point[1] << ", " << point[2] << endl;
	return point;
}

Ray Entity::globalToLocal(const Ray& r) const{
    HRay temp(r);
  	return Ray(trans*temp.origin, trans*temp.vec);

}

Vector Entity::globalToLocal(const Vector v) const{
    HVector temp(v);
	return trans*temp;
}

Point Entity::localToGlobal(const Point& p) const{
    HPoint temp(p);
	return transInv*temp;
}

Ray Entity::localToGlobal(const Ray& r) const{
    HRay temp(r);

  	return Ray(transInv*temp.origin, transInv*temp.vec);

}

Vector Entity::localToGlobal(const Vector v) const{
    HVector temp(v);
	return transInv*temp;
}

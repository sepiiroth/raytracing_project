#include "Vector.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

Vector::Vector() {
    this->m_x = 0;
    this->m_y = 0;
    this->m_z = 0;
}

Vector::Vector(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}

Vector::Vector(const Vector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
}

Vector::Vector(const Point &p) {
    this->m_x = p[0];
    this->m_y = p[1];
    this->m_z = p[2];
}

float Vector::getX() const {
    return this->m_x;
}

float Vector::getY() const {
    return this->m_y;
}

float Vector::getZ() const {
    return this->m_z;
}


void Vector::setX(float x) {
    this->m_x = x;
}

void Vector::setY(float y) {
    this->m_y = y;
}

void Vector::setZ(float z) {
    this->m_z = z;
}

Vector Vector::operator+(const Vector &vec) {
    return Vector(this->m_x + vec.getX(), this->m_y + vec.getY(), this->m_z + vec.getZ());
}

Vector &Vector::operator+=(const Vector &vec) {
    this->m_x += vec.getX();
    this->m_y += vec.getY();
    this->m_z += vec.getZ();
    return *this;
}

const Vector Vector::operator-(const Vector &vec) {
    return Vector(this->m_x - vec.getX(), this->m_y - vec.getY(), this->m_z - vec.getZ());
}

Vector &Vector::operator-=(const Vector &vec) {
    this->m_x -= vec.getX();
    this->m_y -= vec.getY();
    this->m_z -= vec.getZ();
    return *this;
}

Vector Vector ::operator*(float v) {
    return Vector(this->m_x * v,this->m_y * v,this->m_z * v);
}

Vector &Vector::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

Vector Vector ::operator/(float v) {
    assert(v!=0);
    return Vector(this->m_x / v, this->m_y/v, this->m_z/v);
}

Vector &Vector ::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

Vector &Vector::operator=(const Vector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
    return *this;
}

Vector &Vector::operator=(const Point &point) {
    this->m_x = point[0];
    this->m_y = point[1];
    this->m_z = point[2];
    return *this;
}


/*float Vector::operator[](int value) const{
    switch(value) {
        case 0:
            return this->m_x;
            break;
        case 1:
            return this->m_y;
            break;
        case 2:
            return this->m_z;
            break;
        default:
            printf("Erreur lors de la lecture de la coordonnee d'un Vector\n");
            return -1;
            break;
    }
}*/

float &Vector::operator[](int value) {
    if(value < 3) {
        switch(value) {
        case 0:
            return this->m_x;
            break;
        case 1:
            return this->m_y;
            break;
        case 2:
            return this->m_z;
            break;
        }
    } else throw std::out_of_range("invalid value");
}

float Vector::operator[](int value) const {
    if(value < 3) {
        switch(value) {
        case 0:
            return this->m_x;
            break;
        case 1:
            return this->m_y;
            break;
        case 2:
            return this->m_z;
            break;
        }
    } else throw std::out_of_range("invalid value");
}

Vector Vector::operator-() const{
    return Vector(-(this->m_x), -(this->m_y), -(this->m_z));
}


float Vector::dot(const Vector &vec) {
    return this->m_x * vec.getX() + vec.getY() * this->m_y + vec.getZ() * this->m_z;
}

float Vector::norm()
{
    return sqrt(square());
}

float Vector::square() {
    return this->m_x * this->m_x + this->m_y * this->m_y + this->m_z * this->m_z;
}

Vector Vector::normalized() {
    if(norm() > 0)
    {
        *this/=norm();
    }
    return *this;
}

Vector Vector::cross(const Vector &v)
{
	float Nx = (this->m_y * v[2]) - (this->m_z * v[1]);
	float Ny = (this->m_z * v[0]) - (this->m_x * v[2]);
	float Nz = (this->m_x * v[1]) - (this->m_y * v[0]);
	return Vector(Nx, Ny, Nz);
}


void Vector::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<endl;
}

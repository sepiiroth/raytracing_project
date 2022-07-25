#include "Vector3.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

/*Initialisation*/
Vector3::Vector3() {
    this->m_x = 0;
    this->m_y = 0;
    this->m_z = 0;
}

Vector3::Vector3(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
}

Vector3::Vector3(const Vector3 &vec) {
    this->m_x = vec[0];
    this->m_y = vec[1];
    this->m_z = vec[2];
}

/*Operations*/
Vector3 Vector3::operator+(const Vector3 &vec) {
    return Vector3(this->m_x + vec[0], this->m_y + vec[1], this->m_z + vec[2]);
}

Vector3 &Vector3::operator+=(const Vector3 &vec) {
    this->m_x += vec[0];
    this->m_y += vec[1];
    this->m_z += vec[2];
    return *this;
}

Vector3 Vector3::operator-(const Vector3 &vec) {
    return Vector3(this->m_x - vec[0], this->m_y - vec[1], this->m_z - vec[2]);
}

Vector3 &Vector3::operator-=(const Vector3 &vec) {
    this->m_x -= vec[0];
    this->m_y -= vec[1];
    this->m_z -= vec[2];
    return *this;
}

Vector3 Vector3::operator*(float v) {
    return Vector3(this->m_x * v,this->m_y * v,this->m_z * v);
}

Vector3 &Vector3::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

Vector3 Vector3::operator/(float v) {
    assert(v!=0); // Vérifie que v soit différent de 0, sinon un message d'erreur apparait
    return Vector3(this->m_x/v, this->m_y/v, this->m_z/v);
}

Vector3 &Vector3::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

Vector3 &Vector3::operator=(const Vector3 &vec) {
    this->m_x = vec[0];
    this->m_y = vec[1];
    this->m_z = vec[2];
    return *this;
}

float &Vector3::operator[](int value) {
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
    } else throw out_of_range("Valeur invalide!");
}

float Vector3::operator[](int value) const {
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
    } else throw out_of_range("Valeur invalide!");
}

Vector3 Vector3::operator-() const{
    return Vector3(-(this->m_x), -(this->m_y), -(this->m_z));
}

/*Calculs*/
float Vector3::dot(const Vector3 &vec) {
    return this->m_x * vec[0] + this->m_y * vec[1] + this->m_z * vec[2];
}

float Vector3::norm() {
    return sqrt(square());
}

float Vector3::square() {
    return this->m_x * this->m_x + this->m_y * this->m_y + this->m_z * this->m_z;
}

Vector3 Vector3::normalized() {
    if(norm() > 0) {
        *this/=norm();
    }
    return *this;
}

Vector3 Vector3::cross(const Vector3 &v) {
	float Nx = (this->m_y * v[2]) - (this->m_z * v[1]);
	float Ny = (this->m_z * v[0]) - (this->m_x * v[2]);
	float Nz = (this->m_x * v[1]) - (this->m_y * v[0]);
	return Vector3(Nx, Ny, Nz);
}

float Vector3::distanceTo(const Vector3& B) {
    return sqrt(pow((B[0] - this->m_x), 2.) + pow((B[1] - this->m_y), 2.));
}

/*Affiche le vecteur*/
void Vector3::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<"\n"<<endl;
}

#include "HVector.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

HVector::HVector() {
    this->m_x = 0;
    this->m_y = 0;
    this->m_z = 0;
    this->m_w = 0;
}

HVector::HVector(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->m_w = 0;
}

HVector::HVector(const HVector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
    this->m_w = 0;
}

float HVector::getX() const {
    return this->m_x;
}

float HVector::getY() const {
    return this->m_y;
}

float HVector::getZ() const {
    return this->m_z;
}


void HVector::setX(float x) {
    this->m_x = x;
}

void HVector::setY(float y) {
    this->m_y = y;
}

void HVector::setZ(float z) {
    this->m_z = z;
}

HVector HVector::operator+(const HVector &vec) {
    return HVector(this->m_x + vec.getX(), this->m_y + vec.getY(), this->m_z + vec.getZ());
}

HVector &HVector::operator+=(const HVector &vec) {
    this->m_x += vec.getX();
    this->m_y += vec.getY();
    this->m_z += vec.getZ();
    return *this;
}

HVector HVector::operator-(const HVector &vec) {
    return HVector(this->m_x - vec.getX(), this->m_y - vec.getY(), this->m_z - vec.getZ());
}

HVector &HVector::operator-=(const HVector &vec) {
    this->m_x -= vec.getX();
    this->m_y -= vec.getY();
    this->m_z -= vec.getZ();
    return *this;
}

HVector HVector ::operator*(float v) {
    return HVector(this->m_x * v,this->m_y * v,this->m_z * v);
}

HVector &HVector::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

HVector HVector ::operator/(float v) {
    assert(v!=0);
    return HVector(this->m_x / v, this->m_y/v, this->m_z/v);
}

HVector &HVector ::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

HVector &HVector::operator=(const HVector &vec) {
    this->m_x = vec.getX();
    this->m_y = vec.getY();
    this->m_z = vec.getZ();
    return *this;
}

float HVector::operator[](int value) {
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
            printf("Erreur lors de la lecture de la coordonnee d'un HVector\n");
            return -1;
            break;
    }
}

HVector HVector::operator-() {
    return HVector(-(this->m_x), -(this->m_y), -(this->m_z));
}


float HVector::dot(const HVector &vec) {
    return this->m_x * vec.getX() + vec.getY() * this->m_y + vec.getZ() * this->m_z;
}

float HVector::norm()
{
    return sqrt(square());
}

float HVector::square() {
    return this->m_x * this->m_x + this->m_y * this->m_y + this->m_z * this->m_z;
}

HVector HVector::normalized() {
    assert(norm()!=0);
    *this/=norm();
    return *this;
}

void HVector::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<" "<<this->m_w<<endl;
}

#include "HPoint.h"
#include<iostream>
#include<math.h>
#include<assert.h>

using namespace std;

HPoint::HPoint() {
    this->m_x = 0;
    this->m_y = 0;
    this->m_z = 0;
    this->m_w = 1;
}

HPoint::HPoint(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->m_w = 1;
}

float HPoint::getX() const {
    return this->m_x;
}

float HPoint::getY() const {
    return this->m_y;
}
float HPoint::getZ() const {
    return this->m_z;
}

void HPoint::setX(float x) {
    this->m_x = x;
}

void HPoint::setY(float y) {
    this->m_y = y;
}

void HPoint::setZ(float z) {
    this->m_z = z;
}

HPoint HPoint::operator+(const HPoint &p) {
    return HPoint(this->m_x + p.getX(), this->m_y + p.getY(), this->m_z + p.getZ());
}

HPoint &HPoint::operator+=(const HPoint &p) {
    this->m_x += p.getX();
    this->m_y += p.getY();
    this->m_z += p.getZ();
    return *this;
}

HPoint HPoint::operator-(const HPoint &p) {
    return HPoint(this->m_x - p.getX(), this->m_y - p.getY(), this->m_z - p.getZ());
}

HPoint &HPoint::operator-=(const HPoint &p) {
    this->m_x -= p.getX();
    this->m_y -= p.getY();
    this->m_z -= p.getZ();
    return *this;
}

HPoint HPoint::operator*(float v) {
    return HPoint(this->m_x * v,this->m_y * v,this->m_z * v);
}

HPoint &HPoint::operator*=(float v) {
    this->m_x *= v;
    this->m_y *= v;
    this->m_z *= v;
    return *this;
}

HPoint HPoint::operator/(float v) {
    assert(v!=0);
    return HPoint(this->m_x / v, this->m_y/v, this->m_z/v);
}

HPoint &HPoint::operator/=(float v) {
    assert(v!=0);
    this->m_x /= v;
    this->m_y /= v;
    this->m_z /= v;
    return *this;
}

HPoint &HPoint::operator=(const HPoint &p) {
    this->m_x = p.getX();
    this->m_y = p.getY();
    this->m_z = p.getZ();
    this->m_w = 1;
    return *this;
}

float HPoint::operator[](int value) {
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
            printf("Erreur lors de la lecture de la coordonnee d'un HPoint\n");
            return -1;
            break;
    }
}

HPoint HPoint::operator-() {
    return HPoint(-(this->m_x), -(this->m_y), -(this->m_z));
}

float HPoint::dot(const HPoint &p) {
    return this->m_x * p.getX() + p.getY() * this->m_y + p.getZ() * this->m_z;
}

float HPoint::distanceTo(const HPoint& B)
{
    return sqrt(pow(B.getX() - this->getX(), 2) + pow(B.getY() - this->getY(), 2));
}

void HPoint::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<" "<<this->m_w<<endl;
}

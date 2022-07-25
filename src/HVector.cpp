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

HVector::HVector(const Vector3& v)
{
    this->m_x = v[0];
    this->m_y = v[1];
    this->m_z = v[2];
    this->m_w = 0;
}

HVector::HVector(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->m_w = 0;
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
        case 3:
            return this->m_w;
            break;
        default:
            printf("Erreur lors de la lecture de la coordonnee d'un HVector\n");
            return -1;
            break;
    }
}

void HVector::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<" "<<this->m_w<<endl;
}

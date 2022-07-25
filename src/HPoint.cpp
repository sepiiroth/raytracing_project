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

HPoint::HPoint(const Vector3& p)
{
    this->m_x = p[0];
    this->m_y = p[1];
    this->m_z = p[2];
    this->m_w = 1;
}

HPoint::HPoint(float x, float y, float z) {
    this->m_x = x;
    this->m_y = y;
    this->m_z = z;
    this->m_w = 1;
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
        case 3:
            return this->m_w;
            break;
        default:
            printf("Erreur lors de la lecture de la coordonnee d'un HPoint\n");
            return -1;
            break;
    }
}

void HPoint::display() {
    cout<<this->m_x<<" "<<this->m_y<<" "<<this->m_z<<" "<<this->m_w<<endl;
}

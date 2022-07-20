#include "../include/Object.h"

Object::Object()
{
    this->texcoords = Point();
    this->color = Color(1.0f, 0, 0);
    this->trans(2, 3) = 2;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material();
    int m_rows = 10;
    int m_cols = 10;
    texture = new Material[m_rows*m_cols];
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            if((i<5 && j < 5) || i >= 5 && j >= 5)
            {
                texture[i*m_cols+j] = mat;
            }else{
                texture[i*m_cols+j] = Material(Color(0.5, 0.5, 0.5), Color(1, 1, 1), Color(0, 0, 0), 0.0f);
            }
        }
    }
}

Object::~Object()
{
    //dtor
}

Material Object::getMaterial(const Point& p) const
{
    Point tP = getTextureCoordinates(p);
    //tP.display();
    int i = int(tP[0] * 10) * 10 + int(tP[1] * 10);
    //cout <<  << " " <<  << " " << i << endl;
    Material m = texture[i];
    return m;
}

#include "../include/Object.h"

Object::Object()
{
    this->trans = Matrix();
    this->transInv = this->trans.inverse();
    this->mat = Material();
    this->textureMode = TextureMode::Monochrome;
}

Object::Object(Point origin, float scale, TextureMode textureMode, Material material)
{
    this->trans = Matrix();
    this->trans(0, 3) = origin[0];
    this->trans(1, 3) = origin[1];
    this->trans(2, 3) = origin[2];
    this->trans(0, 0) = scale;
    this->trans(1, 1) = scale;
    this->trans(2, 2) = scale;
    this->transInv = this->trans.inverse();
    int m_rows = 10;
    int m_cols = 10;
    texture = new Material[m_rows*m_cols];
    this->mat = material;
    this->textureMode = textureMode;
    switch(textureMode) {
        case TextureMode::Damier:
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
            break;
        case TextureMode::Ligne:
            for(int i = 0; i < m_rows; i++) {
                for(int j = 0; j < m_cols; j++) {
                    if(i%2)
                    {
                        texture[i*m_cols+j] = mat;
                    }else{
                        texture[i*m_cols+j] = Material(Color(0.5, 0.5, 0.5), Color(1, 1, 1), Color(0, 0, 0), 0.0f);
                    }
                }
            }
            break;

    }

}

Object::~Object()
{
    //dtor
}

Material Object::getMaterial(const Point& p) const
{
    switch(this->textureMode)
    {
        case TextureMode::Monochrome:
            return this->mat;
            break;
        default:
            Point tP = getTextureCoordinates(p);
            int i = int(tP[0] * 10) * 10 + int(tP[1] * 10);
            Material m = texture[i];
            return m;
            break;
    }

}

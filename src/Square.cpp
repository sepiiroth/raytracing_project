#include "Square.h"

Square::Square()
{
    this->texcoords = Point();
    this->trans(2, 3) = 0;
    this->trans(0, 0) = 2;
    this->trans(1, 1) = 2;
    this->trans(2, 2) = 2;
    this->transInv = this->trans.inverse();
    this->mat = Material(Color(0.5, 0.1, 0.1), Color(0.75, 0.5, 0.5), Color(0, 0, 0), 0.0f);
    int m_rows = 10;
    int m_cols = 10;
    texture = new Material[m_rows*m_cols];
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            if((i<5 && j < 5) || i >= 5 && j >= 5)
            {
                cout << "A ";
                texture[i*m_cols+j] = mat;
            }else{
                cout << "B ";
                texture[i*m_cols+j] = Material(Color(0.5, 0.5, 0.5), Color(1, 1, 1), Color(0, 0, 0), 0.0f);
            }
        }
        cout << endl;
    }
}

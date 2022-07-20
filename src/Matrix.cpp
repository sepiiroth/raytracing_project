#include "Matrix.h"
#define EPS 1e-10

Matrix::Matrix() {
    m_rows = 4;
    m_cols = 4;
    m_tab = new float[m_rows*m_cols];
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            m_tab[i*m_cols+j] = 0;
        }
    }
    m_tab[0*m_cols+0] = 1;
    m_tab[1*m_cols+1] = 1;
    m_tab[2*m_cols+2] = 1;
    m_tab[3*m_cols+3] = 1;
}

Matrix::Matrix(int l_num, int c_num, float remp) {
    m_rows = l_num;
    m_cols = c_num;
    m_tab = new float[m_rows*m_cols];
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            m_tab[i*m_cols+j] = remp;
        }
    }
}

Matrix::Matrix(const Matrix &m) {
    m_rows = m.m_rows;
    m_cols = m.m_cols;
    m_tab = new float[m_rows*m_cols];
    for(int i = 0; i < m_rows; i++) {
        for(int j = 0; j < m_cols; j++) {
            m_tab[i*m_cols+j] = m.m_tab[i*m_cols+j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& m) {
    Matrix tmp = m;
    swap(tmp);
    return *this;
}

void Matrix::swap(Matrix& m) {
    std::swap(m_rows, m.m_rows);
    std::swap(m_cols, m.m_cols);
    std::swap(m_tab, m.m_tab);
}

int Matrix::getCols() const {
    return m_cols;
}

int Matrix::getRows() const {
    return m_rows;
}

void Matrix::set(int i, int j, float val) {
    m_tab[i*m_cols+j] = val;
}

int Matrix::get(int i, int j) const {
    return m_tab[i*m_cols+j];
}

float& Matrix::operator[](int index) {
    return m_tab[index];
}

float& Matrix::operator()(int i,int j) {
    return  m_tab[j+i*m_cols];
}

float Matrix::operator[](int index) const {
    return m_tab[index];
}

float Matrix::operator()(int i,int j) const {
    return  m_tab[j+i*m_cols];
}

Matrix Matrix::operator*(Matrix m) {
    Matrix c;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float num = 0;
            for (int k = 0; k < 4; k++) {
                num += (*this)(i, k) * m(k, j);
            }
            c(i, j) = num;
        }
    }
    return c;
}

Point Matrix::operator*(HPoint p) const{
    Point point;
    float num = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            num = 0;
            for (int k = 0; k < 4; k++) {
                num += (*this)(j, k) * p[k];
            }
            if(j < 3)
            {
                point[j] = num;
            }

        }
    }
    return point;
}

Vector Matrix::operator*(HVector v) const{
    Vector vec;
    float num = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            num = 0;
            for (int k = 0; k < 4; k++) {
                num += (*this)(j, k) * v[k];
            }
            switch(j) {
                case 0:
                    vec.setX(num);
                    break;
                case 1:
                    vec.setY(num);
                    break;
                case 2:
                    vec.setZ(num);
                    break;
            }
        }
    }
    return vec;
}

float& Matrix::at(int index) {
    if(index < 0 || index >= m_rows*m_cols) {
        throw std::out_of_range("index out of range");
    }
    return m_tab[index];
}

float& Matrix::at(int i,int j) {
    if(i < 0 || i >= m_rows) {
        throw std::out_of_range("i out of range");
    }
    if(j < 0 || j >= m_cols) {
        throw std::out_of_range("j out of range");
    }
    return  m_tab[j+i*m_cols];
}

float Matrix::at(int index) const {
    if(index < 0 || index >= m_rows*m_cols) {
        throw std::out_of_range("index out of range");
    }
    return m_tab[index];
}

float Matrix::at(int i,int j) const {
    if(i < 0 || i >= m_rows) {
        throw std::out_of_range("i out of range");
    }
    if(j < 0 || j >= m_cols) {
        throw std::out_of_range("j out of range");
    }
    return  m_tab[j+i*m_cols];
}

Matrix Matrix::inverse() {

    float A2323 = (*this)(2, 2) * (*this)(3, 3) - (*this)(2, 3) * (*this)(3, 2);
    float A1323 = (*this)(2, 1) * (*this)(3, 3) - (*this)(2, 3) * (*this)(3, 1);
    float A1223 = (*this)(2, 1) * (*this)(3, 2) - (*this)(2, 2) * (*this)(3, 1);
    float A0323 = (*this)(2, 0) * (*this)(3, 3) - (*this)(2, 3) * (*this)(3, 0);
    float A0223 = (*this)(2, 0) * (*this)(3, 2) - (*this)(2, 2) * (*this)(3, 0);
    float A0123 = (*this)(2, 0) * (*this)(3, 1) - (*this)(2, 1) * (*this)(3, 0);
    float A2313 = (*this)(1, 2) * (*this)(3, 3) - (*this)(1, 3) * (*this)(3, 2);
    float A1313 = (*this)(1, 1) * (*this)(3, 3) - (*this)(1, 3) * (*this)(3, 1);
    float A1213 = (*this)(1, 1) * (*this)(3, 2) - (*this)(1, 2) * (*this)(3, 1);
    float A2312 = (*this)(1, 2) * (*this)(2, 3) - (*this)(1, 3) * (*this)(2, 2);
    float A1312 = (*this)(1, 1) * (*this)(2, 3) - (*this)(1, 3) * (*this)(2, 1);
    float A1212 = (*this)(1, 1) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 1);
    float A0313 = (*this)(1, 0) * (*this)(3, 3) - (*this)(1, 3) * (*this)(3, 0);
    float A0213 = (*this)(1, 0) * (*this)(3, 2) - (*this)(1, 2) * (*this)(3, 0);
    float A0312 = (*this)(1, 0) * (*this)(2, 3) - (*this)(1, 3) * (*this)(2, 0);
    float A0212 = (*this)(1, 0) * (*this)(2, 2) - (*this)(1, 2) * (*this)(2, 0);
    float A0113 = (*this)(1, 0) * (*this)(3, 1) - (*this)(1, 1) * (*this)(3, 0);
    float A0112 = (*this)(1, 0) * (*this)(2, 1) - (*this)(1, 1) * (*this)(2, 0);

    //Calcul du determinant
    float det = (*this)(0, 0) * ((*this)(1, 1) * A2323 - (*this)(1, 2) * A1323 + (*this)(1, 3) * A1223)
        - (*this)(0, 1) * ((*this)(1, 0) * A2323 - (*this)(1, 2) * A0323 + (*this)(1, 3) * A0223)
        + (*this)(0, 2) * ((*this)(1, 0) * A1323 - (*this)(1, 1) * A0323 + (*this)(1, 3) * A0123)
        - (*this)(0, 3) * ((*this)(1, 0) * A1223 - (*this)(1, 1) * A0223 + (*this)(1, 2) * A0123);
    det = 1 / det;

    Matrix ret;

    ret(0, 0) = det * ((*this)(1, 1) * A2323 - (*this)(1, 2) * A1323 + (*this)(1, 3) * A1223);
    ret(0, 1) = det * -((*this)(0, 1) * A2323 - (*this)(0, 2) * A1323 + (*this)(0, 3) * A1223);
    ret(0, 2) = det * ((*this)(0, 1) * A2313 - (*this)(0, 2) * A1313 + (*this)(0, 3) * A1213);
    ret(0, 3) = det * -((*this)(0, 1) * A2312 - (*this)(0, 2) * A1312 + (*this)(0, 3) * A1212);
    ret(1, 0) = det * -((*this)(1, 0) * A2323 - (*this)(1, 2) * A0323 + (*this)(1, 3) * A0223);
    ret(1, 1) = det * ((*this)(0, 0) * A2323 - (*this)(0, 2) * A0323 + (*this)(0, 3) * A0223);
    ret(1, 2) = det * -((*this)(0, 0) * A2313 - (*this)(0, 2) * A0313 + (*this)(0, 3) * A0213);
    ret(1, 3) = det * ((*this)(0, 0) * A2312 - (*this)(0, 2) * A0312 + (*this)(0, 3) * A0212);
    ret(2, 0) = det * ((*this)(1, 0) * A1323 - (*this)(1, 1) * A0323 + (*this)(1, 3) * A0123);
    ret(2, 1) = det * -((*this)(0, 0) * A1323 - (*this)(0, 1) * A0323 + (*this)(0, 3) * A0123);
    ret(2, 2) = det * ((*this)(0, 0) * A1313 - (*this)(0, 1) * A0313 + (*this)(0, 3) * A0113);
    ret(2, 3) = det * -((*this)(0, 0) * A1312 - (*this)(0, 1) * A0312 + (*this)(0, 3) * A0112);
    ret(3, 0) = det * -((*this)(1, 0) * A1223 - (*this)(1, 1) * A0223 + (*this)(1, 2) * A0123);
    ret(3, 1) = det * ((*this)(0, 0) * A1223 - (*this)(0, 1) * A0223 + (*this)(0, 2) * A0123);
    ret(3, 2) = det * -((*this)(0, 0) * A1213 - (*this)(0, 1) * A0213 + (*this)(0, 2) * A0113);
    ret(3, 3) = det * ((*this)(0, 0) * A1212 - (*this)(0, 1) * A0212 + (*this)(0, 2) * A0112);

    return ret;
}

Matrix::~Matrix() {
    if(m_tab)delete[]m_tab;
}

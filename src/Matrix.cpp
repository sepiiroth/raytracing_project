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
            for (int k = 0; k < 3; k++) {
                num += (*this)(j, k) * p[k];
            }
            switch(j) {
                case 0:
                    point.setX(num);
                    break;
                case 1:
                    point.setY(num);
                    break;
                case 2:
                    point.setZ(num);
                    break;
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
            for (int k = 0; k < 3; k++) {
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


Matrix::~Matrix() {
    if(m_tab)delete[]m_tab;
}

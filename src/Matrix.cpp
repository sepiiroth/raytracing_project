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

Matrix Matrix::createIdentity(int size) {
    Matrix temp(size, size);
    for (int i = 0; i < temp.getRows(); ++i) {
        for (int j = 0; j < temp.getCols(); ++j) {
            if (i == j) {
                temp(i, j) = 1;
            } else {
                temp(i, j) = 0;
            }
        }
    }
    return temp;
}

Matrix Matrix::augment(Matrix A, Matrix B) {
    Matrix AB(A.getRows(), A.getCols() + B.getCols());
    for (int i = 0; i < AB.getRows(); ++i) {
        for (int j = 0; j < AB.getCols(); ++j) {
            if (j < A.getCols()) {
                AB(i, j) = A(i, j);
            } else {
                AB(i, j) = B(i, j - B.getCols());
            }
        }
    }
    return AB;
}

void Matrix::swapRows(int r1, int r2) {
    float temp = this->m_tab[r1];
    this->m_tab[r1] = this->m_tab[r2];
    this->m_tab[r2] = temp;
}

Matrix Matrix::gaussianEliminate() {
    Matrix Ab(*this);
    int rowsG = Ab.getRows();
    int colsG = Ab.getCols();
    int Acols = m_cols - 1;

    int i = 0; // row tracker
    int j = 0; // column tracker

    // iterate through the rows
    while (i < rowsG) {
        // find a pivot for the row
        bool pivot_found = false;
        while (j < Acols && !pivot_found) {
            if (Ab(i, j) != 0) { // pivot not equal to 0
                pivot_found = true;
            } else { // check for a possible swap
                int max_row = i;
                double max_val = 0;
                for (int k = i + 1; k < rowsG; ++k) {
                    double cur_abs = Ab(k, j) >= 0 ? Ab(k, j) : -1 * Ab(k, j);
                    if (cur_abs > max_val) {
                        max_row = k;
                        max_val = cur_abs;
                    }
                }
                if (max_row != i) {
                    Ab.swapRows(max_row, i);
                    pivot_found = true;
                } else {
                    j++;
                }
            }
        }

        // perform elimination as normal if pivot was found
        if (pivot_found) {
            for (int t = i + 1; t < rowsG; ++t) {
                for (int s = j + 1; s < colsG; ++s) {
                    Ab(t, s) = Ab(t, s) - Ab(i, s) * (Ab(t, j) / Ab(i, j));
                    if (Ab(t, s) < EPS && Ab(t, s) > -1*EPS)
                        Ab(t, s) = 0;
                }
                Ab(t, j) = 0;
            }
        }
        i++;
        j++;
    }
    return Ab;
}

Matrix Matrix::rowReduceFromGaussian() {
    Matrix R(*this);
    int rowsG = R.getRows();
    int colsG = R.getCols();

    int i = rowsG - 1; // row tracker
    int j = colsG - 2; // column tracker

    // iterate through every row
    while (i >= 0) {
        // find the pivot column
        int k = j - 1;
        while (k >= 0) {
            if (R(i, k) != 0)
                j = k;
            k--;
        }

        // zero out elements above pivots if pivot not 0
        if (R(i, j) != 0) {
            for (int t = i - 1; t >= 0; --t) {
                for (int s = 0; s < colsG; ++s) {
                    if (s != j) {
                        R(t, s) = R(t, s) - R(i, s) * (R(t, j) / R(i, j));
                        if (R(t, s) < EPS && R(t, s) > -1*EPS)
                            R(t, s) = 0;
                    }
                }
                R(t, j) = 0;
            }

            // divide row by pivot
            for (int k = j + 1; k < colsG; ++k) {
                R(i, k) = R(i, k) / R(i, j);
                if (R(i, k) < EPS && R(i, k) > -1*EPS)
                    R(i, k) = 0;
            }
            R(i, j) = 1;

        }

        i--;
        j--;
    }

    return R;
}

Matrix Matrix::inverse() {
    Matrix I = Matrix::createIdentity(this->m_rows);
    Matrix AI = Matrix::augment(*this, I);
    Matrix U = AI.gaussianEliminate();
    Matrix IAInverse = U.rowReduceFromGaussian();
    Matrix AInverse(this->m_rows, this->m_cols);
    for (int i = 0; i < AInverse.getRows(); ++i) {
        for (int j = 0; j < AInverse.getCols(); ++j) {
            AInverse(i, j) = IAInverse(i, j + m_cols);
        }
    }
    return AInverse;
}

Matrix::~Matrix() {
    if(m_tab)delete[]m_tab;
}

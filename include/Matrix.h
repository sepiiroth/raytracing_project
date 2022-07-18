#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;


class Matrix {
    private:
        int m_rows, m_cols;
        float* m_tab;
        void swap(Matrix& m);
    public:
        Matrix();
        Matrix(int l_num, int c_num, float remp = 0);
        Matrix(const Matrix &m);
        Matrix& operator=(const Matrix& m);
        int getCols() const;
        int getRows() const;
        void set(int i, int j, float val);
        int get(int i, int j) const;
        float& operator[](int index);
        float& operator()(int i,int j);
        float operator[](int index) const;
        float operator()(int i,int j) const;
        float& at(int index);
        float& at(int i,int j);
        float at(int index) const;
        float at(int i,int j) const;
        Matrix createIdentity(int size);
        Matrix augment(Matrix A, Matrix B);
        void swapRows(int r1, int r2);
        Matrix gaussianEliminate();
        Matrix rowReduceFromGaussian();
        Matrix inverse();
        virtual ~Matrix();
};

#endif // MATRIX_H

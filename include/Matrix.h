#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include "Point.h"
#include "HPoint.h"
#include "Vector.h"
#include "HVector.h"

using namespace std;

class Matrix {
    private:
        int m_rows, m_cols;
        float* m_tab;

        void swap(Matrix& m); //Utiliser dans Matrix = Matrix

    public:
        Matrix();
        Matrix(int l_num, int c_num, float remp = 0);
        Matrix(const Matrix &m);
        virtual ~Matrix();

        float& operator[](int index);
        float operator[](int index) const;
        float& operator()(int i,int j);
        float operator()(int i,int j) const;
        Matrix operator*(Matrix m);
        Point operator*(HPoint p) const;
        Vector operator*(HVector v) const;
        Matrix& operator=(const Matrix& m);

        int getCols() const;
        int getRows() const;
        void set(int i, int j, float val);
        int get(int i, int j) const;
        float& at(int index);
        float& at(int i,int j);
        float at(int index) const;
        float at(int i,int j) const;
        Matrix inverse();
};

#endif

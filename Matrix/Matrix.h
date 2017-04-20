#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <memory>
#include<cstdlib>
#include <time.h>
#include<string>
using namespace std;

class Matrix;

ostream &  operator << (ostream &, Matrix&);

class Matrix
{
protected:
    size_t _rows;
    size_t _columns;
    //double val;
    unique_ptr<double []> data;
    // dArray *data;
   // double * data;
    
public:
    
    Matrix(size_t, size_t, double);
    Matrix(size_t, size_t, string);
    Matrix(){};
    Matrix(size_t, size_t);
    

    Matrix( const  Matrix& );
    
    //set
    void set(size_t, double);
    
    //get
    size_t rows() const;
    size_t columns() const;
    
    double get(size_t, size_t);
    double get(size_t);
    
    Matrix size();
    
    // display
    
    void dispMatrix();
    // Operators
    Matrix T();
    
    // operator overloading
    
    double * operator[](const size_t);
    const Matrix operator=(const Matrix &);
    Matrix  operator+( Matrix &);
    Matrix  operator+( double);
    Matrix  operator*( double);
    
    // Friends
    friend ostream &  operator << (ostream &, Matrix&);
    
};

class Zeros: public Matrix
{
public:
    Zeros(size_t rows, size_t columns): Matrix(rows, columns, 0)
    {
    }
};

class RandMatrix: public Matrix
{
public:
    RandMatrix(size_t rows, size_t columns): Matrix(rows,columns)
    {
        srand((unsigned) time(0));
        int mmax=100,
            mmin=0;
        data=make_unique<double []>(rows * columns);
        {
            for (size_t i =0; i<rows*columns; i++)
                data[i]=((rand()%(mmax-mmin+1))-mmin)/100.00;
        }

    }
};
#endif

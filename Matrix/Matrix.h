#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
//#include <memory>
using namespace std;

class Matrix
{
    size_t _rows;
    size_t _columns;
    unique_ptr<double []> data;
    // dArray *data;
   // double * data;
    
public:
    
    Matrix(size_t, size_t);

    Matrix( const  Matrix& );
    
    //set
    void set(size_t, double);
    
    //get
    size_t rows() const;
    size_t columns() const;
    
    double get(size_t, size_t);
    double get(size_t);
    
    // display
    
    void dispMatrix();
    
    // operator overloading
    
    double * operator[](const size_t);
    Matrix & operator+(const Matrix & obj);
};
#endif

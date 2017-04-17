// Example program
#include <iostream>
#include <memory>
using namespace std;

class Matrix
{
    size_t _rows;
    size_t _columns;
    unique_ptr<double []> data;
    
public:
    
    Matrix(size_t rows=1, size_t columns=1): _rows{rows}, _columns{columns},
    data{make_unique<double []>(rows * columns)}
    {
        for (size_t i =0; i<rows*columns; i++)
            data[i]=1;
    }
    Matrix( const  Matrix& rMatrix)
    {
        for (size_t i =0; i<_rows*_columns; i++)
            data[i]=rMatrix.data[i];
    }
    
    size_t rows() const
    {
        return _rows;
    }
    
    size_t columns() const
    {
        return _columns;
    }
    
    double * operator[](const size_t row)
    {
        if(row >=0)
            return row * _columns + data.get();
        else
        {
            cout <<"ERROR: subscript out of range.\n";
            exit(1);
        }
        
    }
    void subscriptError()
    {
        cout <<"ERROR: subscript out of range.\n";
        exit(0);
    }
    
    double get(size_t i, size_t j)
    {
        return data[i*_columns+j];
    }
    
    void dispMatrix()
    {
        for(size_t i=0; i<_rows ; i++)
        {
            for(size_t j=0; j<_columns;j++)
                cout<< *(j+ i * _columns + data.get()) <<" ";
            cout<<endl;
        }
    }
    
};

void dispMatrix2(Matrix M)
{
    cout<<M[1][2];
    /*for(size_t i=0; i<M.rows() ; i++)
     {
     for(size_t j=0; j<M.columns();j++)
     cout<<M[i][j] <<" ";
     cout<<endl;
     }*/
}

int main()
{
    Matrix M(4, 3);
    M.get(1,2);
    M[-2][1]=5;
    M.dispMatrix();
    //dispMatrix(M);
    cout<<M.get(2,2)<<endl;
    return 0;
}


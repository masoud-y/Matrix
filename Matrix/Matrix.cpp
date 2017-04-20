#include "Matrix.h"

//********************************************* Constructors

Matrix::Matrix(size_t rows, size_t columns, double val): _rows{rows}, _columns{columns},
data{make_unique<double []>(rows * columns)}
{
    for (size_t i =0; i<rows*columns; i++)
        data[i]=val;
}


/*Matrix::Matrix(size_t rows, size_t columns)
{
    Matrix::Matrix(rows, columns, 0);
}*/

Matrix::Matrix(size_t rows, size_t columns): _rows{rows}, _columns{columns},
data{make_unique<double []>(rows * columns)}
{
    for (size_t i =0; i<rows*columns; i++)
        data[i]=0;
        }


Matrix::Matrix(size_t rows, size_t columns, string str): _rows{rows}, _columns{columns}
{
    if(str=="r")
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
}

//***************************************** copy constructor
Matrix::Matrix( const  Matrix& obj)
{
    _columns=obj._columns;
    _rows=obj._rows;
    data=make_unique<double []>(_rows * _columns);
    for(size_t i=0; i< _columns*_rows; i++ )
        data[i]=obj.data[i];
}


/************************************ GET *************/

size_t Matrix::rows() const
{
    return _rows;
}

size_t Matrix::columns() const
{
    return _columns;
}

Matrix Matrix::size()
{
    Matrix M(1,2);
    M[0][0]=_rows;
    M[0][1]=_columns;
    cout<< '['<<_rows<<','<<_columns<< ']'<<endl;
    return M;
}

 double Matrix::get(size_t i, size_t j)
 {
 return data[i*_columns+j];
 }

double Matrix::get(size_t i)
{
    return data[i];
}



//diplay
void Matrix::dispMatrix()
{
    for(size_t i=0; i<_rows ; i++)
    {
        for(size_t j=0; j<_columns;j++)
            // cout<< data[j+ i * _columns] <<" ";
            cout<< data[i*_columns+j] <<" ";
        cout<<endl;
    }
}

/*************************** SET ***********************/

void Matrix::set(size_t i, double val)
{
     data[i]=val;
}


//****************************************** Operators

Matrix Matrix::T()
{
    Matrix M(_columns,_rows);
    for(size_t i=0; i<_columns;i++)
        for(size_t j=0; j<_rows;j++)
            M[i][j]=data[j*_columns+i];
    return M;
}

/*********************************** operator overloading *******************/


//********************* []
double * Matrix::operator[](const size_t row)
{
    if(static_cast<int> (row) <0 || row>=_rows)
    {
        cout <<"ERROR: subscript out of range.\n";
        exit(0);
    }
    else
    {
        return row * _columns + data.get();
    }
}
//***************** =

const Matrix  Matrix::operator=(const Matrix & obj)
{
    _columns=obj._columns;
    _rows=obj._rows;
    data=make_unique<double []>(_rows * _columns);
    for(size_t i=0; i< _columns*_rows; i++ )
        data[i]=obj.data[i];
    return *this;
}

//***************** +

Matrix  Matrix::operator+(Matrix & obj)
{
    if (_rows!=obj._rows || _columns!=obj._columns)
    {
        cout<< "Error: Dimensions doesn't match!\n";
        exit(0);
    }
    else
    {
        Matrix temp(_rows,_columns, 0);
        for(size_t i=0; i<_rows*_columns; i++)
            temp.data[i]=data[i]+obj.data[i];
        return temp;
    }
}

Matrix  Matrix::operator+(double val)
{
        Matrix temp(_rows,_columns, 0);
        for(size_t i=0; i<_rows*_columns; i++)
            temp.data[i]=data[i]+val;
        return temp;
}

Matrix  Matrix::operator*(double val)
{
    Matrix temp(_rows,_columns, 0);
    for(size_t i=0; i<_rows*_columns; i++)
        temp.data[i]=data[i]*val;
    return temp;
}

//********* Friends
//*************************** <<


ostream &  operator << (ostream & strm, Matrix &M)
{
    for(size_t i=0; i<M.rows() ; i++)
    {
        for(size_t j=0; j<M.columns();j++)
            // cout<< data[j+ i * _columns] <<" ";
            strm<< M.data[i*M.columns()+j] <<" ";
            strm<<endl;
            }
    return strm;
}
            

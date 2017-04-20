// Example program
#include <iostream>
#include <memory>
//#include "dArray.h"
#include "Matrix.h"
using namespace std;

/* making the make function
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}*/



/*void dispMatrix2(Matrix M)
{
    cout<<M[1][2];
    for(size_t i=0; i<M.rows() ; i++)
     {
     for(size_t j=0; j<M.columns();j++)
     cout<<M[i][j] <<" ";
     cout<<endl;
     }
}*/

int main()
{
    
    Matrix M1(4, 3, 1);
    
    //RandMatrix M2(4,3);
    Matrix M2(4,3,"r");

    cout<< "M1"<<endl;
    M1.dispMatrix();
    cout<< "M2"<<endl;
    M2.dispMatrix();
    
    Matrix M3;
    cout<< "M3"<<endl;
    M3=M2+M1+M1;
    M3.dispMatrix();
    cout<< " M4"<<endl;
    Matrix M4=M3.T();
    cout<< M4;
    cout<< " M4a"<<endl;
    Matrix M4a=M2.T();
    cout<< M4a;
    Matrix M5=M4+M4a;
    cout<<"M5:\n "<< M5;
    cout<< "times 10 \n";
    Matrix M6=M5*10;
    cout<< M6;


    return 0;
}


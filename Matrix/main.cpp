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
    Zeros Z1(40,3);
    Matrix M1(4, 3, 1);
    
    RandMatrix Mr(4,3);
    
    Matrix M2=Mr;
    
   Matrix sizes= Z1.size();

   // M[2][2]=5;
    cout<< "M1"<<endl;
    M1.dispMatrix();
    cout<< "M2"<<endl;
    M2.dispMatrix();
    
    Matrix M3;
    cout<< "M3"<<endl;
    M3=M2+M1;
    M3.dispMatrix();


    return 0;
}


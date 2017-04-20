#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
//#include <memory>
using namespace std;


class dArray
{
private:
    double *aptr;                     // Pointer to the array
    size_t arraySize;                 // Holds the array size
    void subscriptError();         // Handles invalid subscripts
public:
    dArray(size_t);                 // Constructor
    dArray(const dArray &);    // Copy constructor
    ~dArray();                   // Destructor
    
    size_t size() const               // Returns the array size
    { return arraySize; }
    
    double &operator[](const size_t &);  // Overloaded [] operator
};

#endif

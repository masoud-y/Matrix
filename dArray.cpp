#include "dArray.h"

dArray::dArray(size_t s)
{
    arraySize = s;
    aptr = new double [s];
    for (size_t count = 0; count < arraySize; count++)
        *(aptr + count) = 0;
}

//******************************************************
// Copy Constructor for IntArray class.                *
//******************************************************

dArray::dArray(const dArray &obj)
{
    arraySize = obj.arraySize;
    aptr = new double [arraySize];
    for(size_t count = 0; count < arraySize; count++)
        *(aptr + count) = *(obj.aptr + count);
}

//******************************************************
// Destructor for IntArray class.                      *
//******************************************************

dArray::~dArray()
{
    if (arraySize > 0)
        delete [] aptr;
}

//***********************************************************
// subscriptError function. Displays an error message and   *
// terminates the program when a subscript is out of range. *
//***********************************************************

void dArray::subscriptError()
{
    cout << "ERROR: Subscript out of range.\n";
    exit(0);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

double &dArray::operator[](const size_t &sub)
{
    if (static_cast<int> (sub) < 0 || sub >= arraySize)
        subscriptError();
    return aptr[sub];
}

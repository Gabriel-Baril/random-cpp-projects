#include <iostream>
#include "Box.h"

using namespace std;

void write(Box* r,Box b)
{
    *r = b;
}

int getTabSize(double* arr[])
{
    return (sizeof(*arr)/sizeof(*arr[0]));
}

int main()
{
    Box* b = new Box;
    double* arr[5];

    for(int i = 0;i < getTabSize(arr);i++){
        cout << &arr[i] << endl;
    }

    b->getInformation();
    write(b, new Box(10,10,30,60));
    b->getInformation();

    return 0;
}

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    Rectangle car_1(20,20,10,10,17);
    Rectangle car_2;

    cout << car_1.getInformation() << endl << endl;
    cout << car_2.getInformation();

    return 0;
}

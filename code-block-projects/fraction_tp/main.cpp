#include <iostream>
#include <string>
#include "ZFraction.h"

using namespace std;

int main()
{

    ZFraction frac(12334,77986);

    cout << frac.getNum() << endl;
    cout << frac.getDen() << endl;

    frac.simplification();

    cout << frac.getNum() << endl;
    cout << frac.getDen() << endl;




    return 0;
}

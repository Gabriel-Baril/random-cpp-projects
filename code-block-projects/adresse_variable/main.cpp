#include <iostream>

using namespace std;

int main()
{
    int *p(0);
    p = new int;

    *p = 4;

    cout << *p << endl;

    delete p;
    p = 0;

    return 0;
}

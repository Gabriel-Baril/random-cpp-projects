#include <iostream>

using namespace std;

int c(int& r){
    return r * r;
}

int main()
{
    int a = 10;

    cout << c(a) << endl;

    return 0;
}

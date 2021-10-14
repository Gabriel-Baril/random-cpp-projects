#include <iostream>

using namespace std;

void ajoute(int &nb)
{
    nb = 20;
}

int main()
{
    int a = 5;
    cout << a << endl;
    ajoute(a);
    cout << a << endl;

    return 0;
}

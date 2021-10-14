#include <iostream>

using namespace std;



void increment(int &value)
{
    cout << value << endl;
}

int main()
{
    int var = 5;
    int *p = &var;

    cout << "La valeur de var est : " << var << endl;
    cout << "Ladresse de var est : " << &var << endl;

    cout << "p pointe ladresse de var qui est : " << p << endl;
    cout << "*p pointe la valeur qui correspond a ladresse de var qui est : " << *p << endl;

    increment(var);


    return 0;
}


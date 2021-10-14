#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Faite une addition en entrant 2 nombres" << endl;
    cout << "Premier nombre : ";

    double pNombre(0.0);

    cin >> pNombre;

    cout << "Deuxieme nombre : ";

    double dNombre(0.0);

    cin >> dNombre;

    cout << "Le resultat de " << pNombre << " + " << dNombre << " est : " << pNombre + dNombre << endl;


    return 0;

}

#include <iostream>
#include "Rectangle dans la console.h"

using namespace std;

string drawRectangle(int hauteur,int largeur)
{
    for (int i = 0; i != hauteur; i++)
    {
        for (int i = 0; i != largeur; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
}


int main()
{
    int hauteur(0), largeur(0);

    cout << "Entrer la hauteur du rectangle : ";
    cin >> hauteur;

    cout << "Entrer la largeur du rectangle : ";
    cin >> largeur;

    cout << "Voici votre rectangle de " << hauteur << " de hauteur et de " << largeur << " de largeur." << endl;

    drawRectangle(hauteur,largeur);

}

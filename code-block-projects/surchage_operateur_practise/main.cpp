#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    cout << "Nous créons l’objet Date_initiale= 1 1 2009 ";
    Date Date_initiale(1,1,2009);
    cout << "nNous lui ajoutons 30 jours et 6 mois via l’objet Duree 30 6 0" << endl;
    Date Duree(30,6,2);

    Date Date_finale = Date_initiale + Duree ;
    cout << "Nous obtenons la nouvelle date: ";
    Date_finale.lireDate();


    return 0;
}

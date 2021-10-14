#include <iostream>
#include <Windows.h>
#include "Compte.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    cout << "+------------------------------------+\n";
    cout << "|          Travail Cours #2          |\n";
    cout << "+------------------------------------+\n\n";

    Compte compte1061, compte1201;

    cout << "Les transactions :\n";

    // Opérations sur le compte 1061
    compte1061.deposer(516.22);
    compte1061.retirer(321.11);
    compte1061.retirer(5000.00);
    compte1061.transfererDansAutreCompte(compte1201, 150.00);

    // Opération sur le compte 1201
    compte1201.deposer(150.00);

    cout << endl << "L'historique du compte 1061 est :" << compte1061.obtenirHistorique() << endl;
    cout << "Le solde du compte 1061 est :" << compte1061.obtenirSolde() << " $.";
    cout << "L'historique du compte 1201 est :" << compte1201.obtenirHistorique() << endl;
    cout << "Le solde du compte 1201 est :" << compte1201.obtenirSolde() << " $.";
}
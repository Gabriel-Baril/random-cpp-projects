#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string const nomFichier("C:/Users/UsagerJeux/Desktop/c++ workspace/lire_un_fichier/data.txt");
    ifstream monFlux(nomFichier.c_str());

    string line;
    double nombre;
    string mot;
    char a;

    if(monFlux)
    {
        monFlux >> nombre;
        monFlux >> mot;

        monFlux.ignore(); //Sert a changer de mode (dans cette situation de lecture mot par mot a caractere a caractere)

        monFlux.get(a);
    }
    else
    {
        cout << "Erreur lors de la lecture du fichier";
    }

    return 0;
}

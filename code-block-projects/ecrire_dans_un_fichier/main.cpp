#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    // Pour le chemin dacces il faut mettre des slashs "/" et non desw antislashs "\"
    string const nomFichier("C:/Users/UsagerJeux/Desktop/c++ workspace/tableau/eloMonFwer.txt");
    ofstream monFlux(nomFichier.c_str());  //ios::app (mettre cette ligne de code necrase pas le fichier)

    if(monFlux)
    {
        monFlux << "Bonjour mon fwereee" << endl;
    }
    else
    {
        cout << "Erreur lors de louverture";
    }

    return 0;
}



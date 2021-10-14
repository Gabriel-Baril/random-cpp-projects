#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> allst; // Tableau dynamique oû chaques indexs vaut tout se qui est ecrit sur la ligne en question

    string const nomFichier("C:/Users/UsagerJeux/Desktop/c++ workspace/lire_un_fichier(en entier)/fichier.txt");
    ifstream monFlux(nomFichier.c_str());


    if(monFlux)
    {
        string line;

        while(getline(monFlux, line))
        {
            allst.push_back(line);
            cout << line << endl;

        }

    }
    else
    {
        cout << "Erreur lors de la lecture du fichier";
    }

    // cout << allst[2] << endl; // Cette ligne de code permets dafficher les choses a la ligne 2 independamment des autres lignes du fichier
    cout << endl;
    cout << "Votre fichier contient " << allst.size() << " ligne(s)." << endl;

    monFlux.close();

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int setMdp = 0;
    int mdp = 0;
    int nbEssaie = 0;

    cout << "Regler votre mot de passe numerique: ";
    cin >> setMdp;

    do
    {

        cout << "Entrer le mot de passe numerique : ";
        cin >> mdp;

        nbEssaie++;

        if (nbEssaie == 3)
        {
            cout << "Systeme verrouiller tentative dinfiltration";
        }

    }
    while(mdp != setMdp);

    cout << "systeme deverrouiller en " << nbEssaie << " Essaie." << endl;

    return 0;
}

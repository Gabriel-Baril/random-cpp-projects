#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;


int main()
{

    srand(time(0));

    string m_myst;
    string mot_utilisateur;
    int nbEssaie(5);

    cout << "Saisissez un mot mystere : " ;

    cin >> m_myst;

    string motTransf = m_myst;
    string real_mot = m_myst;

    for(int i = 0; i < motTransf.size(); i++)
    {
        int position = rand() % m_myst.size();

        motTransf[i] = m_myst[position];

        m_myst.erase(position,1);
    }

    do
    {
        cout << endl;
        cout << "Il vous reste " << nbEssaie << " essaie(s)" << endl;
        cout << "Quel est ce mot ?  " << motTransf << endl;
        cout << "mot : ";
        cin >> mot_utilisateur;

        if(mot_utilisateur != real_mot)
        {
            cout << endl;
            cout << "Ce nest pas le mot" << endl;
            cout << endl;
            if(nbEssaie <= 0)
            {
                cout << "Vous navez pas trouver le mot !!!" << endl;
                cout << "Le mot etais : " << real_mot << endl;
                return 0;
            }
        }

        nbEssaie--;

    }
    while(mot_utilisateur != real_mot);

    cout << endl;
    cout << "Bravo vous avez trouver le mot en vous restant " << nbEssaie << " essaie(s)" << endl;

    return 0;
}

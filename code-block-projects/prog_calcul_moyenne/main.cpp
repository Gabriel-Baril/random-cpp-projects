#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> tab(3,27);

    cout << tab.size();

    int const nbNote(5);
    double notes[nbNote];

    double total = 0;

    notes[0] = 12.5;
    notes[1] = 19.5;
    notes[2] = 6.;
    notes[3] = 12;
    notes[4] = 14.5;
    notes[5] = 15;

    for (int i = 0; i < nbNote; i++)
    {
        total += notes[i];
    }

    double moyenne = total/nbNote;

    cout << "Votre moyenne est de : " << moyenne << endl;


    return 0;
}

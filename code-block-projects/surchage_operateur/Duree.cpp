#include "Duree.h"
#include <iostream>
#include <string>

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)   // Si les heures sont différentes
        return true;
    else if (m_heures == b.m_heures && m_minutes < b.m_minutes) //Si elles sont égales, on compare les minutes
        return true;
    else if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes) // Et si elles sont aussi égales, on compare les secondes
        return true;
    else              //Si tout est égal, alors l'objet n'est pas plus petit que b
        return false;

        return (m_heures < b.m_heures && m_minutes < b.m_minutes && m_secondes < b.m_secondes);
}

int Duree::calculeAddition(Duree const& b) const
{

}


bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b);
}

bool operator<(Duree const& a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree resultat;
    resultat = a.calculeAddition(b);

    return resultat;
}

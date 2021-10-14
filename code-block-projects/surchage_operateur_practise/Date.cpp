#include "Date.h"

using namespace std;

Date::Date(int j,int m,int a) : jour(j), mois(m),annee(a)
{
}

Date::~Date()
{
}

void Date::definirDate(int j, int m, int a)
{
    jour = j;
    mois = m;
    annee = a;
}

void Date::lireDate() const
{
    cout << jour << " " << mois << " " << annee << endl;
}

int Date::lireJour() const
{
    return jour;
}

int Date::lireMois() const
{
    return mois;
}

int Date::lireAnnee() const
{
    return annee;
}

Date Date::operator+(const Date &source)
{
    int j, m, a;
    j = jour + source.lireJour();
    m = mois + source.lireMois();
    a = annee + source.lireAnnee();

    if(j>30)
    {
        j-=30;
        m+=1;
    }

    if(m>12)
    {
        m-=12;
        a+=1;
    }

    return Date(j,m,a);
}

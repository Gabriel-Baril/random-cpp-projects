#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>

class Date
{
    public:

    Date(int,int,int);
    ~Date();

    void definirDate(int j, int m, int a);
    void lireDate() const;

    int lireJour() const;
    int lireMois() const;
    int lireAnnee() const;

    Date operator+(const Date&);

    private:

    int jour,mois,annee;

};


#endif // DATE_H_INCLUDED

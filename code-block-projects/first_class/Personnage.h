#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <iostream>
#include <string>
#include "Arme.h"

class Personnage
{
public:

    Personnage(); // Constructeur 1
    Personnage(std::string nomArme, int degatsArme); // Constructeur 2
    Personnage(int nbVie, int nbMana); // Constructeur 3

    ~Personnage(); // Destructeur

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    void afficherEtat() const;
    bool estVivant() const;

private:

    int m_vie;
    int m_mana;
    Arme m_arme;
};

#endif // PERSONNAGE_H_INCLUDED

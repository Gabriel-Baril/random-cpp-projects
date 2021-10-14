#include <string>

class Compte
{
public:
    Compte();
    void deposer(float montant);
    void retirer(float montant);
    void transfererDansAutreCompte(Compte& compteDeDestination, float montant);
    float obtenirSolde();
    std::string obtenirHistorique();

private:
    float solde;
    std::string historique;
};
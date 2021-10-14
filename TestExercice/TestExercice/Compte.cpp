#include "Compte.h"

// Constantes
const float SOLDE_NOUVEAU_COMPTE = 0;
const std::string MESSAGE_RETRAIT_IMPOSSIBLE = "Probl�me : Le montant � retirer est plus �lev� que le solde du compte.";

// Constructeur
Compte::Compte() {
    this->solde = SOLDE_NOUVEAU_COMPTE;
    this->historique = "";
}

// M�thodes
void Compte::deposer(float montant) {
    this->solde += montant;
    this->historique += "D�pot de " + std::to_string(montant) + " $\n";
}
void Compte::retirer(float montant) {
    if (this->solde >= montant) {
        this->solde -= montant;
        this->historique += "Retrait de " + std::to_string(montant) + " $\n";
    }
    else {
        this->historique += MESSAGE_RETRAIT_IMPOSSIBLE + "\n";
    }
}
void Compte::transfererDansAutreCompte(Compte& compteDeDestination, float montant) {
    this->retirer(montant);
    compteDeDestination.deposer(montant);
}
float Compte::obtenirSolde() {
    return this->solde;
}
std::string Compte::obtenirHistorique() {
    return this->historique;
}
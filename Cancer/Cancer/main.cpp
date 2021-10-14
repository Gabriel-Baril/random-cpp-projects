#include <iostream>
#include <string>
using namespace std;

// Messages
const string MESSAGE_EXERCICE_1 = "Exercice 1 - Mise en forme d'un numero de telephone";
const string MESSAGE_EXERCICE_2 = "Exercice 2 - Extraction des trois parties d'un numero de telephone";
const string MESSAGE_EXERCICE_3 = "Exercice 3 - Affichage du deuxieme mot d'une phrase";
const string MESSAGE_EXERCICE_4 = "Exercice 4 - Mise en forme d'un numero de telephone";
const string MESSAGE_EXERCICE_5 = "Exercice 5 - Mise en forme d'un numero de telephone";

// Exercice 1
void MettreEnFormeNumeroDeTelephone() {

    // Messages
    const string MESSAGE_CODE_REGIONAL = "Entrez le code regional : ";
    const string MESSAGE_NUMERO_ECHANGE = "Entrez le numero d'echange : ";
    const string MESSAGE_NUMERO_LOCAL = "Entrez le numero local : ";
    const string MESSAGE_NUMERO_FORMATTE = "Voici le numero de telephone mis en forme : ";

    // Variables
    string codeRegional, numeroEchange, numeroLocal, numeroDeTelephone;

    // Code régional
    cout << MESSAGE_CODE_REGIONAL;
    cin >> codeRegional;

    // Numéro d'échange
    cout << MESSAGE_NUMERO_ECHANGE;
    cin >> numeroEchange;

    // Numéro local
    cout << MESSAGE_NUMERO_LOCAL;
    cin >> numeroLocal;

    // Numéro de téléphone formatté
    numeroDeTelephone = "(" + codeRegional + ") " + numeroEchange + "-" + numeroLocal;
    cout << MESSAGE_NUMERO_FORMATTE << numeroDeTelephone << endl;
}

// Exercice 2
void ExtraireTroisPartiesNumeroDeTelephone() {

    // Messages
    const string MESSAGE_NUMERO_FORMATTE = "Entrez le numero de telephone formatte : ";
    const string MESSAGE_CODE_REGIONAL = "Voici le code regional : ";
    const string MESSAGE_NUMERO_ECHANGE = "Voici le numero d'echange : ";
    const string MESSAGE_NUMERO_LOCAL = "Voici le numero local : ";

    // Variables
    string codeRegional;
    string numeroEchange;
    string numeroLocal;
    string numeroDeTelephone = "";
    

    // Numéro de téléphone formatté
    cout << MESSAGE_NUMERO_FORMATTE;
    cin >> numeroDeTelephone;

    // Séparation des trois parties
    codeRegional = numeroDeTelephone.substr(1, 3);
    numeroEchange = numeroDeTelephone.substr(6, 3);
    numeroLocal = numeroDeTelephone.substr(10, 4);

    // Résultats
    cout << MESSAGE_CODE_REGIONAL << codeRegional << endl;
    cout << MESSAGE_NUMERO_ECHANGE << numeroEchange << endl;
    cout << MESSAGE_NUMERO_LOCAL << numeroLocal << endl;
}

// Exercice 3
void AfficherDeuxiemeMotDePhrase() {

    // Messages
    const string MESSAGE_PHRASE = "Entrez une phrase d'au moins trois mots : ";
    const string MESSAGE_MOT = "Voici le deuxieme mot de la phrase entree : ";

    // Phrase
    string phrase;
    cout << MESSAGE_PHRASE;
    getline(cin, phrase);

    // Deuxième mot
    int indexPremierEspace = phrase.find(" ");
    int indexDeuxiemeEspace = phrase.find(" ", indexPremierEspace + 1);
    cout << MESSAGE_MOT << phrase.substr(indexPremierEspace + 1, indexDeuxiemeEspace - indexPremierEspace) << endl;
}

// Fonction principale
int main() {

    // Exercice 1
     cout << MESSAGE_EXERCICE_1 << endl;
     MettreEnFormeNumeroDeTelephone();

    // Exercice 2
     cout << MESSAGE_EXERCICE_2 << endl;
     ExtraireTroisPartiesNumeroDeTelephone();

    // Exercice 3
    cout << MESSAGE_EXERCICE_3 << endl;
    AfficherDeuxiemeMotDePhrase();

    // Exercice 4

    // Exercice 5

}
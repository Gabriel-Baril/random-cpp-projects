#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

int getSize(char tab[]){
    int i = 0;
    int size = 0;

    while(tab[i] != '\0'){
        size++;
        i++;
    }

    return size;
}

char readChar(){
    char caracter = 0;

    caracter = getchar();
    caracter = toupper(caracter);

    while(getchar() != '\n');

    return caracter;
}

void checkChar(char letter, char myst[], char *cache[]){
    int i = 0;

    while(i < getSize(myst)){
        if(toupper(myst[i]) == letter){
            *cache[i] = letter;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    char motMystere[] = "BANANE";
    char *motCache = malloc(sizeof(char) * getSize(motMystere));
    int nbCoup = 10,i = 0;
    char lettre;
    int discovered = 0;

    if(motCache == NULL){
        exit(0);
    }

    while(i < getSize(motMystere)){
        motCache[i] = '*';
        i++;
    }

    motCache[getSize(motMystere)] = ' ';

    while(!discovered){
        printf("Bienvenue dans le pendu\n\n");
        printf("Il vous reste %d coups a jouer\n",nbCoup);
        printf("Quel est le mot secret ? %s\n", motCache);
        printf("Proposer une lettre : ");
        lettre = readChar();

        checkChar(lettre,motMystere,motCache);
    }


    free(motCache);

    return 0;
}

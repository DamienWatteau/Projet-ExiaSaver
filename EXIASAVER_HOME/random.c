#include <stdio.h> // La bibliothéque contient "printf"
#include <stdlib.h> // Elle contient fonction "srand" / "rand"

int alea(int min, int max)                                   // Paramètres de la fonction qui ont été envoyés
{
     /*Déclaration des variables*/
     int nbgen = 0;

    srand(time(NULL));                                      // Initialise la fonction srand sur le temps actuel
    nbgen=(rand() % (max - min +1)) + min;                  // Rand retourne un un nombre aléatoire dans la variable "nbgen" comprit entre "min" et "max"
    return nbgen;                                           // Renvoie la valeur dans la variable "nbgen"
}


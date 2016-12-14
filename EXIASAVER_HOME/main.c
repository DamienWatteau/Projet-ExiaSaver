#include <stdio.h>  // Cette bibliothèque renferme les routines de traitement d'entrée/sortie fichier.
#include <stdlib.h> // Cette bibliothèque renferme les routines Standard.
#include <sys/types.h>  // Cette bibliothèque renferme les définitions de temps pour Unix. 
#include <sys/wait.h>   // Cette bibliothèque renferme les définitions d'attente.
#include <unistd.h> //  Cette bibliothèque renferme les types et les constantes symbole standard.

#include "random.h"
#include "termSaver1.h"
#include "termSaver2.h"
#include "termSaver3.h"
#include "history.h" //

//#define TAILLE_MAX 1000
// #include "history_ecriture.h"

int main(int argc, char *argv[])
{
    // while (1){
    pid_t pid = 0;
    int nbgen = 0;
    
    /* Détection du "-stats"*/
    
    if (argc != 1 && strcmp(argv[1], "-stats") == 0)
    {
        history();          // Si détection d'un paramètre et 
    }
    else if (argc != 1 && strcmp(argv[1], "-stats") != 0)
    {
        printf("no valid arguments\n");
    }
    else if( argc == 1)
    {
        nbgen = alea(1, 3);
    }
    
    system("clear");
    
    /* Choix dépendant d'une variable aléatoire (nbgen) permmettant de choisir le type de mode veille*/
    
    if (nbgen == 1)
    {
        pid=fork();                                     // Il génére et stocke le PID du fils dans la variable "pid"
        system("clear");                                // Efface le contenu de la console
        if (pid == 0)                                
        {
            termSaver1();                             // Si on est dans le processus fils alors il lance le mode veille statique 
            // Detection de la touche 
        }
        else
        {
           wait(NULL);                              // *                                      
        }
    }
    else if (nbgen == 2)
    {
        pid=fork();                                        // Il génére et stocke le PID du fils dans la variable "pid"
        system("clear");                                   // Efface le contenu de la console
        if (pid == 0)
        {
            termSaver2();                                // Si on est dans le processus fils alors il lance le mode veille dynamique 
        }
        else
        {
            wait(NULL);
        }
        }
        else
        {
            pid=fork();                                  // Il génére et stocke le PID du fils dans la variable "pid"
            system("clear");                            // Efface le contenu de la console
                if (pid == 0)
                {
                    termSaver3();                       // Si on est dans le processus fils alors il lance le mode veille interactif 
                }
                else
                {
                    wait(NULL);
                }
        }
    //}
}

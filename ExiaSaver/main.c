#include <stdio.h>  // Cette bibliothèque renferme les routines de traitement d'entrée/sortie fichier. (NULL)
#include <stdlib.h> // Cette bibliothèque renferme les routines Standard. (NULL, system, strcmp)
#include <sys/types.h>  // Cette bibliothèque renferme les définitions de temps pour Unix. (pid_t)
#include <sys/wait.h>   // Cette bibliothèque renferme les définitions d'attente. (wait)
#include <unistd.h> // Cette bibliothèque renferme les types et les constantes symbole standard. (Fork)
#include <string.h> // Cette bibliothèque renferme les routines de traitement de chaine de caractères. (NULL, strcmp)


/* Déclaration des fichiers headers */
#include "random.h"
#include "history.h"
#include "history_ecriture.h"
#include "statique.h"

int main(int argc, char *argv[])
{
    while (1)
	{
        pid_t pid = 0;
        int nbgen = 0;
        int nbgen2 = 0;
        char cheminImage[100];
	
		/* Détection du "-stats" */
        if (argc != 1 && strcmp(argv[1], "-stats") == 0)
        {
            history();
        }
        else if (argc != 1 && strcmp(argv[1], "-stats") != 0)
        {
            printf("no valid arguments\n");
        }
        else if( argc == 1)
        {
            nbgen = alea(1, 2);
        }
	


        if (nbgen == 1)
        {
            
            system("clear");
            nbgen2 = alea(1, 7);
            history_ecriture(nbgen2, nbgen);
            sprintf(cheminImage, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER1_PBM/image%i.pbm", nbgen2);
            readOpti(cheminImage);
            pid=fork();
            if (pid == 0)
            {
            	system("./touche");
            }
            else
            {
            	
                wait(NULL);    
            }
        }
        else if (nbgen == 2)
        {
            
            system("clear");
            pid=fork();
                if (pid == 0)
                {
                    history_ecriture(0, nbgen);
                    execl("/home/maxime/Bureau/Final/ExiaSaver/dynamic","dynamic", NULL);
                }
                else
                {
                    wait(NULL);
                }
        }
        return 0;
    }
}

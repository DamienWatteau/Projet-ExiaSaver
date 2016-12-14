#include <stdio.h> // (gets, printf)
#include <stdlib.h>
#include <sys/types.h>    //1
#include <unistd.h>    //1
#include <string.h> // (strcmp, )
#define TAILLE_MAX 1000 // Tableau de taille 1000

/* Déclaration des variables de type define */

#define TRUE 1; // Attribut la valeur 1 à la variable "TRUE"  
#define FALSE 0; // Attribut la valeur 0 à la variable "FALSE"  

/* Algorithme de tri simple à bulle  */
void tri_a_bulle(int *tableau, int const n)
{
 	int j   = 0; /* Variable de boucle */
 	int tmp = 0; /* Variable de stockage temporaire */

	/* Booléen marquant l'arrêt du tri si le tableau est ordonné */
	int en_desordre = TRUE;
	/* Boucle de répétition du tri et le test qui
	 arrête le tri dès que le tableau est ordonné(en_desordre=FALSE) */
	while (en_desordre)
	{
		/* Supposons le tableau ordonné */
		en_desordre = FALSE;
		/* Vérification des éléments des places j et j+1 */
		for (j = 0; j < n-1; j++)
		{
			/* Si les 2 éléments sont mal triés */
			if(tableau[j] > tableau[j+1])
			{
				/* Inversion des 2 éléments */
 				tmp = tableau[j+1];
 				tableau[j+1] = tableau[j];
 				tableau[j] = tmp;

 				/* Le tableau n'est toujours pas trié */
				en_desordre = TRUE;
 			}
		}
	}
}


void history() 
{
    char str[50];
    do
    {
		
	/* Affichage visuelle de la commande -stats */
        system("clear");									// Efface le contenu de la console
        printf("\t\t ----------------------------\n");
        printf("\t\t- Affichage des statistiques -\n");
        printf("\t\t ----------------------------\n\n");

        printf("1 - Statistiques sur le nombre de types d'ecrans lances\n");
        printf("2 - Affichage du contenu du fichier 'historique.txt'\n");
        printf("3 - Retour\n\n");
        printf("-----------------\n");
        printf("Votre choix : ");
        gets(str);									//lit une ligne depuis stdin et la stocke dans "str"
        printf("-----------------\n");
    } while(strcmp (str,"1") != 0 && strcmp (str,"2") != 0 && strcmp (str,"3") != 0);   // La boucle attend que l'utilisateur entre "1", "2", "3" dans le terminal
																						//cf. Porte logique NON-ET
		/* Compare avec l'entrée saisie */
        if (strcmp(str, "1") == 0)
        {
			
            int tableau[3]={0};
            int nbStatique = 0;
            int nbDynamique = 0;
            int nbInteractif = 0;
            int c;

            FILE * pFile;

            pFile=fopen ("Log/historique.txt","r");
            if (pFile==NULL) perror ("Error opening file");
            else
            do {
              c = fgetc (pFile);
                if (c == ';')
                {
                 c = fgetc (pFile);
                    if (c == '1')
                    {
                        nbStatique++;
                    }
                    else if (c == '2')
                    {
                        nbDynamique++; //
                    }
                    if (c == '3')
                    {
                        nbInteractif++;
                    }

                }
            } while (c != EOF);
            fclose (pFile);
            tableau[0] = nbStatique;
            tableau[1] = nbDynamique;
            tableau[2] = nbInteractif;
            tri_a_bulle(tableau, 3) ;

            char* premierType;
            char* deuxiemeType;
            char* troisiemeType;

            if (tableau[0] == nbStatique)
            {
                premierType="statique";
            }
            else if (tableau[0] == nbDynamique)
            {
                premierType="dynamique";
            }
            else
            {
                premierType="interactif";
            }

            //
            if (tableau[1] == nbStatique)
            {
                deuxiemeType="statique";
            }
            else if (tableau[1] == nbDynamique)
            {
                deuxiemeType="dynamique";
            }
            else
            {
                deuxiemeType="interactif";
            }
            //

            if (tableau[2] == nbStatique)
            {
                troisiemeType="statique";
            }
            else if (tableau[2] == nbDynamique)
            {
                troisiemeType="dynamique";
            }
            else
            {
                troisiemeType="interactif";
            }
            system("clear");

            printf("\t -----------------------------------------------------\n");
            printf("\t- Statistiques sur le nombre de types d'ecrans lances -\n");
            printf("\t -----------------------------------------------------\n\n\n");

            float ntotal = 0.0;
            float pourcentagePremierType = 0.0;
            float pourcentageDeuxiemeType = 0.0;
            float pourcentageTroisiemeType = 0.0;

            ntotal = nbStatique + nbDynamique + nbInteractif;

            pourcentageTroisiemeType = (tableau[2] / ntotal) *100.0;
            pourcentageDeuxiemeType = (tableau[1] / ntotal) *100.0;
            pourcentagePremierType = (tableau[0] / ntotal) *100.0;
            printf("> - Le mode le plus lance est %s avec %.0f %% ", troisiemeType, pourcentageTroisiemeType); 

            printf("\n-------------------------------------------------\n");
            printf("- %s avec %.0f %% .\n", deuxiemeType, pourcentageDeuxiemeType);
            printf("- %s avec %.0f %% .\n", premierType, pourcentagePremierType);
		
            do
            {
                printf("\nAppuyer sur (1) pour retourner en arrière : ");
                gets(str);

                if ((strcmp(str, "1") == 0))
                {
                    history();
                }

            } while(strcmp (str,"1") != 0);
        }
        else if (strcmp(str, "2") == 0)
        {
            system("clear");
            printf("\t\t--------------------------------------------------\n");
            printf("\t\t- Affichage du contenu du fichier 'historique.txt'-\n");
            printf("\t\t---------------------------------------------------\n\n");

            FILE* fichier = NULL;
            char chaine[TAILLE_MAX] = ""; // Chaîne vide de taille TAILLE_MAX
            fichier = fopen("Log/historique.txt", "r");

                if (fichier != NULL)
                {
                    while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
                    {
                        printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
                    }
                    fclose(fichier);
                }
            //
                do
                {
                    printf("\nAppuyer sur (1) pour retourner en arrière : ");

                    gets(str);
                    if ((strcmp(str, "1") == 0))
                    {
                        history();
                    }

                } while(strcmp (str,"1") != 0);
        }
        else if (strcmp(str, "3") == 0)
        {
            main();
        }
}


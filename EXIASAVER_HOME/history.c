#include <stdio.h> // (gets, printf)
#include <stdlib.h>
#include <sys/types.h>    //1
#include <unistd.h>    //1
#include <string.h> // (strcmp, )
#define TAILLE_MAX 1000 // Tableau de taille 1000

#define TRUE 1;
#define FALSE 0;

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




void history()    //2
{
    char str[50];
    do
    {
        system("clear");
        printf("\t\t ----------------------------\n");
        printf("\t\t- Affichage des statistiques -\n");
        printf("\t\t ----------------------------\n\n");

        printf("1 - Statistiques sur le nombre de types d'ecrans lances\n");
        printf("2 - Affichage du contenu du fichier 'historique.txt'\n");
        printf("3 - Retour\n\n");
        printf("-----------------\n");
        printf("Votre choix : ");
        gets(str);
        printf("-----------------\n");
    } while(strcmp (str,"1") != 0 && strcmp (str,"2") != 0 && strcmp (str,"3") != 0);   // NON-ET
                                                                                        // while ( (strcmp(str, "1") != 0) || (strcmp(str, "2") != 0));
                                                                                        //while(strcmp (str,"1") != 0 && strcmp (str,"2") != 0 && strcmp (str,"3") != 0);

        if (strcmp(str, "1") == 0)
        {
            int tableau[3]={0};
            // n++;n1++;n2++
            int n = 0;
            int n1 = 0;
            int n2 = 0;
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
                        n++;
                    }
                    else if (c == '2')
                    {
                        n1++; //
                    }
                    if (c == '3')
                    {
                        n2++;
                    }

                }
            } while (c != EOF);
            fclose (pFile);
            tableau[0] = n;
            tableau[1] = n1;
            tableau[2] = n2;
            tri_a_bulle(tableau, 3) ;

            //Mode le moins exécuté
            //char premierType[20];

            char* premierType;
            char* deuxiemeType;
            char* troisiemeType;

            if (tableau[0] == n)
            {
                premierType="statique";
                //premierType[0]='s';premierType[1]='t';premierType[2]='a';premierType[3]='t';premierType[4]='i';premierType[5]='q';premierType[6]='u';premierType[7]='e';premierType[8]='\0';

            }
            else if (tableau[0] == n1)
            {
                premierType="dynamique";
            }
            else
            {
                premierType="interactif";

            }

            //
            if (tableau[1] == n)
            {
                deuxiemeType="statique";
            }
            else if (tableau[1] == n1)
            {
                deuxiemeType="dynamique";
            }
            else
            {
                deuxiemeType="interactif";
            }
            //

            if (tableau[2] == n)
            {
                troisiemeType="statique";
            }
            else if (tableau[2] == n1)
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

                // ntotal = n+n1+n2
            float ntotal = 0.0;
            float pourcentagePremierType = 0.0;
            float pourcentageDeuxiemeType = 0.0;
            float pourcentageTroisiemeType = 0.0;

                // Faire un .h avec une structure
            ntotal = n + n1 +n2;

            pourcentageTroisiemeType = (tableau[2] / ntotal) *100.0;
            pourcentageDeuxiemeType = (tableau[1] / ntotal) *100.0;
            pourcentagePremierType = (tableau[0] / ntotal) *100.0;
            printf("> - Le mode le plus lance est %s avec %.0f %% ", troisiemeType, pourcentageTroisiemeType); //premierP

            printf("\n-------------------------------------------------\n");
            printf("- %s avec %.0f %% .\n", deuxiemeType, pourcentageDeuxiemeType);
            printf("- %s avec %.0f %% .\n", premierType, pourcentagePremierType);
            //printf("- %s avec %d %% .\n");
            //printf("- %s avec %d %% .\n");

            /*char premierType[20]="statique";
            char deuxiemeType[20]="statique";
            char troisiemeType[20]="statique";

            int premierP = 0;
            int deuxiemeP = 0;
            int troisiemeP = 0;


            system("clear");

            printf("\t -----------------------------------------------------\n");
            printf("\t- Statistiques sur le nombre de types d'ecrans lances -\n");
            printf("\t -----------------------------------------------------\n\n\n");

                // ntotal = n+n1+n2
            float n = 2.0;
            float ntotal = 10.0;
            float lol = 0.0;

                // Faire un .h avec une structure

            lol = (n / ntotal)*100.0;
            printf("> - Le mode le plus lance est %s avec %f %% .", premierType, lol); //premierP

            printf("\n-------------------------------------------------\n");
            printf("- %s avec %d %% .\n", deuxiemeType, deuxiemeP);
            printf("- %s avec %d %% .\n", troisiemeType, troisiemeP);*/

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


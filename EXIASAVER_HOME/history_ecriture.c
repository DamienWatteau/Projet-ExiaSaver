#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void history_ecriture (int *nbF, int mode)
{

   /* lire l'heure courante */
   time_t now = time (NULL);    /* now contient maintenant la date et l'heure courante */

   /* la convertir en heure locale */
   struct tm tm_now = *localtime (&now);

   /* Creer une chaine JJ/MM/AAAA HH:MM:SS */
   char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];

   /* Formater la date et l'heure (Il enregistre la date et l'heure dans la chaine de caractère s_now  */
   strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);

        FILE* f = NULL;

        f=fopen("/home/watteau/Bureau/Projectss/history/stats.txt", "a");

        if (mode == 1)
        {
            if (f != NULL)
            {
                fprintf(f,"%s ;%d; %d.pbm\n", s_now, mode,*nbF);
                fclose(f);
            }
            // Si 1, Ecrire nom fichier
        }
        else if (mode == 2)
            {
                // Si 2, Taille d'affichage
            }
            else
                {
                // Si 3, position initiale avion sur la console
                }
}


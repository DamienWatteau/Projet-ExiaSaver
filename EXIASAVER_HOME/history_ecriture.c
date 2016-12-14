#include <stdio.h> // Cette bibliothèque renferme les routines de traitement d'entrée/sortie fichier. 
#include <time.h> // Cette bibliothèque permet de manipuler l'heure et la date 

void history_ecriture (int *nbF, int mode)
{

   /* Récupérer l'heure courante */
   time_t now = time (NULL);    // La variable "now" contient la date et l'heure courante

   struct tm tm_now = *localtime (&now); // Conversion en heure locale

   char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"]; // Creer une chaine JJ/MM/AAAA HH:MM:SS

   /* Formater la date et l'heure (Il enregistre la date et l'heure dans la chaine de caractère s_now  */
   strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
   
   /* Ecrire la date, l'heure, le mode veille dans le fichier "stats.txt */
   FILE* f = NULL;
   
   f=fopen("Log/historique.txt", "a");
   
   if (mode == 1)
   {
      if (f != NULL)
      {
         fprintf(f,"%s ;%d; %d.pbm\n", s_now, mode,*nbF);
         fclose(f);
      }
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readOpti(char nomImage[])
{
	FILE* image = NULL;   //Variable pour ouvrir notre image
	char *tableauImage; 
	int i =0, j = 0, linesTab = 0, columnsTab = 0;
	char tank[10], columns[5], lines[5];
	const char s[2] = " ";
	char *token;
	int x = 0 , y = 0, saut = 0;
	int columnsWhile = 0, linesWhile = 0;
	char carac;
	char **tab; //pointeur qui va nous servir de tableau
	int countLine = 0;
	char ecran[24][80];
	int length = 0, width = 0;
	int a = 0, b = 0;
	int countline;
	int countcarac;
	int nbcarac = 0;
	
	
	image = fopen(nomImage, "r"); //ouvrir un fichier
	
	if (image != NULL)  // Si l'image s'est ouverte
	{	
		/*recupérer la taille de l'image*/
		
		while(fgetc(image) != EOF){ // lit caractère par caratère l'image jusqu'à la fin du fichier
			nbcarac++;
		}
		
		tableauImage = malloc(nbcarac * sizeof(char)); // Alloue la taille de nbcarac dans tableauImage
		
		rewind(image); // place le curseur au debut du fichier
		
		/* Lit ligne par ligne l'image dans le tableau*/
		while (fgets(tableauImage, nbcarac, image) != NULL) 
		{
			if(i==1) 
			{
				fgets (tank, 10, image);
				token = strtok(tank, s);
				while(token != NULL)
				{
					if(j == 0)
					{
						strcpy(lines, token);
						token = strtok(NULL, s);
						j++;
					}
					else if(j == 1)
					{
						strcpy(columns, token);
						token = strtok(NULL, s);
					}
				}
			}
			i++;
		}
		
		rewind(image); // "    "
		
		linesTab = atoi(lines); // convertie une chaîne de caractère en une valeure entière (char en int)
		columnsTab = atoi(columns); // " 								"
		
		tab = malloc(columnsTab * sizeof(*tab)); //allocation d'un tableau de pointeur tab de 'columnsTab'
		
		
		for(x = 0; x<columnsTab; x++){ // Création des colonnes du tableau bidimentionnel 
			tab[x] = malloc(linesTab * sizeof(**tab)); // Alloue le taille necéssaire des lignes
		}
		/* On ecrit 1 dans tous le tableau (initialisation) */
		for(x=0 ; x<columnsTab ; x++) 
		{
			for(y=0 ; y<linesTab ; y++)
			{
				tab[x][y] = '1';
			}
		}
		do
		{		
			carac = fgetc(image); // Lit caractère par caractère l'image et stocke le premier caractère dans carac
			
			/* saute les 3 premières lignes de nos .pbm  */
			if ( countLine < 3 &&  carac == 10){
				countLine++;
				
			}
			/* Ecrit les caractères dans le tableau */
			else if (countLine >= 3 && (carac == 48 || carac == 49)){
				tab[linesWhile][columnsWhile] = carac;
				columnsWhile++;
				
			}
			/* Permet de revenir a la ligne suivante à la colonne 0 */
			else if (countLine >= 3 && carac == 10){
				linesWhile++;
				columnsWhile=0;
			}
		}while(carac != EOF); // tant qu'on est pas à la fin du fichier
		
		// Max
		
		countline = 0;
		countcarac =0;
		
		/* Calculs pour le centrage   */
		
		length = (80 - linesTab)/2 ;
		width = (24 - columnsTab)/2;
		
		// délimitation de l'image 
		
		int lengthmax = length + linesTab;
		int widthmax = width + columnsTab;
		
		
		int l = 0;
		int c = 0;
		int oldl = 0;

		for(l = 0; l < 24; l++){
			for(c = 0; c < 80; c++){
			
				if(c > length && l > width && l <= widthmax && c <= lengthmax) // Met en condition toute la taille de l'image (longueur/largeur max)
				{
					if(oldl == 0) // si toujours dans la même ligne
					{
						oldl = l; //garder le l
					}
					if(oldl != l) //si on a changé de ligne depuis le dernier passage
					{
						oldl = l; //on garde le nouveau l
						a++; //on dit à l'image de changer de ligne aussi
					}
					ecran[l][c] = tab[a][b]; //ecrire l'image dans le grand tableau
					b++; //on incrémente b pour changer de colonne
					
					
				}
				else //si on est pas dans l'espace d'écriture de l'image
				{
					b=0; //on remet les colonnes de l'image à 0
					ecran[l][c] = 48; //et on écrit 0 dans le grand tableau
				}
				
			}
			
			
	
		}
		
		
		for(l = 0; l < 24; l++){
			for(c = 0; c < 80; c++){
				// si il rencontre des 0, écrit des espaces
				if(ecran[l][c] == 48){
					printf(" ");
				}
				else if (ecran[l][c] == 49){ // si il rencontre des 1, écrit un caractère spécial
					printf("\u2588"); // caractère unicode u+2588
				}
			}
		}

	
	}
	
	else
	{
		printf("Fail ouverture image :/\n");
	}
	return 0;
}

int main(int argc, char *argv)
{
	char nomImage[50];
	strcpy(nomImage, "/home/maxime/Bureau/Final/bitmap/nyancat.pbm");
	readOpti(nomImage);
	return 0;
}

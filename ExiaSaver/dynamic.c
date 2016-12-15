#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char **readOpti(char nomImage[], int *linesTab, int *columnsTab); //here we initialize the prototypes
void **loop(char **tab, int *linesTab, int *x);
char *timeReader();

int main(int argc, char *argv)
{
	char nomImage0[50], nomImage1[50], nomImage2[50], nomImage3[50], nomImage4[50], nomImage5[50], nomImage6[50], nomImage7[50];
	int  linesTab = 0, columnsTab = 0;
	int x = 0;
	system("clear");
	while (1)
	{
		char *heure = timeReader(); //here we put the time in the array heure
	
		sprintf(nomImage0, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]); //collect the patch of the pictures
		x++;																		//increment x to pass to the next character of the string heure
		sprintf(nomImage1, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage2, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage3, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage4, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage5, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage6, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
		x++;
		sprintf(nomImage7, "/home/maxime/Bureau/Final/ExiaSaver/EXIASAVER2_PBM/%i.pbm", heure[x]);
	
		char **tab0 = readOpti(nomImage0, &linesTab, &columnsTab); //call the function readOpi for each character of the string heure
		char **tab1 = readOpti(nomImage1, &linesTab, &columnsTab);
		char **tab2 = readOpti(nomImage2, &linesTab, &columnsTab);
		char **tab3 = readOpti(nomImage3, &linesTab, &columnsTab);
		char **tab4 = readOpti(nomImage4, &linesTab, &columnsTab);
		char **tab5 = readOpti(nomImage5, &linesTab, &columnsTab);
		char **tab6 = readOpti(nomImage6, &linesTab, &columnsTab);
		char **tab7 = readOpti(nomImage7, &linesTab, &columnsTab);
	
	
		for(x = 0; x < columnsTab; x++) //call loop to print each pictures
		{
			loop(tab0, &linesTab, &x);		
			loop(tab1, &linesTab, &x);		
			loop(tab2, &linesTab, &x);		
			loop(tab3, &linesTab, &x);		
			loop(tab4, &linesTab, &x);		
			loop(tab5, &linesTab, &x);		
			loop(tab6, &linesTab, &x);		
			loop(tab7, &linesTab, &x);
			printf("\n");
		}
		
		int n = 5;
		
		printf("Cet écran sera actualisé dans %d secondes", n);        //put this message in the cache memory
		fflush(stdout);         //force to print the message who was in the cache then erase the message from the cache

		int sec = 0;
		

		while (sec < n)        //while time diffrent from the time we have to wait
		{
		    sec++;      //increase the time from 1 seconde
		    sleep(1);       // wait 1 seconde
		    printf(".");
		    fflush(stdout);
		}
		printf("\n");
		
		system("clear");
		x = 0; //set x to 0 to be able to run the function an other time
	}	
	return 0;
}


char **readOpti(char nomImage[], int *linesTab, int *columnsTab) //function to read a pictureand put it into a array
{
	FILE* image = NULL;
	char *tableauImage;
	int i =0, j = 0, linesTab2 = *linesTab, columnsTab2 = *columnsTab;
	char tank[10], columns[5], lines[5];
	const char s[2] = " ";
	char *token;
	int x = 0 , y = 0, saut = 0;
	int columnsWhile = 0, linesWhile = 0;
	char carac , carac0;
	char **tab; //pointer who is used as an array
	int countLine = 0;
	char ecran[24][80];
	int length = 0, width = 0;
	int a = 0, b = 0;
	int countline;
	int countcarac;
	int compteur = 0;
	int nbcarac = 0;
	
	image = fopen(nomImage, "r"); //open an file
	
	if (image != NULL) 
	{	
	
		while(fgetc(image) != EOF){
			nbcarac++;
		}
		tableauImage = malloc(nbcarac * sizeof(char)); //create an array of the size of the number of character from the picture
		
		rewind(image); //allows to return to the beginning of the picture
	
		while (fgets(tableauImage, nbcarac, image) != NULL) //collect the size of the picture in two char
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
		rewind(image);
		
		linesTab2 = atoi(lines);
		columnsTab2 = atoi(columns);
		
		/*linesTab2 = 3;
		columnsTab2 = 5;*/
		
		//printf("%d ", linesTab2);
		//printf("%d ", columnsTab2);
		
		
		tab = malloc(columnsTab2 * sizeof(*tab)); //allocation d'un tableau de pointeur de 'taille1'
		
		
		for(x = 0; x<columnsTab2; x++){
			tab[x] = malloc(linesTab2 * sizeof(**tab));
		}
		
		do
		{		
			carac = fgetc(image);
					
			if ( countLine < 3 &&  carac == 10){
				countLine++;
				
			}
			else if (countLine >= 3 && (carac == 48 || carac == 49)){
				tab[linesWhile][columnsWhile] = carac;
				columnsWhile++;
				
			}

			else if (countLine >= 3 && carac == 10){
				linesWhile++;
				columnsWhile=0;
			}		
		}while(carac != EOF);
		
		
		/*countline = 0;
		countcarac = 0;
		
		length = (80 - *columnsTab)/2 ;
		width = (24 - *linesTab)/2;
		
		int lengthmax = length + *columnsTab;
		int widthmax = width + *linesTab;*/
		
		
		int l = 0;
		int c = 0;
		int oldl = 0;
		
		/*for(l = 0; l < 24; l++){
			for(c = 0; c < 80; c++){
			
				if(c > length && l > width && l <= widthmax && c <= lengthmax)
				{
					if(oldl == 0)
					{
						oldl = l;
					}
					if(oldl != l)
					{
						oldl = l;
						a++;
					}
					ecran[l][c] = tab[a][b];
					b++;
					
					
				}
				else
				{
					b=0;
					ecran[l][c] = 48;
				}
				
			}
			
			
	
		}
		
		
		for(l = 0; l < 24; l++){
			for(c = 0; c < 80; c++){
				
				if(ecran[l][c] == 48){
					printf(" ");
				}
				else if (ecran[l][c] == 49){
					printf("\u2588");
				}
			}
		}*/

	}
	
	else
	{
		printf("Fail ouverture image :/\n");
	}
	
	*linesTab = linesTab2;
	*columnsTab = columnsTab2;
	return tab;
}

void **loop(char **tab, int *linesTab, int *x)
{
	int y = 0, x2=*x;
	int linesTab3 = *linesTab;
	for(y = 0; y < linesTab3; y++)
		{
				
			if(tab[x2][y] == 48)
			{
				printf(" ");
			}
			else if (tab[x2][y] == 49)
			{
				printf("\u2588");
			}
		}
}

char *timeReader()
{
	int i = 0;
	char *heure;
	
	heure = malloc(8*sizeof(char));
	
	/* Récupérer l'heure courante */
	time_t now = time (NULL);    // La variable "now" contient la date et l'heure courante
	
	struct tm tm_now = *localtime (&now); // Conversion en heure locale
	
	char s_now[sizeof "HH:MM:SS"]; // Creer une chaine JJ/MM/AAAA HH:MM:SS
	
	/* Formater la date et l'heure (Il enregistre la date et l'heure dans la chaine de caractère s_now  */
	strftime (s_now, sizeof s_now, "%H:%M:%S", &tm_now);
	strcpy(heure, s_now);
	//printf("%s", heure);
	
	return heure;
}



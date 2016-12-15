#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int readOpti(char nomImage[])
{
	FILE* image = NULL;
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
	
	if (image != NULL) 
	{	
		//recupérer la taille de l'image
		while(fgetc(image) != EOF){
			nbcarac++;
		}
		
		//printf("%d",nbcarac);
		
		tableauImage = malloc(nbcarac * sizeof(char));
		
		rewind(image);
		
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
		
		rewind(image);
		
		linesTab = atoi(lines);
		columnsTab = atoi(columns);
		
		
		//printf("%d %d \n",  linesTab, columnsTab);
		
		tab = malloc(columnsTab * sizeof(*tab)); //allocation d'un tableau de pointeur de 'taille1'
		
		
		for(x = 0; x<columnsTab; x++){
			tab[x] = malloc(linesTab * sizeof(**tab));
		}
		
		for(x=0 ; x<columnsTab ; x++)
		{
			for(y=0 ; y<linesTab ; y++)
			{
				tab[x][y] = '1';
				//printf("%c " , tab[x][y]);
			}
			//printf("\n");
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
		
		
		countline = 0;
		countcarac =0;
		
		length = (80 - linesTab)/2 ;
		width = (24 - columnsTab)/2;
		
		int lengthmax = length + linesTab;
		int widthmax = width + columnsTab;
		
		
		int l = 0;
		int c = 0;
		int oldl = 0;

		for(l = 0; l < 24; l++){
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

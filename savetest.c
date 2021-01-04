//V1.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//structure pour les 64 cases du jeux permettant de stocker le nom de la case et eventuellement si il y a une piece
typedef struct {
	char* piece;
	char* nom_case;
}Echiquier;
// on creer un tableau de 4 cases --> initiliasation à 64 dans le programme final 
Echiquier plateau[2][2];




//fonction de sauvegarde des places des pièces 
void sauvegarde()
{
	FILE *fichier=NULL;
	fichier = fopen("savetest.txt","w+");
	if (fichier != NULL)
	{
		for (int a = 0; a < 8; a++)
		{
			for(int b = 0; b < 8; b++)
			{		
				fprintf(fichier,"%s",plateau[a][b].piece);
			}
		}	
		fclose(fichier);
	}
	else
	{
	 	printf("erreur alloc\n");
	}
}
// fonction de récuperation à partir du fichier de la place des pieces 
void recup()
{
	char c[4]="";
	FILE *fichier=NULL;
	fichier=fopen("savetest.txt","r");
	fgets(c,65,fichier);
	int i=0;
	for (int a = 0; a < 8;a++)
	{
		for(int b=0; b<2;b++)
		{		
			
			plateau[a][b].piece=(char*)malloc(sizeof(char));
			plateau[a][b].piece[0]=c[i];
			plateau[a][b].piece[1]=c[i+1];
			i = i+2;
		
		}
	}
	//printf("%s\n",plateau[0][0].piece);
	fclose(fichier);
}
 
int main()
{
	plateau[0][0].piece="pb"; // creer une fonction pour initialiser toutes les cases 
	plateau[0][1].piece="pn";
	plateau[1][1].piece="tb";
	plateau[1][0].piece="tn";
	sauvegarde();
	recup();
	return 0;

}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
                            // Création du plateau
typedef struct {
        char* piece;
        char* nom_case;
}Echiquier;
Echiquier plateau[8][8];


int reset_plateau(void)
{
    int i;
    int j;
                            // On rempli le tableau avec les 0 ( cases vides )
    for ( i = 2 ; i < 6 ; i++)  
    {
        for ( j = 0 ; j < 8 ; j++)
        {
            plateau[i][j].piece="00";
        }
    }

                            // On place les pièces noires
    plateau[0][0].piece = plateau[0][7].piece = "tn";
    plateau[0][1].piece = plateau[0][6].piece = "cn";
    plateau[0][2].piece = plateau[0][5].piece = "fn";
    plateau[0][3].piece = "dn";
    plateau[0][4].piece = "rn";

                            // Pions noirs 
    for (i = 0; i < 8 ; i++)
    {
        plateau[1][i].piece = "pb";
    }

                            // On place les pièces blanches
    plateau[7][0].piece = plateau[7][7].piece = "tb";
    plateau[7][1].piece = plateau[7][6].piece = "cb";
    plateau[7][2].piece = plateau[7][5].piece = "fb";
    plateau[7][3].piece = "db";
    plateau[7][4].piece = "rb";

                            // Pions blancs
    for (i = 0; i < 8 ; i++)
    {
        plateau[6][i].piece = "pb";
    }

    
                            // Création des noms des cases
    plateau[0][0].nom_case = "a8"; plateau[0][1].nom_case = "b8"; plateau[0][2].nom_case = "c8"; plateau[0][3].nom_case = "d8";
    plateau[0][4].nom_case = "e8"; plateau[0][5].nom_case = "f8"; plateau[0][6].nom_case = "g8"; plateau[0][7].nom_case = "h8";
    plateau[1][0].nom_case = "a7"; plateau[1][1].nom_case = "b7"; plateau[1][2].nom_case = "c7"; plateau[1][3].nom_case = "d7";
    plateau[1][4].nom_case = "e7"; plateau[1][5].nom_case = "f7"; plateau[1][6].nom_case = "g7"; plateau[1][7].nom_case = "h7";
    plateau[2][0].nom_case = "a6"; plateau[2][1].nom_case = "b6"; plateau[2][2].nom_case = "c6"; plateau[2][3].nom_case = "d6";
    plateau[2][4].nom_case = "e6"; plateau[2][5].nom_case = "f6"; plateau[2][6].nom_case = "g6"; plateau[2][7].nom_case = "h6";
    plateau[3][0].nom_case = "a5"; plateau[3][1].nom_case = "b5"; plateau[3][2].nom_case = "c5"; plateau[3][3].nom_case = "d5";
    plateau[3][4].nom_case = "e5"; plateau[3][5].nom_case = "f5"; plateau[3][6].nom_case = "g5"; plateau[3][7].nom_case = "h5";
    plateau[4][0].nom_case = "a4"; plateau[4][1].nom_case = "b4"; plateau[4][2].nom_case = "c4"; plateau[4][3].nom_case = "d4";
    plateau[4][4].nom_case = "e4"; plateau[4][5].nom_case = "f4"; plateau[4][6].nom_case = "g4"; plateau[4][7].nom_case = "h4";
    plateau[5][0].nom_case = "a3"; plateau[5][1].nom_case = "b3"; plateau[5][2].nom_case = "c3"; plateau[5][3].nom_case = "d3";
    plateau[5][4].nom_case = "e3"; plateau[5][5].nom_case = "f3"; plateau[5][6].nom_case = "g3"; plateau[5][7].nom_case = "h3";
    plateau[6][0].nom_case = "a2"; plateau[6][1].nom_case = "b2"; plateau[6][2].nom_case = "c2"; plateau[6][3].nom_case = "d2";
    plateau[6][4].nom_case = "e2"; plateau[6][5].nom_case = "f2"; plateau[6][6].nom_case = "g2"; plateau[6][7].nom_case = "h2";
    plateau[7][0].nom_case = "a1"; plateau[7][1].nom_case = "b1"; plateau[7][2].nom_case = "c1"; plateau[7][3].nom_case = "d1";
    plateau[7][4].nom_case = "e1"; plateau[7][5].nom_case = "f1"; plateau[7][6].nom_case = "g1"; plateau[7][7].nom_case = "h1";


                            // Affichage du plateau sur la console
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            printf("%s", plateau[i][j].piece);
        }
        printf("\n");
        
    }
    printf("\n");
    for (i=0;i<8;i++)
    {
        for (j=0;j<8;j++)
        {
            printf("%s", plateau[i][j].nom_case);
        }
        printf("\n");
    }
    
    return 0;
}

int* recup(char *caseAVerif)
{
    int i = 0;
    int j = 0;
    int *recupcase = (int*)malloc(20*sizeof(int));
    for(  i = 0; i<8;  i++)
    {
        for ( j = 0; j<8; j++)
        {
            if (strcmp(caseAVerif,plateau[i][j].nom_case) == 0)
            {
                goto stop;
            }
        }
    }
    stop : 
    recupcase[0] = i;
    recupcase[1] = j;
    return recupcase;

    
}
int reine(int x, int y, int *deplacement)
{
    int j = 0;
    
    
    // Si noire
    if(plateau[x][y].piece[1] == 'n')
    {
        // Bas
        for (int i = x+1; i < 8 && plateau[i-1][y].piece[1] != 'b'; i++)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'b')
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        // Haut 
        for (int i = x-1; i >= 0 && plateau[i+1][y].piece[1] != 'b'; i--)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'b' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        // Gauche
        for (int i = y-1; i >= 0 && plateau[x][i+1].piece[1] != 'b'; i--)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'b' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
    
        // Droite
        for (int i = y+1; i < 8 && plateau[x][i-1].piece[1] != 'b'; i++)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'b' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
            
        }
        
        // Bas Droite
        for (int i=x+1, k=y+1; i<8 && k<8 && plateau[i-1][k-1].piece[1] != 'b'; i++, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
            
        // Bas Gauche
        for (int i=x+1, k=y-1; i<8 && k>=0 && plateau[i-1][k+1].piece[1] != 'b'; i++, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Gauche
        for (int i=x-1, k=y-1; i>=0 && k>=0 && plateau[i+1][k+1].piece[1] != 'b'; i--, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Droite
        for (int i=x-1, k=y+1; i>=0 && k<8 && plateau[i+1][k-1].piece[1] != 'b'; i--, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
            
    }
        // Si blanche
    if(plateau[x][y].piece[1] == 'b')
    {
        // Bas
        for (int i = x+1; i < 8 && plateau[i-1][y].piece[1] != 'n'; i++)
        {
            
            if ( (strcmp(plateau[i][y].piece,"00") == 0 )|| plateau[i][y].piece[1] == 'n' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            } else {break;}
        
        }
        
        // Haut 
        for (int i = x-1 ; i >= 0 && plateau[i+1][y].piece[1] != 'n'; i--)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'n' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        
        // Gauche
        for (int i = y-1; i >= 0 && plateau[x][i+1].piece[1] != 'n'; i--)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'n' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
        
        // Droite
        for (int i = y+1; i < 8 && plateau[x][i-1].piece[1] != 'n'; i++)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'n' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
        
        // Bas Droite
        for (int i=x+1, k=y+1; i<8 && k<8 && plateau[i-1][k-1].piece[1] != 'n'; i++, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                    
                }else {break;}
            }
        // Bas Gauche
        for (int i=x+1, k=y-1; i<8 && k>=0 && plateau[i-1][k+1].piece[1] != 'n'; i++, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Gauche
        for (int i=x-1, k=y-1; i>=0 && k>=0 && plateau[i+1][k+1].piece[1] != 'n'; i--, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Droite
        for (int i=x-1, k=y+1; i>=0 && k<8 && plateau[i+1][k-1].piece[1] != 'n'; i--, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
    }
    return j;
}
int fou(int x, int y, int *deplacement)
{
    int j = 0;
    
    
    // Si noire
    if(plateau[x][y].piece[1] == 'n')
    {
        
        // Bas Droite
        for (int i=x+1, k=y+1; i<8 && k<8 && plateau[i-1][k-1].piece[1] != 'b'; i++, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
            
        // Bas Gauche
        for (int i=x+1, k=y-1; i<8 && k>=0 && plateau[i-1][k+1].piece[1] != 'b'; i++, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Gauche
        for (int i=x-1, k=y-1; i>=0 && k>=0 && plateau[i+1][k+1].piece[1] != 'b'; i--, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Droite
        for (int i=x-1, k=y+1; i>=0 && k<8 && plateau[i+1][k-1].piece[1] != 'b'; i--, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'b' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
            
    }
        // Si blanche
    if(plateau[x][y].piece[1] == 'b')
    {
        
        // Bas Droite
        for (int i=x+1, k=y+1; i<8 && k<8 && plateau[i-1][k-1].piece[1] != 'n'; i++, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                    
                }else {break;}
            }
        // Bas Gauche
        for (int i=x+1, k=y-1; i<8 && k>=0 && plateau[i-1][k+1].piece[1] != 'n'; i++, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Gauche
        for (int i=x-1, k=y-1; i>=0 && k>=0 && plateau[i+1][k+1].piece[1] != 'n'; i--, k--)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
        
        // Haut Droite
        for (int i=x-1, k=y+1; i>=0 && k<8 && plateau[i+1][k-1].piece[1] != 'n'; i--, k++)
            {
                if ( (strcmp(plateau[i][k].piece,"00") == 0) || plateau[i][k].piece[1] == 'n' )
                {
                    deplacement[j] = i;
                    j++;
                    deplacement[j] = k;
                    j++;
                }else {break;}
            }
    }
    return j;
}
int tour(int x,int y,int *deplacement)
{
    int j = 0;
    
    // Si blanche :
    if(plateau[x][y].piece[1] == 'b')
    {
        
        // Bas
        for (int i = x+1; i < 8 && plateau[i-1][y].piece[1] != 'n'; i++)
        {
            
            if ( (strcmp(plateau[i][y].piece,"00") == 0 )|| plateau[i][y].piece[1] == 'n' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            } else {break;}
        
        }
        
        // Haut 
        for (int i = x-1 ; i >= 0 && plateau[i+1][y].piece[1] != 'n'; i--)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'n' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        
        // Gauche
        for (int i = y-1; i >= 0 && plateau[x][i+1].piece[1] != 'n'; i--)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'n' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
        
        // Droite
        for (int i = y+1; i < 8 && plateau[x][i-1].piece[1] != 'n'; i++)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'n' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
    }
    
    // Si noire :
    if(plateau[x][y].piece[1] == 'n')
    {
        // Bas
        for (int i = x+1; i < 8 && plateau[i-1][y].piece[1] != 'b'; i++)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'b')
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        // Haut 
        for (int i = x-1; i >= 0 && plateau[i+1][y].piece[1] != 'b'; i--)
        {
            if ( (strcmp(plateau[i][y].piece,"00") == 0) || plateau[i][y].piece[1] == 'b' )
            {
                deplacement[j] = i;
                j++;
                deplacement[j] = y;
                j++;
            }else {break;}
        }
        // Gauche
        for (int i = y-1; i >= 0 && plateau[x][i+1].piece[1] != 'b'; i--)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'b' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
        }
    
        // Droite
        for (int i = y+1; i < 8 && plateau[x][i-1].piece[1] != 'b'; i++)
        {
            if ( (strcmp(plateau[x][i].piece,"00") == 0) || plateau[x][i].piece[1] == 'b' )
            {
                deplacement[j] = x;
                j++;
                deplacement[j] = i;
                j++;
            }else {break;}
            
        }
    }
    
    return j;
}
int pion( int y, int x, int *deplacement)
{
    int j = 0;

    //test si la piece est blanche ou noire
    if(plateau[y][x].piece[1] == 'b')
    {
        //avant 1 case
        if(y >= 0 && (strcmp(plateau[y-1][x].piece, "00") == 0))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x;
            j++;
        }
        //avant 2 cases
        if(y==6 && (strcmp(plateau[y-2][x].piece,"00") == 0))
        {
            deplacement[j] = y-2;
            j++;
            deplacement[j] = x;
            j++;
        }
        //diagonale bas droite
        if(plateau[y-1][x+1].piece[1] == 'n')
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //diagonale bas gauche
        if(plateau[y-1][x-1].piece[1] == 'n')
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
    }
    
    if(plateau[y][x].piece[1] == 'n')
    {
        //avant 1 case
        if((y+1) < 8 && (strcmp(plateau[y+1][x].piece,"00") == 0) )
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x;
            j++;
        }
        //avant 2 cases
        if(y==1 && (strcmp(plateau[y+2][x].piece, "00") == 0) )
        {
            deplacement[j] = y+2;
            j++;
            deplacement[j] = x;
            j++;
        }
        //diagonale haut droite
        if(plateau[y+1][x+1].piece[1] == 'b')
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //diagonale haut gauche
        if(plateau[y+1][x-1].piece[1] == 'b')
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
    }
    return j;
}
int cavalier( int y, int x, int *deplacement)
{
    int j = 0;
    
    
    //test si la piece est blanche ou noire
    if(plateau[y][x].piece[1] == 'b')
    {
        //droite
        if((y+1 < 8) && (x+2 < 8) && (strcmp(plateau[y+1][x+2].piece, "00") == 0 || plateau[y+1][x+2].piece[1] == 'n'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x+2;
            j++;
        }
        
        if((y-1 >= 0) && (x+2 < 8) && (strcmp(plateau[y-1][x+2].piece,"00") == 0 || plateau[y-1][x+2].piece[1] == 'n'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x+2;
            j++;
        }
        //arrière
        if((y+2 < 8) && (x+1 < 8) && (strcmp(plateau[y+2][x+1].piece, "00") == 0 || plateau[y+2][x+1].piece[1] == 'n') )
        {
            deplacement[j] = y+2;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        
        if((y+2 < 8) && (x-1 >= 0) && (strcmp(plateau[y+2][x-1].piece, "00") == 0 || plateau[y+2][x-1].piece[1] == 'n'))
        {
            deplacement[j] = y+2;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //avant
        if((y-2 >= 0) && (x+1 < 8) && (strcmp(plateau[y-2][x+1].piece, "00") == 0 || plateau[y-2][x+1].piece[1] == 'n'))
        {
            deplacement[j] = y-2;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        
        if((y-2 >= 0) && (x-1 >= 0) && (strcmp(plateau[y-2][x-1].piece, "00") == 0 || plateau[y-2][x-1].piece[1] == 'n'))
        {
            deplacement[j] = y-2;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //gauche
        if((y+1 < 8) && (x-2 >= 0) && (strcmp(plateau[y+1][x-2].piece,"00") == 0 || plateau[y+1][x-2].piece[1] == 'n'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x-2;
            j++;
        }
        
        if((y-1 >= 0) && (x-2 >= 0) && (strcmp(plateau[y-1][x-2].piece, "00") == 0 || plateau[y-1][x-2].piece[1] == 'n'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x-2;
            j++;
        }
        
    }
    if(plateau[y][x].piece[1] == 'n')
    {
        //droite
        if((y+1 < 8) && (x+2 < 8) && (strcmp(plateau[y+1][x+2].piece,"00") == 0 || plateau[y+1][x+2].piece[1] == 'b'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x+2;
            j++;
        }
        
        if((y-1 >= 0) && (x+2 < 8) && (strcmp(plateau[y-1][x+2].piece, "00") == 0 || plateau[y-1][x+2].piece[1] == 'b'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x+2;
            j++;
        }
        //avant
        if((y+2 < 8) && (x+1 < 8) && (strcmp(plateau[y+2][x+1].piece,"00") == 0 || plateau[y+2][x+1].piece[1] == 'b'))
        {
            deplacement[j] = y+2;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        
        if((y+2 < 8) && (x-1 >= 0) && (strcmp(plateau[y+2][x-1].piece, "00") == 0 || plateau[y+2][x-1].piece[1] == 'b'))
        {
            deplacement[j] = y+2;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //arrière
        if((y-2 >= 0) && (x+1 < 8) && (strcmp(plateau[y-2][x+1].piece,"00") == 0 || plateau[y-2][x+1].piece[1] == 'b'))
        {
            deplacement[j] = y-2;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        
        if((y-2 >= 0) && (x-1 >= 0) && (strcmp(plateau[y-2][x-1].piece,"00") == 0 || plateau[y-2][x-1].piece[1] == 'b'))
        {
            deplacement[j] = y-2;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //gauche
        if((y+1 < 8) && (x-2 >= 0) && (strcmp(plateau[y+1][x-2].piece, "00") == 0 || plateau[y+1][x-2].piece[1] == 'b'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x-2;
            j++;
        }
        
        if((y-1 >= 0) && (x-2 >= 0) && (strcmp(plateau[y-1][x-2].piece,"00") == 0 || plateau[y-1][x-2].piece[1] == 'b'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x-2;
            j++;
        }
    }
    return j;
}
int roi( int x, int y, int *deplacement)
{
    int j = 0;
    
    //test si la piece est blanche ou noire
    if(plateau[y][x].piece[1] == 'b')
    {
        //arriere droite
        if((x+1 < 8) && (y+1 < 8) && (strcmp(plateau[x+1][y+1].piece, "00") == 0 || plateau[x+1][y+1].piece[1] == 'n'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        // arriere
        if((x+1 < 8) && (y < 8) && (strcmp(plateau[x+1][y].piece,"00") == 0 || plateau[x+1][y].piece[1] == 'n'))
        {
            deplacement[j] = y;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //arriere gauche
        if((x+1 < 8) && (y-1 >= 0) && (strcmp(plateau[x+1][y-1].piece, "00") == 0 || plateau[x+1][y-1].piece[1] == 'n'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //gauche
        if((x < 8) && (y-1 >= 8) && (strcmp(plateau[x][y-1].piece, "00") == 0 || plateau[x][y-1].piece[1] == 'n'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x;
            j++;
        }
        //avant gauche
        if((x-1 >= 0) && (y-1 >= 0) && (strcmp(plateau[x-1][y-1].piece, "00") == 0 || plateau[x-1][y-1].piece[1] == 'n'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //avant
        if((x-1 >= 0) && (y < 8) && (strcmp(plateau[x-1][y].piece, "00") == 0 || plateau[x-1][y].piece[1] == 'n'))
        {
            deplacement[j] = y;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //avant droite
        if((x-1 >=0) && (y+1 < 8) && (strcmp(plateau[x-1][y+1].piece,"00") == 0 || plateau[x-1][y+1].piece[1] == 'n'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //droite
        if((x < 8) && (y+1 < 8) && (strcmp(plateau[x][y+1].piece, "00") == 0 || plateau[x][y+1].piece[1] == 'n'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x;
            j++;            
        }
        
    }

    if(plateau[y][x].piece[1] == 'n')
    {
        //arriere droite
        if((x+1 < 8) && (y+1 < 8) && (strcmp(plateau[x+1][y+1].piece, "00") == 0 || plateau[x+1][y+1].piece[1] == 'b'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        // arriere
        if((x+1 < 8) && (y < 8) && (strcmp(plateau[x+1][y].piece,"00") == 0 || plateau[x+1][y].piece[1] == 'b'))
        {
            deplacement[j] = y;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //arriere gauche
        if((x+1 < 8) && (y-1 >= 0) && (strcmp(plateau[x+1][y-1].piece, "00") == 0 || plateau[x+1][y-1].piece[1] == 'b'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x+1;
            j++;
        }
        //gauche
        if((x < 8) && (y-1 >=0) && (strcmp(plateau[x][y-1].piece, "00") == 0 || plateau[x][y-1].piece[1] == 'b'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x;
            j++;
        }
        //avant gauche
        if((x-1 >= 0) && (y-1 >=0) && (strcmp(plateau[x-1][y-1].piece, "00") == 0 || plateau[x-1][y-1].piece[1] == 'b'))
        {
            deplacement[j] = y-1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //avant
        if((x-1 >= 0) && (y < 8) && (strcmp(plateau[x-1][y].piece, "00") == 0 || plateau[x-1][y].piece[1] == 'b'))
        {
            deplacement[j] = y;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //avant droite
        if((x-1 >=0) && (y+1 < 8) && (strcmp(plateau[x-1][y+1].piece,"00") == 0 || plateau[x-1][y+1].piece[1] == 'b'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x-1;
            j++;
        }
        //droite
        if((x < 8) && (y+1 < 8) && (strcmp(plateau[x][y+1].piece, "00") == 0 || plateau[x][y+1].piece[1] == 'b'))
        {
            deplacement[j] = y+1;
            j++;
            deplacement[j] = x;
            j++;            
        }
        
    }
    return j;
}

int mvt(char *casedep, char *casearr)
{
    int j = 0;
    int *deplacement = (int*)malloc(20*sizeof(int));
    bool testpromo = false;
    printf("Donner le case de départ:");
    scanf("%s",casedep);
    printf("Où voulez-vous déplacer votre pièces?");
    scanf("%s",casearr);
    // utlisation d'une fonction qui verifie si la casse d'arrive et valide 
    switch(plateau[recup(casedep)[0]][recup(casedep)[1]].piece[0])
    {
        case 'r':
            j = roi(recup(casedep)[0],recup(casedep)[1],deplacement);
            break;
        case 'd':
            j = reine(recup(casedep)[0],recup(casedep)[1],deplacement);
            break;
        case 'p':
            j = pion(recup(casedep)[0],recup(casedep)[1],deplacement);
            testpromo = true;
            break;
        case 'c':
            j = cavalier(recup(casedep)[0],recup(casedep)[1],deplacement);
            break;
        case 't':
            j = tour(recup(casedep)[0],recup(casedep)[1],deplacement);
            break;
        case 'f':
            j = fou(recup(casedep)[0],recup(casedep)[1],deplacement);
            break;
        default:
            printf("Il n'y a pas de pièce sur cette case\n");

    }
    for ( int i = 0; i < j; i = i+2)
    {
        if(deplacement[i] == recup(casearr)[0] && deplacement[i+1] == recup(casearr)[1])
        {
            plateau[recup(casearr)[0]][recup(casearr)[1]].piece = plateau[recup(casedep)[0]][recup(casedep)[1]].piece;
            plateau[recup(casedep)[0]][recup(casedep)[1]].piece = "00";
            break;
        }
        else 
        {
            printf("la case n'est pas valide\n");
        }
    }
         // Promotion si possible
    if ( testpromo == true )
    {
        if ( plateau[recup(casearr)[0]][recup(casearr)[1]].piece[1] == 'n' )
        {
            if ( recup(casearr)[0] == 7 ) plateau[recup(casearr)[0]][recup(casearr)[1]].piece = "dn";
        }
        if ( plateau[recup(casearr)[0]][recup(casearr)[1]].piece[1] == 'b' ) 
        {
            if ( recup(casearr)[0] == 0 ) plateau[recup(casearr)[0]][recup(casearr)[1]].piece = "db";
        }
    }

    return 0;
}


int main (void) 
{
    char *casedep = (char*)malloc(4*sizeof(char));
    char *casearr = (char*)malloc(4*sizeof(char));
    reset_plateau();
    mvt(casedep, casearr);

    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            printf("%s", plateau[i][j].piece);
        }
        printf("\n");
        
    }
    printf("\n");
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            printf("%s", plateau[i][j].nom_case);
        }
        printf("\n");
    }

    return 0;
}

	


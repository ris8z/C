/*
Scrivere un Programma C che:

1) Prendere dalla lina di comando 9 interi e un carattere C.
Inserice gli interi in una matrice M di dim 3X3 allocata dinamicamente.

2)Implementa la funzione:

int* RimpiazzaMaggiori(int **M, char c); (non c'e' scritto che deve ritornare metto void, esericizio spiegato di merda)
-che calcola la media dei valori in M;

-e pone a uno tutte le posizioni in M il cui valore e' maggiore
della media e a 0 quelle, in cui il valore e' minore della media.

-Infine stampa a video una matrice di caratteri dove e' presente il carattere c se il
corrispondente valore in M  e' 1 e uno spazio altrimenti.

Input:
12 1 15 5 10 3 11 0 9
La matrice binaria e':
1 0 1
0 1 0
1 0 1
Inserisci un carattere: A
La matrice di caratteri e':
A   A
  A 
A   A
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define row 3
#define col 3

void RimpiazzaMaggiori(int **M, char c);

//conta che tento di farla il piu' perfect possibile tipo checkko tutti i return value ecc...
//tu quando lo fai sbattitene, poi se hai temmpo metti i check
int main(int argc, char **argv){
  int **matrix;
  int i;
  char c;

  if( argc < 11 )
    return 1;

  //allocation  
  matrix = malloc(row * sizeof(int*));
  if( matrix == NULL )
    return 2;

  for( i = 0; i < row; i++ ){
    matrix[i] = malloc(col * sizeof(int));
    if( matrix[i] == NULL )
      return 2;
  }

  //filling the matrix and the character
  for( i = 0; i < row * col; i++ )
  {
    matrix[i / col][i % col] = atoi(argv[1 + i]); 
  }

  if( strlen(argv[1 + i]) > 1 )
    return 3;
  c = argv[1 + i][0];

  //call the function  
  RimpiazzaMaggiori(matrix, c);


  //free the funcking memory
  for( i = 0; i < row; i++ )
  {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}

void RimpiazzaMaggiori(int **M, char c){
  int media = 0, i, j;

  for( i = 0; i < row * col; i++ ){
    media += M[i / col][i % col]; 
  }
  media = media / (row * col);

  for( i = 0; i < row * col; i++ ){
    if( M[i / col][i % col] > media ){
      M[i / col][i % col] = 1;
    }
    else{
      M[i / col][i % col] = 0;
    }   
  }
  
  //print the binary matrix
  printf("La matrice binaria e':\n");
  for( i = 0; i < row; i++ ){
    for( j = 0; j < col; j++ ){
      printf("%d", M[i][j]);
    }
    printf("\n");
  }

  //print the character matrix
  printf("La matrice di caratteri e':\n");
  for( i = 0; i < row; i++ ){
    for( j = 0; j < col; j++ ){
      if( M[i][j] == 1){
        putchar(c);
      }else{
        putchar(' ');
      }
    }
    printf("\n");
  }
}

/*
Scrivere un programma C che:
1) Prende da linea di comando due interi n e m, e n*m intersi successivi.
Alloca una matrice di interi M di dimensioni nxm e la inizializza con gli
interi letti in input

2) Implementa la funzione
mini_max_pari_dispari(int **M, int n, int m, int *row, int *col)
che individua la riga la cui somma degli elementi sia minima
e la colonna la cui somma degli elementi sia massima


input:
    3 4 12 33 22 11 3 67 1 23 76 34 12 1
output:
    La riga con somma minima e': 0
    La colonna con somma massima e': 1
*/

#include <stdio.h>
#include <stdlib.h>

void mini_max_pari_dispari(int **M, int n, int m, int *row, int *col);

int main(int argc, char **argv){
  if( argc < 3)
    return 1;

  int row = atoi(argv[1]);
  int col = atoi(argv[2]);
  int **matrix = NULL;
  int result_row = 0;
  int result_col = 0;
  int i;

  //allocation
  matrix = malloc(col * sizeof(int*));
  if( matrix == NULL )
    return 2;
  
  for(i = 0; i < row; i++){
    matrix[i] = malloc(col * sizeof(int));
    if( matrix[i] == NULL )
      return 2; 
  }
  //filling up the matrix
  for(i = 0; i < row * col; i++){
    matrix[i / col][i % col] = atoi(argv[3 + i]);
  }
  
  //NOTA CHE: stampare la matrice per capire se e' tutto OK e' un MUST
  //ma se devi scrivere a carta e penna a poco serve

  mini_max_pari_dispari(matrix, row, col, &result_row, &result_col);
  printf("La riga con somma minima e': %d\n", result_row);
  printf("La colonna con somma massima e': %d\n", result_col);

  //free the fucking memory
  for(i = 0; i < row; i++)
    free(matrix[i]);
  free(matrix);
}


void mini_max_pari_dispari(int **M, int n, int m, int *row, int *col){
  int i, j;
  int min_row_sum = 1000000000;
  int max_col_sum = -1000000000;
  int sum;

  for(i = 0; i < n; i++){
    sum = 0;
    for(j = 0; j < m; j++)
      sum += M[i][j];

    if(sum < min_row_sum){
      min_row_sum = sum;
      *row = i;
    }
  }

  for(j = 0; j < m; j++){
    sum = 0;
    for(i = 0; i < n; i++)
      sum += M[i][j];

    if(sum > max_col_sum){
      max_col_sum = sum;
      *col = j;
    }
  }
}
#include<stdio.h>

//massimo numero di righe e colonne che il programma puo supportare
#define row 30
#define col 30

int main(){
    int mat[row][col];
    int i,j;
    int R, C; //numero di righe colonne e correnti della matrice

    printf("Quante righe ovvero row   ?:");
    scanf("%d", &R);

    printf("Quante colonne ovvero col ?:");
    scanf("%d", &C);


    printf("Inserire Valori della Matrice:\n");

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("\nInserire valore in posizione riga %d, colonna %d --> ", i, j);
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

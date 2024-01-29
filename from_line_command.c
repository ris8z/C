#include<stdio.h>
#include<stdlib.h>

//massimo numero di righe e colonne che il programma puo supportare
#define row 30
#define col 30

int main(int argc, char **argv){
   
    int mat[row][col];
    int R = atoi(argv[1]);
    int C = atoi(argv[2]);
    int i,j;
    

    //modo che mi piace di piu'
    for(i = 0; i < argc - 3; i++){
        mat[i / C][i % C] = atoi(argv[i + 3]);
    }

    //modo che mi piace di meno
    /*for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%s", argv[i * C + j + 3]);
            non devi fa printf ma
            mat[i][j] = atoi(argv[i * C + j + 3]);
        }
    }*/

    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include<stdio.h>

#define row 3
#define col 3

int main(){
    int mat[row][col] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };
    int i,j;

    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

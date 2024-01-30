#include<stdio.h>

int main(){

    int a[5] = {12, 4, 5, 69, 76};

    int target = 69;
    int i;
    int N = 5;


    i = 0;
    while(i < N && a[i] != target){
        i++;
    }

    if(i < N){
    //trovato
        printf("Trovato in posizione: %d, con valore: %d\n", i, a[i]);
    }else{
    //non trovato
        printf("Non trovato unlucky\n");
    }


    return 0;
}

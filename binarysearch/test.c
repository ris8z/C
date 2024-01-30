#include<stdio.h>

//funziona solo se l'arry e' ordinato
int bs(int array[50], int N, int target);
int bs2(int array[50], int N, int target);

int main(){

    int vett[50] = {1, 5, 7, 12, 56, 78, 89};

    printf("%d\n", bs(vett, 7, 12));// 3
    printf("%d\n", bs(vett, 7, 56));// 4

    printf("%d\n", bs2(vett, 7, 56));// 4
    printf("%d\n", bs2(vett, 7, 89));// 6
    printf("%d\n", bs2(vett, 7, 5));// 1
    return 0;
}

int bs(int array[50], int N, int target){

    int L = 0; // sinstra pointer
    int R = N - 1; // destra pointer
    int guess;

    while(L <= R){
        guess = (L + R) / 2;

        if(array[guess] == target){
            return guess;
        }else if(array[guess] < target){
            L = guess + 1;
        }else{
        //ovvere array[guess] > target
            R = guess - 1;
        }
    }

    return -1;
}

int bs2(int array[50], int N, int target){

    int L = 0; // sinstra pointer
    int R = N - 1; // destra pointer
    int guess;

    while(L < R){
        guess = (L + R) / 2;

        if(array[guess] < target){
            L = guess + 1;
        }else{
            R = guess;
        }
    }


    if(array[L] == target){
        return L;
    }

    return -1;
}

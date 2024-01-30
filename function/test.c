#include<stdio.h>
//implementiamo un paio di semplici funzioni
int sum(int a, int b);

//ci restituisce la posizione del nostro target se lo trova oppure -1
int linearSearch(int vett[50],int N, int target);

int main(){
//------------------------------->sum
    int x = 1;
    int y = 5;
    int c = sum(x, y);

    printf("%d + %d = %d\n", x, y , c);

//------------------------------->liner search
    int array[50] = {1, 2, 3, 4, 5, 6, -123, 699, 89, 111};
    //7
    printf("%d\n", linearSearch(array, 10, 69));// expected output -1
    printf("%d\n", linearSearch(array, 10, 699));;// expected output 7

    return 0;
}

int sum(int a, int b){
    return a + b;
}

int linearSearch(int vett[50],int N, int target){
    int i = 0;

    while(i < N && vett[i] != target){
        i++;
    }

    if(i < N){
        return i;
    }

    return -1;
}

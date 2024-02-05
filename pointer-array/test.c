#include<stdio.h>

void printarray(int vet[], int N);

void newstyle(int *address, int N);


int main(){

    int vett[5] = {1,2,3,4,5};

    printarray(vett, 5);
    newstyle(vett, 5);
    newstyle(&vett[0], 5);

    int *p = &vett[0];

    newstyle(p, 5);

    return 0;
}

void printarray(int vet[], int N){
    for(int i = 0; i < N; i++)
        printf("%d ", vet[i]);
    printf("\n");

}
//address = address of the first CELLA of the array
void newstyle(int *address, int N){
    for(int i = 0; i < N; i++)
        printf("%d ", *(address + i));
    printf("\n");
}

#include<stdio.h>

//fai uno funzione void che trova il minino di un array la funzione deve essere di questo tipo
//void (int *array, int *dim, int *ris);

void findmin(int *array, int *dim, int *ris);

int main(){
    int ris = 1000000000;
    int array[5] = {23,1,3,565,69};
    int dim = 5;

    findmin(array, &dim, &ris);

    printf("Il minimo e' : %d\n", ris);
}
//v[i] e' congruo a *(v + i)
void findmin(int *array, int *dim, int *ris){
    for(int i = 0; i < *dim; i++){
        if(*(array + i) < *ris){
            *ris = array[i];
        }
    }
}

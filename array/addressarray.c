#include<stdio.h>

int main(){
    int v[150];
    int tmp;
    int N;

    int *p1 = NULL;
    int *p2 = NULL;

    p1 = &v[0];
    p2 = &v[1];
    printf("size of int %ld \n", sizeof(int));
    printf("Address of v[0] : %zu \n", v);
    //printf("Address of v[1] : %zu \n", p2);
}

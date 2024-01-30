#include<stdio.h>

int main(){
    int v[150];
    int tmp;
    int N;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%d", &tmp);
        v[i] = tmp;
    }

    for(int i = 0; i < N; i++){
        printf("%d  ", v[i]);
    }
    printf("\n");

}

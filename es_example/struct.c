#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct c C;

struct c{
    char name[20];
    char capital[20];
    float population;
    int size;
};


//./a.out irlanda dublino 3 4 italia roma 5 89
int main(int argc, char **argv){

    int N = (argc - 1) / 4;
    int index;
    C arr[50];

    for(int i = 0; i < N; i++){
        index = 1 + (i * 4);

        strcpy(arr[i].name, argv[index]);
        strcpy(arr[i].capital, argv[index + 1]);
        arr[i].population = atof(argv[index + 2]);
        arr[i].size = atoi(argv[index + 3]);
    }


    for(int i = 0; i < N; i++){
        printf("%s %s %.2f %d\n", arr[i].name, arr[i].capital, arr[i].population, arr[i].size);
    }

    // (P + i)->nomevar

    return 0;
}

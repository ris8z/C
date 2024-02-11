#include<stdio.h>
#include<string.h>
/*
conservare dei dati su dei cantanti di sanremo con un (array);

*/


typedef struct cantante singer;

struct cantante{
    char name[50];
    int age;
};

/*
typedef struct diocane{
    int age;
}cane;
*/

int main(int argc, char **argv){

    singer C1;

    singer cantantiSanremo[3];

    strcpy(C1.name, "annalisa");
    C1.age = 38;

    printf("C1.name = %s, C1.age = %d\n", C1.name, C1.age);


    for(int i = 0; i < 3; i++){
        scanf("%s", cantantiSanremo[i].name);
        scanf(" %d", &cantantiSanremo[i].age);
    }

    for(int i = 0; i < 3; i++){
        printf("pos %d, name = %s, age = %d\n", i + 1, cantantiSanremo[i].name, cantantiSanremo[i].age);
    }

    return 0;
}

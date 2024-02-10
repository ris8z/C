#include<stdio.h>

int main(int argc, char **argv){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};

    printf("arr  = %zu \n", (long)arr);
    printf("&arr = %zu \n", (long)&arr);

    printf("sizeof(int) %ld \n", sizeof(int));


    printf("arr + 1  = %zu \n", (long)(arr + 1));
    printf("&arr + 1 = %zu \n", (long)(&arr + 1));


    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    
    printf("mat  = %zu \n", (long)mat); //sarebbe l'address di {1,2,3}
    printf("*mat = %zu \n", (long)*mat); //sarebbe l'address di dove sta 1

    printf("mat + 1  = %zu \n", (long)(mat + 1)); //sarebbe l'address di {1,2,3} + 1 quindi {4,5,6}
    printf("*mat + 1 = %zu , value: %d\n", (long)(*mat + 1), *(*mat + 1)); //sarebbe l'address di dove sta 1 + 1 quindi di 2
    printf("Value: %d\n", **(mat + 1));

    int (*p)[3] = mat;
    
    printf("Value [0][0] = %d\n", **p);


    char *string = "mario";

    char *pm = string;

    while(*pm != '\0'){
        printf("%c\n", *pm);
        pm++;
    }
    return 0;
}

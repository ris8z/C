#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){
    int mat1[50][50];
    int r1, c1;

    int mat2[50][50];
    int r2, c2;


    r1 = atoi(argv[1]);
    c1 = atoi(argv[2]);

    printf("%s == 3\n", *(argv + 3 + (r1 * c1)));

    char **p = argv + 3 + (r1 * c1);
    r2 = atoi(*p);
    p++;
    c2 = atoi(*p);
    p++;



    printf("%d %d \n", r2 , c2);

    while(*p){
        printf("%s\n", *p);
        p++;
    };


    return 0;
}

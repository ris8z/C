#include<stdio.h>
#include<string.h>


int main(int argc, char **argv){

    char *string = argv[1];
    char *key = argv[2];

    int Nstring = strlen(string);
    int Nkey = strlen(key);

    int i,j;


    i = 0;
    j = 0;
    while( i < Nstring ){
        if(string[i] == key[j]){
            j++;
            if(j == Nkey){
                break;
            }
        }else{
            if(j > 0){
                i--;
            }
            j = 0;
        }
        i++;
    };


    printf("%d\n", i - j + 1);

    
    return 0;
}

#include<stdio.h>

int main(){

    char name[100];
    char cognome[100];
    char nazionalita[100];


    printf("Inserire il tuo nome plis : ");
    scanf("%s", name);

    printf("Inserire il tuo cognome plis : ");
    scanf("%s", cognome);


    printf("Inserire la tua nazionalita plis : ");
    scanf("%s", nazionalita);


    printf("Il tuo nome e' %s, cognome: %s e sei %s\n", name, cognome, nazionalita);

    char c1 = 'p';
    char c2 = 'p';

    if(c1 == c2){
        printf("prodco de diooooo\n");
    }

    return 0;
}

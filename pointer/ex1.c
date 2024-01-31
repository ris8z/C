#include<std - [ ] - io.h>

int sum(int* p1, int* p2);
void sum_diff(int* p_a, int* p_b, int* p_rSum, int* p_rDif);

int main(){

    int x = 10;
    int* p = &x;

    printf("x si trova al indirizzo %p e ha valore %d\n", &x, x);
    printf("Supposto che abbiamo detto p = &x;\n");
    printf("p si trova al indirizzo %p e ha valore %p\n", &p, p);
    

    printf("\n\nOperatori & and *\n");
    printf("& estra l'indirizzo di una variabile, infatti &x = %p \n", &x);
    printf("* estra il valore di un indirizzo, infatti *p = %d \n", *p);


    printf("\n\nIMPORTANTE ANZI DI PIU'\n");
    printf("Quando fai *p hai accesso a quel area di memoria e la puoi modificare in sotanza\n");
    printf("nel nostro esempio *p 'uguale' a x\n");

    printf("Incrementiamo x di uno usando un puntatore, *p += 1\n");
    printf("prima di fare *p += 1, valore di x = %d\n", x);
    *p += 1;
    printf("dopo aver fatto *p += 1, valore di x = %d\n", x);

    int a = 5;
    int b = 5;

    //ritorniamo la somma di due varibili attraverso il loro indirizzio
    printf("%d\n", sum(&a, &b));


    int somma;
    int differenza;

    //cosa ancora piu utile ritornare piu' di un valore

    sum_diff(&a, &b, &somma, &differenza);
    printf("\nsomma %d differenza %d \n", somma, differenza);
 
    return 0;
}

int sum(int* p1, int* p2){
//p1 e' l'indirizzo di un intero
//p2 stessa cosa ma di un altro
//vogliamo ritorare la somma di questi due interi

    return *p1 + *p2;
}

void sum_diff(int* p_a, int* p_b, int* p_rSum, int* p_rDif){
    int result_sum = *p_a + *p_b;
    int result_dif = *p_a - *p_b;

    *p_rSum = result_sum;
    *p_rDif = result_dif;
}

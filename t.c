#include <stdio.h>
#include <stdlib.h>

int i = 0;

typedef struct digit Digit;
struct digit {
    int n;
    int *d; //i assume che questo sia il vettore per storare i numeri del binario
};

Digit* createBinary();
void Det2Dig(int val, Digit *dval);
void freeAll(Digit* dv);

int main(int argc, char** argv)
{
    int value = atoi(argv[1]);
    Digit* mydig = createBinary(value);
    Det2Dig(value, mydig);
    freeAll(mydig);
    return 0;
}

Digit* createBinary(int val)
{
    while(val != 0)//singifaca [(val % 2 != 0) oppure (val / 2 != 0)] l'unica volta in cui questo e'
                                          //possible e' quando val e' zero ergo puoi scrivere val != 0
    {   
        i++;
        val = val / 2;
    }
    Digit* dval = malloc(sizeof(Digit));
    dval -> d = malloc(sizeof(int) * i);
    return dval; 
}

void Det2Dig(int val, Digit *dval)
{
    //sto while serve per contare quante cifre mi servono per allocare la mem
    int j = i - 1;
  
    int tmp = val;
    while(j >= 0)
    {
        dval -> d[j] = tmp % 2; 
        //printf("%d ", dval -> d[j]);
        tmp = tmp / 2;
        j--;
    }   
    
    //printf("%d\n", i);
    printf("La conversione in binario di %d è: ", val);
    for(int k = 0; k < i; k++)
        printf("%d ", dval -> d[k]);

}

void freeAll(Digit* dv)
{
    free(dv -> d);
}
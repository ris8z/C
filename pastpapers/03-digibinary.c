/*
Scrivere un programma C che:
1) Definisce un tipo digit come un record due campi int n e int *d
2) Prendere un intro val da linea di comando
3) Implementa la funzione

void Det2Dig(int val, digit *dval) che:
-calcola il numero di bit n necessari a rappresentare val in binario;
-alloca d come vettore di n interi;
-pone in d i bit della rapresentazione binaria di val

input
    57
output
La rappresentazione binaria di 57 e': 0111001
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct digit digit;

struct digit{
  int n;
  int *d;
};

void Det2Dig(int val, digit *dval);

int main(int argc, char **argv){
  if( argc < 2)
    return 1;
  int val;

  val = atoi(argv[1]);
  digit dval;

  Det2Dig(val, &dval);
  
  printf("La rappresentazione binaria di %d e': ", val);
  for(int i = 0; i < dval.n; i++)
    printf("%d",(dval.d)[i]);
  printf("\n");

  //free la cazzo di memoria ti vedo che non lo fai!
  free(dval.d);

  return 0;  
}

void Det2Dig(int value, digit *dval){
  int tmp, i;
  int dim = 0;  

  //get the value of n
  tmp = value;
  while(tmp != 0){
    dim += 1;
    tmp = tmp / 2;
  }

  //allocation
  dval -> n = dim;
  dval -> d = malloc(dim * sizeof(int));
  if( dval -> d == NULL )
    exit(0);

  //filling the array up dval -> d (t'ho detto che il cambio in binaro e' importante esce sempre cazzo SEMRPE)
  tmp = value;
  i = 0;
  while(tmp != 0){
    (dval -> d)[dim - 1 - i] = tmp % 2;
    tmp = tmp / 2;
    i++;
  }
}


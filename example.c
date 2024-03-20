#include<stdio.h>
#include<stdlib.h>

int* myFirstVarInTheHeap(int a)
{
  int *result;
  result = malloc(sizeof(int) * 1);//chiedo al signore sistema operativo lo tengo lo spazio per un intero
  
  if( result == NULL)
  {
    //il signore oprativo mi risponde che non lo tengo allo esco
    exit(0);
  }
  
  //lo spazio lo tengo e quindi ci metto il cazzo che voglio dentro in questo caso a
  *result = a;

  //ritorno l'indirizzo di dove ho messo a
  return result;
}

int main()
{

  int *p = myFirstVarInTheHeap(1);

  printf("%d\n", *p);

  free(p);


  return 0;
}
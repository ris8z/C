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


  free(p);



  int matrix[3][4] ={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
  };

  int C = 4;
  int R = 3;
  int maxsum = -10000000;
  int sum;

  for(int i = 0; i < R; i++){
    sum = 0;
    for(int j = 0; j < C; j++){
        printf("%d ", matrix[i][j]);
        sum += matrix[i][j];
    }
    printf("somma riga %d = %d\n", i, sum);
    if( maxsum < sum){
      maxsum = sum;
    }
  }
  printf("Riga piu grossa %d\n", maxsum);


  int minsum = 100000000;

  for(int i = 0; i < C; i++){
    sum = 0;
    for(int j = 0; j < R; j++){
        printf("%d ", matrix[j][i]);
        sum += matrix[j][i];
    }
    printf("somma colnna %d = %d\n", i, sum);
    if( minsum > sum){
      minsum = sum;
    }
  }
  printf("Riga piu piccola %d\n", minsum);

  return 0;
}
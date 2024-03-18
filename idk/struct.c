#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//./a.out Germaina berlino 3.8 Italia roma 3.4

/*
argc = 7
argv = {
  "./a.out",   0
  "Germaina",  1
  "berlino",   2
  "3.8",       3
  "italia",    4
  "roma",      5
  "3.4",       6
}

vogliamo pirnatre un paese per lina 
Germaina beriono 3.8
italia roma 3.4
*/

typedef struct Nazione{
  char name[30];
  char capital[30];
  int pop;
}nation;

int main(int argc, char **argv){

  nation arr_n[10];

  int N = (argc - 1) / 3;

  for(int i = 0; i < N; i++)
  {
    strcpy(arr_n[i].name,argv[1 + i*3]);
    strcpy(arr_n[i].capital,argv[1 + i*3 + 1]);
    arr_n[i].pop = atoi(argv[1 + i*3 + 1 + 1]);
  }

  for(int i = 0; i < N; i++)
  {
    printf("%s ", arr_n[i].name);
    printf("%s ", arr_n[i].capital);
    printf("%d \n", arr_n[i].pop);
  }

  return 0;  
}
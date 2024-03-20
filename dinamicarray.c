#include<stdio.h>
#include<stdlib.h>

int *p;//questa e' una variabile globale singifica che sta nel heap e tutte le funzioni la possono usare
int max_dim = 5;
int current_dim = 0;


void startAllocation();
void append(int a);
//int pop();//ritorna l'ultimo elmento della list(e lo leva dalla lista)
void freeArray();
void printarray();

int main()
{
  startAllocation();
  append(1);
  append(2);
  printarray();
  append(3);
  append(4);
  append(5);
  append(6);
  printarray();
  freeArray();
  return 0;
}

void startAllocation()
{
  p = malloc(sizeof(int) * 5);

  if( p == NULL )
    exit(0);

}

void append(int a)
{
  if( current_dim < max_dim)
  {
    p[current_dim] = a;
    current_dim += 1;
    return;
  }

  int *tmp = realloc(p, sizeof(int) * (max_dim + 1));

  if( tmp == NULL )
    exit(0);

  if( tmp != p)
    p = tmp;

  p[current_dim] = a;
  current_dim += 1;
}

void printarray()
{
  for(int i = 0; i < current_dim; i++)
  {
    printf("%d ", p[i]);
  }
    printf("\n");
}

void freeArray(){
  free(p);
}
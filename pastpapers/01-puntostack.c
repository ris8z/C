/*
Scrivere un programma C che :
1)Definisce un Punto come un record con i campi float x e y

2)Implementa uno stack con capacita' limitata di 10 punti, con le funzioni
void Push(Stack *s, Punto P)
Punto Pop(Stack* s)

3)Inserice in sequenza nello stack i punti
P1(12,3), P2(14,4), P3(7, 9).

Successivamente estrae un punto alla volta dallo stack e stampa
le cordinate del punto estratto
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct Punto Punto;
typedef struct Node Node;
typedef struct Stack Stack;

struct Punto{
  float x;
  float y;
};

struct Node{
  Punto point;
  Node *next;
};

struct Stack{
  int dim;
  Node* head;
};

void Push(Stack *s, Punto p);
Punto Pop(Stack* s);

int main(int argc, char **argv){
  Punto p1; p1.x = 12; p1.y = 3;
  Punto p2; p2.x = 14; p2.y = 4;
  Punto p3; p3.x = 7; p3.y = 9;
  Punto tmp;

  Stack myStack;
  myStack.dim = 0;
  myStack.head = NULL;

  Push(&myStack, p1);
  Push(&myStack, p2);
  Push(&myStack, p3);
  for(int i = 0; i < 3; i++){
    tmp = Pop(&myStack);
    printf("(%.2f, %.2f)\n", tmp.x, tmp.y);
  }

  return 0;
}

void Push(Stack *s, Punto p){
  if( s -> dim >= 10)
    return;

  s -> dim += 1;
  Node *tmp = malloc(sizeof(Node));
  if( tmp == NULL )
    exit(0);
  tmp -> point = p;
  tmp -> next = s -> head;
  s -> head = tmp;
}

Punto Pop(Stack* s){
  if( s -> dim == 0 )
    exit(0);
  
  Node* target = s -> head;
  Punto result = s -> head -> point;
  s -> head = s -> head -> next;
  free(target);
  return result;
}
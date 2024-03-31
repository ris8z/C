/*
Scrivere un programma C che:

1) Definisce una struttura Stack implmentata con una lista singolarmente
concatenata, in cui ciscun nodo contiene un valore intero e il punatore al
nodo successivo

2) Prende in input dlla linea di comando un valore int n

3) implemente la funzione
Stack *crea_stack_fibonacci(int n)
-che prende in input un valore intero n e restituisce
uno stack in cui sono inseriti i primi n numeri di fibonacci

4)Stampa il contentuto dello stack nella funzione main
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Stack Stack;

struct Node{
  int val;
  Node* next;
};

struct Stack{
  Node* head;
  int dim;
};

Stack* create_stack();
Node* push_element(Stack *s, int value);
// Node* pop_element(Stack *s);
void display(Node* head);
Stack *crea_stack_fibonacci(int n);
void FreeStack(Node* head);

int main(int argc, char **argv){
  if( argc < 2)
    return 1;
  
  int n = atoi(argv[1]);

  Stack* myFiboStack = crea_stack_fibonacci(n);
  printf("Il contenuto dello stack e':");
  display(myFiboStack -> head);
  printf("\n");
  FreeStack(myFiboStack -> head);
  free(myFiboStack);

  return 0;
}

Stack* create_stack(){
  Stack* s = malloc(sizeof(Stack));
  if( s == NULL )
    exit(0);
  s -> head = NULL;
  s -> dim = 0;
  return s;
}

Node* push_element(Stack *s, int value){
  Node* newElement = malloc(sizeof(Node));
  if( newElement == NULL )
    exit(0);
  
  newElement -> val = value;
  newElement -> next = s -> head;
  s -> head = newElement;
  s -> dim += 1;

  return newElement;
}

// Node* pop_element(Stack *s){
//   if( s -> dim < 1)
//     return NULL;
  
//   Node* target_element = s -> head;
//   s -> head = s -> head -> next;
//   s -> dim -= 1;

//   return target_element;
// }

void display(Node* head){
  if( head == NULL ){
    return;
  } 
  display(head -> next);
  printf("%d ", head -> val);
}


//1 1 2 3 5 8 ...
Stack *crea_stack_fibonacci(int n){
  Stack *result = create_stack();
  int prec = 1;
  int curr = 1;
  int i = 0;

  while( i < n){
    push_element(result, prec);
    curr = prec + curr;
    prec = curr - prec;
    i += 1;
  }

  return result;
}

void FreeStack(Node* head){
  if( head == NULL ){
    return;
  }
  FreeStack(head -> next);
  free(head);
}
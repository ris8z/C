/*
Scrivere un programma C che:

1) Definisce una lista doppiamente concatenate
Lista_DL, i cui nodi contengone un campo dato di tipo intero

2) Implementa la funzione
void Ordina_Lista(Lista_DL L), che ordina la lista L
mediante l'algoritom bubble sort applicato alla lista.

4) Implementa la funzione main, che prende un elenco di numeri interi
da linea di comando, li inserisce in una lista di tipo Lista_DL e poi ordina
la lista con la funzione Ordina_Lista. Inoltre stampa la lista prima e dopo
l'ordinamento.

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Lista_DL Lista_DL;

struct Node{
  int val;
  Node* next;
  Node* prec;
};

struct Lista_DL{
  Node* head;
  Node* tail;
};

Lista_DL* createList();
Node* createNode(int value);
Node* addNode(Node* head, Node* new);
void pushValueToList(Lista_DL* L, int value);
void swapTwoNode(Lista_DL* L, Node* i, Node* j);
void Ordina_Lista(Lista_DL* L);

void display(Node* head);

int main(int argc, char **argv){
  Lista_DL* myList = createList();
  
  for(int i = 0; i < argc - 1; i++){
    pushValueToList(myList, atoi(argv[1 + i]));
  }
  display(myList -> head);
  
  Ordina_Lista(myList);
  display(myList -> head);

  return 0;
}

Lista_DL* createList(){
  Lista_DL* result = malloc(sizeof(Lista_DL));
  result -> head = NULL;
  result -> tail = NULL;
  return result;
}

Node* createNode(int value){
  Node* n = malloc(sizeof(Node));
  n -> val = value;
  n -> next = NULL;
  n -> prec = NULL;
  return n;
}

Node* addNode(Node* head, Node* new){
  if( head == NULL ){
    return new;
  }

  head -> next = addNode(head -> next, new);
  head -> next -> prec = head;

  return head;
}

void pushValueToList(Lista_DL* L, int value){
  Node* new_entry = createNode(value);
  L -> head = addNode(L -> head, new_entry);
  L -> tail = new_entry;
}

void display(Node* head){
  if( head == NULL ){
    printf("NULL\n");
    return;
  }
  printf("(%d)->", head -> val);
  display(head -> next);
}

void swapTwoNode(Lista_DL* L, Node* i, Node* j){
  // x <- i <- j <- y
  // x -> i -> j -> y
  // we want this order
  // x -> j -> i -> y
  // x <- j <- i <- y
  Node* x = i -> prec;
  Node* y = j -> next;

  if( x != NULL ){
    x -> next = j;
  }else{
    //if x is null, i -> prec is null therefore i it's the head of the  list
    L -> head = j;
  }

  if( y != NULL ){
    y -> prec = i;
  }else{
    L -> tail = i;
  }

  i -> next = y;
  i -> prec = j;

  j -> next = i;
  j -> prec = x;

}

void Ordina_Lista(Lista_DL* L){
  if( L -> head == NULL )
    return;
  
  Node* curr = NULL;
  Node* leftPointer = NULL;//this point to the part of the list already sorted
  int flag;//check if the list is not sorted, 1 means that is not sorted bc there was a swap

  do{
    curr = L -> head;
    flag = 0;
    while(curr -> next != leftPointer)
    {
      if( (curr -> val) > (curr -> next -> val) )
      {
        swapTwoNode(L, curr, curr -> next);
        flag = 1;
      }else{
        curr = curr -> next;
      }
    }
    leftPointer = curr;
  }while(flag);

}
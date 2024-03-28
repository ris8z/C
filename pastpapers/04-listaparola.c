/*
Scrivere un programma C che:
1) Prende in input dalla linea di comando una parola
2) definisce un nodo Carattere come record che contine un
carattere e un punatore al nodo successivo
3) implmenta la funzione
Intero *crea_lista(char parola[]) (penso che qua il tipo e' sbagliato)
che prende in input una parola e
restituisce il puntatore alla testa di una lista 
di caratteri

input
  imprescindibile
output
  La lista e':i->m->p->r->e->s->c->i->n->d->i->b->i->l->e->NULL
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carattere Carattere;

struct Carattere{
  char c;
  Carattere *next;
};

//DISCLAIMER le funzione che servono sono solo crea_lista, add_element, display
//ma le ho implmentate si con ricursione che senza per fare vedere la differenza e soprattuto
//quanto e' chill implmentare le liste con la recursion.
Carattere* crea_lista(char parola[]);
Carattere* add_element(Carattere* head, Carattere* New);
Carattere* add_element_iter(Carattere* head, Carattere* New);
void display(Carattere* head);
void display_iter(Carattere* head);
void freeList(Carattere* head);
void freeList_iter(Carattere* head);

int main(int argc, char **argv){
  if( argc < 2)
    return 1;
  //get input and fill the list <----------------
  char *parola = argv[1];
  Carattere *mylist = crea_lista(parola);

  //print the list  <----------------
  printf("La lista e':");
  display(mylist);
  //display_iter(mylist);

  //free the fucking memory <----------------
  freeList(mylist);
  //freeList_iter(mylist);

  return 0;
}

Carattere* crea_lista(char parola[]){
  Carattere* head = NULL;

  for(int i = 0; i < strlen(parola); i++){
    Carattere* new = malloc(sizeof(Carattere));
    new -> c = parola[i];
    new -> next = NULL;
    head = add_element(head, new);
    //head = add_element_iter(head, new);
  }

  return head;
}



//nota quanto e' piu small la funzione ricorsiva in queto caso
Carattere* add_element(Carattere* head, Carattere* New){
  if( head == NULL )
    return New;
  
  head -> next = add_element(head -> next, New);
  
  return head;
}

Carattere* add_element_iter(Carattere* head, Carattere* New){
  if( head == NULL )
    return New;
  
  Carattere* curr = head;
  while( curr -> next != NULL )
  {
    curr = curr -> next;
  }
  curr -> next = New;

  return head;
}



//qui ricorsiva e iterativa so praticamente uguali
void display(Carattere* head){
  if( head == NULL){
    printf("NULL\n");
    return;
  }
  printf("%c->", head -> c);
  display(head -> next);
}

void display_iter(Carattere* head){
  while( head != NULL ){
    printf("%c->", head -> c);
    head = head -> next;
  }
  printf("NULL\n");
}



//qui ricorsiva e iterativa so praticamente uguali
void freeList(Carattere* head){
  if( head == NULL )
    return;
  Carattere* linkNext = head->next;
  free(head);
  freeList(linkNext);
}

void freeList_iter(Carattere* head){
  while( head != NULL ){
    Carattere* link = head->next;
    free(head);
    head = link;
  }
}
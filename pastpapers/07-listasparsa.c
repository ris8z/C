#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elemento Elemento;

//questo e' l'antenato della classa
struct Elemento{
  char c;
  int pos;
  Elemento* next;
};

Elemento* add_element(Elemento* head, Elemento* new);
Elemento* add_element_rec(Elemento* head, Elemento* new);
Elemento* crea_elemento(char c, int pos);
void display(Elemento* head);
void freeList(Elemento* head);
Elemento* creat_vettore_sparso(char string[], int len);

int main(int argc, char **argv){

  Elemento* head = creat_vettore_sparso("indissolubilmente", strlen("indissolubilmente"));
  display(head);

  return 0;
}

Elemento* add_element_rec(Elemento* head, Elemento* new){
  if( head == NULL)
    return new;

  head -> next = add_element_rec(head->next, new);
  return head;
}

Elemento* add_element(Elemento* head, Elemento* new){
  if( head == NULL ){
    return new;
  }

  Elemento* curr = head;
  while( curr -> next != NULL ){
    curr = curr -> next;
  }

  curr -> next = new;

  return head;
}


//questa e' l'antenato del init
Elemento* crea_elemento(char c, int pos){
  Elemento* result = malloc(1*sizeof(Elemento));
  result -> c = c;
  result -> pos = pos;
  result -> next = NULL;
  return result;
}


void display(Elemento* head){
  if(head != NULL){
    printf("(%c %d)\n", head->c, head->pos);
    display(head -> next);
  }
}

void freeList(Elemento* head){
  Elemento* linkNext;

  while(head != NULL){
    linkNext = head -> next;
    free(head);
    head = linkNext;
  }
}


Elemento* creat_vettore_sparso(char string[], int len){
  Elemento* result = NULL;
  int bool_vocale;
  char c;

  for(int i = 0; i < len; i++){
    c = string[i];
    bool_vocale = (c == 'a' ||  c == 'e' || c == 'i' || c == 'o' || c == 'u');
    if(bool_vocale){
      result = add_element(result, crea_elemento(c, i));
    }
  }
  return result;
}
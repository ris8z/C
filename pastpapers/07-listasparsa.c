#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Elemento Elemento;

//questo e' l'antenato della classe
struct Elemento{
  char c;
  int pos;
  Elemento* next;
};



//ho commetato tutto quello che non serve, le uniche funzioni che devi impara so le prime 3
Elemento* crea_elemento(char c, int pos);
Elemento* add_element(Elemento* head, Elemento* new);
void display(Elemento* head);
Elemento* creat_vettore_sparso(char string[], int len);
//Elemento* add_element_rec(Elemento* head, Elemento* new);
//void freeList(Elemento* head);


int main(int argc, char **argv){
  if( argc < 2)
    return 1;
  
  Elemento* head = creat_vettore_sparso(argv[1], strlen(argv[1]));
  printf("Il vettore sparo e': ");
  display(head);
  //freeList(head);

  return 0;
}



//questa e' l'antenato del init
Elemento* crea_elemento(char c, int pos){
  Elemento* result = malloc(1*sizeof(Elemento));
  result -> c = c;
  result -> pos = pos;
  result -> next = NULL;
  return result;
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

// Elemento* add_element_rec(Elemento* head, Elemento* new){
//   if( head == NULL)
//     return new;

//   head -> next = add_element_rec(head->next, new);
//   return head;
// }


void display(Elemento* head){
  if( head == NULL ){
    printf("NULL\n");
    return;
  }
  printf("(%d,%c)->", head->pos, head->c);
  display(head -> next);
}

// void freeList(Elemento* head){
//   Elemento* linkNext;

//   while(head != NULL){
//     linkNext = head -> next;
//     free(head);
//     head = linkNext;
//   }
// }


Elemento* creat_vettore_sparso(char string[], int len){
  Elemento* result = NULL;
  int lower_v, upper_v;
  char c;

  for(int i = 0; i < len; i++){
    c = string[i];
    lower_v = (c == 'a' ||  c == 'e' || c == 'i' || c == 'o' || c == 'u');
    upper_v = (c == 'A' ||  c == 'E' || c == 'I' || c == 'O' || c == 'U');
    if(lower_v || upper_v){
      result = add_element(result, crea_elemento(c, i));
    }
  }
  return result;
}
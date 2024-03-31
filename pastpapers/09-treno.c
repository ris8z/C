/*
Scrivere un programma C che:

1) Rappresenta un treno come una lista di 11 nodi (ogni nodo e' un
record e rappresenta una carozza), in cui un array di 100 elementi che rappresentano i posti
(0 liberi, 1 occupato)

2) Implementa le funzioni
int prenota_posto(Treno T, int carrozza)
trova le prima
posizione libera nella carrozza corrispondente, la segna come occupata
e restituisce la posizione come output

3)nel main(), definisce un treno T, inizializza l'occupazione
dei posti in modo casuale. Inoltre, prende da linea di comando il numero
della carrozza in cui prenotare e stampa il posto prenotato nella carrozza.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Treno Treno;
typedef struct Carrozza Carrozza;

struct Carrozza{
  int posti[100];
  Carrozza* next;
};

struct Treno{
  Carrozza* head;
};

Treno* crea_Treno(int numero_carrozze);
Treno* aggiungi_carrozza(Treno* t, Carrozza* c);
Carrozza* crea_Carrozza();
void free_Carrozze(Carrozza *head);
int prenota_posto(Treno T, int carrozza);

#define N_CAROZZE 11

int main(int argc, char **argv){
  if( argc < 2)
    return 1;
  srand(time(0));//serve per far workare int r = rand() % 2; che ti da un numero casuale tra 0 e 1
  
  int posto;
  int n = atoi(argv[1]);
  
  Treno* myTrain = crea_Treno(N_CAROZZE);
  posto = prenota_posto(*myTrain, n);
  if(posto != -1){
    printf("carrozza %d posot %d\n", n, posto);
  }else{
    printf("carrozza %d piena!", n);
  }

  free_Carrozze(myTrain -> head);
  free(myTrain);
  
  return 0;
}

Treno* crea_Treno(int numero_carrozze){
  Treno* new_treno = malloc(sizeof(Treno));
  if( new_treno == NULL )
    exit(0);
  
  new_treno -> head = NULL;
  for(int i = 0; i < numero_carrozze; i++){
    Carrozza* new_carrozza = crea_Carrozza();
    new_treno = aggiungi_carrozza(new_treno, new_carrozza);
  }

  return new_treno;
}

Carrozza* crea_Carrozza(){
  Carrozza* result = malloc(sizeof(Carrozza));
  if( result == NULL )
    exit(0);
  
  for( int i = 0; i < 100; i++ ){
    (result -> posti)[i] = rand() % 2;
  }
  result -> next = NULL;
 
  return result;
}

Treno* aggiungi_carrozza(Treno* t, Carrozza* c){
  if( t -> head == NULL){
    t -> head = c;
    return t;
  }

  Carrozza* link = t -> head;
  t -> head = c;
  c -> next = link;

  return t;
}

void free_Carrozze(Carrozza *head){
  if( head == NULL){
    return;
  }
  free_Carrozze(head -> next);
  free(head);
}

int prenota_posto(Treno T, int carrozza){
  //assumo che carrozza abbia valori solo da 0 fino a 10
  Carrozza *curr = T.head;
  int i = 0;
  while( i < carrozza){
    curr = curr -> next;
    i += 1;
  }

  int *arrayTarget = curr -> posti;

  //linear search to get the first 0
  i = 0;
  while( i < 100 && arrayTarget[i] != 0){
    i+=1;
  }

  if( i < 100){
    //abbiamo trovato uno zero
    arrayTarget[i] = 1;
    return i;
  }else{
    //tutta la carrozza occupata
    return -1;
  }
}
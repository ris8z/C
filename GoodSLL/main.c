#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node{
    int val;
    Node* next;
};


//1) prima funzione da fare sempre quella che crea il nodo
Node* create_node(int value);//deve RITORNARE il l'indirizzo della zona di memoria allocato per il nodo


//2) poi ti serve una funzione per aggiungere un nodo usa solo una di queste a seconda del caso
Node* add_in_head(Node* head, int value);
Node* add_in_tail(Node* head, int value); // rigorosamente ricorsivo

//3) poi ci serve una funzione per rimovere elementi (o a sisitra o a destra)
Node* pop_in_head(Node** head);//ci serve il doppio putatore pk vogliamo modificare la testa e ritornare l' elemento poppato
Node* pop_in_tail(Node** head);

//4)per debug
void display(Node* head);


int main(){
    Node* myhead = NULL;
    myhead = add_in_head(myhead, 1);
    myhead = add_in_head(myhead, 2);
    myhead = add_in_head(myhead, 3);
    myhead = add_in_head(myhead, 4);
    printf("STACK(aggiungi e rimovi alla stessa estremita della lista o sinistra o destra (head, tail))\n\n");
    printf("Se aggiungi in head stai aggiungendo a sinistra, all inizo della lista\n");
    display(myhead);

    printf("\n\n");
    printf("Se rimovi in testa rimovi a sinistra\n");
    Node* elemento_rimosso = pop_in_head(&myhead);
    printf("L' elemento rimosso ha valore %d\n\n", elemento_rimosso -> val);
    display(myhead);
    

    printf("==========================================\n");
    printf("QUEUE(aggiungi e rimovi a estremita OPPOSTE della lista o sinistra o destra (head, tail))\n\n");

    Node* myhead1 = NULL;
    myhead1 = add_in_tail(myhead1, 1);
    myhead1 = add_in_tail(myhead1, 2);
    myhead1 = add_in_tail(myhead1, 3);
    myhead1 = add_in_tail(myhead1, 4);
    printf("Se aggiungi in tail stai aggiungendo a destra, quindi alla fine\n");
    display(myhead1);

    printf("\n\n");
    printf("Se rimovi in testa rimovi a sinistra\n");
    Node* elemento_rimosso1 = pop_in_head(&myhead1);
    printf("L' elemento rimosso ha valore %d\n\n", elemento_rimosso1 -> val);
    display(myhead1);

//    Node* elemento_rimosso2 = pop_in_tail(&myhead1);
//    printf("\n\nSe rimovi in coda rimovi a destra\nL' elemento rimosso ha valore %d\n\n", elemento_rimosso2 -> val);
//    display(myhead1);   


    return 0;
}


Node* create_node(int value){
    Node* address_of_the_new_node = malloc(sizeof(Node));
    
    if(address_of_the_new_node == NULL)
        exit(0);
    
    address_of_the_new_node -> val = value;
    address_of_the_new_node -> next = NULL;
    
    return address_of_the_new_node;
}

Node* add_in_head(Node* head, int value){
    //giovanni nel main vuole usare la nostra funzione come
    //head = add_in_head(head, 5)
    if( head == NULL)
        return create_node(value);

    Node* new_node = create_node(value);
    new_node -> next = head; // il NULL a rigo 32 viene cambiato con l' idrizzo della vecchia testa

    return new_node;
}

Node* add_in_tail(Node* head, int value){
    if( head == NULL)
        return create_node(value);

    head -> next = add_in_tail(head -> next, value);

    return head;
}


Node* pop_in_head(Node** head){
    if(*head == NULL)
        return NULL;

    Node* target = *head;
    *head = (*head) -> next;

    return target;
}

Node* pop_in_tail(Node** head){
    if( *head == NULL)
        return NULL;

    Node* target = NULL;

    if( (*head) -> next == NULL ){
        target = *head;
        *head = NULL; // head -> next;
        return target;
    }

    //head esiste
    //head -> esiste pure
    Node* curr = *head;
    while(curr -> next -> next != NULL){
        curr = curr -> next;    
    }

    // 1 -> 2 -> null
    target = curr -> next; // il due
    curr -> next = NULL;// 1 -> NULL

    return target;
}


void display(Node* head){
    if(head){
        printf("(%d)->",  head -> val);
        display(head -> next);
    }else{
        printf("NULL\n");
    }
}

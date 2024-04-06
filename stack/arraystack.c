#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

struct Stack{
  int arr[100];
  int top;
};



Stack* create_stack();
void display(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);

int main(){
  Stack* mystack = create_stack();
  push(mystack, 1);
  push(mystack, 2);
  display(mystack);
  int mypoppedel = pop(mystack);
  printf("Ho appenda poppato %d dallo stack\n", mypoppedel);
  display(mystack);

  return 0;
}

Stack* create_stack(){
  Stack* result = malloc(sizeof(Stack));
  for(int i = 0; i < 100; i++){
    result -> arr[i] = 0;
  }
  result -> top = -1;
  return result;  
}

void push(Stack* s, int value){
  s -> top += 1;
  s -> arr[s -> top] = value;
}

int pop(Stack* s){
  int result = s -> arr[s -> top];
  s -> top -= 1;
  return result;
}

int peek(Stack* s){
  return s -> arr[s->top];
}

void display(Stack* s){
  for(int i = 0; i < s -> top + 1; i++){
    printf("%d ", s -> arr[i]);   
  }
  printf("\n");
}
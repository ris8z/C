/*
Scrivere un programma C che:
1) Prende in input dalla linea di comando una parola
2) Implmenta la funzione ricorsiva 
  void separa_vocali(char V[], int n)
  -che stampa prima tutte le vocali
  -e poi tutte le consonanti
input:
  vOlutAmEnte
output:
  e E A u O v l t m n t
*/
#include <stdio.h>
#include <string.h>

//La versione commentata e' come io l'avrei fatta, che ha piu senso pero' unlucky
//lui parte dalla fine della stringa io dal inizio, non ha detto da nessuna parte che devi partire dalla fine
//skill issue i think
//infatti il suo ouput e' al contrario il mio no, ok basta flex tu impara la sua che i prof so strani.
void separa_vocali(char V[], int n);

int main(int argc, char **argv){
  if( argc < 2)
    return 1;

  char *parola = argv[1];

  separa_vocali(parola, strlen(parola));
  printf("\n");

  return 0;
}

// questa sfrutta male il fatto che V[] e' un ptr a char e si gode
// void separa_vocali(char V[], int n){
//   if( n == 0 )
//     return;

//   char c = V[0];
//   int lowercase_vowel, uppercase_vowel;
//   lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
//   uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

//   if(lowercase_vowel || uppercase_vowel)
//     printf("%c ", V[0]);
  
//   separa_vocali(V + 1, n - 1);

//   if(!(lowercase_vowel || uppercase_vowel))
//     printf("%c ", V[0]);
// }


void separa_vocali(char V[], int n){
  if( n == 0 )
    return;

  char c = V[n - 1];
  int lowercase_vowel, uppercase_vowel;
  lowercase_vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
  uppercase_vowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

  if(lowercase_vowel || uppercase_vowel)
    printf("%c ", V[n - 1]);
  
  separa_vocali(V, n - 1);
  
  if(!(lowercase_vowel || uppercase_vowel))
    printf("%c ", V[n - 1]);
}
#include<stdio.h>


int contaOccorrenze(int arr[], int n, int value);

int main(){
  int arr[] = {1,2,3,4,5,6,3,3,3};
  int n = 9;

  int result = contaOccorrenze(arr, n, 3); //mi aspetto che result diventa 3
  printf("%d\n", result);

  return 0;
}

int contaOccorrenze(int arr[], int n, int value){
  return n==0?0:(arr[n-1]==value)+contaOccorrenze(arr,n-1,value);
}
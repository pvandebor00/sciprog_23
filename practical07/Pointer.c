#include <stdio.h>
#include <stdlib.h>

int *allocatearray(int n);
void fillwithones(int *p, int n);
void printarray(int *p, int n);
void clean(int *p);

int main(void){
  int i, n, *p;
  n = 10;
  // main loop
  for (i=1; i<=n; i++){ // starting at 1 to avoid an array of length 0
    p = allocatearray(i);
    fillwithones(p,i);
    printarray(p,i);
    clean(p);
  }
}


int *allocatearray(int n){
  int *p;
  p = malloc(n * sizeof(int)); // allocate a pointer as an array
  return p;
}

void fillwithones(int *arr, int n){
  int i;
  for (i=0; i<n; i++){
    arr[i]=1; // set every value in the array to 1
  }
  arr = NULL; // set internal pointer parameter to a NULL value
}

void printarray(int *p, int n){ // prints an array of length n
  int i;
  printf("["); // formatting
  for (i=0; i<n; i++){
    printf("%d ", p[i]); // main printing
  }
  printf("]\n");
}

void clean(int *p){ // frees memory at p, and points p to a NULL value
  free(p);
  p = NULL;
}

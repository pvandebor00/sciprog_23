#include <stdio.h>

void fibo(int *p1, int *p2);

int main(void){
  int n, i, f0, f1;
  int *p1, *p2;
  printf("Please fill in value for n:"); // Request value for n
  scanf("%d",&n);
  f0 = 0;   // initial values
  f1 = 1;
  p1 = &f0; // pointer construction
  p2 = &f1;
  printf("%d \n", *p1); // write 0 initially 

  for (i=1; i<n; i++) { // Starting at 1 because F1 is already computed
    fibo(p1, p2); // main fibonacci function 
    printf("%d \n", *p2); // write series
  }
}

void fibo(int *p1, int *p2){
  int temp;
  temp = *p2; // setting unmodified r-value of p2 aside for future use
  *p2 = *p1 + *p2; // Adding r-values of pointers and storing this at the r-value that p2 points to
  *p1 = temp; // storing r-value of p2 as the r-value of p1 to allow recursion
}

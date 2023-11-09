#include <stdio.h>
int gcdIter(int a, int b);
int gcdRecu(int a, int b);

int main (void){
  int a, b, gcd;
  // Asking for input numbers
  printf("First number: \n");
  scanf("%d", &a);
  printf("Second number: \n");
  scanf("%d", &b);
  printf("GCD Iterative: ");
  // run gcd iterative
  gcd = gcdIter(a, b);
  printf("%d\nGCD Recursive: ", gcd);
  // run gcd recursive
  gcd = gcdRecu(a, b);
  printf("%d\n", gcd);
}


int gcdIter(int a, int b){
  // iterative greatest common denominator function
  // based on provided pseudocode
  int temp;
  while (b != 0){
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int gcdRecu(int a, int b){
  // recursive greatest common denominator function
  // based on provided formula
  if (b == 0){
    return a;
  } else {
    gcdRecu(b, a % b);
  }
}

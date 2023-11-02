#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double element(int x);
double *allocateelementarray(int n);


int main(void){
  int i, n;
  double f, *p;
  // Ask for polynomial order
  printf("Insert polynomial order between 1 and 15: \n"); // this is not actually checked for
  scanf("%d",&n);
  f = 1.0; // set f(0)
  p = allocateelementarray(n); // create array of n elements in f
  for (i=0; i<n; i++){
    f = f + p[i]; // sum together
  }
  printf("%.15f \n",f);
  // clear pointer
  free(p);
  p = NULL;
}

double element(int x){ // Calculate 1^x/x!
  int i;
  double a, b;
  // Calculate x!
  a = 1.0;
  for (i=1; i<=x; i++){ // start at i=1 and include i==x for parity with factorial notation (the case of 0! is ignored here)
    b = (double) i;
    a = a * b;
  }
  // return element in series
  return pow(1.0,x) / a; // 1^x can be ignored but is included for good practice
}

double *allocateelementarray(int n){
  // Create a pointer to an array of n elements, with the elements of the series as values
  int i;
  double *p;
  p = malloc(n * sizeof(double)); // allocation
  for (i=0; i<n; i++){
    p[i] = element(i+1); // i+1 to skip case of f(0), since it is set separately
  }
  return p;
}


/* For n = [1-14], the calculated value is below the actual value of e, with an ever improving estimate. 
However, for n=15, the 13th digit exceeds the actual value of e. 
At this point, the floating point error influences the calculations.
 */


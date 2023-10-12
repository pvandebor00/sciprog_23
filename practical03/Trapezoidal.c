#include <stdio.h>
#include <math.h>

int main(void) {
  int i,N;
  float a,b,dist,sum;
  N = 12;
  a = 0.0;
  b = M_PI / 3.0;
  dist = (b - a) / N; // Distance between 2 equidistant points between a and b
  sum = tan(a) + tan(b); // Starting value
  for (i=1; i<N; i++) { // starting from i=1 to avoid double counting i=0
    sum = sum + 2 * tan(dist * i);
  }
  sum = 0.5 * dist  * sum; // Factor in front is equal to distance/2
  printf("Log(2): %f, Trapezoidal: %f \n", log(2), sum);
}

 

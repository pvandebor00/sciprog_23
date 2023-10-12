
#include <stdio.h>
#include <math.h>

float pi;
float resultArr[13]; // declaring array with 13 points (since 0-60 is inclusive)

float degtorad(float arg); // declaring functions
float tanTrap(int N);

int main(void) {
  int i;
  float degarg, radarg, area;
  pi = atanf(1.0)*4.0; // Calculating value for pi
  for (i=0; i<13; i++) { 
    degarg = 5 * i; // generating angles from 0-60 degrees with spacings of 5 degrees
    radarg = degtorad(degarg); // conversion to radians
    resultArr[i] = tan(radarg); // calculating tangent and storing result in array
  }
  area = tanTrap(12); // calling function to calculate area
  printf("%f \n",area);
}

float degtorad(float arg) { // As taken from lecture slides
  return ( (pi * arg) / 180.0 );
}

float tanTrap(int N) { // Trapezoidal function for tan, based on assignment 3
  int i;
  float area,fac;
  area = resultArr[0] + resultArr[N]; // Starting value for area
  for (i=1; i<N; i++) { // i=1 to avoid double counting i = 0
    area = area + 2 * resultArr[i]; // reading value of tan(x) from array
  }
  fac = (degtorad(60.0)-degtorad(0.0))/N; // correcting factor
  return 0.5 * fac * area; // returning final value
}

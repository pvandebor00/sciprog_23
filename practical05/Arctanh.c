#include <stdio.h>
#include <math.h>

void arctanh1(float delta, int i);
void arctanh2(int i);
float atanh1arr[181]; // 181 = abs(-0.9 - 0.9)/0.01 + 1
float atanh2arr[181]; // spans [-0.9,0.9] with spacing of 0.01

int main(void){
  float delta;
  int i;

  printf("Please fill in delta: \n"); // requesting value for delta
  scanf("%f",&delta);

  printf("Arctanh using McLaurin series:\n");
  for (i=0; i<181; i++) { // looping over all 181 values
    arctanh1(delta, i);
    printf("%.10e ", atanh1arr[i]); // %.10e format gives 10 sig figs in scientific notation
  }

  printf("\nArctanh using natural logarithms:\n");
  for (i=0; i<181; i++){
    arctanh2(i);
    printf("%.10e ", atanh2arr[i]);
  }
  printf("\n"); // for formatting
}


void arctanh1(float delta, int i){ // Maclaurin series approximation of arctanh
  int go = 1; // go/stop variable
  float val, n = 0; 
  float el, x;
  x = -0.9 + 0.01 * (float) i; // Calculate x as a function of i
  while (go) {
    el = pow(x, 2*n+1) / (2*n+1); // Calculate value of McLaurin series at point x
    val = val + el;
    go = fabs(el) > delta; // termination check
    n++; // iterate n
  }
  atanh1arr[i] = val; // store value in array
}

void arctanh2(int i){
  float x,val;
  x = -0.9 + 0.01 * (float) i; // Calculate x as a function of i
  val = 0.5 * (logf(1+x) - logf(1-x)); // natural log approximation
  atanh2arr[i] = val; // storing value in array
}

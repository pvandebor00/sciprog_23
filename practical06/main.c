#include <stdio.h>

int main (void){
  int n,p,q;
  int i,j,k; // Loop indices
  n = 5;
  p = 3;
  q = 4;
  int A[p][n]; // reverse order due to C array indexing being opposite from matrix indexing
  int B[q][p]; 
  int C[q][n];
  for (i=0; i<n; i++){
    for (j=0; j<p; j++){
      for (k=0; k<q; k++){
	B[k][j] = j-k; // matrix indexing and C array indexing are different
	C[k][i] = 0; // initialization of C
      }
      A[j][i] = i+j; // order does not matter for addition
    }
  }

  matmult(n,p,q,A,B,C); // call matrix multiplication function

  // Printing loops
  for (i=0; i<p; i++){
    printf("         ["); // whitespace to line up B with C
    for (j=0; j<q; j++){
      printf("%d ", B[j][i]);
    }
    printf("]\n");
  }
  printf("\n");
  for (i=0; i<n; i++){
    printf("[");
    for (j=0; j<p; j++){
      printf("%d ", A[j][i]);
    }
    printf("] [");
    for(j=0; j<q; j++){
      printf("%d ", C[j][i]);
    }
    printf("]\n");
  }
}

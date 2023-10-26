void matmult(int n, int p, int q, int matA[p][n], int matB[q][p], int matC[q][n]);

void matmult(int n, int p, int q, int matA[p][n], int matB[q][p], int matC[q][n]) {
  int i,j,k;
  for (i=0; i<q; i++){
    for (j=0; j<n; j++){
      for (k=0; k<p; k++){
        matC[i][j] = matC[i][j] + matA[k][j]*matB[i][k];
      }
    }
  }
}

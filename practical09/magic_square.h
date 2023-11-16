#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int ** square, const int n) {

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    // This value only holds up for normal magic squares (having values of 1-n^2)
    // but that is the case for this test.
    int M = (n * (n*n + 1))/2;

    int i, j;
    int row, col;
    int diag1, diag2;
    diag1 = 0;
    diag2 = 0;
    for (i=0; i<n; i++) { // loop over number of rows
      row = 0;
      col = 0;
      for (j=0; j<n; j++) {
	row = row + square[i][j]; // sum up values per row
	col = col + square[j][i]; // sum up values per column
      }
      if (row !=M || col != M) { // check for mismatch with expected sum for magic square
	return 0;
      }


      diag1 = diag1 + square[i][i]; // sum up 1 major diagonal
      diag2 = diag2 + square[i][n-i-1]; // sum up the other major diagonal
    }
    if (diag1 != M || diag2 != M) { // check for mismatch with expected sum for magic square
      return 0;
    }
    return 1; // return 1 if all tests are passed
}


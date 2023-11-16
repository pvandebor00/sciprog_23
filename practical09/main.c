#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){  

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
    int n = getlines(filename);

    f = fopen(filename, "r"); // open file in read mode

    int *p;
    int **mat;
    int i, j, magic;

    mat = malloc(sizeof(int) * n); // allocate memory of matrix

    for (i=0; i<n; i++) {
      p = malloc(sizeof(int) * n); // allocate memory for single row
      for (j=0; j<n; j++) {
	fscanf(f, "%d", &p[j]); // read value from file
	printf("%d ", p[j]); // prints square
      }
      printf("\n");
      mat[i] = p; // set pointer to 1 row of memory
    }

    magic = isMagicSquare(mat, n); // Calling magic square function

    // Output
    if (magic == 1) {
      printf("This is a magic square.\n");
    } else {
      printf("This is not a magic square.\n");
    }


    // Cleaning up
    free(p);
    p = NULL;
    for (i=0; i<n; i++) { 
      free(mat[i]); // free individual rows
      mat[i] = NULL; // set row pointer to NULL
    }
    free(mat); // free matrix
    mat = NULL; // set pointer to NULL

    fclose(f); // close file

    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}

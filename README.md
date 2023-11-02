# SciProg23 Practicals
## Pelle van de Bor

Included in this repository are pieces of code from week 2 onward for the Scientific Programming course.
All this code is written in C. The repository will be updated regularly, whenever a new practical is finished.

Each individual practical has its own folder, where all the files necessary to run the relevant code will be situated, as well as the code itself, clearly marked as .c files. Code may be compiled on the sciprog system using the command `gcc -o <code-name> <code-name.c> (-lm)`, where `-lm` is only used for programs that require the `<math.h>` module. 
The list for programs requiring this module is:

- Assignment 2: Conversion.c
- Assignment 3: Trapezoidal.c
- Assignment 4: tangentCalculations.c
- Assignment 5: Arctanh.c
- Assignment 7: eEval.c

To compile the code for assignment 6, run the `make` command in the folder containing the individual files. `make clean` is an additional option to get rid of the two `.o` files.
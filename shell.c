#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(int num, char *var[]) {
  // num and *var[] are function parameters, meaning inputs to function main
  
  if(num != 2) {
    // checks to make sure there are 2 input variables
    // 1 for program name and 1 for n value

    fprintf(stderr, "Input format: ./shell <n>\n");
    return 1; // non-zero return = terminate
  } //end if

  char *input = var[1];

  for(int i = 0; i < strlen(input); i++) {
    // iterates from 0 to length of input by one each time

    if(!isdigit(input[i])) {
      // checks to make sure input char is a digit
      // if not, prompts error and terminates
      
      fprintf(stderr, "Error: input needs to be only an integer.\n");
      return 1;
    } //end if
  } //end for
  
  int n = atoi(var[1]); // turns string n into integer

  if(n < 1 || n > 100) {
    // checks to make sure bounds are correct (1<=n<=100)

    fprintf(stderr, "Error: n not within bounds (1 <= n <= 100)\n");
    return 1;
  } //end if
  
  int **matrix = malloc(n*sizeof(int *));
  // creates pointer to a pointer for each variable of matrix
  // (i.e., matrix[row][column]

  for(int i = 0; i < n; i++) {
    // iterates from 0 to input n by one each time
    
    matrix[i] = malloc(n*sizeof(int));
    // dynamically allocate memory for one row of array matrix
  } //end for
  
  int x = ceil(n/2.0) - 1;
  int y = ceil(n/2.0) - 1;
  int d = 0; // direction var
  int c = 1; // counter var
  int s = 1; // direction length var

  matrix[x][y] = c++; // puts first num at center and increments c
  // save c to the matrix position x, y
  
  for(int k = 1; k < n; k++) {
    // iterates from 1 to input n by one each time
    
    for(int j = 0; j < (k < (n-1) ? 2:3); j++) {
      // Loops from 0 based on k and n. First checks if k < (n-1) and
      // uses the ? operator to determine the limit. If true, the limit
      // becomes 2, and if false becomes 3. Iterates by one each time
      
      for(int i = 0; i < s; i++) {
	// iterates from 0 to s by one each time

	switch(d) {
	case 0: y++; break;
	case 1: x++; break;
	case 2: y--; break;
	case 3: x--; break;
	} //end switch
	
      matrix[x][y] = c++;
      } //end for (i from 0 to s)
      
      d = (d+1)%4;
      // increments d from current value and applies modulo so value cannot reach 4
      // if divisible by 4, resets to case 0
    } //end for (j from 0 to k < (n-1))
    
    s = s + 1; // increments direction length variable by one
  } //end for (k from 1 to n)
	
  FILE *pFile = fopen("ans.out", "w"); // opens and begins writing to new file "ans.out"

  if(pFile == NULL) {
    // checks to see if file successfully opens

    fprintf(stderr, "Error: file 'ans.out' can't be opened.\n");
    return 1;
  } //end if

  int width = (int)log10(n*n) + 1; // calculates how many digits the number has

  for(int i = 0; i < n; i++) {
    // iterates from 0 to user input n by one each time

    for(int j = 0; j < n; j++) {
      // iterates from 0 to user input n by one each time

      fprintf(pFile, "%*d ", width, matrix[i][j]);
      // The * indicates that the first variable passed will indicate
      // the number of columns to use
      // prints matrix of [i] and [j] to new file from pointer
    } // end for (j from 0 to n)

    fprintf(pFile, "\n"); // newline for next row
  } // end for (i from 0 to n)

  fclose(pFile); // closes file

  for(int i = 0; i < n; i++) {
    free(matrix[i]); // rellocates to prevent memory leak
    free(matrix);
    return 0;
  } // end for (i from 0 to n)

 } //end main

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int n;
  float *array;


  printf("Enter the size of an array (1-125): ");
  if(scanf("%d", &n) != 1 || n < 1 || n > 125) {
    // checks to make sure user input is an int and within bounds
    // if it's not, returns error message

    fprintf(stderr, "Error: Array size invalid.\n");
    return 1; // non-zero return = terminate
  } //end if

  array = malloc(n*sizeof(float));
  // Malloc allocated requested number of bytes by sizeof function
  // that calculates number of bytes required for n floats
  // (i.e., dynamically allocating float to hold n floats)
  
  if(array == NULL) {
    // checks to see if pointer 'array' points to valid address

    fprintf(stderr, "Error: Address invalid.\n");
    return 1;
  } //end if

  for(int i = 0; i < n; i++) {
    // iterates from 0 to user input n by one each time

    if(i == 0) {
      // checks to make sure input is not 0 (avoids dividing by 0)
      
      array[i] = 1; //sets initial value to 1 instead of 0
    } //end if
    
    else {
      array[i] = (1 + pow(i,2) + (pow(i,3))/3); // given formula
    } //end else
    
  } //end for

  printf("Enter element to retrieve (1-%d): ", n); // inclusive

  int element;
  if(scanf("%d", &element) != 1 || element < 1 || element > n) {
    // checks to make sure user input is an int and within new bounds
    // if it's not, returns error message

    fprintf(stderr, "Error: invalid element to retrieve.\n");
    free(array);
    // since malloc() was used previously, free() is used to deallocate memory
    return 1;
  } //end if

  printf("Your value is %.4f\n", array[element - 1]);

  free(array);
  // since malloc() was used previously, free() is used to deallocate memory
  return 0;

} //end main

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char filename[256]; // makes array of 256 characters since char can hold up to 255
  FILE *pFile; // makes file pointer named pFile to FILE char filename[256];

  printf("Enter file name: ");
  if(scanf("%255s", filename) != 1) {
    // reads up to 255 characters into filename
    // char data type stores 255 different values
    // if file value when read is != 1 (successfully read), then returns error

    fprintf(stderr, "Error: File can't be read.\n");
    return 1; // non-zero return = terminate
  } //end if

  pFile = fopen(filename, "r"); // opens and begins reading file

  if(pFile != NULL) {
    // if file CAN be successfully opened, then returns error

    fprintf(stderr, "Error: File already exists.\n");
    fclose(pFile); // closes file since it already exists
    return 1;
  } //end if

  pFile = fopen(filename, "w");

  if(pFile == NULL) {
    // if file cannot be successfully created, then returns error

    fprintf(stderr, "Error: File can't be created.\n");
    return 1;
  } //end if

  for(int i = 1; i <= 100; i++) {
    // iterates from 1 to 100 by one each time
    
    fprintf(pFile, "%d\n", i);
    // writes numbers 1 to 100 (one number per line) in newly created file
  }

  fclose(pFile); // closes file
  return 0;  

} //end main

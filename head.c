#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char filename[256]; // makes array of 256 characters since char can hold up to 255
  FILE *pFile; // makes file pointer named pFile to FILE
  char line[1024]; // makes array of 1024 char elements in line variable
  int num = 0;

  printf("Enter file name: ");
  if(scanf("%255s", filename) != 1) {
    // reads up to 255 characters into filename
    // char data type stores 255 different values
    // if file value when read is != 1 (successfully read), then returns error

    fprintf(stderr, "Error: File can't be read.\n");
    return 1; // non-zero return = terminate
  } //end if

  pFile = fopen(filename, "r"); // opens and begins reading file
  
  if(pFile == NULL) {
    // if file cannot be successfully opened, then returns error
    
    fprintf(stderr, "Error: File can't be opened.\n");
    return 1;
  } //end if

  while(num < 3 && fgets(line, sizeof(line), pFile) != NULL) {
    // max iteration of 3 (i.e., counts first 3 lines of file)
    // fgets reads line (successfully) of file from pFile into array 'line'

    printf("%s", line); // prints line (string)
    num = num + 1; // iteration
  } //end while

  fclose(pFile); // closes file
  return 0;

} //end main

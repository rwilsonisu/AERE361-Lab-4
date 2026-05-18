#include <stdio.h>
#include <stdlib.h>
#define line_length 1024 // defines the line length as 1024 chars

int main(void) {
  char filename[256]; // makes array of 256 characters since char can hold up to 255
  FILE *pFile; // makes file pointer named pFile to FILE
  char line[3][line_length];
  /* 2D array that stores 3 rows in array and number of columns in each row (line_length).
     This allows fgets to look through each line of the file and store previous lines
     to be able to print the last 3.
  */
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
  } // end if

  while(fgets(line[num % 3], line_length, pFile) != NULL) {
    // fgets reads each line in modulus of 3 (successfully) of file from pFile into array 'line' of num.
    // The modulus (%) 3 makes sure fgets only stores 3 lines at a time, basically overwriting every 4th
    // line to a new one and so on

    num = num + 1; // iteration
  } //end while

  fclose(pFile); // close file
  
  for(int i = 0; i < 3 && i < num; i++) {
    // iterates from 0 to 3, and makes sure its less than num, by one each time

      if(num < 3) {
	printf("%s", line[i]);
      } //end if

      else {
	printf("%s", line[(num -3 + i) % 3]);
	// if ending line isn't modulus of 3, it iterates i until it can
	// prints lines in chronological order as well
      } // end else
  } //end for
  
  return 0;

} //end main

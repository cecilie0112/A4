#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUTMAX 100

void inputFun(char *);
long int getNumb(char *);

int main(void) {
  //int * windowArray = calloc(10, sizeof(int));

  do {
    char inputArray [INPUTMAX];
    inputFun(inputArray); //Get input
    long int numb = getNumb(inputArray); //Extrating the number from the input
    
  }while(1);

  return 0;
}

long int getNumb(char * inputArray) {
  int size = strlen(inputArray);
  int j = 0;
  char * numbArray = calloc(size, sizeof(char));

  for (int i = 0; i < size; i++) {
    if (isdigit(inputArray[i]) || inputArray[i] == '-') {
      numbArray[j++] = inputArray[i];
    }
  }
  
  char * endPtr;
  long int numb = strtol(numbArray, &endPtr, 10);
  free(numbArray);

  return numb;
}

void inputFun(char * inputArray) {
    scanf("\n%[^\n]%*c", inputArray);
    return;
}
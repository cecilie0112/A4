#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUTMAX 100

void inputFun(char *);
long int getNumb(char *);
int detMode(char *);

void openMode(int *, int, int *);
void closeMode(int *, int, int *);
void switchMode(int *, int, int *);
void dispOutput(int);

int main(void) {
  int * windowArray = calloc(10, sizeof(int));
  int windowArrayIndx = 0;

  do {
    char inputArray[INPUTMAX];
    inputFun(inputArray); //Get input
    int mode = detMode(inputArray); //Gets the mode (open -> 1, close -> 2, switch -> 3)
    long int numb = getNumb(inputArray); //Extrating the number from the input

    switch (mode) {
      case 1: openMode(windowArray, numb, &windowArrayIndx);
      case 2: closeMode(windowArray, numb, &windowArrayIndx);
      case 3: switchMode(windowArray, numb, &windowArrayIndx);
    }

    // printf("Number: %ld\n", numb);
    // printf("Mode: %d\n", mode);
  }while(1);

  return 0;
}

void openMode (int * windowArray, int numb, int * windowArrayIndx) {
    windowArray[*windowArrayIndx] = numb;
    ++(*windowArrayIndx);
    return;
}

int detMode(char * inputArray) {
  switch (inputArray[0]) {
    case 'o' : return 1; break;
    case 'c' : return 2; break;
    case 's' : return 3; break;
    default: return 0;
  }
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
    scanf("%[^\n]%*c", inputArray);
    return;
}
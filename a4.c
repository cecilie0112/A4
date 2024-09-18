#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUTMAX 100

void inputFun(char *);
long int getNumb(char *);
int detMode(char *);

int main(void) {
  //int * windowArray = calloc(10, sizeof(int));

  do {
    char inputArray[INPUTMAX];
    inputFun(inputArray); //Get input
    int mode = detMode(inputArray); //Gets the mode (open -> 1, close -> 2, switch -> 3)
    long int numb = getNumb(inputArray); //Extrating the number from the input

    

    printf("Number: %ld\n", numb);
    printf("Mode: %d\n", mode);
  }while(1);

  return 0;
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
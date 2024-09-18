#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INPUTMAX 100

void inputFun(char *);


int main(void) {
  //int * windowArray = calloc(10, sizeof(int));
  char inputArray [INPUTMAX];

  do {
    inputFun(inputArray);
    printf("%s\n", inputArray);
  }while(1);

  return 0;
}

void inputFun(char * inputArray) {
    scanf("%[^\n]%*c", inputArray);
    return;
}
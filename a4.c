#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUTMAX 100


typedef struct node {
  long int value;
  struct node * next;
} ListNode;

typedef struct
{
  ListNode * head;
} List;

void inputFun(char *);
long int getNumb(char *);
int detMode(char *);

void openMode(List *, long int);
void closeMode(List *, long int);
void switchMode(List *, long int);
void dispOutput(int);

int main(void) {
  List * windowList = malloc(sizeof(List));
  windowList -> head = NULL;

  do {
    char inputArray[INPUTMAX];
    inputFun(inputArray); //Get input
    int mode = detMode(inputArray); //Gets the mode (open -> 1, close -> 2, switch -> 3)
    long int numb = getNumb(inputArray); //Extrating the number from the input

    switch (mode) {
      case 1: openMode(windowList, numb);
      // case 2: closeMode(windowArray, numb);
      // case 3: switchMode(windowArray, numb);
    }

    // printf("Number: %ld\n", numb);
    // printf("Mode: %d\n", mode);
    // printf("%ld\n", windowList -> head -> value);
  }while(1);

  return 0;
}

void openMode(List * windowList, long int numb) {
  ListNode * newNode = malloc(sizeof(ListNode));
  newNode -> value = numb;
  newNode -> next = windowList -> head;
  windowList -> head = newNode;
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
    scanf("\n%[^\n]%*c", inputArray);
    return;
}
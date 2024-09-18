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
void deleteList(List *);
void deleteNode(List *, ListNode *);

int main(void) {
  List * windowList = malloc(sizeof(List));
  windowList -> head = NULL;

  do {
    char inputArray[INPUTMAX];
    inputFun(inputArray); //Get input
    int mode = detMode(inputArray); //Gets the mode (open -> 1, close -> 2, switch -> 3)
    long int numb = getNumb(inputArray); //Extrating the number from the input

    switch (mode) {
      case 1: openMode(windowList, numb); break;
      case 2: closeMode(windowList, numb); break; 
      case 3: switchMode(windowList, numb); break;
    }

    // printf("Number: %ld\n", numb);
    // printf("Mode: %d\n", mode);
    if ((windowList -> head) != NULL) {
      printf("%ld\n", windowList -> head -> value);
    }
  }while((windowList -> head) != NULL);

  //FREE THE LIST 
  //deleteList(windowList);

  return 0;
}

void deleteList(List * windowList) {
  if (windowList -> head == NULL) {
    printf("List is empty!");
    return;
  }
  ListNode * current; 
  while(windowList -> head != NULL) {
    current = windowList -> head;
    windowList -> head = windowList -> head -> next;
    deleteNode(windowList, current);
  }
}

void deleteNode(List * windowList, ListNode * toDelete) {
  if (windowList -> head == NULL) {
    printf("List is empty!");
    return;
  }
  if (windowList -> head == toDelete) {
    ListNode * temp = windowList -> head;
    windowList -> head = toDelete -> next;
    free (temp);
    return;
  }

  ListNode * temp;
  ListNode * temp_next;

  while ((temp_next != NULL) && (temp_next != toDelete)) {
    temp = temp -> next;
    temp_next = temp_next -> next;
  }

  if (temp_next != NULL) {
    temp -> next = temp_next -> next;
    free(temp_next);
    return;
  }
}

void switchMode(List * windowList, long int numb) {

}

//This function removes a specificed node from the stack
void closeMode(List * windowList, long int numb) {
  if (windowList -> head == NULL) {
    printf("List is empty. Nothing to be deleted.");
    return;
  }

  if ((windowList -> head -> value) == numb) {
    ListNode * nextHead = windowList -> head -> next;
    free(windowList -> head);
    windowList -> head = nextHead;
    return;
  }

  ListNode dummy;
  dummy.next = windowList -> head;
  ListNode * curr = dummy.next;
  ListNode * prev = curr;

  while ((curr != NULL) && (curr -> value != numb)) {
    prev = curr;
    curr = curr -> next;
  }

  if (curr != NULL) {
    prev -> next = curr -> next;
    free(curr);
  }
  return;
}

//This function creates a new node with the number as its value as inserts it at the head of the list
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
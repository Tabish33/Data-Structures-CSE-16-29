#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};


void display(struct Node **head ){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);

    do {
      printf("%d\n", temp->data );
      temp = temp->next;
    } while( temp!= (*head) );

}

void insertLast(int data, struct Node **head, struct Node **last ){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = (*head);

    if ( (*head) == NULL) {
        (*head) = ptr;
        (*last) = ptr;
    }
    else {
        (*last)->next = ptr;
        (*last) = ptr;
    }
}

void insertFront(int data, struct Node **head, struct Node **last ){
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;
  ptr->next = NULL;

  if ( (*head) == NULL) {
      (*head) = ptr;
      (*last) = ptr;
  }
  else {
      struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
      temp = (*head) ;
      (*head) = ptr;
      (*head)->next = temp;
      (*last)->next = (*head);
  }
}


void deleteFront(struct Node **head, struct Node **last){

  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp = (*head);

  if ( (*head)->next == (*head) ) {
     (*head) = NULL;
     (*last) = NULL;
     free(temp);
  }
  else {
    (*head) = (*head)->next;
    (*last)->next = (*head);
    free(temp);
  }
}


void deleteLast(struct Node **head, struct Node **last){

  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
  temp = (*head);

  do {
    prev = temp;
    temp = temp->next;
  } while(temp->next != (*head));

  (*last) = prev;
  (*last)->next = (*head);
}


int main(){
  struct Node *head = NULL;
  struct Node *last = NULL;
  insertLast(24, &head, &last);
  insertLast(56, &head, &last);
  insertLast(7, &head, &last);
  insertLast(543, &head, &last);
  insertFront(6, &head, &last);
  insertFront(8, &head, &last);
  deleteLast(&head, &last);
  deleteLast(&head, &last);
  deleteFront(&head, &last);
  display(&head);
}

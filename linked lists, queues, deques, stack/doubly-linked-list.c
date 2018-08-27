#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};


void displayFromFront(struct Node **head ){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);
    while (temp!= NULL) {
      printf("%d\n", temp->data );
      temp = temp->next;
    }
}


void displayFromRear(struct Node **tail ){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*tail);
    while (temp!= NULL) {
      printf("%d\n", temp->data );
      temp = temp->prev;
    }
}


void insertAtFront(int data, struct Node **tail, struct Node **head){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if ( (*head) == NULL) {
        (*head) = ptr;
        (*tail) = ptr;
    }
    else {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp = (*head) ;
        temp->prev = ptr;
        (*head) = ptr;
        (*head)->next = temp;
    }
}


void insertAtRear(int data, struct Node **tail, struct Node **head ){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if ( (*head) == NULL) {
        (*head) = ptr;
        (*tail) = ptr;
    }
    else {
        ptr->prev = (*tail);
        (*tail)->next = ptr;
        (*tail) = ptr;
    }
}


void reverse( struct Node **head, struct Node **tail){
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *next = (struct Node*)malloc(sizeof(struct Node));
    struct Node *temp= (struct Node*)malloc(sizeof(struct Node));
    curr = (*head);
    prev = NULL; next = NULL;

    (*tail) = (*head);

    while (curr != NULL) {
      temp = curr->next;
      curr->next = curr->prev;
      curr->prev = temp;
      prev =curr;
      curr = temp;
    }
    (*head) = prev;
}


int main(){
  struct Node *head1 = NULL;
  struct Node *tail1 = NULL;
  insertAtFront(12, &tail1, &head1);
  insertAtFront(45, &tail1, &head1);
  insertAtRear(33,&tail1, &head1);
  insertAtRear(6, &tail1, &head1);
  insertAtFront(78, &tail1, &head1);
  displayFromFront(&head1);
  printf("-------------------\n");
  reverse(&head1,&tail1);
  displayFromFront(&head1);
  printf("tail%d\n", tail1->data);
}

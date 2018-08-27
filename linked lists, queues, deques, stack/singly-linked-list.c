#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node *next;
};

void display(struct Node **head ){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);
    while (temp!= NULL) {
      printf("%d\n", temp->data );
      temp = temp->next;
    }
}


void insertAtRear(int data, struct Node **tail, struct Node **head ){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if ( (*head) == NULL) {
        (*head) = ptr;
        (*tail) = ptr;
    }
    else {
        (*tail)->next = ptr;
        (*tail) = ptr;
    }
}

void insertAtFront(int data, struct Node **tail, struct Node **head){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if ( (*head) == NULL) {
        (*head) = ptr;
        (*tail) = ptr;
    }
    else {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp = (*head) ;
        (*head) = ptr;
        (*head)->next = temp;
    }
}


void deleteNodeWithData(int data, struct Node **head){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);

    if (temp->data == data) {
      (*head) = (*head)->next;
      free(temp);
      return;
    }

    while (temp != NULL && temp->data != data ) {
       prev = temp;
       temp = temp->next;
    }

    if (temp == NULL) {
      printf("Node not found\n" );
    } else {
      prev->next = temp->next;
      free(temp);
    }
}

void deleteNodeAtPosition(int pos, struct Node **head){
    int start = 0;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);

    if (pos == 0) {
      (*head) = (*head)->next;
      free(temp);
      return;
    }

    while (temp != NULL && start != pos ) {
       prev = temp;
       temp = temp->next;
       start++;
    }

    if (temp == NULL) {
      printf("Out Of bounds\n" );
    } else {
      prev->next = temp->next;
      free(temp);
    }
}


void reverse( struct Node **head, struct Node **tail){
    struct Node *prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *next = (struct Node*)malloc(sizeof(struct Node));
    curr = (*head);
    prev = NULL; next = NULL;

    (*tail) = (*head);

    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    (*head) = prev;
}



struct Node* merge(struct Node **head1 , struct Node **head2){
  struct Node *merge_head = (struct Node*)malloc(sizeof(struct Node));
  struct Node *merge_tail = (struct Node*)malloc(sizeof(struct Node));
  struct Node *temp1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *temp2 = (struct Node*)malloc(sizeof(struct Node));
  temp1 = (*head1);
  temp2 = (*head2);
  merge_head = NULL;
  merge_tail = NULL;
  while ( temp1!= NULL ) {
      insertAtRear(temp1->data, &merge_tail, &merge_head);
      temp1 = temp1->next;
  }
  while ( temp2!= NULL ) {
      insertAtRear(temp2->data, &merge_tail, &merge_head);
      temp2 = temp2->next;
  }
  return merge_head;
}


void concat(struct Node **tail1, struct Node **head2 , struct Node **tail2){
  (*tail1)->next = (*head2);
  (*tail1)  = (*tail2);
}


int main(){
  struct Node *head1 = NULL;
  struct Node *head2  = NULL;
  struct Node *head3  = NULL;
  struct Node *tail1 = NULL;
  struct Node *tail2 = NULL;

  printf("--------L1-------\n");
  insertAtFront(12, &tail1, &head1);
  insertAtFront(45, &tail1, &head1);
  insertAtRear(33,&tail1, &head1);
  insertAtRear(6, &tail1, &head1);
  insertAtFront(78, &tail1, &head1);
  display(&head1);

  printf("--------L2-------\n");
  insertAtFront(4, &tail2, &head2);
  insertAtFront(2325, &tail2, &head2);
  insertAtRear(416,&tail2, &head2);
  insertAtRear(16, &tail2, &head2);
  insertAtFront(8, &tail2, &head2);
  display(&head2);

  printf("--------L3-------\n");
  concat(&tail1, &head2, &tail2);
  display(&head1);

}

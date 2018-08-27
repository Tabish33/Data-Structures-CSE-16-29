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

void insert(int data, struct Node **head, struct Node **last ){
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


int main(){
  struct Node *head = NULL;
  struct Node *last = NULL;
  insert(24, &head, &last);
  insert(56, &head, &last);
  insert(7, &head, &last);
  insert(543, &head, &last);
  display(&head);
}

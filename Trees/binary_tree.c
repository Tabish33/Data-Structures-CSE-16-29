#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *left;
  struct node *right;
  int data;
};


struct node* queue[30];
int front = -1;
int rear = -1;

void enqueue(struct node *data){
  if (front == -1) {
    front++;
    rear++;
    queue[front]= data;
  }
  else {
    rear++;
    queue[rear]= data;
  }
}

struct node* dequeue(){
  if (front == -1) {
    printf("Queue is empty\n");
  }
  else{
     struct node* data =  queue[front];
     if ( front == rear ) {
      front = -1;
      rear = -1;
    }
    else {
      front++;
    }
    return data;
  }

}

void emptyQueue(){
  while (front != -1) {
    dequeue();
  }
}


struct node* newNode(int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));

  ptr->left = NULL;
  ptr->right = NULL;
  ptr->data = data;

  return ptr;
};

void insert(struct node **root, int data){
  enqueue((*root));

  while (front != -1) {
    struct node *Node = (struct node*)malloc(sizeof(struct node));
    Node = dequeue();

    if (Node->left == NULL) {
        Node->left = newNode(data);
        break;
    }
     else if (Node->right == NULL) {
       Node->right = newNode(data);
       break;
    }

    enqueue(Node->left);
    enqueue(Node->right);
  }

  emptyQueue();
}

void InOrderTraversal(struct node *root){
  if (root == NULL) {
    return;
  }
  InOrderTraversal(root->left);
  printf("%d ", root->data );
  InOrderTraversal(root->right);
}


void PreOrderTraversal(struct node *root){
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data );
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}

void PostOrderTraversal(struct node *root){
  if (root == NULL) {
    return;
  }
  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);

  printf("%d ", root->data );
}

int main(){
  struct node *root = newNode(1);
  insert(&root,2);
  insert(&root,3);
  insert(&root,4);
  insert(&root,5);

  PostOrderTraversal(root);


}

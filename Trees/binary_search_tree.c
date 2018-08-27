#include <stdio.h>
#include <stdlib.h>

struct node{
  struct node *left;
  struct node *right;
  int data;
};


struct node* newNode(int data){
  struct node *ptr = (struct node*)malloc(sizeof(struct node));

  ptr->left = NULL;
  ptr->right = NULL;
  ptr->data = data;

  return ptr;
};

void insert(struct node **root, int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *prev = (struct node*)malloc(sizeof(struct node));
    temp = (*root);
    prev = temp;

    while (temp != NULL) {
      prev = temp;
      if (data < temp->data ) {
        temp = temp->left;
      }
      else {
        temp = temp->right;
      }
    }

    if (data < prev->data ) {
      prev->left = newNode(data);
    }
    else {
      prev->right = newNode(data);
    }
}

struct node* search(struct node *root, int data){
    if ( root == NULL || root->data == data ) {
      if (root != NULL) {
        return root;
      }
      printf("Node Not Found");
    }

    if ( data < root->data ) {
      return search(root->left,data);
    }
    else {
      return search(root->right,data);
    }

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


struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}


struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL) return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);

    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
  struct node *root = newNode(100);
  insert(&root,20);
  insert(&root,30);
  insert(&root,10);
  insert(&root,500);
  insert(&root,40);

  PreOrderTraversal(root);
  printf("\n");
  deleteNode(root,100);
  PreOrderTraversal(root);

}

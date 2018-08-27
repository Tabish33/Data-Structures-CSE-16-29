#include <stdio.h>
#include <stdlib.h>

struct Vertex{
  struct Node *head ;
  struct Node *tail ;
};

struct Node{
  int data;
  struct Node *next;
};

void displayLinkedList(struct Node **head ){

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);
    while (temp!= NULL) {
      printf("%d ", temp->data );
      temp = temp->next;
    }
    printf("\n");
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


void initializeGraph(struct Vertex graph[], int num_of_vertices){
    int i;
    for ( i = 0; i < num_of_vertices; i++) {
      struct Vertex v;
      v.head = NULL;
      v.tail = NULL;
      graph[i] = v;
    }
}


void addEdge(struct Vertex graph[],int v1,int v2){
    insertAtFront(v2,&graph[v1].tail,&graph[v1].head);
}


void displayGraph(struct Vertex graph[], int num_of_vertices){
    int i;
    for ( i = 0; i < num_of_vertices; i++) {
        printf("%d: ",i);
        displayLinkedList(&graph[i].head);
    }
}


int main(){

  int num_of_vertices= 5;
  struct Vertex graph[num_of_vertices];

  initializeGraph(graph, num_of_vertices);

  addEdge(graph,0,2);
  addEdge(graph,1,2);
  addEdge(graph,2,1);
  addEdge(graph,2,4);
  addEdge(graph,1,3);
  addEdge(graph,3,2);
  addEdge(graph,3,1);
  addEdge(graph,3,4);
  addEdge(graph,4,3);
  addEdge(graph,4,2);

  displayGraph(graph,num_of_vertices);

}

#include <stdio.h>
#include <stdlib.h>

int queue[10];
int front = -1;
int rear = -1;

void enqueue(int data){
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

int dequeue(){
  if (front == -1) {
    printf("Queue is empty\n");
  }
  else{
     int data =  queue[front];
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


struct Vertex{
  struct Node *head ;
  struct Node *tail ;
  int visited;
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
    insertAtRear(v2,&graph[v1].tail,&graph[v1].head);
}


void displayGraph(struct Vertex graph[], int num_of_vertices){
    int i;
    for ( i = 0; i < num_of_vertices; i++) {
        printf("%d: ",i);
        displayLinkedList(&graph[i].head);
    }
}


void bfs(struct Vertex graph[], int num_of_vertices, int head){
  enqueue(head); //Initialize head of graph
  graph[head].visited = 1;

  while (front != -1) {
    int vertex = dequeue();
    printf("%d ",vertex );


    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = graph[vertex].head;

    while (temp!= NULL) {
      if (graph[temp->data].visited != 1) {
        graph[temp->data].visited = 1;
        enqueue(temp->data);
      }
      temp = temp->next;
    }
  }
}

int main(){

  int num_of_vertices= 6;
  struct Vertex graph[num_of_vertices];

  initializeGraph(graph, num_of_vertices);

  addEdge(graph,0,1);
  addEdge(graph,0,2);
  addEdge(graph,1,3);
  addEdge(graph,2,3);
  addEdge(graph,2,4);
  addEdge(graph,3,2);
  addEdge(graph,3,5);

  displayGraph(graph,num_of_vertices);
  int head = 0;
  bfs(graph, num_of_vertices,head);

}

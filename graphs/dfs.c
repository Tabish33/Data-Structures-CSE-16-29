#include <stdio.h>
#include <stdlib.h>

int stack[10];
int start = -1;
int top = -1;

void display(){
  int i;
  for (i = start ; i <= top; i++) {
      printf("%d ",stack[i] );
  }
  printf("\n");
}

void peek(){
  printf("%d\n", stack[top]);
}

void push(int data){
  if (top == -1 && start == -1 ) {
    top++;
    start++;
    stack[top] = data;
  }
  else {
    top++;
    stack[top] = data;
  }
}


int pop(){
  if (top == -1) {
    printf("Stack is empty\n" );
  }
  else {
    int data = stack[top];
    top--;
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


void dfs(struct Vertex graph[], int num_of_vertices, int head){
  push(head); //Initialize head of graph
  graph[head].visited = 1;

  while (top != -1) {
    int vertex = pop();
    printf("%d ",vertex );


    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = graph[vertex].head;

    while (temp!= NULL) {
      if (graph[temp->data].visited != 1) {
        graph[temp->data].visited = 1;
        push(temp->data);
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
  addEdge(graph,1,2);
  addEdge(graph,2,0);
  addEdge(graph,2,3);
  addEdge(graph,3,3);

  displayGraph(graph,num_of_vertices);
  int head = 2;
  dfs(graph, num_of_vertices,head);

}

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

void dequeue(){
  if (front == -1) {
    printf("Queue is empty\n");
  }
  else if ( front == rear ) {
    printf("%d\n",queue[front]);
    front = -1;
    rear = -1;
  } else {
    printf("%d\n",queue[front]);
    front++;
  }
}

int main(){
  enqueue(23);
  enqueue(56);
  enqueue(19);
  enqueue(38);

  dequeue();
  dequeue();
  dequeue();
  dequeue();
  dequeue();
}

#include <stdio.h>
#include <stdlib.h>

int queue[10];
int front = -1;
int rear = -1;


void display(){
  int i;
  for (i = front ; i <= rear ;i++) {
    printf("%d ", queue[i] );
  }
  printf("\n");
}

void bubblesort(){
  int flag = 1;
  while (flag == 1) {
    int flag2 = 0;
    int i = front;
    while ( i < rear ) {
      if (queue[i] > queue[i+1]){
        flag2 = 1;
        int temp = queue[i];
        queue[i] = queue[i+1];
        queue[i+1] = temp;
      }
      i++;
    }
    if ( flag2 != 1 ) {
      flag = 0;
    }
  }
  display();

}

void enqueue(int data){
  if (front == -1) {
    front++;
    rear++;
    queue[front]= data;
  }
  else {
    rear++;
    queue[rear]= data;
    bubblesort();
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
}

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


void pop(){
  if (top == -1) {
    printf("Stack is empty\n", );
  }
  else {
    printf("%d\n",stack[top]);
    top--;
  }
}

int main(){
    push(3);
    push(456);
    push(56);
    push(14);
    display();
}

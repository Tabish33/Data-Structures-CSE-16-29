#include <stdio.h>
#include <stdlib.h>

char expression[] = "+9*26";

int stack[20];
int start = -1;
int top = -1;

void display(){
  int i;
  for (i = start ; i <= top; i++) {
      printf("%d ",stack[i] );
  }
  printf("\n");
}

char peek(){
  printf("%d\n",stack[top] );
  return stack[top];
}

void push(char data){
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

char pop(){
  if (top == -1) {
    printf("Stack is empty\n");
  }
  else {
    int temp = stack[top];
    top--;
    return temp;
  }
}

int charToInt(char c){
  return c - '0';
}

int identifier(char c){
   if ( c == '+' || c == '*' ||c == '/' || c == '%' || c == '-' || c == '^' ) {
    return 1;
  }
  else {
    return 2;
  }
}


int operate(int a, int b, char expr){
  switch ( expr ) {
    case '+': return a+b;
    case '*': return a*b;
    case '/': return a/b;
    case '-': return a-b;
    case '%': return a%b;
    case '^': return a^b;
  }
}

int expLen(){
  int len = 0;
  while (expression[len] != '\0') {
    len++;
  }
  return len;
}

void prefixResolution(){
    int len = expLen()-1;
    while (len >= 0 ) {
        if ( identifier(expression[len]) == 2 ) {
           int num = charToInt(expression[len]);
           push(num);
        }
        else{
          int a = pop();
          int b = pop();
          signed int c = operate(a,b,expression[len]);
          push(c);
        }
        len--;
    }
    peek();
}


int main(){
  prefixResolution();
}

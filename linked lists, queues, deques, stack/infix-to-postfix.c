#include <stdio.h>
#include <stdlib.h>

char stack[40];
char expression[] = "a+b*(c^d-e)^(f+g*h)-i"; // ABC*DEF^/G*-H*+
char output[40];
int output_start = 0;
int start = 0;
int top = 0;

void displayOutput(){
  int i;
  for (i = 0; i < 30; i++) {
    printf("%c", output[i] );
  }
  printf("output end\n");
}

void display(){
  int i;
  for (i = start ; i <= top; i++) {
      printf("%c ",stack[i] );
  }
  printf("\n");
}

char peek(){
  // printf("%c\n", stack[top]);
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
    // printf("%c\n",stack[top]);
    int temp = stack[top];
    top--;
    return temp;
  }
}


int priority(char c){
  if (c == ')') {
    return 1;
  }
  else if( c == '^'){
    return 2;
  }
  else if( c == '/' || c == '*' || c == '%'){
    return 3;
  }
  else if( c == '+' || c == '-'){
    return 4;
  }
  else if( c == '('){
    return 5;
  }
  return 6;
}

void infixToPostfix(){
    int i = 0;
    while ( expression[i] != '\0' ) {
        char Exp = expression[i];
        int Priority= priority(Exp);

        if ( Priority == 6) {
          output[output_start] = Exp;
          output_start++;
        }

        else if( Priority== 1 ){
          while ( peek() != '(') {
             output[output_start] = pop();
             output_start++;
          }
          pop();
        }

        else if(Priority == 5){
          push(Exp);
        }

        else{
            if ( Priority< priority(peek()) ) {
              push(Exp);
            }
            else {
              while ( Priority >= priority(peek())  ) {
                 output[output_start] = pop();
                 output_start++;
              }
              push(Exp);
            }
        }
        i++;
        printf("\n");
    }

    // EMPTY ITEMS LEFTIN STACK
    while ( peek() != '(' ) {
      output[output_start] = pop();
      output_start++;
    }


}

int main(){
  stack[0] = '(';
  infixToPostfix();
  displayOutput();

}

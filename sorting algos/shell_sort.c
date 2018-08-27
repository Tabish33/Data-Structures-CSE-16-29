#include <stdio.h>
#include <math.h>

void display(int arr[],int start,int end_index){
  int i;
  for ( i = start; i <= end_index; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}

int get_gap(int num){
  return floor(num/2);
}

void make_pass(int arr[],int end, int size,int gap){
  int curr;
  while ( end < size ) {
    curr = end;
    while ( arr[curr] < arr[curr-gap] && (curr-gap) >= 0 ) {
      int temp = arr[curr];
      arr[curr] = arr[curr-gap];
      arr[curr-gap] = temp;
      curr-=gap;
    }
    end++;
  }
}

void shell_sort(int arr[],int size){
  int gap = get_gap(size);

  while (gap > 0) {
    int end = gap;
    make_pass(arr,end,size,gap);
    gap = get_gap(gap);
  }
}

int main(){
  int size = 6;
  int start = 0;
  int arr[6] = {162,45,3,456,24,54};
  shell_sort(arr,size);
  display(arr,0,5);
}

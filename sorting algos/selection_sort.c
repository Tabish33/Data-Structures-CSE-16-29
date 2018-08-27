#include <stdio.h>

void display(int arr[],int size){
  int i;
  for ( i = 0; i < size; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}

int get_min_element(int arr[],int start_index, int size){
  int min = 1e7;
  int min_index;
  for ( start_index; start_index < size; start_index++) {
     if (arr[start_index] < min) {
        min = arr[start_index];
        min_index = start_index;
     }
  }
  return min_index;
}

void selection_sort(int arr[], int size){
  int i ;
  for (i = 0; i < size-1; i++) {
    int min_index = get_min_element(arr,i,size);
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

int main(){
  int size = 6;
  int arr[6] = {12,45,3,456,24,54};
  selection_sort(arr,size);
  display(arr,size);
}

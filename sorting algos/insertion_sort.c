#include <stdio.h>

void display(int arr[],int size){
  int i;
  for ( i = 0; i < size; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}

void insertion_sort(int arr[], int size ){
  int i ;
  for (i = 1; i < size; i++) {
    int j = i-1;
    while (arr[j] > arr[j+1] && j >=0 ) {
      int temp= arr[j+1];
      arr[j+1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main(){
  int size = 6;
  int arr[6] = {12,45,3,456,2,54};
  insertion_sort(arr,size);
  display(arr,size);
}

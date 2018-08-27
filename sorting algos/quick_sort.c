#include <stdio.h>

void display(int arr[],int start,int end_index){
  int i;
  for ( i = start; i <= end_index; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}


int partition(int arr[], int start_index, int end_index){
  int pivot = arr[end_index];
  int pIndex = start_index;
  int i;

  for ( i = start_index+1; i < end_index; i++) {
    if ( arr[i] < pivot ) {
      int temp = arr[pIndex];
      arr[pIndex] = arr[i];
      arr[i] = temp;
      pIndex++;
    }
  }

  int temp = arr[pIndex];
  arr[pIndex] = pivot;
  arr[end_index] = temp;

  return pIndex;
}


void quick_sort(int arr[], int start_index, int end_index){
  if (end_index <= start_index ) {
    return;
  }

  int pivot = partition(arr,start_index,end_index);

  quick_sort(arr,start_index,pivot-1);
  quick_sort(arr,pivot+1,end_index);

  return;
}


int main(){
  int size = 6;
  int start = 0;
  int arr[6] = {162,45,3,456,24,54};
  quick_sort(arr,start,size-1);
  display(arr,0,5);
}

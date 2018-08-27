#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void display(int arr[],int start,int end_index){
  int i;
  for ( i = start; i <= end_index; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}


void modify_main_array(int arr[],int merged_arr[], int start_index, int end_index){
  int i;
  int j = 0;
  for ( i = start_index; i <= end_index; i++) {
    arr[i] = merged_arr[j];
    j++;
  }
}


void merge(int arr[], int start_index,int mid_index, int end_index){

  int size = (end_index-start_index)+1;
  int *merged_and_sorted_subarr = (int*)malloc(sizeof(int)*size);
  int i= 0, j= start_index, k= mid_index+1;

  while ( j<= mid_index && k <= end_index ) {
    if (arr[j] < arr[k]) {
      merged_and_sorted_subarr[i] = arr[j];
      j++;
    }
    else {
      merged_and_sorted_subarr[i] = arr[k];
      k++;
    }
    i++;
  }

  while (j<= mid_index) {
    merged_and_sorted_subarr[i] = arr[j];
    j++;
    i++;
  }

  while (k<= end_index) {
    merged_and_sorted_subarr[i] = arr[k];
    k++;
    i++;
  }

  modify_main_array(arr,merged_and_sorted_subarr,start_index,end_index);

  free(merged_and_sorted_subarr);
}


void merge_sort(int arr[], int start_index, int end_index){
  if (end_index <= start_index ) {
    return;
  }

  int mid = floor(start_index + ( end_index - start_index )/2) ;

  merge_sort(arr,  start_index,  mid );
  merge_sort(arr,  mid+1,  end_index);

  merge(arr,start_index,mid,end_index);
  return;
}


int main(){
  int size = 6;
  int start = 0;
  int arr[6] = {162,45,3,456,24,54};
  merge_sort(arr,start,size-1);
  display(arr,0,5);
}

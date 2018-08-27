#include <stdio.h>

int binary_search( int arr[], int num, int start_index, int end_index){

  int mid = start_index + (end_index-start_index)/2;

  if ( end_index  == start_index || arr[mid] == num ) {
     if ( arr[mid] != num ) {
       return -1;
     }
     return mid;
  }

  if ( num < arr[mid] ) {
     return binary_search(arr,num,start_index,mid);
  }
   else {
     return binary_search(arr,num,mid+1,end_index);
  }
}

int main(){
  int arr[10] = {10,11,12,13,14,15,16,17,18,19};
  int start_index = 0;
  int end_index = 9;
  int num = 15;
  int index = binary_search(arr,num,start_index,end_index);
  printf("%d\n", index );
}

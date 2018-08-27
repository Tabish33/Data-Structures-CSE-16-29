#include <stdio.h>
#include <stdlib.h>

void display(int arr[],int start,int end_index){
  int i;
  for ( i = start; i <= end_index; i++) {
     printf("%d ",arr[i] );
  }
  printf("\n");
}

int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

int getMin(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < mx)
            mx = arr[i];
    return mx;
}

void count_sort(int arr[], int size, int exp){
  int max = getMax(arr,size);
  int min = getMin(arr,size);
  int count_size = max-min+1;
  int *count = (int*)malloc(sizeof(int)*count_size);
  int *sorted_array = (int*)malloc(sizeof(int)*(size));
  int i;
  // Intiliaze count
  for ( i = 0; i < count_size ; i++) {
    count[i] = 0;
  }
  // Set Counts
  for ( i = 0; i < size ; i++) {
    int num = arr[i];
    int count_index = ((num-min)/exp)%10;
    count[count_index]+=1;
  }
  // Set Sumcounts
  for ( i = 1; i < count_size ; i++) {
    count[i] += count[i-1];
  }
  // get sorted input
  for ( i = 0; i < size ; i++) {
    int num = arr[i];
    int count_index = ((num-min)/exp)%10;
    int sum_count = count[count_index];
    sorted_array[sum_count-1] = num;   // -1 because index starts from 0 not 1;
    count[count_index]-=1;
  }
  //set arr to sorted_array
  for ( i = 0; i < size ; i++) {
    arr[i] = sorted_array[i];
  }

  free(sorted_array);
}


void radix_sort(int arr[], int n){
    int m = getMax(arr, n);
    int exp;

    for ( exp = 1; m/exp > 0; exp *= 10)
        count_sort(arr, n, exp);
}

int main(){
  int size = 6;
  int start = 0;
  int arr[6] = {9,4,10,8,2,4};
  radix_sort(arr,size);
  display(arr,0,5);
}

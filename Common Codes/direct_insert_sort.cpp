#include <cstdio>
//  Min => Max 
//  DATA: indexd | A[i] | unindexed
void direct_insert_sort(int arr[], int n) {
  int i, j, tmp;  //  tmp as temporary data
  for(i = 1; i < n; i++) {
    if(arr[i-1] > arr[i]) {
      tmp = arr[i];
      for(j = i-1; arr[j] > tmp; j--) //  move forward to reseve i's postion
        arr[j+1] = arr[j];
      arr[j+1] = tmp; 
      //  ATTENTION: Check the location
    }
  }
}
int main()
{
  int arr[] = {73, 68, 80, 85, 73, 74, 33, 49, 74, 90, 23, 22, 1, 0, 57, 11, 27, 35, 60, 45};

  int len = sizeof(arr) / sizeof(arr[0]);
  direct_insert_sort(arr, len);
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
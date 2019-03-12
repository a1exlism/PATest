#include <cstdio>
// 二分查找框架
int binary_search(int arr[], int len, int x) {
  int low = 0,
      high = len - 1;
  int mid;
  while(low <= high) {
    mid = (low+high)/2;
    if(arr[mid] == x) {
      break;
    } else if(arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if(arr[mid] == x)
    return mid;
  else
    return -1;
}

int main() {
  int arr[] = {0, 1, 11, 22, 23, 27, 33, 35, 45, 49, 57, 60, 68, 73, 73, 74, 74, 80, 85, 90};
  int len = sizeof(arr) / sizeof(arr[0]);
  int x;
  scanf("%d", &x);
  printf("Position: %d", binary_search(arr, len, x));
  return 0;
}
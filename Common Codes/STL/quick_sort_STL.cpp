#include <cstdio>
#include <algorithm>
using namespace std;
//  结构体见2018_D
//  sort(arrStart, arrEnd[, compare]);
bool compare(int a, int b);

int main()
{
  int arr[] = {73, 68, 80, 85, 73, 74, 33, 49, 74, 90, 23, 22, 1, 0, 57, 11, 27, 35, 60, 45};
  int len = sizeof(arr) / sizeof(arr[0]);

  sort(arr, arr+len);
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  sort(arr, arr+len, compare);
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
 
  return 0;
}

bool compare(int front, int end) {
  //  降序
  if(front > end)
    return 1;
  else
    return 0;
}
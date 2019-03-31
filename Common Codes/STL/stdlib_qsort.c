#include <stdio.h>
#include <stdlib.h>
/* WARNING qsort int stdlib.h
 * void qsort (void* base, size_t num, size_t size,
 * int (*compar)(const void*,const void*)); 
 */
int cmp(const void *a, const void *b);
int main() {
  int arr[] = { 40, 10, 100, 90, 20, 25 };
  int num = sizeof(arr)/sizeof(int);
  qsort(arr, num, sizeof(int), cmp);
  for(int i = 0; i < num; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}

int cmp(const void *a, const void *b) {
  //  WARNING: this meaning when to exchang a and b
  //  `int*` 强制类型转换
  if(*(int*)a > *(int*)b) {
    return 1;
  } else {
    return 0;
  }
}
#include <cstdio>
int main() {
  int arr[20] = { 20, 46, 98, 38, 13, 66, 71, 92, 23, 90, 3, 74, 8, 88, 63, 73, 79, 19, 11, 28 };
  int len = 20;
  //  ASC
  int j, tmp;

  for(int i = 1; i < len; i++) {
    //  WARNING: 插入只能倒着来
    j = i;
    tmp = arr[i];
    while(j > 0 && tmp < arr[j-1]) {
      //  ATTENTION 若以arr[i]作判断标准则会出现arr[i]马上被覆盖的情况
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = tmp;
  }
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
 
  return 0;
}
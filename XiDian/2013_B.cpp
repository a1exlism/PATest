#include <cstdio>
//  送分 print frequency
//  9 8 5 1 7 2 8 2 9 10 1 7 8 9 5 6 9 0 1 9
const int num = 20;
int main() {
  int arr[20] = {0};
  int tmp;
  for(int i = 0; i < num; i++) {
    scanf("%d", &tmp);
    arr[tmp]++;
  }
  for(int i = 0; i < 11; i++) {
    printf("%d:%d\n", i, arr[i]);
  }
  return 0;
}
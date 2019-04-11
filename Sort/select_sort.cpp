#include <cstdio>
void swap(int &a, int &b);
int main() {
  int arr[20] = { 20, 46, 98, 38, 13, 66, 71, 92, 23, 90, 3, 74, 8, 88, 63, 73, 79, 19, 11, 28 };
  int len = 20;
  int maxI;
  for(int i = 0; i < len-1; i++) {
    maxI = i;
    for(int j = i+1 ; j < len; j++) {
      if(arr[maxI] < arr[j])
        maxI = j;
    }
    swap(arr[i], arr[maxI]);
  }
  for(int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
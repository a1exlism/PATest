#include <cstdio>
const int MAXN = 2000;
int main() {
  int a = 0,
      b = 0,
      i = 0,
      result[MAXN] = {0};
  int len = 0;
  int tmp = 0;
  bool isZero = true;
  //  无须腾出空格
  while(scanf("%d%d", &a, &b) != EOF) {
    if(b != 0) {
      result[i++] = a * b;
      result[i++] = b - 1;
      if(b-1 != 0) 
        isZero = false;
    }
  }
  if(isZero == true) {
    printf("0 0");
    return 0;
  }
  for(len = i, i = 0; i < len; i++) {
    printf("%d", result[i]);
    if(i < len-1) {
      printf(" ");
    } 
  }
  return 0;
}
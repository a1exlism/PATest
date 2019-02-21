//  数组循环右移
//  ATTENTION: 不使用辅助数组
#include <cstdio>
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  //  ATTENTION: 题干中需要M<N
  M %= N; 
  int str[N];
  int i, tmp;
  for(i = 0; i < N; i++) {
    if(M + i < N) {
      scanf("%d", str+i); 
    } else {
      scanf("%d", &tmp);
      printf("%d ", tmp);
    }
  }
  for(i = 0; i < N-M; i++) {
    printf("%d", str[i]);
    if(i < N-M-1) {
      printf(" ");
    }
  }
  return 0;
}
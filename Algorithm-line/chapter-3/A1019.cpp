/*
 * Unknown problem 3rd, why timeout?
 */
#include <cstdio>
#include <cmath>
const int MAXN = 100;
int main() {
  int N, b;
  int coes[MAXN] = {0},
      hl, ml, tmp;  //  hl: 最高次项, ml: mid index
  bool flag = true;
  scanf("%d %d", &N, &b);
  //  进制转换
  hl = 0;
  do {
    coes[hl++] = N % b;
    N /= b;
  } while(N);
  // printf("==%d==\n", hl);
  //  判断回文
  ml = hl / 2;
  --hl;
  for(int i = hl; i > -1; i--) {
    if(i < ml && coes[i] != coes[hl-i]) {
      flag = false;
    }
  }
  if(flag)
    printf("Yes\n");
  else
    printf("No\n");
  for(int i = hl; i > -1; i--) {
    printf("%d", coes[i]);
    if(i > 0)
      printf(" ");
  }
  return 0;
}
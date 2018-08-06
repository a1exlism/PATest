/**
 *  进制转换
 *  D进制转十进制
 **/
#include <cstdio>

int main() {
  int x, d, y, product = 1; //  product = d^0 d^1 D^2 ...
  y = 0;
  scanf("%d%d", &x, &d);
  while(x != 0) {
    y += (x % 10) * product; //  取最低位
    x /= 10;                 //  去掉最低位, 使line12被迫向上*d
    product *= d;
    printf("x: %d\n", x);
  }
  printf("%d", y);
  return 0;
}
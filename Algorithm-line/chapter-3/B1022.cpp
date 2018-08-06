/**
 *  D进制的A+B 
 * 
 *  十进制转化为D进制
 */
#include <cstdio>
int main() {
  int a, b, d, x, y[30] = {0};
  scanf("%d%d%d", &a, &b, &d);
  x = a + b;
  int i = 0;
  do {
    y[i++] = x % d;
    x = x / d;
  } while(x != 0);

  while(--i > -1) {
    printf("%d", y[i]);
  }
  return 0;
}

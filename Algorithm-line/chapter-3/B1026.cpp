/**
 * 程序运行时间
 * ATTENTION: math round函数一直用不来, 辣鸡
 * */
#include <cstdio>
const int CLK_TCK = 100;
int main() {
  int a, b;
  int h, m, s;
  scanf("%d %d", &a, &b);
  int t = (b - a + CLK_TCK / 2) / CLK_TCK;
  h = t / 3600;
  t -= h * 3600;
  m = t / 60;
  t -= m * 60;
  s = t;
  printf("%02d:%02d:%02d", h, m, s);
  return 0;
}
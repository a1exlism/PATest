#include <cstdio>
int main() {
  int a,b,m, d[32] = {0};
  int sum, i = 0;
  scanf("%d %d %d", &a, &b, &m);
  sum = a + b;
  if(!sum) i++;
  //  ATTENTION: 判0处理
  while(sum) {
    d[i++] = sum % m;
    sum /= m; 
  }
  do {
    printf("%d", d[--i]);
  } while(i > 0);
  return 0;
}
#include <cstdio>
//  A+B C
int main() {
  long long a, b, c;
  int times = 0;
  scanf("%d", &times);
  for(int i = 0; i < times; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a + b > c) {
      printf("Case #%d: true", i+1);
    } else {
      printf("Case #%d: false", i+1);
    }
    if(i < times-1) {
      printf("\n");
    }
  }
  return 0;
}
#include <cstdio>
//  A+B C
int main() {
  long long a, b, c, sum;
  int times = 0;
  bool flag = false;
  scanf("%d", &times);
  for(int i = 0; i < times; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    sum = a + b;
    if(a < 0 && b < 0 && sum >= 0) {
      //  下溢
      flag = false;
    } else if(a > 0 && b > 0 && sum <= -2) {
      //  上溢
      flag = true;
    } else if(sum > c) {
      flag = true;
    } else {
      flag = false;
    }
    if(flag) {
      printf("Case #%d: true\n", i+1);
    } else {
      printf("Case #%d: false\n", i+1);
    }
  }
  return 0;
}
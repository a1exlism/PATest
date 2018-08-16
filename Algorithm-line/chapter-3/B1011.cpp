/**
 *    A + B > C
 *    给定区间[-2^31, 2^31]内的3个整数A、B和C，请判断A+B是否大于C。 
 *    ATTENTION: Range
 * */
#include <cstdio>
int main() {
  int T = 0;
  long long a = 0, b = 0, c = 0;
  scanf("%d", &T);
  for(int i = 0; i < T; i++) {
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a + b > c) {
      printf("Case #%d: true", i+1);
    } else {
      printf("Case #%d: false", i+1); 
    }
    if(i != T-1) {
      printf("\n");
    }
  }
  return 0;
}
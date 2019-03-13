#include <cstdio>
#include <cmath>
int main() {
  int a, b, sum;
  scanf("%d %d", &a, &b);
  sum = a + b;
  if(sum < 0) {
    printf("-");
    sum = -sum;
  }
  int x2, x1, remainder;
  x2 = sum / pow(1000, 2);
  sum -= x2 * pow(1000, 2);
  x1 = sum / pow(1000, 1);
  remainder = sum % 1000;
  if(x2) {  //  sum >= 1,000,000
    printf("%d,", x2);
    printf("%03d,", x1);
    printf("%03d", remainder);
  } else if(x1){  //  1,000 <= sum < 1,000,000
    printf("%d,", x1);
    printf("%03d", remainder);
  } else {  //  sum < 1000
    printf("%d", remainder);
  }
  return 0;
}
#include <cstdio>
#include <cmath>
/**
 * 4 1 2 3 4
 * 5 1 2 3 4 5
 * 0
 */
bool isSu(int n);
int main() {
  int n, sum;
  int tmp;
  while(scanf("%d", &n) != EOF) {
    if(n == 0)
      break;
    sum = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &tmp);
      if(tmp == 1)  //  special
        continue;
      if(isSu(tmp)) {
        sum += tmp;
      }
    }
    printf("%d\n", sum);
  }
  return 0;
}

bool isSu(int n) {
  int sqrtn = sqrt(n);
  bool flag = true;
  for(int i = 2; i <= sqrtn; i++) {
    if(n % i == 0) {
      flag = false;
      break;
    }
  }
  return flag;
}
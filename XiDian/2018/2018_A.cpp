#include <cstdio>
//  1 1 2 2 2 1 1 2 2 0 : 22
//  2 0 : 2
//  1 2 2 : 7
int main() {
  int sum = 0;
  int tmp, pre, add;
  bool isFirst = true;
  add = 2;  //  累计; init: 2
  while(scanf("%d", &tmp) != EOF) {
    if(tmp == 0) break;
    if(tmp == 2) {
      if(pre == 1 || isFirst == 1) {
        sum+= add;
      } else {
        add += 2;
        sum+= add;
      }
    } else {
      sum++;
      add = 2;  //  re-init
    }
    pre = tmp;
    isFirst = false;
  }
  printf("%d", sum);
  return 0;
}
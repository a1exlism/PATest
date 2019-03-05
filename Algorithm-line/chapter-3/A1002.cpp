#include <cstdio>
const int MAXN = 1001;
int main() {
  float terms[MAXN] = {0},
      an;  //  single term
  int n = 0,
      num = 0,
      count = 0; // 系数非零项
  int i = 0;
  scanf("%d", &num);
  for(i = 0; i < num; i++) {
    scanf("%d %f", &n, &an);
    terms[n] = an;
  }
  count = num;
  scanf("%d", &num);
  for(i = 0; i < num; i++) {
    scanf("%d %f", &n, &an);
    if(terms[n] == 0)
      count++;
    terms[n] += an;
    if(terms[n] == 0)
      count--;
  }
  printf("%d", count);
  //  MAXN的原因: 最高次 >= count
  for(i = MAXN; i > -1; i--) {
    if(terms[i] == 0)
      continue;
    //  输出格式错误: 需要考虑count=0的情况
    printf(" %d %.1f", i, terms[i]);
  }
  return 0;
}
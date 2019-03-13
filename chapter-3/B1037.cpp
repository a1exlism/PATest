#include <cstdio>
int get_sum (int g, int s, int k);
int main() {
  //  i 应付 | o 本金
  int i_g, i_s, i_k, i_sum,
      o_g, o_s, o_k, o_sum;
  int sum, g, s, k;
  scanf("%d.%d.%d", &i_g, &i_s, &i_k);
  scanf("%d.%d.%d", &o_g, &o_s, &o_k);
  i_sum = get_sum(i_g, i_s, i_k);
  o_sum = get_sum(o_g, o_s, o_k);
  if(i_sum > o_sum) {
    printf("-");  //  unaffordable
    sum = i_sum - o_sum;
  } else {
    sum = o_sum - i_sum;
  }
  g = sum / (17 * 29);
  sum %= (17 * 29);
  s = sum / 29;
  k = sum % 29;
  printf("%d.%d.%d", g, s, k);
  return 0;
}

int get_sum (int g, int s, int k) {
  int sum = (g * 17 + s) * 29 + k;
  return sum;
}
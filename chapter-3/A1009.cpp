#include <cstdio>
const int MAXN = 1001;
int main() {
  //  anX^n
  double terms[MAXN*2] = {0},
         an = 0;
  struct termsa {
    int n;
    double an;
  }terms_a[MAXN];
  int i = 0,
      n = 0,
      num_a = 0, num_b = 0,
      count = 0;
  scanf("%d", &num_a);
  for(i = 0; i < num_a; i++) {
    scanf("%d%lf", &(terms_a[i].n), &(terms_a[i].an));
  }
  scanf("%d", &num_b);
  for(i = 0; i < num_b; i++) {
    scanf("%d%lf", &n, &an);
    //  product
    for(int j = 0; j < num_a; j++) {
      terms[terms_a[j].n + n] += terms_a[j].an * an;
      // printf("%1f\n",terms_a[j].an * an);
    }
  }
  //  get total counts
  for(i = 0; i < MAXN*2; i++) {
    if(terms[i] != 0)
      count++;
    // printf("==%d==", count);
  }
  printf("%d", count);
  for(i = MAXN*2-1; i > -1; i--) {
    if(terms[i] != 0)
      printf(" %d %.1f", i, terms[i]);
  }
  return 0;
}
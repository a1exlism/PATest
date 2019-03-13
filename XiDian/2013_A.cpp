#include <cstdio>
//  Simple
//  fibonachi X%3 == 0
//  input: 0 1 2
int fi(int n);
int main() {
  int N, n, sum;
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &n);
    sum = fi(n);
    if(sum % 3 == 0) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}

int fi(int n) {
  if(n == 0) {
    return 7;
  }
  if(n == 1) {
    return 11;
  }
  return fi(n-1) + fi(n-2);
}
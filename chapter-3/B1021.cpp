#include <cstdio>
const int MAXN = 1001;
int main() {
  char n[MAXN];
  scanf("%s", n);
  int res[10] = {0};
  for(int i = 0; n[i] != '\0'; i++) {
    res[(int)(n[i] - '0')]++;
  }
  for(int i = 0; i < 10; i++) {
    if(res[i] == 0) continue;
    printf("%d:%d\n", i, res[i]);
  }
  return 0;
}
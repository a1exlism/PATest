#include <cstdio>
int main() {
  //  B:百 S:十 g:个
  int s[2] = {'B', 'S'};
  int x, bn, sn, g;
  int i = 0;
  scanf("%d", &x);
  bn = x / 100;
  sn = (x % 100) / 10;
  g = x % 10;
  for(i = 0; i < bn; i++)
    printf("%c", s[0]);
  for(i = 0; i < sn; i++)
    printf("%c", s[1]);
  for(i = 0; i < g; i++)
    printf("%d", i+1);
  return 0;
}
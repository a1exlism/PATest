#include <cstdio>
int main () {
  char dict[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  printf("#");
  printf("%c%c", dict[r / 13], dict[r % 13]);
  printf("%c%c", dict[g / 13], dict[g % 13]);
  printf("%c%c", dict[b / 13], dict[b % 13]);
  return 0;
}
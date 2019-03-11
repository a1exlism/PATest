#include <cstdio>
#include <cstring>
void rprint(int n);
const char dict[10][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
int main() {
  char str[1000];
  int sum;
  fgets(str, sizeof(str), stdin);
  str[strlen(str)-1] = '\0';
  for(int i = 0; str[i] != '\0'; i++)
    sum += (str[i] - '0');
  // printf("%d\n", sum);
  rprint(sum);
  return 0;
}

void rprint(int n) {
  int r = n / 10;
  if(r == 0) {
    printf("%s", dict[n]);
    return;
  }
  rprint(r);
  printf(" %s", dict[n % 10]);
}
#include <cstdio>
const int MAXN = 10000;
int main() {
  char num[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
  char str[MAXN];
  int sum = 0, res[100] = {0};
  scanf("%s", str);
  int i = 0;
  while(str[i] != '\0') {
    sum = sum + (str[i] - '0');
    i++;
  }
  // printf("==SUM: %d==\n", sum);
  //  split
  i = 0;
  do {
    res[i++] = sum % 10;
    sum /= 10;
  } while(sum);
  //  translate
  for(int j = i-1; j > -1; j--) {
    printf("%s", num[res[j]]);
    if(j > 0) {
      printf(" ");
    }
  }
  return 0;
}
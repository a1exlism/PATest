#include <cstdio>
#include <cstring>
int main() {
  char dict[10][8] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight","nine"};
  char tmp[10000];
  int sum, len;
  int sumarr[1000];
  len = 0;
  fgets(tmp, sizeof(tmp), stdin);
  tmp[strlen(tmp)-1] = '\0';
  for(int i = 0; tmp[i] != '\0';i++)
    sum = sum + tmp[i] - '0';
  do {
    sumarr[len++] = sum % 10;
    sum /= 10;
  } while(sum);
  for(int j = len-1; j > -1; j--) {
    printf("%s", dict[sumarr[j]]);
    if(j > 0)
      printf(" ");
  }
  return 0;
}
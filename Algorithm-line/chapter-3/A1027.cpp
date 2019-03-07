#include <cstdio>
int main() {
  //  radix 10 -> 13
  char dict[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
  int eno, i;
  char mno[3];
  mno[2] = '\0'; 
  printf("#");
  while(scanf("%d", &eno) != EOF) {
    i = 1;
    do {
      mno[i--] = dict[eno % 13];
      eno /= 13;
    } while(eno);
    printf("%s", mno);
  }
  return 0;
}
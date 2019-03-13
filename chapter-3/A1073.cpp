#include <cstdio>
const int MAXN = 10000;
int main() {
  char sign1, sign2, num[MAXN];
  int exp;
  int i = 1, fnum;
  //  Scanf
  scanf("%c%c.", &sign1, num+0);
  // printf("NUM:==%c==\n", num[0]);
  while(scanf("%c", num+i) != EOF) {
    if(num[i] == 'E') {
      scanf("%c%d", &sign2, &exp);
      break;
    }
    i++;
  }
  // printf("NUM:==%c==\n", num[1]);
  fnum = i; //  E之前的位数
  //  Printf
  if(sign1 == '-') printf("%c", sign1);
  if(exp == 0) {
    printf("%c.", num[0]);
    for(int j = 1; j < fnum; j++) {
      printf("%c", num[j]);
    }
    return 0;
  }
  if(sign2 == '-') {
    //  3.14E-05 3.14E-01
    printf("0.");
    for(int j = 1; j < exp; j++) {
      printf("0");
    }
    // printf("==%d==", fnum);
    for(int j = 0; j < fnum; j++) {
      printf("%c", num[j]);
    }
  } else {
    //  +3.14E+05 +3.14E+01:测试点4
    int diff = (fnum - 1) - exp;
    if(diff < 0) {
      diff = -diff;
      for(int j = 0; j < fnum; j++) {
        printf("%c", num[j]);
      }
      for(int j = 0; j < diff; j++)
        printf("0");
    } else {
      for(int j = 0; j <= exp; j++)
        printf("%c", num[j]);
      if(diff != 0)
        printf(".");
      for(int j = exp+1; j < fnum; j++)
        printf("%c", num[j]);
    }
  }
  return 0;
}
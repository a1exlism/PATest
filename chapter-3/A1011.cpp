#include <cstdio>
int main() {
  struct Bet {
    char name;
    float odd;
    Bet() {
      name = 'W';
      odd = 1.0;
    }
  } bet[3];
  float w, t, l;
  float max_sum = 1;
  for(int i = 0; i < 3; i++) {
    scanf("%f %f %f", &w, &t, &l);
    bet[i].odd = w;
    if(t > bet[i].odd) {
      bet[i].odd = t;
      bet[i].name = 'T';
    }
    if(bet[i].odd < l) {
      bet[i].odd = l;
      bet[i].name = 'L';
    }
  }
  for(int i = 0; i < 3; i++) {
    printf("%c ", bet[i].name);
    max_sum *= bet[i].odd;
  }
  printf("%.2f", (max_sum * 0.65 -1) * 2);
  return 0;
}

//  BETTER: 每三次输入得出W/T/L, 得到最大值max_single
//  ATTENTION: UNKNOWN PROBLEM 19'
#include <cstdio>
int main() {
  float results[5] = {0};
  int len = 0,
      num = 0,
      remain = 0,
      A2order = 0,
      A3num = 0;

  scanf("%d", &len);
  //  MOD
  for(int i = 0; i < len; i++) {
    scanf("%d", &num);
    remain = num % 5;
    switch (remain)
    {
      case 0:
        if(num %2 == 0) 
          results[0] += num;
        break;
      case 1:
        if(A2order++ %2 == 0)
          results[1] += num;
        else
          results[1] -= num;
        break;
      case 2:
        results[2] ++;
        break;
      case 3:
        results[3] += num;
        A3num ++;
        break;
      case 4:
        if(results[4] < num)
          results[4] = num;
        break;
      default:
        break;
    }
  }
  for(int i = 0; i < 5; i++) {
    if(results[i] == 0) {
      printf("N");
    } else if(i == 3){
      results[3] /= A3num;
      printf("%.1f", results[3]);
    } else {
      printf("%d", (int)results[i]);
    }
    if(i < 4) {
      printf(" ");
    }
  }
  return 0;
}
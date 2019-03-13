#include <cstdio>
#include <cstring>
/*
 * input1: a5b3aba13b4
 * input2: a2b3aba13b4
 */

int main() {
  char str[50];
  scanf("%s", str);
  char repeat;
  int len, tmp;
  int dur, endIndex;  //  连续数
  len = strlen(str);
  for(int i = 0; i < len; i++) {
    tmp = str[i] - '0';
    if(tmp < 10 && tmp > -1) {  //  num
      char nextC = str[i+1];
      if(tmp < 3 && (nextC < '0' || nextC > '9')) {
        printf("%d", tmp);  //..小于3不压缩
        continue;
      }
      repeat = str[i-1];
      endIndex = i+1;
      dur = tmp;
      while(str[endIndex] <= '9' && str[endIndex] >= '0') {
        dur = dur*10 + str[endIndex] - '0';
        endIndex++;
      }
      for(int j = 1; j < dur; j++) {  //  已经输出过一个, 所以-1
        printf("%c", repeat);
      }
      i = endIndex-1; //  for的原因 需要-1
    } else {
      printf("%c", str[i]);
      dur = 0;
    }
  }
  
  return 0;
}
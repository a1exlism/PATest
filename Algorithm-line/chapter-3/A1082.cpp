#include <cstdio>
#include <cstring>
const char dict[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const char wei[5][5] = { "Shi", "Bai", "Qian", "Wan", "Yi"};
int main() {
  char val[15];
  int left, right, len;
  scanf("%s", val);
  len = strlen(val);
  left = 0, right = len - 1;
  if (val[0] == '-')
  {
    printf("Fu");
    left++;
  }
  //  特例: single one
  if(left == right) {
    //  ATTENTION: val为char格式
    printf("%s", dict[val[right]-'0']);
    return 0;
  }
  while (left + 4 <= right)
  {
    right -= 4;
  }
  int zeros;
  bool gotZero; //  至少前一位为0
  while (left < len) { //  Every Signle 4 group
    zeros = 0;
    gotZero = 0;
    while (left <= right) {
      // printf("\n==%c", val[left]);
      if (val[left] == '0') {
        gotZero = 1;
        zeros++;
      } else {
        if(gotZero) {
          printf(" %s", dict[0]); 
          gotZero = 0;
        }
        //  Normal number output
        if(left > 0) {
          printf(" ");
        } 
        printf("%s", dict[val[left]-'0']); 
        if(left < right) {
          // printf("\n--: %d", right-left-1);
          printf(" %s", wei[right-left-1]); 
        }
      }
      left++;
    }
    //  Yi 0|3 / Wan 4|7
    int xi = (len-1-right)/4;
    
    if(0 < xi && zeros < 4) {
      // printf("\n++: %d", xi+3);
      printf(" %s", wei[xi+2]); 
    }
    right += 4;
  }
  return 0;
}
/**
 * 部分A+B
 * 这里似乎没有遇到题目中的long long值问题
 * */
#include <cstdio>

int main() {
  int A, a, B, b;
  int sum_A = 0;
  int sum_B = 0;
  scanf("%d %d %d %d", &A, &a, &B, &b);
  
  while(A != 0) {
    //  取最低位
    if(A % 10 == a) {
      sum_A = sum_A * 10 + a;
    }
    //  去最低位
    A /= 10;
  }
  while(B != 0) {
    //  取最低位
    if(B % 10 == b) {
      sum_B = sum_B * 10 + b;
    }
    //  去最低位
    B /= 10;
  }
  printf("%d", sum_A + sum_B);
  return 0;
}
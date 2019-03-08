#include <cstdio>
int main() {
  char str1[20] = "555", str2[20];
  int  num1, num2 = 666;
  //  sscanf    从左到右 ->
  sscanf(str1, "%d", &num1);
  //  sprintf   从右到左 <-
  sprintf(str2, "%d", num2);

  printf("str1: %s, num1: %d\n", str1, num1);
  printf("str2: %s, num2: %d", str2, num2);
  return 0;
}
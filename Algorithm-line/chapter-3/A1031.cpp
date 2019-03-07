#include <cstdio>
#include <cstring>
int main() {
  int n1, n2, len, tmp;
  char str[90];
  scanf("%s", str);
  for(len = 0; str[len] != '\0'; len++) ;
  //  get n1=n3 and n2
  for(n1 = 1; n1 <= n2; n1++) {
    tmp = len + 2 - 2 * n1;
    //  ATTENTION: 这里与前一题B1027一样, 需要后悔
    if(n1 > tmp)
      break;
    n2 = tmp;
    // printf("==%d==\n", n2);
  }
  char gap[n2-2];
  int i;
  for(i = 0; i < n2 - 2; i++ ) {
    gap[i] = ' ';
  }
  gap[i] = '\0';    // ATTENTION: string 赋值需要添加\0来作结尾
  n1 = (len + 2 - n2) / 2;
  // printf("--%d--\n", n1);
  //  0-n1-1
  for(i = 0; i < n1-1; i++) {
    printf("%c%s%c\n", str[i], gap, str[len-1-i]);
  }
  for(i = 0; i < n2; i++) {
    printf("%c", str[n1-1+i]);
  }
  return 0;
}
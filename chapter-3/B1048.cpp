#include <cstdio>
#include <cstring>
void reverse(char str[], int len);
int main() {
  char dict[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
  char str1[101], str2[101], str[202];
  scanf("%s %s", str1, str2);
  int len1 = strlen(str1),
      len2 = strlen(str2);
  int n = 0;
  //  reverse string
  reverse(str1, len1);
  reverse(str2, len2);
  int i, a, b;
  for(i = 0; i < len1 || i < len2; i++) {
    a = i < len1 ? str1[i] - '0' : 0;
    b = i < len2 ? str2[i] - '0' : 0;
    if((i+1) % 2 == 1) {  //  Odd
      str[n++] = dict[(a+b)%13];
    } else {
      str[n++] = (b-a+10)%10 + '0';
    }
  }
  /* WARNING: 比较奇怪, 单独写出来之后测试点5没有通过
  if(i == len1) { //  B more
    while(i < len2)
      str[n++] = str2[i++];
  } else {  //  A more
    while(i < len1) {
      if((i+1) % 2 == 1) {
        str[n++] = str1[i++];
      } else {
        str[n++] = 10-(str1[i++]-'0') + '0';
      }
    }
  }
  */
  str[n] = '\0';
  reverse(str, strlen(str));
  printf("%s", str);
  return 0;
}
void reverse(char str[], int len) {
  char tmp;
  for(int i = 0; i < len / 2; i++) {
    tmp = str[i];
    str[i] = str[len-1-i];
    str[len-1-i] = tmp;
  }
  // printf("%s\n", str);
}
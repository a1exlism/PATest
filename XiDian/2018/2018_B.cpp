#include <cstdio>
#include <cstring>
//  字符串匹配, 暴力
const int MAXN = 100;
void str_trans(char str[], int len);
int main () {
  char str1[MAXN], str2[MAXN];
  int same_num, tmp;
  int len1, len2, len;
  fgets(str1, MAXN, stdin);
  len1 = strlen(str1)-1;
  str1[len1] = '\0';
  fgets(str2, MAXN, stdin);
  len2 = strlen(str2)-1;
  str2[len2] = '\0';
  len = len1+len2;

  //  set same format
  str_trans(str1, len1);
  str_trans(str2, len2);
  
  //  MAX Same str num 暴力算法
  same_num = -1;
  for(int i = 0; i < len1; i++) {
    tmp = 0;  //  init
    for(int j = 0; j < len2; j++) {
      if(str1[j+i] != str2[j])
        break;
      tmp++;  //  完全一致的情况
    }
    if(same_num < tmp)
      same_num = tmp;
  }
  printf("%.0f%%", (float)(same_num*2*100/len));
  return 0;
}

void str_trans(char str[], int len) {
  //  统一小写
  for(int i = 0; i < len; i++) {
    if(str[i] <= 'Z' && str[i] >= 'A') {
      str[i] = str[i] - 'A' + 'a';
    }
  }
}
/**
 *  回文串
 **/
#include <cstdio>
#include <cstring>
int main() {
  char str[255] = "";
  scanf("%s", str);
  int str_len = 0;
  str_len = strlen(str);
  //  ATTENTION: 这里的length为humable, /2之后至少为中值
  for(int i = 0; i < str_len/2; i++) {
    if(str[i] != str[str_len-1-i]) {
      printf("NO");
      return 0;
    }
  }
  printf("YES"); 
  return 0;
}
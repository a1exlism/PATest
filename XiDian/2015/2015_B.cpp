#include <cstdio>
#include <cstring>
/**
 * SDFJSLDGIOERTDNJNKSHJNDKABHBSDHCASBABSDCABCABC 
 * ABCABCCCBACC
 */
const int MAXN = 1001;
int main() {
  int narr[26] = {0};
  char str[MAXN];
  int len;
  scanf("%s", str);
  len = strlen(str);
  int tmpIndex;
  for(int i = 0; i < len; i++) {
    tmpIndex = str[i]-'A';
    narr[tmpIndex] ++;
  }
  //  output
  for(int i = 0; i < 26; i++) {
    if(narr[i] != 0) {
      printf("%c%d", (char)('A'+i), narr[i]);
    }
  }
  return 0;
}
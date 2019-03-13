#include <cstdio>
#include <cstring>
int get_common_index(char str1[], char str2[]);
void reverse(char str[]);
const int MAXN = 270;
int main() {
  //  Find Common Suffix
  int N;
  char newstr[MAXN], comstr[MAXN];
  scanf("%d", &N);
  getchar();  //  WARNING 消除\n
  fgets(comstr, MAXN, stdin);
  comstr[strlen(comstr)-1] = '\0';
  reverse(comstr);
  int last_common_index = 0;
  for(int i = 1; i < N; i++) {
    fgets(newstr, MAXN, stdin);
    newstr[strlen(newstr)-1] = '\0'; 
    reverse(newstr);
    last_common_index = get_common_index(comstr, newstr);
    //  WARNING 每次更新common index
    comstr[last_common_index+1] = '\0';
    // printf("\n=%d th=Common_Str: %s==", i, comstr);
  }
  int final_index = 0;
  if(comstr[0] == '\0') {
    printf("nai");
  } else {
    reverse(comstr);
    printf("%s", comstr);
  }
  return 0;
}

int get_common_index(char str1[], char str2[]) {
  //  返回相同的最后一个index
  int len1 = strlen(str1),
      len2 = strlen(str2);
  int i, x = 0;
  for(i = 0; i < len1 && i < len2; i++) {
    if(str1[i] != str2[i]) {
      x = i;
      break;
    }
  }
  x = i - 1;
  return x;
}

void reverse(char str[]) {
  // printf("==Before: %s==\n", str);
  int len = strlen(str);
  char tmp;
  for(int i = 0; i < len / 2; i++) {
    tmp = str[i];
    str[i] = str[len-1-i];
    str[len-1-i] = tmp;
  }
  // printf("==After: %s==\n", str);
}
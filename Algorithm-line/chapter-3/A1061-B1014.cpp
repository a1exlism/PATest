#include <cstdio>
int main() {
  char str[100];
  int i = 0, count = 0,
      pos[80] = {-1};
  //  init
  pos[count++] = 0;
  while(scanf("%c", str+i) != EOF) {
    if(str[i] == ' ') {
      pos[count++] = i+1;
      // printf("--%d--\n", i-1);
    }
    i++;
  }
  int tmp = 0;
  printf("==Count: %d==\n", count-1);
  for(int j = count-1; j > -1; j--) {
    tmp = pos[j];
    // printf("==%d==\n", tmp);
    while(str[tmp] != ' ' && str[tmp] != '\n') {
      printf("%c", str[tmp++]);
    }
    if(j > 0) printf(" ");
  }
  
  return 0;
}
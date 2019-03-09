/**
 *  说反话
 *  words reverse
 *          ATTENTION: while 能不用就不用, 坑爹
 *          2018+ : gets函数无法使用, 改用fgets
 **/

#include <cstdio>
#include <cstring>
int main()
{
  char str[500];    //  既定内存可以更大, 一开始的100提示partitial accept
  char str_arr[50][50];
  int j = 0, k = 0;
  // gets(str);
  fgets(str, sizeof(str), stdin);
  str[strlen(str)-1] = '\0';

  for(int i = 0; str[i] != '\0'; i++) {
    if(str[i] != ' ') {
      str_arr[j][k++] = str[i];
    } else {
      //  TODO: Close the string
      str_arr[j][k] = '\0';
      //  ATTENTION: Re-initial
      j++;
      k = 0;
    }
  }

  /** BAD circulation **/
  // while(str[i] != '\0') {
  //   if(str[i] == ' ') {
  //     str_arr[j][k] = '\0';
  //     j++;
  //     k = 0;
  //     i++;
  //   } else {
  //     str_arr[j][k++] = str[i++];
  //   }
  // }


  while(j > 0) {
    printf("%s ", str_arr[j--]);
  }
  printf("%s", str_arr[j]);

  return 0;
}

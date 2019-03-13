#include <cstdio>
int main() {
  //  输出**有问题**的号码
  char checksum[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
  int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
  int num, sum, i;
  char id[19];
  bool allpass = true;
  scanf("%d", &num);
  for(int j = 0; j < num; j++) {
    scanf("%s", id);
    //  0. init
    id[18] = '\0';
    sum = 0;
    //  WARNING downbelow
    for(i = 0; i < 17; i++) {
      if(id[i] < '0' || id[i] > '9') break;
      sum = sum + weight[i] * (id[i] - '0');
    }
    if(i < 17 || checksum[sum % 11] != id[17]) {
      //  un-number 非法 17th char
      printf("%s\n", id);
      allpass = false;
    } 
  }
  if(allpass) printf("All passed");
  return 0;
}
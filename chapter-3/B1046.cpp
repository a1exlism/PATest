//  划拳 中文理解0分...
#include <cstdio>
int main() {
  int round_all,
    ya, yb, //  yell
    ha, hb; //  hands
  int win_1 = 0,
      win_2 = 0;
  scanf("%d", &round_all);
  int i = 0, sum = 0;
  while(i++ < round_all) {
    scanf("%d %d %d %d", &ya, &ha, &yb, &hb);
    sum = ya + yb;
    if(ha == sum && hb != sum)  win_1++;
    if(hb == sum && ha != sum)  win_2++; 
  }
  printf("%d %d", win_2, win_1);
  return 0;
}
#include <stdio.h>
//  此题也可以先把所有数据全部录入, 之后进行合法性判断和yId,oId查询
int main() {
  typedef struct User
  {
    char name[20];
    long long age;
    User() {
      age = 0;
    }
  } User;
  int num,
      yId = 0, oId = 0,
      y,m,d,
      count = 0;
  long long youngest = 20140907,
            oldest   = 18140905,
            tmp;
  scanf("%d", &num);
  User users[num];
  for(int i = 0; i < num; i++) {
    scanf("%s %d/%d/%d", users[i].name, &y, &m, &d);
    //  BETTER: 这个方式用来比较age, 极好的!
    tmp = y * 10000 + m * 100 + d;
    // printf("%lld\n", tmp);
    if(oldest < tmp && tmp < youngest) {
      count++;
      users[i].age = tmp;
      if(users[yId].age == 0) {
        yId = i;
        continue;
      }
      if(users[oId].age == 0) {
        oId = i;
        continue;
      }
      if(users[oId].age > tmp)
        oId = i;
      if(users[yId].age < tmp)
        yId = i;
    }
  }
  if(count == 0) {
    //  极端情况
    printf("0");
  } else {
    printf("%d %s %s", count, users[oId].name, users[yId].name);
  }
  return 0;
}
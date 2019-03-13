#include <cstdio>
const int MAXN = 1001;
bool check(char pass[]);
int main() {
  struct Team {
    char name[11];
    char pass[11];
  } teams[MAXN];
  int failid[MAXN];
  int num, len;
  bool res = true;
  len = 0;
  scanf("%d", &num);
  for(int i = 0; i < num; i++) {
    scanf("%s %s", teams[i].name, teams[i].pass);
    res = check(teams[i].pass);
    if(!res) {  //  with issue
      failid[len++] = i;
    }
  }
  if(len == 0) {
    if(num == 1) {
      printf("There is 1 account and no account is modified");
    } else {
      printf("There are %d accounts and no account is modified", num);
    }
  } else {
    printf("%d\n", len);
    for(int i = 0; i < len; i++) {
      printf("%s %s\n", teams[failid[i]].name, teams[failid[i]].pass);
    }
  }
  return 0;
}

bool check(char pass[]) {
  //  check && rebuild
  bool flag = true;
  char x;
  for(int i = 0; pass[i] != '\0'; i++) {
    x = pass[i];
    switch(x) {
      case '1':
        pass[i] = '@';
        flag = false;
        break;
      case 'l':
        pass[i] = 'L';
        flag = false;
        break;
      case '0':
        pass[i] = '%';
        flag = false;
        break;
      case 'O':
        pass[i] = 'o';
        flag = false;
        break;
    }
  }
  return flag;
}
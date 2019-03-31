#include <cstdio>
#include <algorithm>
using namespace std;
//  读文件
const int MAXN = 1000;
typedef struct {
  char id[21];
  int num;  //  做对题数
  int score;
} Grade;
bool cmp1(Grade a, Grade b);
bool cmp2(Grade a, Grade b);
int main() {
  Grade grade[MAXN];
  FILE *fp;
  fp = fopen("Score.txt", "r");
  int i = 0;
  while(fscanf(fp, "%s %d %d", grade[i].id, &grade[i].num, &grade[i].score) != EOF)
    i++;
  int len = i;
  sort(grade, grade+len, cmp1);
  sort(grade, grade+len, cmp2);
  for(int i = 0; i < len; i++) {
    printf("%s %d %d\n", grade[i].id, grade[i].num, grade[i].score);
  }
  fclose(fp); //  WARNING: don't forget close the file
  return 0;
}

bool cmp1(Grade a, Grade b) {
  if(a.num > b.num)
    return true;
  else
    return false;
}

bool cmp2(Grade a, Grade b) {
  if(a.score > b.score)
    return true;
  else
    return false;
}
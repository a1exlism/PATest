#include <cstdio>
int main() {
  int n = 0;
  typedef struct{
    char name[15];
    char no[15];
    int score;
  } Student;

  //  BETTER: 设计一个最外边界就不需要init判断了
  int max = -1, maxId = 0,
      min = 101, minId = 0;
  scanf("%d", &n);
  Student stu[n];
  for(int i = 0; i < n; i++) {
    scanf("%s %s %d", stu[i].name, stu[i].no, &stu[i].score);
    if(max < stu[i].score) {
      max = stu[i].score;
      maxId = i;
    }
    if(min > stu[i].score) {
      min = stu[i].score;
      minId = i;
    }
  }
  printf("%s %s\n", stu[maxId].name, stu[maxId].no);
  printf("%s %s", stu[minId].name, stu[minId].no);
  return 0;
}
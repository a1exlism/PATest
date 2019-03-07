#include <cstdio>
int main() {
  //  difference between 
  //  the lowest grade of all the male students
  //  the highest grade of all the female students.
  const int MAXN = 1000;
  struct Stu {
    char name[20];
    char genda;
    char id[20];
    int score;
  } stu[MAXN]; //  0-F 1-M
  int min_M = 101, mi = -1,
      max_F = -1, fi = -1,   //  gradeF ​​ −gradeM
      num = 0;
  scanf("%d", &num);
  for(int i = 0; i < num; i++) {
    scanf("%s %c %s %d", stu[i].name, &stu[i].genda, stu[i].id, &stu[i].score);
    // printf("==%c %d==\n", stu[i].genda, stu[i].score);
  }
  for(int i = 0; i < num; i++) {
    if(stu[i].genda == 'F' && stu[i].score > max_F) {
      fi = i;
      max_F = stu[i].score;
    }
    if(stu[i].genda == 'M' && stu[i].score < min_M)  {
      mi = i;
      min_M = stu[i].score;
    }
  }
  if(mi != -1 && fi != -1) {
    printf("%s %s\n", stu[fi].name, stu[fi].id);
    printf("%s %s\n", stu[mi].name, stu[mi].id);
    printf("%d", max_F - min_M);
  } else {
    if(mi == -1) {
      printf("%s %s\n", stu[fi].name, stu[fi].id);
      printf("Absent\nNA");
    } else {
      printf("Absent\n");
      printf("%s %s\nNA", stu[mi].name, stu[mi].id); 
    }
  }
  
  return 0;
}
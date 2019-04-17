#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int NUM = 20;
typedef struct {
  char ID[20];
  int grade;
  int rank;
} Stu;

bool cmp(Stu a, Stu b);

int main()
{
  int arr[NUM] = {73, 68, 80, 85, 73, 74, 33, 49, 74, 90, 23, 22, 1, 0, 57, 11, 27, 35, 60, 45};
  Stu stu[NUM];
  for(int i = 0; i < NUM; i++) {
    sprintf(stu[i].ID, "Std_NO.%03d", i+1);
    stu[i].grade = arr[i];
    stu[i].rank = -1;
  }
  //  Ranking RULES: same grade for same rank
  sort(stu, stu+NUM, cmp);
  //  * init
  int samenum = 0;
  stu[0].rank = 1;
  for(int i = 1; i < NUM; i++) {
    if(stu[i].grade == stu[i-1].grade)
      samenum ++;

    stu[i].rank = 1+i-samenum;  //  rank from 1
  }

  for(int i = 0; i < NUM; i++) {
    printf("No: %2d | ID: %s | Grades: %2d | Rank: %d\n", i+1, stu[i].ID, stu[i].grade, stu[i].rank);
  }
  return 0;
}

//  as front.grade > later.grade ORDER
bool cmp(Stu a, Stu b) {
  return a.grade > b.grade;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//  CHECKed 1. Rank method, correct
//  CHECKed 2. ID sort prob REAL PROB
const int MAXNUM = 30001;
typedef struct {
  //  ATTENTION: last 3'. You Can't use longlong OR double to compare. Not know so far.
  // double id;
  char id[15];
  int grade;
  int f_rank;
  int g_id;
  int g_rank;
} Stu;

bool cmp(Stu a, Stu b);

int main() {
  int N, K, len, duplicate_num;
  Stu stu[MAXNUM];
  len = 0;
  duplicate_num = 0;
  scanf("%d", &N);
  for(int i = 0, _i = 0; i < N; i++) {
    scanf("%d", &K);
    for(int j = 0; j < K; j++) {
      _i = len+j;
      // scanf("%s %d", stu[_i].id, &stu[_i].grade);
      scanf("%s %d", stu[_i].id, &stu[_i].grade);
      stu[_i].g_id = i+1;  //  group from 1
    }
    sort(stu+len, stu+len+K, cmp);

    /* == For Group Rank == */
    //  init
    stu[len].g_rank = 1;
    duplicate_num = 0;
    for(int j = len+1; j < len+K; j++) {
      if(stu[j-1].grade == stu[j].grade) {
        stu[j].g_rank = stu[j-1].g_rank;
        duplicate_num++;
      } else {
        stu[j].g_rank = stu[j-1].g_rank + 1 + duplicate_num;
        duplicate_num = 0;  //  RE-init
      }
    }

    len += K;
  }

  printf("%d\n", len);
  sort(stu, stu+len, cmp);
  
  duplicate_num = 0;

 
  /* == For Final Rank == */
  duplicate_num = 0;
  for(int i = 0; i < len; i++) {
    if(i == 0) {
      stu[i].f_rank = 1; 
    } else {
      if(stu[i-1].grade == stu[i].grade) {
       stu[i].f_rank = stu[i-1].f_rank;
       duplicate_num ++;
      } else {
       stu[i].f_rank = stu[i-1].f_rank + 1 + duplicate_num;
       duplicate_num = 0;
      }
    }
    printf("%s %d %d %d\n", stu[i].id, stu[i].f_rank, stu[i].g_id, stu[i].g_rank);
    // printf("%0.f %3d %2d Group: %2d %2d\n", stu[i].id, stu[i].grade, stu[i].f_rank, stu[i].g_id, stu[i].g_rank);
  }
  return 0;
}

bool cmp(Stu a, Stu b) {
  if(a.grade == b.grade) {
    return strcmp(a.id, b.id) < 0;
    // return a.id < b.id;
  } else {
    //  WARNING: 审题不仔细 -6'
    return a.grade > b.grade;
  }
}
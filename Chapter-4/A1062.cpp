#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
//  ATTENTION: WHAT?? const int MAXN = 99999; 运行时错误, 可明明在10^5内啊
typedef struct {
  int id;
  int talent;
  int virtue;
  int fgrade;
  int order;
} People;
bool cmp (const People a, const People b);
int main() {
  int N, L, H;
  scanf("%d %d %d", &N, &L, &H);
  People men[MAXN];
  int id, tv, tt, no, order;
  no = 0;
  for(int i = 0; i < N; i++) {
    scanf("%d %d %d", &id, &tv, &tt);
    //  only the ones whose grades of talent and virtue
    //  are both not below this line(L) will be ranked;
    if(tv < L || tt < L) continue;
    //  Classify
    if(tv >= H && tt >= H) {
      //  sages
      order = 0;
    } else if (tv >= H) {
      //  noblemen
      order = 1;
    } else if (tv < H && tt < H && tv >= tt) {
      //  fool men
      // printf("\ntriger");
      order = 2;
    } else {
      //  others
      order = 3;
    }
    // printf("==tv: %d; tt: %d; order: %d==\n", tv, tt, men[i].order);
    men[no].order = order;
    men[no].id = id;
    men[no].virtue = tv;
    men[no].talent = tt;
    men[no].fgrade = tv + tt; 
    no++;
  }
  //  sort
  sort(men, men+no, cmp);
  //  output
  printf("%d\n", no);
  for(int i = 0; i < no; i++) {
    printf("%d %d %d\n", men[i].id, men[i].virtue, men[i].talent);
  }
  return 0;
}

//  WARNING: 这题考的是cmp复合函数设计
bool cmp (const People a, const People b) {
  if(a.order == b.order) {
    if(a.fgrade == b.fgrade) {
      if(a.virtue == b.virtue) {
        return a.id < b.id; 
      } else {
        return a.virtue > b.virtue;
      }
    } else {
      return a.fgrade > b.fgrade;
    }
  } else {
    return a.order < b.order;
  }
}
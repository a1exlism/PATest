/* 
 * INPUT: 5 \n (1, 3), (3, 5), (6, 7), (2, 4), (3, 9)
 * OUTPUT: 1,3;3,5;6,7
 * Notice: 尽量使用更小片段.
 */
#include <cstdio>
#include <algorithm>
using namespace std;
typedef struct {
  int l;
  int r;
} Interval;
const int MAXN = 1000;
bool cmp(Interval a, Interval b);
int main() {
  Interval intervals[MAXN];
  int n;
  int nextP = -1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &intervals[i].l, &intervals[i].r);
  }
  sort(intervals, intervals+n, cmp);
  for(int i = 0; i < n; i++) {
    if(intervals[i].l >= nextP) {
      printf("(%d, %d) ", intervals[i].l, intervals[i].r);
      //  update
      nextP = intervals[i].r;
    }
  }
  return 0;
}

bool cmp(Interval a, Interval b) {
  if(a.l == b.l)
    return a.r < b.r;
  else 
    return a.l < b.l;
}

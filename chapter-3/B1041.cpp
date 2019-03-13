#include <cstdio>
int get_id(int pa);
int main() {
  typedef struct {
    // char no[16];
    long long no;
    int pa;
    int pb;
  } List;
  int n = 0,  //  provide N infos
      i = 0,
      m = 0,  //  get M infos
      tmp = 0;
  scanf("%d", &n);
  List list[n];
  for(i = 0; i < n; i++) {
    // scanf("%s %d %d", list[i].no, &list[i].pa, &list[i].pb);
    scanf("%lld %d %d", &list[i].no, &list[i].pa, &list[i].pb);
  }
  scanf("%d", &m);
  for(i = 0; i < m; i++) {
    scanf("%d", &tmp);
    for(int j = 0; j < n; j++) {
      if(list[j].pa == tmp)
        printf("%lld %d\n", list[j].no, list[j].pb);
    }
  }
  return 0;
}


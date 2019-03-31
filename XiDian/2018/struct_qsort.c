#include <stdio.h>
#include <stdlib.h>
const int MAXN = 500;
typedef struct {
  int y;
  int m;
  int d;
  int date;
  int size;
} File;
int cmp1(const void * a, const void * b);
int cmp2(const void * a, const void * b);
int main() {
  int y, m, d, size;
  int i = 0;
  int len = 0;
  File files[MAXN];
  while(scanf("%d/%d/%d %d", &y, &m, &d, &size) != EOF) {
    files[i].y = y;
    files[i].m = m;
    files[i].d = d;
    files[i].size = size;
    files[i].date = y*10000+m*100+d;
    i++;
  }
  len = i;
  //  sort
  qsort(files, len, sizeof(File), cmp1);
  qsort(files, len, sizeof(File), cmp2);
  for(int i = 0; i < len; i++) {
    printf("%d/%d/%d %d\n", files[i].y, files[i].m, files[i].d, files[i].size);
  }
  return 0;
}

int cmp1(const void * a, const void * b) {
  if((*(File*)a).date < (*(File*)b).date)
    return 1;
  else
    return 0;
}

int cmp2(const void * a, const void * b) {
  if( (*(File*)a).date == (*(File*)b).date
   && (*(File*)a).size < (*(File*)b).size )
    return 1;
  else
    return 0;
}
#include <cstdio>
#include <algorithm>
/*
 * 2018/3/23 1024
 * 2018/3/23 2048
 * 2018/4/23 100
 */
using namespace std;
const int MAXN = 1000;
typedef struct File {
  int yy;
  int mm;
  int dd;
  int date;
  int size;
}File;
bool cmp(const File a, const File b);
bool cmp2(const File a, const File b);
int main() {
  int len, i;
  int y, m, d, size;
  File files[MAXN];
  len = i = 0;
  while(scanf("%d/%d/%d %d", &y, &m, &d, &size) != EOF) {
    files[i].yy = y;
    files[i].mm = m;
    files[i].dd = d;
    files[i].size = size;
    files[i].date = y*10000 + m*100 + d;
    i++;
  }
  len = i;
  printf("%d", len);
  //  sort date -> size
  sort(files, files+len, cmp);
  sort(files, files+len, cmp2);
  //  print
  for(int i = 0; i < len; i++) {
    y = files[i].yy;
    m = files[i].mm;
    d = files[i].dd;
    size = files[i].size;
    printf("%d/%d/%d %d\n", y, m, d, size);
  }
  return 0;
}

bool cmp(const File a, const File b) {
  if(a.date < b.date)
    return false;
  else
    return true;
}

bool cmp2(const File a, const File b) {
  if(a.date == b.date && a.size > b.size)
    return true;
  else
    return false;
}
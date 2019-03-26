#include <cstdio>
#include <cstring>
//  马鞍点 | 20'+
const int MAXN = 100;
int main() {
  int row, col;
  int tmp;
  int rowmin[MAXN];
  int row_in_col_index[MAXN];  //  取最小值所对应列的index
  int colmax[MAXN];
  memset(rowmin, -1, sizeof(rowmin));
  memset(colmax, -1, sizeof(colmax));
  scanf("%d %d", &row, &col);
  for(int i = 0; i < row; i++) {  //  row nums
    for(int j = 0; j < col; j++) {  //  single row | col nums
      scanf("%d", &tmp);
      if(rowmin[i] == -1 || tmp < rowmin[i]) {
        rowmin[i] = tmp;
        row_in_col_index[i] = j;
        // printf("\n==rowmin: %d==", tmp);
      }
      // printf("\n=%d=rowmin: %d==", i, rowmin[i]);
      if(colmax[j] == -1 || tmp > colmax[j]) {
        colmax[j] = tmp;
        // printf("\n==colmax: %d==", tmp);
      }
    }
  }
  //  check
  bool flag = false;
  int col_index;
  for(int i = 0; i < row; i++) {  //  列号对照
    col_index = row_in_col_index[i];
    tmp = rowmin[i];
    if(rowmin[i] == colmax[col_index]) {
      printf("%d %d %d\n", i, col_index, rowmin[i]);
      flag = true;
      break;
    }
  }
  if(!flag) {
    printf("no\n");
  }
  return 0;
}
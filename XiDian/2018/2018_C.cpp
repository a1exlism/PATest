#include <cstdio>
/*
 * 2
 * 1 1 4 4
 * 2 3 6 5
 */
const int MAXN = 100;
void fill(int arr[][MAXN], int lx, int ly, int rx, int ry);
int main() {
  int matrix[MAXN][MAXN] = {0}; 
  int num;
  int lx, ly, rx, ry;
  scanf("%d", &num);
  for(int i = 0; i < num; i++) {
    scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
    fill(matrix, lx, ly, rx, ry);
  }
  int sum = 0;
  for(int i = 0; i < MAXN; i++) {
    for(int j = 0; j < MAXN; j++) {
      if(matrix[i][j] > 0)
        sum++;
    }
  }
  printf("%d", sum);
  return 0;
}

void fill(int arr[][MAXN], int lx, int ly, int rx, int ry) {
  for(int i = lx; i < rx; i++) {
    for(int j = ly; j < ry; j++) {
      arr[i][j] ++;
    }
  }
}
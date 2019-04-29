/* 
 * N 皇后问题 - Recursion 方案
 * 实质也是排列组合Permutation问题
 */
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = 10;                //    最多8*8 八皇后
int n = 0;                          //    n 皇后
bool HashTableUsed[MAXN] = {false}; //    WARNING: From 0
int queues[MAXN] = {0};
void generateP(int index);
bool isPossible(int index, int val);

int main() {
  scanf("%d", &n);
  generateP(0);
  printf("Done\n");
  return 0;
}

void generateP(int index) {
  if (index == n) {
    for (int i = 0; i < n; i++)
      printf("%d", queues[i]);
    printf("\n");
    return;
  } else {
    for (int i = 0; i < n; i++) {
      if (!HashTableUsed[i]) {
        if (isPossible(index, i + 1)) {
          queues[index] = i + 1;
          HashTableUsed[i] = true;
          generateP(index + 1);
          HashTableUsed[i] = false;
        } else {
          printf("==impossible checked Index: %d val: %d==\n", index, i + 1);
          return;
        }
      }
    }
  }
}

//  is possible for this index
//  WARNING: index from 0
bool isPossible(int index, int val) {
  int disRow, disCol;
  for (int i = 0; i < index; i++) {
    disCol = 0 + abs(float(index - i));
    disRow = 0 + abs(float(val - queues[i]));
    if (disCol == disRow)
      return false;
  }
  return true;
}

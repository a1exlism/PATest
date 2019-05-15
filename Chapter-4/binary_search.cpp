/* 
 * INPUT: 100 \n
 * TIPS: 输入必须有序, 否则pos无意义
 * 21 70 20 6 41 27 5 65 71 32 46 44 8 23 13 76 86 11 91 23 24 93 2 2 23 57 10 75 12 75 42 71 82 65 89 53 47 52 40 96 40 65 70 58 69 9 61 24 47 7 60 91 8 72 5 21 95 95 40 22 86 63 11 22 99 97 27 12 20 64 98 22 35 18 20 84 98 54 87 97 16 24 21 85 44 1 62 62 24 20 24 84 93 23 4 63 15 28 77 9 
 * 1 10 11 11 12 12 13 15 16 18 2 2 20 20 20 20 21 21 21 22 22 22 23 23 23 23 24 24 24 24 24 27 27 28 32 35 38 40 40 40 41 42 44 44 46 47 47 5 5 52 53 54 57 58 6 60 61 62 62 63 63 64 65 65 65 69 7 70 70 71 71 72 75 75 76 77 8 8 82 84 84 85 86 86 87 89 9 9 91 91 93 93 95 95 96 97 97 98 98 99
 * Search X \n
 * OUTPUT: position of X
 */
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;
bool cmp(int a, int b);

int main() {
  int n, pos;
  int arr[MAXN], target;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &target);
  sort(arr, arr+n, cmp);
  //  TIPS Binary Search Start
  int left, right, mid;
  left = 0;
  right = n - 1;
  pos = -1;
  while(left <= right) {
    mid = (left + right) / 2;
    if (arr[mid] < target) {
      left = mid + 1; //  greater
    } else if(arr[mid] > target) {
      right = mid - 1;  //  less
    } else {
      pos = mid;
      break;
    }
  }
  if(pos == -1) {
    printf("Not Found\n");
  } else {
    printf("Found in %dth position.\n", pos+1);
  }
  
  return 0;
}

bool cmp(int a, int b) {
  return a < b;
}

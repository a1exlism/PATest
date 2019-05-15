/* 
 * INPUT:
 * 100
 * 1 10 11 11 12 12 13 15 16 18 2 2 20 20 20 20 21 21 21 22 22 22 23 23 23 23 24 24 24 24 24 27 27 28 32 35 38 40 40 40 41 42 44 44 46 47 47 5 5 52 53 54 57 58 6 60 61 62 62 63 63 64 65 65 65 69 7 70 70 71 71 72 75 75 76 77 8 8 82 84 84 85 86 86 87 89 9 9 91 91 93 93 95 95 96 97 97 98 98 99
 * 11
 * OUTPUT: 
 * pos
 */
#include <cstdio>

const int MAXN = 1000;
int lower_bound(int arr[], int left, int right, int target);
int upper_bound(int arr[], int left, int right, int target);

int main() {
  int n, arr[MAXN], target;
  int pos, rl, rr;  //  range [rl, rr)
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  scanf("%d", &target);
  pos = lower_bound(arr, 0, n, target);
  printf("1st >= target position: %d\n", pos+1);
  pos = upper_bound(arr, 0, n, target);
  printf("1st > target position: %d\n", pos+1);
  printf("last <= target position: %d\n", pos);
  return 0;
}

/* lower_bound: `第一个` >= target 的 position
 * ATTENTION  必然存在一个pos, 即使不存在.
 * 1. 范围 0-n 因为返回的是left, 和mid条件left=mid+1;
 * 2. left < right
 * 3. return left|right
 */
int lower_bound(int arr[], int left, int right, int target) {
  int mid = -1;
  //  WARNING 当while循环结束(l==r)时,此时的返回就是所得到的pos[0-n];
  while(left < right) {
    mid = (left + right) / 2;
    if(arr[mid] >= target) {
      right = mid;  //  TIPS 包含相等的情况
    } else {
      left = mid + 1;
    }
  }
  return left;
}

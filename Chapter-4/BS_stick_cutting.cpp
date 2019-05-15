/* 
 * 题目描述: 给出N根木棍划分出K段长度相等(l整数)的木棍,木棍尽可能的长.
 * Input: N K; L1, L2...LN
 * Output: l
 * 5 9
 * 10 22 31 9 11
 * TIPS 模板: Binary_search_1st_match
 */

#include <cstdio>

const int MAXN = 100;   //  max stick numbers
int get_stick_nums(int arr[], int len, int L);

int main() {
  int sticks[MAXN];
  int N, K;
  int left, right, mid;
  scanf("%d%d", &N, &K);
  right = -1;
  for(int i = 0; i < N; i++) {
    scanf("%d", sticks+i);
    if(sticks[i] > right)
      right = sticks[i];
  }
  left = 1;
  int k;
  while(left < right) {
    mid = (left + right) / 2;
    //  ATTENTION: 找到最大(`最后`)一个LEN使得k >= K; => 找到最小(`最早`)一个LEN使得k < K; => return LEN-1(LEN下降,k上升)
    //  TIPS2: L和N是负相关
    k = get_stick_nums(sticks, N, mid);
    if(k < K) {
      right = mid;
    } else {
      left = mid + 1;
    }
    printf("nums: %d\n", k);
  }
  left --;
  printf("LEN: %d", left);
  return 0;
}

int get_stick_nums(int arr[], int len, int L) {
  int num = 0;
  for(int i = 0; i < len; i++) {
    num += arr[i] / L;
  }
  return num;
}

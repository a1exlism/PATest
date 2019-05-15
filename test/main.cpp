/* 
 * 题目描述: 给出N根木棍划分出K段长度相等(l整数)的木棍,木棍尽可能的长.
 * Input: N L1, L2...LN K
 * Output: l
 * 5 10 22 31 9 11
 * 9
 */
#include <cstdio>

const int MAXN = 100;
int stick_num(int arr[], int n, int single_len);

int main() {
  int arr[MAXN];
  int n, num;
  int len_l,len_h;
  len_h = -1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if(len_h < arr[i])
      len_h = arr[i];
  }
  printf("Set split nums: \n");
  scanf("%d", &num);
  len_l = 0;
  int mid;
  while(len_l + 1 < len_h) {
    mid = (len_l + len_h) / 2;
    if(stick_num(arr, n, mid) >= num) { //  num:↑ => len↑ => num↓
      len_l = mid;
    } else {
      len_h = mid;
    }
  }
  printf("Max split len: %d", len_l);
  return 0;
}

int stick_num(int arr[], int n, int single_len) {
  int num = 0;
  for(int i = 0; i < n; i++) {
    num += arr[i] / single_len;
  }
  return num;
}

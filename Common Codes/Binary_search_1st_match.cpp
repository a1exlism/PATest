#include <cstdio>
//  二分查找框架: `第一个满足该条件Condition`的位置index
//  TIPS 1: 区间只用左闭右闭[left, right], 个人认为更加容易理解;
//  TIPS 2: 寻找`最后一个`满足该条件的位置, 只需要更改while内if条件, 返回-1/+1即可;
int meet_condition_1st(int arr[], int left, int right);

int main() {
  int arr[100] = {};
  int left, right;
  meet_condition_1st(arr, left, right); //  WARNING Range: 0-N
  return 0; 
}

//  WARNING: [pos, ?] 都能满足条件
int meet_condition_1st(int arr[], int left, int right) {
  int mid;
  while( left < right ) { //  TIPS: 当left==right时, 条件唯一成立
    mid = (left + right) / 2;
    if( CONDITION ) { //  TIPS: mid右边可能满足条件
      right = mid;
    } else {  //  TIPS: mid左边不满足条件
      left = mid + 1;
    }
  }
  return left;
}

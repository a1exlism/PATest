#include <stdio.h>
void swap(int *a, int *b);
//  base bubble sort

int main() {
    int nums[7] = {2, 5, 6, 1, 19, 9, 7};
    int length = 7;
    int max_length = 7;    //  每次比较之后少一次
    int max_num = 0;

    for(int i = 0; i < length; i++) {
        printf("%d ", *(nums+i));
    }

    for(int i = 1; i < length; i++ ) {  //  length - 1 times
      for(int j = 0; j < length-i; j++) { //  明确max既定位置
        if(nums[j] > nums[j+1])
          swap(nums+j, nums+j+1);
      }
    }
    printf("\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
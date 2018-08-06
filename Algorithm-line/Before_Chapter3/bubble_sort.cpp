#include <stdio.h>
//  base bubble sort
// void swap(int *a, int *b);  //  Function declaration before

int main() {
    int nums[7] = {2, 5, 6, 1, 19, 9, 7};
    int length = 7;
    int max_length = 7;    //  每次比较之后少一次
    int max_num = 0;

    for(int i = 0; i < length; i++) {
        printf("%d ", *(nums+i));
    }

    for(int i = 1; i < length; i++ ) {  //  length - 1 times
        max_length -= i;
        for(int j = 0; j < max_length; j++) {
            if(nums[j] > nums[j+1]) {
                // swap(nums+j-1, nums+j);
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
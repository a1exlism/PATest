#include <stdio.h>

int main() {
    int arr[2] = {1, 2};
    int tmp = arr[0];
    arr[0] = arr[1];
    arr[1] = tmp;
    
    for(int i = 0; i < 2; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
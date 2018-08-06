#include <cstdio>
#include <math.h>

int main() {
    int column = 0;
    int row = 0;
    char charactor = ' ';
    scanf("%d %c", &column, &charactor);
    
    row = round(column/2.0);
    // printf("row: %d\n", row);
    char arr[row][column];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if(i == 0 || i == row-1) {
                printf("%c", charactor);
            } else {
                if(j == 0 || j == column-1) {
                    printf("%c", charactor);
                } else {
                    printf(" ");
                }
            }
        }
        if(i != row-1) {
            printf("\n");
        }
    }
    return 0;
}
/**
 * Callatz Conjecture
 */

#include <cstdio>

int main() {
    int num = 0;
    scanf("%d", &num);
    if( num > 1000 ) {
        return 0;
    }
    
    int count = 0;
    while ( num != 1 ) {
        if( num % 2 == 0 ) {
            num = num / 2;
        } else {
            num = (3 * num + 1) / 2;
        }
        count ++;
    } ;

    printf("%d", count);   
    return 0;
}
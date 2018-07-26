/**
 * Callatz Conjecture
 */

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    cin >> num;
    if( num > 1000 ) {
        return 0;
    }
    
    int count = 0;
    do {
        if( num / 2 == 0 ) {
            num = num / 2;
        } else {
            num = (3 * num + 1) / 2;
        }
        count ++;
    } while ( num == 1 );

    cout << count;
    return count;
}
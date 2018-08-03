 /**
  * 挖掘机技术
  */
#include <cstdio>
#include <string.h>

int main() {
    int num = 0;
    scanf("%d", &num);
    int scores[num];//  or memset(arr, val[0,1], sizeof(arr))
    memset(scores, 0, sizeof(scores));
    //  int scores[num];    wrong: init values
    int school_no = 0;
    int score = 0;
    int max_score = 0;
    int best_school_no = 0;
    int tmp_score;
    while(num--) {
        scanf("%d %d", &school_no, &score);
        tmp_score = scores[school_no-1] + score;
        scores[school_no-1] = tmp_score;
        if(max_score < tmp_score) {
            max_score = tmp_score;
            best_school_no = school_no;
        }
    }
    printf("%d %d", best_school_no, max_score);
    return 0;
}
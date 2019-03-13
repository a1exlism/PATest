#include <cstdio>
int main() {
  int N;
  char C;
  int row, max, sum_one, i, diff;
  scanf("%d %c", &N, &C);
  max = (N + 1) / 2;  //  最大可用
  // printf("max: %d", max);
  i = 1, row = 0, sum_one = 0;  //  sum in one side
  do {
    sum_one += i;
    i += 2;
    row ++;
    if(sum_one + i > max) break;
  } while (sum_one <= max);
  diff = N - sum_one * 2 + 1;

  // printf("row: %d\n", row);

  //  output
  for(int i = 0; i < row; i++) { //  1st行 -> rowth行
    for(int j = 0; j < i; j++) printf(" ");

    for(int j = 0; j < 2*(row-i)-1; j++) {
      printf("%c", C); 
    }
    printf("\n");
  }
  for(int i = 1; i < row; i++) { //  row+1 th行 -> 2 * row th行
    for(int j = 1; j < row - i; j++) {
      printf(" ");
    }
    for(int j = 0; j < (2 * i + 1); j++) printf("%c", C); 
    printf("\n");
  }
  printf("%d", diff);
  return 0;
}
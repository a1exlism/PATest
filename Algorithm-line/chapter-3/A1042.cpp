#include <cstdio>
int main() {
  //  0. initial 1-54
  const int N = 54;
  int shuffle_times = 0;
  int pos[54] = {1},
      cards[54] = {1},
      tmp[54] = {1};
  scanf("%d", &shuffle_times);
  for(int i = 0; i < N; i++) {
    cards[i] = 1+i;
    scanf("%d", pos+i);
  }
  //  1. position shuffle
  for(int j = 0; j < shuffle_times; j++) {
    //  shuffle
    int newPos = 0;
    for(int i = 0; i < 54; i++) {
      newPos = pos[i]-1;
      tmp[newPos] = cards[i];
    }
    for(int i = 0; i < 54; i++) {
      cards[i] = tmp[i];
    }
  }
  //  2. translation
  char prefix = '\0';
  int quotient = 0,
      remainder = 0;
  for(int i = 0; i < 54; i++) {
    quotient = cards[i] / 13;
    remainder = cards[i] % 13;
    if(remainder == 0) {
      remainder = 13;
    }
    switch (quotient)
    {
      case 0:
        prefix = 'S';
        break;
      case 1:
        prefix = 'H';
        break;
      case 2:
        prefix = 'C';
        break;
      case 3:
        prefix = 'D';
        break;
      default:
        prefix = 'J';
        break;
    }
    printf("%c%d", prefix, remainder);

    if(i < 53) {
      printf(" ");
    }
  }
  return 0;
}
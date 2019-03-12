#include <cstdio>
int get_sum(int x);
void swap(int &a, int &b);
int main() {
  int sum[1000] = {0};
  int n, tmp, count;
  count = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &tmp);
    sum[count++] = get_sum(tmp);
    // printf("\n==%d==", sum[count-1]);
  }
  //  selection sort
  int minI;
  for(int i = 0; i < count-1; i++) {  //  max
    minI = i;
    for(int j = i+1; j < count; j++) {
      if(sum[j] < sum[minI])
        minI = j;
    }
    swap(sum[minI], sum[i]);
  }
  for(int i = 0; i < count; i++) {
    printf("%d", sum[i]);
    if(i < count-1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  return 0;
}

int get_sum(int x) {
  int sum = 0;
  do {
    sum += x % 10;
    x /= 10;
  } while(x);

  return sum;
}

void swap(int &a, int &b) {
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
}
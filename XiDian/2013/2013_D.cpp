#include <cstdio>
#include <cmath>
//  简单 进制转换
//  input: 10 2 10 10 0 0 
void to2(int n);
void to10(int n);
int main() {
  int n, m;
  while(scanf("%d %d", &n, &m) != EOF) {
    if(n == 0 && m == 0)
      break;
    if(m == 2) {  //  10->2
      to10(n);
    } else {  //  2->10
      to2(n);
    }
    printf("\n");    
  }
  return 0;
}

void to2(int n) {
  if(n / 2 == 0){
    printf("%d", n);
    return;
  }
  to2(n/2);
  printf("%d", n % 2);
}

void to10(int n) {
  int h = 0;
  int sum = 0;
  do{
    sum += pow(2, h) * (n % 10);
    n /= 10;
    h++;
  } while(n);
  printf("%d", sum);
}
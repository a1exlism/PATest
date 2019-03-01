#include <cstdio>
using namespace std;
const int MAXN = 100000;
void swap(int &a, int &b);
int main()
{
  //  sum: total distance
  int N, M, start, end, sum, min;
  int gap[MAXN] = {0}, dis[MAXN] = {0};
  sum = min = 0;
  //  dis[0] = 0; index: 1-N
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", gap+i);
    sum += gap[i];
    dis[i+1] = sum;
  }
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &start, &end);
    //  swap
    if(end < start) {
      swap(start, end);
    }
    //  get dis
    min = dis[end-1]-dis[start-1];
    if(min < sum - min) {
      printf("%d", min);
    } else{
      printf("%d", sum - min);
    }
    //  return
    if(i < M-1){
      printf("\n");
    }
  }
  return 0;
}
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
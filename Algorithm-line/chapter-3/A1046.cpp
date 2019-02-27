#include <cstdio>
using namespace std;
const int MAXN = 10000;
void swap(int &a, int &b);
int main()
{
  int N, M, start, end, sum;
  int gap[MAXN], dis[MAXN];
  //  dis: 1-X的总距离 index: 0~N-1
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", gap+i);
    sum += gap[i];
    dis[i] = sum;
  }
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &start, &end);
    //  swap
  }
  return 0;
}
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
#include <cstdio>
int get_min_dis(int start, int end, int arr[], int N);
int main()
{
  //  input data: 1~N | index: 0~N-1
  int N = 0,
      M = 0;
  scanf("%d", &N);
  int D[N], start, end;
  //  ATTENTION: 注意数组初始化定量大小 Wrong: results[M] 写在M定义之前会导致数据出错
  for (int i = 0; i < N; i++)
  {
    scanf("%d", D + i);
  }
  scanf("%d", &M);
  int results[M];
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d", &start, &end);
    // printf("==%d==\n", get_min_dis(start, end, D, N));
    results[i] = get_min_dis(start, end, D, N);
    // printf("%d\n", results[i]);
  }
  for (int i = 0; i < M; i++)
  {
    printf("%d", results[i]);
    if (i < M - 1)
    {
      printf("\n");
    }
  }
  return 0;
}
int get_min_dis(int start, int end, int arr[], int N)
{
  //  arr[0] Nth-1st distance
  int sum_f = 0,
      sum_b = 0;
  int tmp = 0;
  if (start > end)
  {
    tmp = start;
    start = end;
    end = tmp;
  }
  //  1. forward
  for (int i = start - 1; i < end - 1; i++)
  {
    sum_f += arr[i];
  }
  // printf("sum_f: %d\n", sum_f);
  //  2. backward
  for (int i = end - 1; i < N; i++)
  {
    //  end->1
    sum_b += arr[i];
  }
  for (int i = 0; i < start - 1; i++)
  {
    //  1->start
    sum_b += arr[i];
  }
  int min =  sum_b < sum_f ? sum_b : sum_f;
  // printf("MINA: %d\n", sum_f);
  // printf("MINB: %d\n", sum_b);
  return min;
}
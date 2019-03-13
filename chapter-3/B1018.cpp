//  统计双方的胜、平、负次数
#include <cstdio>
char Get_Max_Char(int arr[], int n);
int main()
{
  //  results: A W-T-L
  //  win_x: 获胜次数 以0-B 1-C 2-J 为准
  int results[3] = {0},
      win_A[3] = {0},
      win_B[3] = {0};
  int n = 0;
  char A, B;
  char FA, FB;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    //  ATTENTION: 空格处理
    getchar();
    scanf("%c %c", &A, &B);
    // printf("==%c-%c==\n", A, B);
    if (A == B)
    {
      results[1]++;
    }
    else if ((A == 'B' && B == 'C') || (A == 'C' && B == 'J') || (A == 'J' && B == 'B'))
    {
      results[0]++;
      switch (A)
      {
      case 'B':
        win_A[0]++;
        break;
      case 'C':
        win_A[1]++;
        break;
      default:
        win_A[2]++;
        break;
      }
    }
    else
    {
      results[2]++;
      switch (B)
      {
      case 'B':
        win_B[0]++;
        break;
      case 'C':
        win_B[1]++;
        break;
      default:
        win_B[2]++;
        break;
      }
    }
  }
  FA = Get_Max_Char(win_A, 3);
  FB = Get_Max_Char(win_B, 3);
  printf("%d %d %d\n", results[0], results[1], results[2]);
  printf("%d %d %d\n", results[2], results[1], results[0]);
  printf("%c %c", FA, FB);
  return 0;
}

char Get_Max_Char(int arr[], int n) {
  int mIndex = 0;
  for(int i = 1; i < n; i++) {
    if(arr[mIndex] < arr[i]) 
      mIndex = i;
  }
  switch (mIndex)
  {
    case 0:
      return 'B';
    case 1:
      return 'C';
    default:
      return 'J';
  }
}
/**
 *  日期差值 X = b-a+1 
 *  思路: 追赶 day by day
 */
#include <cstdio>
bool IsLeap(int year);

int main()
{
  int mons[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int a, b;
  int y1, y2;
  int m1, m2;
  int d1, d2;
  int tmp = 0;
  int diff;
  while (scanf("%d%d", &a, &b) != EOF)
  {
    if (a > b)
    { //  b > a
      tmp = a;
      a = b;
      b = tmp;
    }
    //  data init
    diff = 1;
    y1 = a / 10000;
    y2 = b / 10000;
    m1 = a % 10000 / 100;
    m2 = b % 10000 / 100;
    d1 = a % 100;
    d2 = b % 100;
    //  a follow b day by day
    while (y1 != y2 || m1 != m2 || d1 != d2)
    {
      d1++;
      //  Leap Year February
      if (IsLeap(y1))
      {
        mons[2] = 29;
      }
      else
      {
        mons[2] = 28;
      }
      if (d1 == mons[m1] + 1) //  ATTENTION: bad!
      {
        m1++;
        d1 = 1;
      }
      if (m1 == 12 + 1)
      {
        y1++;
        m1 = 1;
      }
      diff++;
    }
    printf("%d\n", diff); //  ATTENTION: 输出格式不对
  }
  return 0;
}

bool IsLeap(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
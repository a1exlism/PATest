/* 
 * 全排列 建议横向思考
 */
#include <cstdio>

FILE *fp;

const int MAXN = 10; //  n < 10 [1-9]
int n, P[MAXN];
bool HashTable[MAXN] = {false}; //  check cirtain character is used.
void createP(int index)
{
  if (index == n)
  {
    //  output
    for (int i = 0; i < n; i++)
    { //  n figures
      fprintf(fp, "%d", P[i]);
    }
    fprintf(fp, "\n");
    /* for (int i = 0; i < n; i++)
    {
      printf("%d", P[i]);
    }
    printf("\n"); */
  }
  else
  {
    //  create figure by figure
    for (int i = 0; i < n; i++)
    {
      if (!HashTable[i])
      {
        P[index] = i + 1;
        HashTable[i] = true; //  stash
        createP(index + 1);  //  next figure
        HashTable[i] = false;
      }
    }
  }
}
int main()
{
  scanf("%d", &n);
  fp = fopen("output", "w+");
  createP(0); //  0 ~ n-1th figure
  return 0;
}
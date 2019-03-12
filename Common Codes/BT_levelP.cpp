#include <cstdio>

typedef char TElemType;
/* 二叉樹的二叉鏈表存儲表示 */
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode *lchild, *rchild; /* 左右孩子指針 */
} BiTNode, *BiTree;

int level(BiTree T, BiTNode *N)
{
  int i, j;
  if (T == NULL)
  {
    return 0;
  }
  if (T == N)
  {
    return 1;
  }
  i = level(T->lchild, N);
  j = level(T->rchild, N);
  if (i != 0)
  {
    return (i + 1);
  }
  else if (j != 0)
  {
    return (j + 1);
  }
  else
  {
    return 0;
  }
}

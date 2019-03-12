int lev = 0;
typedef struct node
{
  int key;
  struct node *lchild, *rchild;
} bitree;
void level(bitree *bt, int x)
{
  if (bt != 0)
  {
    lev++;
    if (bt->key == x)
      return;
    else if (bt->key > x)
      level(bt->lchild, x);
    else
      level(bt->rchild, x);
  }
}
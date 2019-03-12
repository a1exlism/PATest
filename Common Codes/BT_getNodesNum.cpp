#include <cstdio>
void delete (bitree &t, binode *p)
{ //p初始为空
  if (t == null)
    return;
  if (t->lchild == null && t->rchlid == null)
  {               //如果为叶节点
    if (p = null) //该树只有根节点
      free(t);
    else
    {
      free(t);
      p->lchild = null;
      p->rchild = null;
    }
  }
  else
  {
    p = t;
    delete (t->lcihld, p);
    delete (t->rchild, p);
  }
}
}

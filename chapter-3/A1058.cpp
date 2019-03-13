#include <cstdio>
int main() {
  int ga, sa, ka,
      gb, sb, kb,
      gs, ss, ks; //  sum 
  scanf("%d.%d.%d %d.%d.%d", &ga, &sa, &ka, &gb, &sb, &kb);
  ks = ka + kb;
  sa += ks / 29;
  ks %= 29;
  ss = sa + sb;
  ga += ss / 17;
  ss %= 17;
  gs = ga + gb;
  printf("%d.%d.%d", gs, ss, ks);
  return 0;
}
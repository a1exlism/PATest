#include <cstdio>
int main() {
  FILE *fpi, *fpo;
  fpi = fopen("./source.in", "r");
  fpo = fopen("./res.out", "w");

  int a, b, c;
  char x[100] = "";
  fgets(x, sizeof(x), fpi);
  fscanf(fpi, "%d %d %d", &a, &b, &c);
  printf("%s", x);
  fprintf(fpo, "%d %d %d", a, b, c);

  fclose(fpi);
  fclose(fpo);
  return 0;
}
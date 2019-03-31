#include <cstdio>
const int MAXN = 1001;
void with_fgets();
void with_fscanf();
int main() {
  with_fgets();
  printf("\n=========\n");
  with_fscanf();
  return 0;
}

void with_fgets() {
  FILE *fp;
  char str[MAXN];
  fp = fopen("source.in", "r");
  while(1) {
    fgets(str, MAXN, fp);
    printf("%s", str);
    //  BETTER: feof with END of reading file
    if(feof(fp))
      break;
  }
  //  WARNING: close the file
  fclose(fp);
}

void with_fscanf() {
  FILE *fp;
  char str[MAXN], a;
  int b;
  //  WARNING: 固定格式
  fp = fopen("./source.in", "r");
  while(fscanf(fp, "%s %c %d", str, &a, &b) != EOF) {
    printf("%s a: %c ; b: %d\n", str, a, b);
  }
  fclose(fp);
}
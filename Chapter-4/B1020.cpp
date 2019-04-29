#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXTYPE = 2000;
typedef struct{
  double remain;  //  WARNING: 审题不仔细
  double profit;  //  **$/T
  double total_val;
} Cake;
bool cmp (Cake a, Cake b);

int main() {
  int cnum, demand;
  double tmp, wealth = 0;
  Cake cakes[MAXTYPE];
  scanf("%d %d", &cnum, &demand);
  for(int i = 0; i < cnum; i++) {
    scanf("%lf", &tmp);
    cakes[i].remain = tmp;
  }
  for(int i = 0; i < cnum; i++) {
    scanf("%lf", &tmp);
    cakes[i].total_val = tmp;
    cakes[i].profit = tmp / (double)cakes[i].remain;
  }
  sort(cakes, cakes+cnum, cmp);
  //  calculation
  for(int i = 0; i < cnum; i++) {
    if(demand >= cakes[i].remain) {
      demand -= cakes[i].remain;
      wealth += cakes[i].total_val;
      if(demand == 0)
        break;
    } else {
      wealth += demand * cakes[i].profit;
      break;
    }
  }
  printf("%.2f", wealth);

  return 0;
}

bool cmp (Cake a, Cake b) {
  return a.profit > b.profit;
}

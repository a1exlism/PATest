#include <cstdio>
#include <cmath>
/* 
 * 装水问题 Page 133
 * 给定R,r 求高度h使得S1/S2=r
 * TIPS: 使用的框架依然是`Binary_sarch_exact`
 */

const double PI = acos(-1);
const double PRECISION = 1e-5;

double get_rate(double R, double h);

int main() {
  double R, r, h;
  scanf("%lf %lf", &R, &r);  //  WARNING: 0 < r < 1
  //  TIPS main part
  double left, right, mid;
  left = 0;
  right = R;
  while(right - left >= PRECISION) {
    mid = (left + right) / 2;
    if (get_rate(R, mid) < r) {
      left = mid;
    } else {
      right = mid;
    }
    printf("Rate: %f\n", get_rate(R, mid));
  }
  h = left;
  printf("h: %f", h);
  return 0;
}

double get_rate(double R, double h) {
  double S1, S2, theta;
  theta = acos((R - h) / R);
  S1 = theta * pow(R, 2) - (R - h) * (R * sin(theta));
  S2 = PI * pow(R, 2) / 2;
  return S1 / S2;
}

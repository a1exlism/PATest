/* 
 * √2近似值, 精确到10^-5
 */
#include <cstdio>
const double PRECISION = 1e-5;
double f(double x) {
  return x * x;
}
int main() {
  double left = 1;
  double right = 2;
  double mid = -1;
  while(right - left >= PRECISION) {  //  最终需要得到的结果: 精确度<Precision
    mid = (left + right) / 2;
    if(f(mid) < 2) {  //  get close
      left = mid;     
    } else {
      right = mid;
    }
  }
  printf("%f", left);
  return 0;
}

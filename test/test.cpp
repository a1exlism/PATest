#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

//  sort(arrStart, arrEnd[, compare]);
bool compare(int a, int b);

int main()
{
  char str[100]="test_string";
  char out_str[100];
  std::string out_str = str.substr(0, 5);
  printf("%s", out_str);
  return 0;
}

bool compare(int front, int end) {
  //  降序
  if(front > end)
    return 1;
  else
    return 0;
}
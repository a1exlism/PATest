#include <cstdio>
int main() {
  char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  //  1. week
  char str[4][61];
  scanf("%s %s %s %s", str[0], str[1], str[2], str[3]);
  int iw, ih, im; //  index
  char x;
  for(iw = 0; iw < 60; iw++) {
    x = str[0][iw];
    if(x == str[1][iw] && x <= 'G' && x >= 'A')
      break;
  }
  printf("%s ", week[x-'A']);
  //  2. hour
  for(ih = iw + 1;ih < 60; ih++) {
    x = str[0][ih];
    if(x == str[1][ih]) {
      if(x >= '0' && x <= '9') {
        ih = x - '0';
        break;
      }
      if(x >= 'A' && x <= 'N') {
        ih = x - 'A' + 10;
        break;
      }
    }
  }
  printf("%02d:", ih);
  //  3. min
  for(im = 0; im < 60; im++) {
    x = str[2][im];
    if( (x >= 'a' && x <= 'z' ) || (x >= 'A' && x <= 'Z')) {
      if(x == str[3][im]) 
        break;
    }
  }
  printf("%02d", im);
  return 0;
}
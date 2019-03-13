#include <cstdio>
int main() {
  typedef struct {
    char id[20];
    int signin;
    int signout;
  } Stuff;
  int num = 0,
     first = 0,last = 0,
     h,m,s;
  scanf("%d", &num);
  Stuff stuffs[num];
  for(int i = 0; i < num; i++) {
    scanf("%s", stuffs[i].id);
    scanf("%d:%d:%d", &h, &m, &s);
    stuffs[i].signout = h * 10000 + m * 100 + s;
    // stuffs[i].signin = h * 3600 + m * 60 + s;
    scanf("%d:%d:%d", &h, &m, &s); 
    stuffs[i].signout = h * 10000 + m * 100 + s;
    // stuffs[i].signout = h * 3600 + m * 60 + s;
  }
  for(int i = 1; i < num; i++) {
    if(stuffs[first].signin > stuffs[i].signin)
      first = i;
    if(stuffs[last].signout < stuffs[i].signout)
      last = i;
  }
  printf("%s %s", stuffs[first].id, stuffs[last].id);
  return 0;
}
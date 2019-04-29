/* 
 * 字符串出现次数
 * Set len-3 str-arr(no more than 100) consists of [A-Z] && [a-z] && [0-9]
 * Assumption: if got num, must be the last one.
 * INPUT: N line String, str1\n str2\n ...strN | M check string value
 * OUTPUT: the string repeat count
 == TEST ==
 7
abc
cde
oo8
oo8
nsd 
se3
see
5
oo8
abb
nds
see
se3
 */
#include <cstdio>
#include <cmath>
const int MAXN = 100;
const int LEN = 3;
int Str[MAXN][5];
int HashTable[52 * 52 * 52 + 10];
int Convert_hash (char str[], int len) {
  //  Character convert into Decimal Number
  int sum = 0;
  for(int i = 0; i < len; i++) {
    if(str[i] <= 'Z' && str[i] >= 'A') {
      sum = sum * 52 + str[i] - 'A';
    } else if(str[i] <= 'z' && str[i] >= 'a') {
      sum = sum * 52 + str[i] - 'a'; 
    } else {
      sum = sum * 52 + str[i];
    }
  }
  return sum;
}
int main() {
  int N, M;
  char tmp[5];
  scanf("%d", &N);
  //  create table
  for(int i = 0; i < N; i++) {
    scanf("%s", tmp);
    HashTable[Convert_hash(tmp, LEN)]++;
  }
  //  check string
  printf("\n");
  scanf("%d", &M);
  for(int i = 0; i < M; i++) {
    scanf("%s", tmp);
    printf("%s : %d\n", tmp, HashTable[Convert_hash(tmp, LEN)]);
  }
  return 0;
}
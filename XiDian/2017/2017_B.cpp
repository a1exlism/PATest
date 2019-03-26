#include <cstdio>
#include <cstring>
const int MAXN = 101;
void toLower(char arr[]);
int main() {
	char str[MAXN][MAXN];
	int n, plen, len;
	bool isSensitive;
	char pattern[MAXN];
	scanf("%s", pattern);
	scanf("%d", &isSensitive);
	scanf("%d", &n);
	
	plen = strlen(pattern);
	bool isMatch = false;
	
	if(!isSensitive) 
		toLower(pattern);
	
	for(int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		len = strlen(str[i]);
		isMatch = false;
		if(!isSensitive)
			toLower(str[i]);
		//	check pattern
		int k;
		for(int j = 0; j <= len-plen; j++) {
			for(k = 0; k < plen; k++) {
				if(str[i][j+k] != pattern[k])
					break;
			}
			if(k == plen) {	//	if match
				printf("%s\n", str[i]);
				break;
			}
		}		
	}
	return 0;
}

void toLower(char arr[]) {
	int i = 0;
	while(arr[i] != '\0') {
		if(arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] = arr[i] + 'a' - 'A';
		}
	}
}

#include <cstdio>
#include <algorithm>
const int MAXN = 1000;
using namespace std;
int main() {
	int arr[MAXN] = {0};
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n;i++) {
		scanf("%d", arr+i);
	}
	if(n == 1) {	//	only 1 
		printf("%d", arr[0]);
	}
	//	1. Sort could be 
//	sort(arr, arr+n);
	//	2. cmp
	int i = 0,
		lt = 0,
		mt = 0;
	bool flag = false;
	for(i = 1; i < n; i++) {
		//printf("%d", arr[i]);
		lt = mt = 0;
		for(int j = 0; j < i; j++) {
			if(arr[j] < arr[i])
				lt++;
		}
		for(int j = i+1; j < n; j++) {
			if(arr[j] > arr[i])
				mt++;
		}
		if(lt == mt) {
			flag = true;
			break;
		}
	}
	if(flag) {
		printf("%d", arr[i]);
	} else {
		printf("-1");
	}
	return 0;
}

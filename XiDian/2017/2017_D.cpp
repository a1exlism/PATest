#include <cstdio>
#include <cstring>
bool afford(int arr[], int req);
void fill(int arr[], int num, int row);
int main() {
	int arr[20][5];
	memset(arr, 0, sizeof(arr));
	int n, reqn;
	bool affordable = false;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &reqn);
		affordable = false;
		//	check continuable
		for(int j = 0; j < 20; j++) {
			affordable = afford(arr[j], reqn);
			if(affordable) {
				fill(arr[j], reqn, j);
				break;
			}
		}
		if(!affordable) {
			for(int j = 0; j < 20; j++) {
				for(int k = 0; k < 5; k++) {
					if(arr[j][k] == 0) {
						arr[j][k] = 1;
						printf("%d", j*5+k+1);
						if(reqn > 0) {
							printf(" ");
						}
						reqn--;
					}
					if(reqn == 0)
						break;
				}
				if(reqn == 0)
					break;
			}
			printf("\n");
		}
	}
	return 0;
}

bool afford(int arr[], int req) {	
	//	req: number left: left number
	int left = 5;
	for(int i = 0; i < 5; i++) {
		if(arr[i]) {
			left--;
		}
	}
	if(left < req)
		return false;
	return true;
}

void fill(int arr[], int num, int row) {
	for(int i = 0; i < 5 && num > 0; i++) {
		if(arr[i] == 0) {
			arr[i]++;
			printf("%d", row*5+i+1);
			if(num > 0)
				printf(" ");
			num--;
		}
	}
	printf("\n");
}

#include <cstdio>
#include <cstring>
const int MAXN = 1000;
struct Stuff{
	char name[10];
	int stays;
} stuff[MAXN];
int main() {
	int sh, sm,
		eh, em;
	int len = 0;
	char tmpname[MAXN];
	int tmpstays;
	int matchId;
	//	1st: take record
	while(scanf("%s %d:%d %d:%d", tmpname, &sh, &sm, &eh, &em) != EOF) {
		matchId = -1;	//init
		//	calculate the time
		tmpstays = eh*60+em-(sh*60+sm);
		//	2nd: find the one
		bool isMatch = true;
		for(int i = 0; i < len; i++) {
			//	CHINESE compare UNICODE
			for(int j = 0; stuff[i].name[j] != '\0' && tmpname[j] != '\0'; j++) {
				if(stuff[i].name[j] != tmpname[j]) {
					isMatch = false;
					break;
				}
			} 
			if(strlen(stuff[i].name) == strlen(tmpname) && isMatch) {
				matchId = i;
//				printf("\n==name: %s\n", tmpname);
				break;
			}
		}
		if(matchId != -1) {
			stuff[matchId].stays += tmpstays;
		} else {
			strcpy(stuff[len].name, tmpname);
			stuff[len].stays = tmpstays;
			len++;
		}
	}
	for(int i = 0; i < len; i++) {
		printf("%s %d\n", stuff[i].name, stuff[i].stays);
	}
	return 0;
}

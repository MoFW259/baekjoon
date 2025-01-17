#include <stdio.h>
int country[1001][4];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	int k=0, rank = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &country[k][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		if (i == K) continue;
		if (country[K][1] < country[i][1]) {
			rank++;
		}
		else if (country[K][1] > country[i][1]) {
			break;
		}
		else {
			if (country[K][2] < country[i][2]) {
				rank++;
			}
			else if (country[K][2] > country[i][2]) {
				break;
			}
			else {
				if (country[K][3] < country[i][3]) {
					rank++;
				}
			}
		}
	}
	printf("%d", rank);
}
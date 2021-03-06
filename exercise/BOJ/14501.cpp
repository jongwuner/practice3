#include<iostream>
#include<algorithm>
using namespace std;
int N, DP[105], ses[105], ben[105];
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &ses[i], &ben[i]);
	}
	for (int i = 1; i <= N + 1; i++) {
		DP[i] = max(DP[i], DP[i - 1]);
		DP[i + ses[i]] = max(DP[i + ses[i]], DP[i] + ben[i]);
	}
	printf("%d\n", DP[N + 1]);
	return 0;
}
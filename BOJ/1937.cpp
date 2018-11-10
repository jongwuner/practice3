#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<utility>
#define MAX 505

using namespace std;

const int mvY[4] = { -1, 0, 1, 0 };
const int mvX[4] = { 0, 1, 0, -1 };
int N, a[MAX][MAX], dp[MAX][MAX], ans;
typedef pair<int, int> Pair;
typedef pair<int, Pair> PPair;
priority_queue<PPair, vector<PPair>, greater<PPair>> pq;
int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &a[i][j]);
			pq.push({ a[i][j],{ i, j } });
			dp[i][j] = 1; // 문제 이해를 보면 거기서 죽는 것도 하루를 사는 것.
		}
	}
	// 우선순위 큐를 쓰는 이유. 숫자 크기가 작은 것으로는 다시 가지 못한다는 조건. 
	// 한번 방문하면 다시 볼 필요 없다. 
	while (!pq.empty()) {
		int val = pq.top().first;
		Pair pos = pq.top().second;
		pq.pop();
		for (int k = 0; k < 4; k++) {
			int nextY = pos.first + mvY[k];
			int nextX = pos.second + mvX[k];
			if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) continue;


			if (a[nextY][nextX] > a[pos.first][pos.second]) {
				int tmp = (dp[nextY][nextX] > dp[pos.first][pos.second] + 1) ? dp[nextY][nextX] : dp[pos.first][pos.second] + 1;
				dp[nextY][nextX] = tmp;
			}
			//값을 초기화해줄때, 지금 검사하는 경로보다, 예전에 더 큰 경로가 있었을 경우에는 초기화하지 않는다.
			ans = max(ans, dp[nextY][nextX]);
		}
	}
	printf("%d\n", ans);
	return 0;
}


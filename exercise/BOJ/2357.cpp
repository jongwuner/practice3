#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int ROOT = 1;
int N, M, segSize = 1;
vector<Pair> seg;
//first = 최대
//second = 최소.
void init() {
	for (int i = segSize - 1; i >= 1; i--) {
		seg[i].first = max(seg[2 * i].first, seg[2 * i + 1].first);
		seg[i].second = min(seg[2 * i].second, seg[2 * i + 1].second);
	}
}
Pair query(int L, int R, int nodeIdx, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return{ -1e9, 1e9 };
	if (L <= nodeL && nodeR <= R) return seg[nodeIdx];
	int mid = (nodeL + nodeR) / 2;
	Pair left = query(L, R, 2 * nodeIdx, nodeL, mid);
	Pair right = query(L, R, 2 * nodeIdx + 1, mid + 1, nodeR);
	return { max(left.first, right.first), min(left.second, right.second) };
}
int main() {
	scanf("%d%d", &N, &M);
	while (segSize < N) segSize *= 2;
	seg.resize(2 * segSize, { -1e9, 1e9 });
	for (int i = 0; i < N; i++) {
		scanf("%d", &seg[i + segSize].first);
		seg[i + segSize].second = seg[i + segSize].first;
	}
	init();
	for (int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		a--; b--;
		Pair ans = query(a, b, ROOT, 0, segSize - 1);
		printf("%d %d\n", ans.second, ans.first);
	}
	return 0;
}
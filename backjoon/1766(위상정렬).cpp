#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> E[32001];
int V[32001] = { 0 };
void solve() {
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 1; i <= N; ++i) {
		if (V[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		for (int i = 0; i < E[cur].size(); ++i) {
			int e = E[cur][i];
			--V[e];
			if (V[e] == 0)
				pq.push(e);
		}
		cout << cur << ' ';
	}

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		E[a].push_back(b);
		++V[b];
	}
	solve();
	return 0;
}
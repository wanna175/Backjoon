#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int truth[51] = { 0 };
int graph[51][51] = { 0 };
void solve(int N) {//BFS
	queue<int> q;
	for (int i = 1; i <= N; ++i)
		if (truth[i] == 1)
			q.push(i);
	while (q.size() > 0) {
		int cur = q.front();
		for (int i = 1; i <= N; ++i)
			if (graph[cur][i] == 1 && truth[i] != 1) {
				truth[i] = 1;
				q.push(i);
			}
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M,know;
	cin >> N >> M;
	cin >> know;
	for (int i = 0; i < know; ++i) {
		int t;
		cin >> t;
		truth[t] = 1;
	}
	map<int, vector<int>> m;
	for (int i = 0; i < M; ++i) {
		int t;
		cin >> t;
		vector<int> come(t, 0);
		for (int j = 0; j < t; ++j)
			cin >> come[j];
		for(int j=0;j<t-1;++j)
			for (int k = j + 1; k < t; ++k) {
				graph[come[j]][come[k]] = 1;
				graph[come[k]][come[j]] = 1;
			}
		m[i] = come;
	}
	solve(N);
	int answer=M;
	for(int i=0;i<M;++i)
		for(int j=0;j<m[i].size();++j)
			if (truth[m[i][j]] == 1) {
				--answer; break;
			}
	cout << answer;
	return 0;
}
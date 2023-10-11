#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int graph[101][101] = { 0 };
int solve(int V, int N) {
	int ret = 0;
	vector<int> bfs(N + 1, 0);
	queue<int> q;
	q.push(V);
	bfs[V] = 1;
	while (q.size() > 0) {
		ret++;
		for (int i = 1; i <= N; ++i) {
			if (graph[q.front()][i] != 0
				&& bfs[i]==0) {
				q.push(i);
				bfs[i] = bfs[q.front()]+1;
			}
		}
		q.pop();
	}
	for (int i = 1; i <= N; ++i) 
		ret += bfs[i];
	return ret-N;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int min = 1000000,ret=-1;
	vector<int> Kevin_Bacon(N + 1, 0);
	for (int i = 0; i < M; ++i) {
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2]++;
		graph[tmp2][tmp1]++;
	}
	for (int i = 1; i <= N; ++i) {
		Kevin_Bacon[i] = solve(i, N);
		if (min > Kevin_Bacon[i]) {
			ret = i;
			min = Kevin_Bacon[i];
		}
	}
	cout << ret;
	return 0;
}
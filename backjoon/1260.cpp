#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int graph[1001][1001] = { 0 };
void DFS(int V,int N,vector<int>& dfs) {
	if (dfs.size() == N)
		return;
	dfs.push_back(V);
	for (int i = 1; i <= N; ++i) {
		if (graph[V][i] != 0
			&&find(dfs.begin(),dfs.end(),i)==dfs.end())
			DFS(i, N,dfs);
	}
}
void BFS(int V,int N,vector<int>& bfs){
	queue<int> q;
	q.push(V);
	bfs.push_back(V);
	while (q.size() > 0) {
		for (int i = 1; i <= N; ++i) {
			if (graph[q.front()][i] != 0
				&& find(bfs.begin(), bfs.end(), i) == bfs.end()) {
				q.push(i);
				bfs.push_back(i);
			}
		}
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, V;
	cin >> N >> M >> V;
	for (int i = 0; i < M; ++i) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		graph[tmp1][tmp2]++;
		graph[tmp2][tmp1]++;
	}
	vector<int> dfs,bfs;
	DFS(V, N,dfs);
	BFS(V, N, bfs);
	for (int i = 0; i < dfs.size(); ++i)
		cout << dfs[i] << ' ';
	cout << endl;
	for (int i = 0; i < bfs.size(); ++i)
		cout << bfs[i] << ' ';
	return 0;
}
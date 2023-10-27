#include <iostream>
#include <vector>
using namespace std;
#define pii pair<int,int>
int N, E, INF = 800001;
vector<pii> aE[801];//정점당 간선 저장배열
bool visited[801] = { false };
int DFS(int V,int dest,int cur) {
	int ret=INF;
	if (V == dest)
		return cur;
	visited[V] = true;
	for (int i = 0; i < aE[V].size(); ++i) {
		int next = aE[V][i].second;
		int cost = aE[V][i].first;
		if (!visited[next])
			ret = min(ret, DFS(next, dest, cur+cost));
	}
	visited[V]=false;
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		aE[a].push_back({ c,b });
		aE[b].push_back({ c,a });
	}
	int v1, v2;
	cin >> v1 >> v2;
	int s = DFS(v1, v2, 0);
	int f1 = DFS(1, v1, 0), f2 = DFS(1, v2, 0);
	int t2 = DFS(v2, N, 0), t1 = DFS(v1, N, 0);
	int ret = f1 + t2;
	ret = min(ret, f2 + t1);
	ret += s;
	if (s == INF || (f1 == INF && f2 == INF)
		|| (t1 == INF && t2 == INF))
		cout << -1;
	else
		cout << ret;
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
int N, E, INF = 800001;
vector<pii> aE[801];//정점당 간선 저장배열
vector<int> d;
void dijkstra(int V) {
	d.clear();
	d.resize(N + 1, INF);
	d[V] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,V });

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (distance > d[current]) continue;
		for (int i = 0; i < aE[current].size(); ++i) {
			int next = aE[current][i].second;
			int next_distance = aE[current][i].first+distance;
			if (d[next] > next_distance) {
				d[next] = next_distance;
				pq.push({ -next_distance,next });
			}
		}
	}

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
	int f1,f2,s,t1,t2;
	dijkstra(1);
	f1 = d[v1];
	f2 = d[v2];
	dijkstra(v1);
	s = d[v2];
	t1 = d[N];
	dijkstra(v2);
	t2 = d[N];
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
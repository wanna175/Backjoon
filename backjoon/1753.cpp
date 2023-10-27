#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int ,int>
using namespace std;
int V, E,K,INF=200001;
vector<pii> a[20001];
vector<int> d;
void djikstra(int v) {
	d.clear();
	d.resize(V + 1, INF);
	d[v] = 0;
	priority_queue<pii> pq;
	pq.push({ 0,v });

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (distance > d[current]) continue;
		for (int i = 0; i < a[current].size(); ++i) {
			int next = a[current][i].second;
			int next_distance = distance + a[current][i].first;

			if (next_distance < d[next]) {
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
	cin >> V >> E >> K;
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back({ w,v });
	}
	djikstra(K);
	for (int i = 1; i < d.size(); ++i) {
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}

	return 0;
}
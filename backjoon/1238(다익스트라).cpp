#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, X,INF=100001;
vector<pair<int,int>> cost[1001];
vector<int> d;
int cache_d[1001] = {0};
void dijkstra(int start) {
	d.clear();
	d.resize(N + 1, INF);
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0,start));

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (distance > d[current]) continue;

		for (int i = 0; i < cost[current].size(); ++i) {
			int next = cost[current][i].second;
			int next_distance = distance + cost[current][i].first;

			if (next_distance < d[next]) {
				d[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> X;
	for (int i = 0; i < M; ++i) {
		int first, second, value;
		cin >> first >> second >> value;
		cost[first].push_back(make_pair(value, second));
	}
	for (int i = 1; i <= N; ++i) {
		if (i != X) {
			dijkstra(i);
			cache_d[i] = d[X];
		}
	}
	dijkstra(X);
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		cache_d[i] += d[i];
		ret = max(ret, cache_d[i]);
	}
	cout << ret;
	return 0;
}
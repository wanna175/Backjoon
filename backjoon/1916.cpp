#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>
using namespace std;
int N, M, INF = 100000001;
vector<pii> a[1001];
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
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		a[s].push_back({ c,e });
	}
	int s, e;
	cin >> s >> e;
	dijkstra(s);
	cout << d[e];

	return 0;
}

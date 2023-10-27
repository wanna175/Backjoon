#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, X, INF = 100001;
vector<pair<int, int>> cost[2][1001];//거꾸로 경로도 저장
vector<int> d[2];
void dijkstra(int k) {
	d[k].clear();
	d[k].resize(N + 1, INF);
	d[k][X] = 0;//무조건 X에서 출발
	priority_queue<pair<int, int>> pq;
	pq.push({0, X});

	while (!pq.empty()) {
		int current = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (distance > d[k][current]) continue;

		for (int i = 0; i < cost[k][current].size(); ++i) {
			int next = cost[k][current][i].second;
			int next_distance = distance + cost[k][current][i].first;

			if (next_distance < d[k][next]) {
				d[k][next] = next_distance;
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
		cost[0][first].push_back({ value, second });
		cost[1][second].push_back({ value, first });
	}
	dijkstra(1);
	dijkstra(0);
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		ret = max(ret, d[0][i]+d[1][i]);
	}
	cout << ret;
	return 0;
}
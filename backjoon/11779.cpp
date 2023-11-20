#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int,int>

using namespace std;
int n, m, INF = 100000001;
vector<pii> a[1001];//간선 정보
vector<int> d;
vector<int> path;
void dijkstra(int V) {
	d.clear();
	d.resize(n + 1, INF);
	path.clear();
	path.resize(n + 1, 0);
	d[V] = 0;

	priority_queue<pii> pq;
	pq.push({ 0,V });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (distance > d[cur]) continue;
		for (int i = 0; i < a[cur].size(); ++i) {
			int next = a[cur][i].second;
			int next_distance = distance + a[cur][i].first;
			if (d[next] > next_distance) {
				pq.push({ -next_distance,next });
				d[next] = next_distance;
				path[next] = cur;
			}
		}
	}
}
void print_path(int start,int end) {
	int ret = 0, idx = end;
	vector<int> trace;

	trace.push_back(end);
	while (path[idx] != 0) {
		trace.push_back(path[idx]);
		idx = path[idx];
		++ret;
	}
	cout << d[end] << '\n';
	cout << ret + 1 << '\n';
	for (int i = trace.size() - 1; i >= 0; --i)
		cout << trace[i] << ' ';
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		a[s].push_back({ c,e });
	}
	int start, end;
	cin >> start >> end;
	dijkstra(start);
	print_path(start, end);
	return 0;
}
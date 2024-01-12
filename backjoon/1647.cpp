#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> e;
int N, M;
int parent[100001] = { 0 };
vector<e> edges;
vector<e> mst;
int Find(int v) {
	if (parent[v] == v)return v;
	else return parent[v] = Find(parent[v]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) parent[y] = x;
}
int kruskal() {
	int _max = 0;
	int ret = 0;
	for (int i = 0; i < edges.size(); ++i) {
		int s = edges[i].second.first;
		int e = edges[i].second.second;

		if (Find(s) == Find(e)) continue;

		mst.push_back(edges[i]);
		Union(s, e);
		_max = max(_max, edges[i].first);
		ret += edges[i].first;
		if (mst.size() == N - 1) return ret-_max;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i) {
		int n1, n2, c;
		cin >> n1 >> n2 >> c;
		edges.push_back({ c,{n1,n2} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i < 100001; ++i)
		parent[i] = i;
	cout << kruskal();
	return 0;
}
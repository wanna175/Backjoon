#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> e;
int V, E;
int parent[10001] = { 0 };
vector<e> edges;
vector<e> mst;
int Find(int v) {
	if (parent[v] == v) return v;
	else return parent[v] = Find(parent[v]);
}
void Union(int x,int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) parent[y] = x;
}
int kruskal() {
	int ret=0;
	for (int i = 0; i < edges.size(); ++i) {
		int s = edges[i].second.first;
		int e = edges[i].second.second;

		if (Find(s) == Find(e)) continue;//사이클 발생시 다음 최소 간선으로

		mst.push_back(edges[i]);
		Union(s, e);
		ret += edges[i].first;
		if (mst.size() == V - 1) return ret;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	for (int i = 1; i <= E; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		edges.push_back({ c,{s,e} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 1; i <= V; ++i)
		parent[i] = i;
	cout << kruskal();
	return 0;
}
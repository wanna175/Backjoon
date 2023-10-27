#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n,idx=-1,max_v=-1;
vector<pii> a[10001];
bool visited[10001] = { false };
int DFS(int V,int cur) {
	visited[V] = true;
	int ret = -1;
	for (int i = 0; i < a[V].size(); ++i) {
		int next = a[V][i].second;
		int cost = a[V][i].first;
		if(!visited[next])
			ret = max(ret,DFS(a[V][i].second, cur + a[V][i].first));
	}
	visited[V] = false;
	if (ret == -1) {
		if (max_v < cur) {
			max_v = cur;
			idx = V;
		}

		return cur;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		a[s].push_back({ c,e });
		a[e].push_back({ c,s });
	}
	DFS(1, 0);
	cout<<DFS(idx, 0);
	return 0;
}
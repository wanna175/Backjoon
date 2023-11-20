#include <iostream>
#include <vector>
#define pii pair<int,int>
using namespace std;
int n, m, r,INF=1501;
int region[101] = { 0 };
vector<pii> a[101];
vector<vector<int>> d;
void Floyd_Warshall() {
	d.clear();
	d.resize(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; ++i)
		d[i][i] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			d[i][a[i][j].first] = a[i][j].second;
		}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for (int j = 1; j <= n; ++j) {
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];
			}
}
int solve() {
	int sol = 0;
	for (int i = 1; i <= n; ++i) {
		int ret = 0;
		for (int j = 1; j <= n; ++j) {
			if (d[i][j] <= m)
				ret += region[j];
		}
		sol = max(sol, ret);
	}
	return sol;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; ++i)
		cin >> region[i];
	for (int i = 0; i < r; ++i) {
		int s, e, l;
		cin >> s >> e >> l;
		a[s].push_back({ e,l });
		a[e].push_back({ s,l });
	}
	Floyd_Warshall();
	cout << solve();
	return 0;
}
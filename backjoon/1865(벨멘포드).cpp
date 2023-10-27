#include <iostream>
#include <vector>
#include <tuple>
#define ti tuple<int,int,int>
using namespace std;
int N, M, W,INF=5000001;
vector<tuple<int,int,int>> a;
vector<int> d;
bool Bellman_Ford(int V) {
	d.clear();
	d.resize(N + 1, INF);
	d[V] = 0;
	for (int i = 0; i <= N-1; ++i) {
		for (int j = 0; j < a.size(); ++j) {
			int From = get<0>(a[j]);
			int To = get<1>(a[j]);
			int Cost = get<2>(a[j]);

			if (d[From] == INF)	continue;
			if (d[To] > d[From] + Cost)
				d[To] = d[From] + Cost;
		}
	}
	for (int j = 0; j < a.size(); ++j) {
		int From = get<0>(a[j]);
		int To = get<1>(a[j]);
		int Cost = get<2>(a[j]);

		if (d[From] == INF)	continue;
		if (d[To] > d[From] + Cost)
			return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	for (int i = 0; i < TC; ++i) {
		a.clear();
		int s, e, t;
		cin >> N >> M >> W;
		for (int j = 0; j < M; ++j) {
			cin >> s >> e >> t;
			a.push_back({ s,e,t });
			a.push_back({ e,s,t });
		}
		for (int j = 0; j < W; ++j) {
			cin >> s >> e >> t;
			a.push_back({ s,e,-t });
		}
		for (int j = 1; j <= N; ++j) {
			a.push_back({ 0,j,0 });
		}
		bool answer = Bellman_Ford(0);
		if (answer)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int n, m, INF = 10000001;
vector<vector<int>> cache(101,vector<int>(101,INF));
void Floyd_Warshall() {
	for (int k = 1; k <= n; ++k)//거쳐가는 정점
		for (int i = 1; i <= n; ++i)//출발점
			for (int j = 1; j <= n; ++j)//도착점
				if (cache[i][j] > cache[i][k] + cache[k][j])
					cache[i][j] = cache[i][k] + cache[k][j];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if(cache[a][b]>c)
			cache[a][b] = c;
	}
	for (int i = 1; i <= n; ++i)
		cache[i][i] = 0;
	Floyd_Warshall();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (cache[i][j] == INF)
				cout << 0;
			else
				cout << cache[i][j];
			if (j != n)
				cout << ' ';
		}
		cout << '\n';
	}
		
	return 0;
}
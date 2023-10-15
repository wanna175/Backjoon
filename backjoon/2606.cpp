#include <iostream>
#include <vector>
using namespace std;
int path[101][101] = { 0 };
void solve(vector<int>& cache,int cur,int N) {
	cache[cur]++;
	for (int i = 1; i <= N; ++i) {
		if (cache[i] == 0 && path[cur][i] != 0) {
			solve(cache, i, N);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N,E,answer=0;
	cin >> N>>E;
	vector<int> cache(N+1, 0);
	for (int i = 0; i < E; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		path[v1][v2] = 1;
		path[v2][v1] = 1;
	}
	solve(cache, 1, N);
	for (int i = 2; i <= N; ++i)
		if (cache[i] != 0)
			++answer;
	cout << answer;
	return 0;
}
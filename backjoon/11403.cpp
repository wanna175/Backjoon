#include <iostream>

using namespace std;
int N;
int graph[100][100] = { 0 };
int cache[100][100] = { 0 };
void solve(int y,int cur) {
	for (int i = 0; i < N; ++i) {
		if (graph[cur][i] != 0&&cache[y][i]==0) {
			cache[y][i] = 1;
			solve(y,i);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0;i<N;++i)
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	for (int i = 0; i < N; ++i)
		solve(i,i);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; j++) {
			cout << cache[i][j];
			if (j != N - 1)
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}
#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> cache;
vector<vector<int>> board;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	board.resize(N+1, vector<int>(N+1, 0));
	cache.resize(N+1, vector<int>(N+1, 0));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cache[i][j] = board[i][j] + cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1];
	for (int i = 1; i <= M; ++i) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << cache[y2][x2] - cache[y2][x1 - 1] - cache[y1 - 1][x2] + cache[y1 - 1][x1 - 1]<<'\n';
	}
	return 0;
}
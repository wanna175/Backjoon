#include <iostream>

using namespace std;
int board[501][501] = { 0 };
int cache[501][501] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= i; ++j) {
			cin >> board[i][j];
			if (i == N)
				cache[i][j] = board[i][j];
		}
	
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= N - i; ++j)
			cache[N - i][j] = max(cache[N - i + 1][j], cache[N - i + 1][j + 1]) + board[N - i][j];
	}
	cout << cache[1][1];
	return 0;
}
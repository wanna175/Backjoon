#include <iostream>
using namespace std;
int board[2][100001] = { 0 };
int cache[2][100001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, n;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> n;
		for (int j = 1; j <= n; ++j)
			cin >> board[0][j];
		for (int j = 1; j <= n; ++j)
			cin >> board[1][j];
		cache[0][1] = board[0][1];
		cache[1][1] = board[1][1];
		for (int j = 2; j <= n; ++j) {
			cache[0][j] = max(cache[1][j - 1], cache[1][j - 2])+board[0][j];
			cache[1][j] = max(cache[0][j - 1], cache[0][j - 2])+board[1][j];
		}
		cout << max(cache[0][n], cache[1][n])<<'\n';
	}
	return 0;
}
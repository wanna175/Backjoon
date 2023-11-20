#include <iostream>

using namespace std;
int N;
int board[17][17] = { 0 };
int dp[3][17][17] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> board[i][j];
	dp[0][1][2] = 1;//초기값 저장
	for (int i = 3; i <= N; ++i) {
		if (board[1][i] != 0)
			break;
		dp[0][1][i] = 1;
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 2; j <= N; ++j) {
			if (board[i][j] != 0) continue;
			dp[0][i][j] = dp[1][i][j-1] + dp[0][i][j-1];
			dp[2][i][j] = dp[1][i - 1][j] + dp[2][i - 1][j];
			if (board[i - 1][j] != 0 || board[i][j - 1] != 0)
				continue;
			dp[1][i][j] = dp[0][i - 1][j - 1] + dp[1][i - 1][j - 1] + dp[2][i - 1][j - 1];
		}
	}
	cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N];
	return 0;
}
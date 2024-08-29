#include<iostream>
#define M 1000000000
using namespace std;
int N;
int dp[101][10];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < 10; ++i)
		dp[1][i] = 1;

	for (int i = 2; i < 101; ++i) {
		dp[i][0] = dp[i - 1][1]%M;
		for (int j = 1; j < 9; ++j)
			dp[i][j] = (dp[i - 1][j - 1] % M + dp[i - 1][j + 1] % M) % M;
		dp[i][9] = dp[i - 1][8] % M;
	}
	int sum = 0;
	for (int i = 0; i < 10; ++i)
		sum = (sum+ dp[N][i]) % M;
	cout << sum;
	return 0;
}
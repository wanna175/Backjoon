#include <iostream>

using namespace std;
int N,mod = 1000000000;
int dp[10][101][1024] = { 0 };
int solve(int cur_num,int n,int bit) {
	if (dp[cur_num][n][bit] != 0) return dp[cur_num][n][bit];
	if (N <= n) {
		if (bit == 1023)return 1;
		return 0;
	}
	int ret = 0;
	if (cur_num < 9) {
		ret += solve(cur_num + 1, n + 1, bit | 1 << cur_num+1);
	}
	if (cur_num > 0) {
		ret += solve(cur_num - 1, n + 1, bit | 1 << cur_num-1);
	}
	ret %= mod;
	return dp[cur_num][n][bit] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int answer = 0;
	for (int i = 1; i < 10; ++i) {
		answer += solve(i, 1, 1 << i);
		answer %= mod;
	}
	cout << answer;
	return 0;
}
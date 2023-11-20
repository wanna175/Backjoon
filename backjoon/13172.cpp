#include<iostream>

using namespace std;
int M,mod = 1000000007;
int dice[10001][2] = { 0 };
long long calculate_power(int n,int m) {
	if (m == 1)
		return n%mod;
	long long ret;
	if (m % 2 == 0) {
		long long c = calculate_power(n, m / 2);
		ret = (c*c) % mod;
	}
	else {
		long long c = calculate_power(n, (m-1) / 2);
		ret = (c*c) % mod;
		ret = (ret * n) % mod;
	}
	return ret;
}
long long solve() {
	long long Q=0;
	for (int i = 1; i <= M; ++i) {
		Q += (calculate_power(dice[i][0], mod - 2)*dice[i][1])%mod;
		Q %= mod;
	}
	return Q;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	for (int i = 1; i <= M; ++i)
		cin >> dice[i][0] >> dice[i][1];
	cout << solve();
	return 0;
}
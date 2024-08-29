#include<iostream>
#include<cmath>
#include<algorithm>
#define M 1500002
using namespace std;
int N;
int T[M];
int P[M];
int dp[M];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> T[i] >> P[i];

	//뒤에서 부터 dp를 채운다.
	for (int i = N; i >= 1; --i) {
		if(i+T[i]>N+1){
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i + T[i]] + P[i], dp[i + 1]);
	}

	cout << *max_element(dp, dp + N + 1);
	return 0;
}
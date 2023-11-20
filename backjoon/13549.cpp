#include<iostream>
using namespace std;
int N, K;
int DP[100001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;

	for (int i = N - 1; i >= 0; --i)
		DP[i] = DP[i + 1] + 1;
	for (int i = N + 1; i <= K; ++i) {
		if (i % 2 == 0)
			DP[i] = min(DP[i - 1] + 1, DP[i / 2]);
		else
			DP[i] = min(DP[i - 1] + 1, DP[(i + 1) / 2] + 1);
	}
	cout << DP[K];
	return 0;
}
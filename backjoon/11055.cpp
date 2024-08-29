#include<iostream>

using namespace std;
int N;
int arr[1000];
int dp[1000];
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int mv = 0;
	int cmp;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		dp[i] = arr[i];
		cmp = 0;
		for (int j = 0; j <i; ++j) {
			if (arr[j] < arr[i]&&dp[j]>cmp) {
				cmp = dp[j];
			}
		}
		dp[i] += cmp;
		if (mv < dp[i]) mv = dp[i];
	}

	cout << mv;

	return 0;
}
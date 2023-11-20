#include<iostream>
using namespace std;
int N, K;
int DP[100001] = { 0 };
int DP2[100001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	DP2[N] = 1;
	for (int i = N - 1; i >= 0; --i) {
		DP[i] = DP[i + 1] + 1;
		DP2[i] = 1;
	}
	for (int i = N + 1; i <= K; ++i) {
		if (i % 2 == 0) {
			DP[i] = min(DP[i - 1] + 1, DP[i / 2]+1);
			if (DP[i - 1] == DP[i / 2])
				DP2[i]=DP2[i-1]+DP2[i/2];
			else {
				if (DP[i] == DP[i / 2]+1)
					DP2[i] = DP2[i/2];
				else
					DP2[i] = DP2[i - 1];
			}
		}
		else {
			DP[i] = min(DP[i - 1]+ 1, DP[(i + 1) / 2] + 2);
			if (DP[i - 1]== DP[(i + 1) / 2]+1)
				DP2[i] = DP2[i - 1] + DP2[(i + 1) / 2];
			else {
				if (DP[i] == DP[i - 1] + 1)
					DP2[i] = DP2[i - 1];
				else
					DP2[i] = DP2[(i + 1) / 2];
			}
		}
	}
	cout << DP[K]<<'\n'<<DP2[K];
	return 0;
}
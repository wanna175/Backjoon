#include <iostream>
using namespace std;
int N;
int A[1000] = { 0 };
int DPu[1000] = { 0 };
int DPd[1000] = { 0 };
int solve() {
	int ret = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (A[i] > A[j])
				DPu[i] = max(DPu[i], DPu[j] + 1);
		}
	}
	for (int i = N-1; i >=0; --i) {
		for (int j = i +1; j < N; ++j) {
			if (A[i] > A[j])
				DPd[i] = max(DPd[i], DPd[j] + 1);
		}
	}
	for (int i = 0; i < N; ++i)
		ret = max(ret, DPu[i] + DPd[i] + 1);
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	cout << solve();
	return 0;
}
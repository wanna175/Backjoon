#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N,M;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> M;
		vector<int> A, B;
		int ai = 0, bi = 0,ans=0;
		for (int n = 0; n < N; ++n) {
			int a; cin >> a;
			A.push_back(a);
		}
		for (int m = 0; m < M; ++m) {
			int b; cin >> b;
			B.push_back(b);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (ai; ai < N; ++ai) {
			for (bi; bi < M && A[ai] > B[bi]; ++bi);
			ans += bi;
		}
			cout<< ans << '\n';
	}

	return 0;
}
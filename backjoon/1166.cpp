#include<iostream>
#include<iomanip>
#include<cmath>
#define LL long long
using namespace std;
double solve(double A,LL N,LL L
	,LL W,LL H) {
	double ldx = 0, rdx = A, mid;
	for (int i = 0; i < 10000; ++i) {
		mid = (ldx + rdx) / 2;
		LL l = L / mid, w = W / mid, h = H / mid;
		if (l*w*h < N)
			rdx = mid;
		else
			ldx = mid;
	}
	return ldx;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout << setprecision(32);

	LL N, L, W, H;
	cin >> N >> L >> W >> H;
	double A = min(L, min(W, H));
	cout << solve(A, N, L, W, H);
	return 0;
}
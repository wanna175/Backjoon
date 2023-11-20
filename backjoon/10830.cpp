#include <iostream>
#include <vector>
#include <map>
#define Matrix vector<vector<int>>
using namespace std;
int N,mod=1000;long long B;
map<long long, Matrix> cache;
Matrix mat_multi(Matrix a, Matrix b) {
	Matrix mat;
	mat.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			long long ret = 0;
			for (int k = 0; k < N; ++k) {
				ret += a[i][k]*b[k][j]%mod;
			}
			mat[i][j] = ret % mod;
		}
	}
	return mat;
}
Matrix solve(long long n) {
	if (cache.find(n)!=cache.end()) return cache[n];
	Matrix ret;
	if (n % 2 == 0) {
		Matrix mat= solve(n / 2);
		ret = mat_multi(mat, mat);
	}
	else {
		Matrix mat = solve((n-1) / 2);
		ret = mat_multi(mat, mat);
		ret = mat_multi(ret, cache[1]);
	}
	return cache[n] = ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> B;
	Matrix mat,ret;
	mat.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j) {
			cin >> mat[i][j];
			mat[i][j] %= mod;
		}
	cache[1] = mat;
	ret = solve(B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ret[i][j];
			if (j != N - 1)
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
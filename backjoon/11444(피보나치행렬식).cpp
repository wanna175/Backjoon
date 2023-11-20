#include <iostream>
#include <map>
#include <vector>
#define Matrix vector<vector<long long>>
using namespace std;
int N=2, mod = 1000000007; long long B;
map<long long, Matrix> cache;
Matrix mat_multi(Matrix a, Matrix b) {
	Matrix mat;
	mat.resize(N, vector<long long>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			long long ret = 0;
			for (int k = 0; k < N; ++k) {
				ret += a[i][k] * b[k][j] % mod;
			}
			mat[i][j] = ret % mod;
		}
	}
	return mat;
}
Matrix pow_mat(long long n) {
	if (cache.find(n) != cache.end()) return cache[n];
	Matrix ret;
	if (n % 2 == 0) {
		Matrix mat = pow_mat(n / 2);
		ret = mat_multi(mat, mat);
	}
	else {
		Matrix mat = pow_mat((n - 1) / 2);
		ret = mat_multi(mat, mat);
		ret = mat_multi(ret, cache[1]);
	}
	return cache[n] = ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> B;
	Matrix mat(2, vector<long long>(2, 1));
	mat[1][1] = 0;
	cache[1] = mat;
	Matrix ret;
	ret = pow_mat(B);
	cout << ret[0][1];
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int A, B, C;
long long solve(int n) {
	if (n == 1)
		return A % C;
	long long ret;
	if (n % 2 == 0)
		ret = solve(n / 2) * solve(n / 2);
	else
		ret = (solve((n - 1) / 2)* (solve((n - 1) / 2))%C) *A;
	return ret%C;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	cout << solve(B);
	return 0;
}
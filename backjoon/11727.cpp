#include <iostream>

using namespace std;
int cache[1001] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	cache[1] = 1;
	cache[2] = 3;
	for (int i = 3; i <= n; ++i) {
		cache[i] = (cache[i - 1] + cache[i - 2] * 2) % 10007;
	}
	cout << cache[n];
	return 0;
}
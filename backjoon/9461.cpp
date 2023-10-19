#include <iostream>

using namespace std;
long long cache[101] = { 0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 1;
	cache[4] = 2;
	cache[5] = 2;
	for (int i = 6; i <= 100; ++i)
		cache[i] = cache[i - 1] + cache[i - 5];
	for (int i = 0; i < T; ++i) {
		int t;
		cin >> t;
		cout << cache[t] << '\n';
	}
	return 0;
}
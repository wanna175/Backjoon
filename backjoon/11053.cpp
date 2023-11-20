#include <iostream>
#include <vector>
using namespace std;
int N;
int cache[1001] = { 0 };
vector<int> arr;
int solve() {
	int ret = 0;
	for (int i = 1; i <= N; ++i) {
		int cur = arr[i];
		for (int j = i + 1; j <= N; ++j) {
			if (cur < arr[j])
				cache[j] = max(cache[i] + 1,cache[j]);
		}
		ret = max(ret, cache[i]);
	}
	return ret+1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	arr.resize(N + 1, 0);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	cout << solve();
	return 0;
}

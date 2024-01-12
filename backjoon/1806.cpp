#include <iostream>
#define INF 100000
using namespace std;
int N, S;
int nums[INF] = { 0 };
int solve() {
	int left = 0, right = 0, sum = nums[0];
	int _min = INF+1;
	while (true) {
		if (sum< S) {
			right++;
			if (right >= N)
				break;
			sum += nums[right];
		}
		else if (sum >= S) {
			_min = min(_min, right - left + 1);
			if (left == right) {
				right++;
				if (right >= N)
					break;
				sum += nums[right];
			}
			sum -= nums[left];
			left++;
		}
	}
	if (_min == INF + 1)
		_min = 0;
	return _min;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	cout << solve();
	return 0;
}
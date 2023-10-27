#include <iostream>
#include <vector>
using namespace std;
int N;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int min_cache[3],min_next[3];
	int max_cache[3],max_next[3];
	cin >> min_cache[0] >> min_cache[1] >> min_cache[2];
	max_cache[0] = min_cache[0];
	max_cache[1] = min_cache[1];
	max_cache[2] = min_cache[2];

	for (int i = 2; i <= N; ++i) {
		int v1, v2, v3;
		cin >> v1 >> v2 >> v3;
		max_next[0] = max(max_cache[0], max_cache[1]) + v1;
		max_next[1] = max(max_cache[0], max(max_cache[1],max_cache[2])) + v2;
		max_next[2] = max(max_cache[1], max_cache[2]) + v3;

		min_next[0] = min(min_cache[0], min_cache[1]) + v1;
		min_next[1] = min(min_cache[0], min(min_cache[1], min_cache[2])) + v2;
		min_next[2] = min(min_cache[1], min_cache[2]) + v3;

		max_cache[0] = max_next[0];
		max_cache[1] = max_next[1];
		max_cache[2] = max_next[2];

		min_cache[0] = min_next[0];
		min_cache[1] = min_next[1];
		min_cache[2] = min_next[2];
	}

	cout << max(max(max_cache[0], max_cache[1]), max_cache[2]) << ' ';
	cout << min(min(min_cache[0], min_cache[1]), min_cache[2]);
	return 0;
}
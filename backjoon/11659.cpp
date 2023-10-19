#include <iostream>
#include <vector>
using namespace std;
int cache[100001] = { 0 };
void solve(const vector<int>& arr) {
	cache[1] = arr[1];
	for (int i = 2; i < arr.size(); ++i)
		cache[i] = arr[i] + cache[i - 1];
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> arr(N + 1, 0);
	vector<int> answer(M, 0);
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	solve(arr);
	for (int i = 0; i < M; ++i) {
		int l, r;
		cin >> l >> r;
		answer[i] = cache[r] - cache[l - 1];
	}
	for (int i = 0; i < M; ++i)
		cout << answer[i] << '\n';
	return 0;
}
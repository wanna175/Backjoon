#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int k;
int arr[13];
void backtracking(int idx, int m, string ans) {
	ans += to_string(arr[idx]);
	if (m == 1) {
		cout << ans << '\n';
		return;
	}
	ans += " ";
	for (int i = idx + 1; i < k; ++i)
		backtracking(i, m - 1, ans);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		fill_n(&arr[0], 13,0);
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; ++i) cin >> arr[i];
		for (int i = 0; i <= k - 6; ++i) backtracking(i, 6, "");
		cout << '\n';
	}
	return 0;
}
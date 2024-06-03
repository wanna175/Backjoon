#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int N, M;
vector<int> arr;
map<string, bool> val;
void backtracking(int idx,int m, string ans) {
	ans += to_string(arr[idx]);
	if (m == 1) {
		if (val.find(ans) != val.end()) return;
		cout << ans << '\n';
		val[ans] = true;
		return;
	}
	ans += " ";
	for (int i = idx+1; i < N; ++i) {
		backtracking(i, m - 1, ans);
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < N; ++i) backtracking(i, M, "");
	return 0;
}
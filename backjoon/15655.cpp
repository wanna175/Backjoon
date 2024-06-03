#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int N, M;
vector<int> arr;
void backtracking(int n,int m,string ans) {
	if (m == 1) {
		cout << ans + to_string(n) << "\n";
		return;
	}
	ans += to_string(n) + " ";
	for (int v:arr) {
		if (v<=n) continue;
		backtracking(v, m - 1, ans);
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
	for (int v : arr) {
		backtracking(v, M, "");
	}
	return 0;
}
#include<iostream>
#include<string>
using namespace std;
int N, M;
void backtracking(int n,int m,string ans) {
	if (m == 1) {
		cout << ans + to_string(n) << '\n';
		return;
	}
	ans += to_string(n)+" ";
	for (int i = 1; i <= N; ++i)
		backtracking(i, m - 1, ans);
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		backtracking(i, M, "");
	return 0;
}
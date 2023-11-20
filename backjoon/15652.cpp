#include<iostream>
#include<vector>
using namespace std;
int N, M;
void solve(int picked, vector<int>& s) {
	if (picked == M) {
		for (int i = 0; i < M; ++i) {
			cout << s[i];
			if (i != M - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}
	int m = (s.size()!=0)?s.back():1;
	for (int i = m; i <= N; ++i) {
		s.push_back(i);
		solve(picked + 1, s);
		s.pop_back();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> s;
	cin >> N >> M;
	solve(0, s);
	return 0;
}
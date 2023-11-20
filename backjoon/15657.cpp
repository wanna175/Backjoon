#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int> vec;
void solve(int picked, vector<int>& s,int sel) {
	if (picked == M) {
		for (int i = 0; i < M; ++i) {
			cout << s[i];
			if (i != M - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = sel; i < N; ++i) {
		s.push_back(vec[i]);
		solve(picked + 1, s,i);
		s.pop_back();
	}

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	vector<int> s;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int s; cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end());
	solve(0, s,0);
	return 0;
}
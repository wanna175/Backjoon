#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int N, M;
vector<int> vec;
map<vector<int>,bool> cache;
bool visited[8] = { false };
void solve(int picked,vector<int>& s) {
	if (picked == M&&!cache[s]) {
		cache[s] = true;
		for (int i = 0; i < M; ++i) {
			cout << s[i];
			if (i != M - 1)
				cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			s.push_back(vec[i]);
			solve(picked + 1, s);
			s.pop_back();
			visited[i] = false;
		}
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
	solve(0, s);
	return 0;
}

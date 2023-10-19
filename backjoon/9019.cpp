#include <iostream>
#include <queue>
#include <string>
using namespace std;
int A, B;
queue<int> q;
void Push(vector<string>& cache, int next, int cur,string cmd) {
	if (cache[next] != "")
		return;
	q.push(next);
	cache[next] = (cache[cur] != "start") ? cache[cur] + cmd : cmd;
}
void solve(vector<string>& cache) {
	while (q.size() > 0) {
		int cur = q.front();
		if (cur == B)
			return;
		int d = (cur * 2) % 10000;
		int s = (cur == 0) ? 9999 : cur - 1;
		int l = (cur * 10) % 10000 + cur / 1000;
		int r = (cur % 10) * 1000 + cur / 10;
		Push(cache, d, cur,"D");
		Push(cache, s, cur,"S");
		Push(cache, l, cur,"L");
		Push(cache, r, cur,"R");
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		vector<string> cache(10000, "");
		cin >> A >> B;
		cache[A] = "start";
		q.push(A);
		solve(cache);
		cout << cache[B] << '\n';
		q = queue<int>();
	}
	return 0;
}
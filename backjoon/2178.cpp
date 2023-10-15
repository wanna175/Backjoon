#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<string> path(100, "");
int cache[100][100] = { 0 };
int N, M;
void move(queue<pair<int, int>>& q, int y, int x,int cury,int curx) {
	if (y<0 || y>N - 1 || x<0 || x>M - 1
		||path[y][x]=='0'||cache[y][x]!=0)
		return;
	q.push(make_pair(y, x));
	cache[y][x] = cache[cury][curx] + 1;
}
int solve() {
	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	cache[0][0] = 1;
	while (q.size()>0) {
		int y = q.front().first;
		int x = q.front().second;
		if (y == N - 1 && x == M - 1)
			return cache[y][x];
		move(q, y + 1, x, y, x);
		move(q, y - 1, x, y, x);
		move(q, y, x + 1, y, x);
		move(q, y, x - 1, y, x);
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> path[i];
	cout << solve();
	return 0;
}
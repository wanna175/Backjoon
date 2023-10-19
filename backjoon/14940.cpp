#include <iostream>
#include <queue>
using namespace std;
int n, m;
int board[1001][1001] = { 0 };
int cache[1001][1001] = { 0 };
void checkRangePush(queue<pair<int,int>>& q,pair<int, int> pos,pair<int,int> cur) {
	if(1 > pos.first || 1 > pos.second || n < pos.first || m < pos.second
		||cache[pos.first][pos.second]!=0|| board[pos.first][pos.second]==0|| board[pos.first][pos.second] == 2)
		return;
	q.push(pos);
	cache[pos.first][pos.second] = cache[cur.first][cur.second] + 1;
}
void solve(queue<pair<int,int>>& q) {
	while (q.size() > 0) {
		int y = q.front().first, x = q.front().second;
		checkRangePush(q, make_pair(y + 1, x), q.front());
		checkRangePush(q, make_pair(y - 1, x), q.front());
		checkRangePush(q, make_pair(y, x + 1), q.front());
		checkRangePush(q, make_pair(y, x - 1), q.front());
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<pair<int, int>> q;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 2)
				q.push(make_pair(i, j));
		}
	solve(q);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (board[i][j] == 1 && cache[i][j] == 0)
				cout << -1;
			else
				cout << cache[i][j];
			if (j != m)
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
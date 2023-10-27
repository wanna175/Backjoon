#include <iostream>
#include <queue>
using namespace std;

int path[101] = { 0 };
int board[101] = { 0 };
void move(int num,int cur,queue<int>& q) {
	int next = num + cur;
	if (next > 100)
		return;
	if (path[next] != 0)
		next = path[next];
	if (board[next] != 0)
		return;
	q.push(next);
	board[next] = board[cur] + 1;
}
void solve() {
	queue<int> q;
	q.push(1);
	while (q.size() > 0) {
		if (q.front() == 100)
			break;
		move(1, q.front(), q);
		move(2, q.front(), q);
		move(3, q.front(), q);
		move(4, q.front(), q);
		move(5, q.front(), q);
		move(6, q.front(), q);
		q.pop();
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y;
	cin >> N >> M;
	for (int i = 0; i < N + M; ++i) {
		cin >> x >> y;
		path[x] = y;
	}
	solve();
	cout << board[100];
	return 0;
}
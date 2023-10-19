#include <iostream>
#include <queue>
using namespace std;
int M, N;
int box[1000][1000] = { 0 };
int queuePush(queue<pair<int, int>>& q,int y, int x,pair<int,int> prev) {
	if (y < 0 || x < 0 || M <= x || N <= y || box[y][x] != 0)
		return 0;
	q.push(make_pair(y, x));
	box[y][x] = box[prev.first][prev.second] + 1;
	return 1;
}
int solve(queue<pair<int,int>>& q,int empty) {
	int cnt = q.size();
	pair<int, int> pos;
	while (q.size()>0) {
		pos = q.front();
		int y = pos.first;
		int x = pos.second;
		cnt += queuePush(q, y + 1, x, pos);
		cnt += queuePush(q, y, x + 1, pos);
		cnt += queuePush(q, y - 1, x, pos);
		cnt += queuePush(q, y, x - 1, pos);
		q.pop();
	}
	if (empty + cnt < M * N)
		return -1;
	return box[pos.first][pos.second] - 1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int empty = 0;
	queue<pair<int,int>> q;
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push(make_pair(i, j));
			if (box[i][j] == -1)
				++empty;
		}
	cout << solve(q, empty);
	return 0;
}
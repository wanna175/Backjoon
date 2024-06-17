#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
string board[5];
bool isvisit[5][5];
int answer = 0;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
bool BFS(int y,int x) {
	queue<pair<int, int>> q;
	bool visit[5][5];
	int result = 1;
	bool ret = false;

	fill_n(&visit[0][0], 25, false);
	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || ny>4 || nx < 0 || nx>4) continue;
			if (visit[ny][nx]||!isvisit[ny][nx]) continue;
			visit[ny][nx] = true;
			q.push({ ny,nx });
			result++;
		}
	}
	if (result == 7) {
		ret = true;
	}
	return ret;
}
void backtracking(int y,int x,int m,int s) {
	s += (board[y][x] == 'S') ? 1 : 0;
	isvisit[y][x] = true;
	if (m == 1) {
		if (s > 3 && BFS(y,x)) answer++;
		isvisit[y][x] = false;
		return;
	}
	int i = y, j = x;
	while (true) {
		if (j == 4) {
			i++;
			j = 0;
			if (i > 4) break;
		}
		else j++;
		backtracking(i, j, m - 1, s);
	}
	isvisit[y][x] = false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill_n(&isvisit[0][0], 25, false);
	for (int i = 0; i < 5; ++i) cin >> board[i];
	for(int i=0;i<5;++i)
		for (int j = 0; j < 5; ++j) {
			backtracking(i, j, 7, 0);
		}
	cout << answer;
	return 0;
}
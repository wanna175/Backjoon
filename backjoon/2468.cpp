#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int board[100][100];
bool isvisited[100][100];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
void BFS(int y,int x,int rain) {
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	isvisited[y][x] = true;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (board[ny][nx] <= rain || isvisited[ny][nx]) continue;
			Q.push({ ny,nx });
			isvisited[ny][nx] = true;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	for (int r = 0; r < 100; ++r) {
		int tmp = 0;
		fill_n(&isvisited[0][0], 100 * 100, false);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j) {
				if (!isvisited[i][j] && board[i][j] > r) {
					BFS(i,j,r);
					tmp++;
				}
			}
		if (tmp > answer) answer = tmp;
	}
	cout << answer;
	return 0;
}
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define Y first
#define X second
using namespace std;
int N, M;
int board[300][300];
bool isvisited[300][300];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
void BFS(int y, int x) {
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	isvisited[y][x] = true;
	while (!Q.empty()) {
		int cy = Q.front().Y;
		int cx = Q.front().X;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (board[ny][nx] <= 0 || isvisited[ny][nx]) continue;
			Q.push({ ny,nx });
			isvisited[ny][nx] = true;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0) board[i][j] = -1;
		}
	}
	int time = 1;
	while (true) {
		bool zero = true;
		vector<pair<int, int>> ice;
		for (int i = 1; i < N - 1; ++i) {
			for (int j = 1; j < M - 1; ++j) {
				if (board[i][j] == 0)
					board[i][j] = -1;
				else if (board[i][j] > 0)
					ice.push_back({ i,j });
			}
		}

		for (auto v : ice) {
			for (int d = 0; d < 4; ++d) {
				if (board[v.Y][v.X] == 0) break;
				if (board[v.Y + dy[d]][v.X + dx[d]] == -1) board[v.Y][v.X]--;
			}
			if (board[v.Y][v.X] > 0) zero = false;
		}
		if (zero) {
			time = 0;
			break;
		}
		fill_n(&isvisited[0][0], 300 * 300, false);
		int ret=0;
		for (auto v : ice) {
			if (!isvisited[v.Y][v.X] && board[v.Y][v.X] > 0) {
				BFS(v.Y, v.X); ret++;
			}
		}
		if (ret >= 2)
			break;
		time++;
	}
	cout << time;
	return 0;
}
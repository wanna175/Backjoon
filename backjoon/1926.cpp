#include<iostream>
#include<queue>

using namespace std;

int board[500][500];
bool isvisited[500][500] = {0};
int N, M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int BFS(int y, int x) {
	int ret = 0;
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
			if (ny < 0 || nx < 0 || ny >= N || nx >= M || isvisited[ny][nx]) continue;
			if (board[ny][nx] != 1) continue;
			Q.push({ ny,nx });
			isvisited[ny][nx] = true;
		}
		ret++;
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	int count = 0,answer=0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!isvisited[i][j]&&board[i][j]==1) {
				count++;
				int tmp = BFS(i,j);
				if (answer < tmp)
					answer = tmp;
			}
		}
	}
	cout << count << '\n' << answer;
	return 0;
}
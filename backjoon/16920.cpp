#include<iostream>
#include<queue>

using namespace std;
struct pos {
	int y;
	int x;
	int cnt;
};
int N, M, P;
int Pn[10];
int answer[10];
char board[1000][1000];
queue<pos> border[10];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
void Expension(int p) {
	int fy = -1, fx = -1;
	bool isend = false;
	while (!border[p].empty()) {
		int cy = border[p].front().y;
		int cx = border[p].front().x;
		int cnt = border[p].front().cnt;
		if (isend && fy == cy && fx == cx)
			break;
		if (cnt == Pn[p]) {
			cnt = 0;
		}
		border[p].pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (board[ny][nx] != '.') continue;
			border[p].push({ ny,nx,cnt+1 });
			if (cnt + 1 == Pn[p] && !isend) {
				fy = ny; fx = nx; isend = true;
			}
			board[ny][nx] = p + '0';
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> P;
	for (int i = 1; i <= P; ++i) {
		cin >> Pn[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			int num = board[i][j] - '0';
			if (num >= 1 && num < 10)
				border[num].push({ i,j,0 });
		}
	}
	while (true) {
		for (int i = 1; i <= P; ++i) {
			Expension(i);
		}
		bool isend = true;
		for (int i = 1; i <= P; ++i) {
			if (!border[i].empty()) {
				isend = false;
			}
		}
		if (isend) break;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int num = board[i][j] - '0';
			if (num >= 1 && num < 10)
				answer[num]++;
		}
	}
	for (int i = 1; i <= P; ++i) cout << answer[i] << " ";
	return 0;
}
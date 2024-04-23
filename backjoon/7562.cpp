#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int I;
int y, x;
int target_y, target_x;
int board[300][300];
int dy[8] = { 1,1,2,2,-1,-1,-2,-2 };
int dx[8] = { 2,-2,1,-1,2,-2,1,-1 };
int BFS() {
	queue<pair<int, int>> Q;
	Q.push({ y,x });

	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 8; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= I || nx >= I) continue;
			if (board[ny][nx] == -1) return board[cy][cx];
			if (board[ny][nx] != 0) continue;
			board[ny][nx] = board[cy][cx] + 1;
			Q.push({ ny,nx });
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> I;
		fill(&board[0][0], &board[299][300], 0);
		cin >> y >> x;
		cin >> target_y >> target_x;
		board[y][x] = 1;
		board[target_y][target_x] = -1;
		if (board[y][x] == -1) cout << 0 << '\n';
		else {
			int answer = BFS();
			cout << answer << '\n';
		}
	}

	return 0;
}
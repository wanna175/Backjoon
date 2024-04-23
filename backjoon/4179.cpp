#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int w, h;
char board[1002][1002];
int cnt[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int BFS(const vector<pair<int, int>>& pos, int y, int x) {
	queue<pair<int, int>> Q;
	Q.push({ y,x });
	cnt[y][x] = 1;
	for (auto v : pos) {
		Q.push({ v.first,v.second });
	}
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 1 || nx < 1 || ny > h || nx > w) continue;
			if (board[ny][nx] == 'F' || board[ny][nx] == '#') continue;
			if (board[cy][cx] == 'J') {
				if (board[ny][nx] == 'J')
					continue;
				int flag = false;
				for (int j = 0; j < 4; ++j) {
					if (board[ny + dy[j]][nx + dx[j]] == 'F')
						flag = true;
				}
				if (flag) continue;
				cnt[ny][nx] = cnt[cy][cx] + 1;
				if (ny == 1 || ny == h || nx == 1 || nx == w)
					return cnt[ny][nx];
			}
			Q.push({ ny,nx });
			board[ny][nx] = board[cy][cx];
		}
	}
	return -1;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	int y = -1, x = -1;
	vector<pair<int, int>> fire;
	for (int i = 1; i <= h; ++i) {
		for (int j = 1; j <= w; ++j) {
			cin >> board[i][j];
			cnt[i][j] = 0;
			if (board[i][j] == 'J') {
				y = i; x = j;
				cnt[y][x] = 1;
			}
			else if (board[i][j] == 'F') {
				fire.push_back({ i,j });
			}
		}
	}
	int answer = 0;
	if (y == 1 || y == h || x == 1 || x == w)
		answer = 1;
	else
		answer = BFS(fire, y, x);
	if (answer == -1)
		cout << "IMPOSSIBLE\n";
	else
		cout << answer << '\n';
	return 0;
}
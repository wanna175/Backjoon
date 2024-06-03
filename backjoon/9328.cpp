#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int T;
int h, w;
char board[102][102];
bool isvisited[102][102];
bool bag[26];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int BFS() {
	vector<pair<int, int>> door[26];
	int ret = 0;
	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	isvisited[0][0] = true;
	while (!Q.empty()) {
		int cy = Q.front().first;
		int cx = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny>h+1 || nx>w+1) continue;
			if (board[ny][nx] == '*'||isvisited[ny][nx])continue;
			if ('a' <= board[ny][nx] && board[ny][nx] <= 'z') {
				int idx = board[ny][nx] - 'a';
				bag[idx] = true;
				while (!door[idx].empty()) {
					int y = door[idx].back().first;
					int x = door[idx].back().second;
					door[idx].pop_back();
					Q.push({ y,x });
					isvisited[y][x] = true;
				}
			}
			if ('A' <= board[ny][nx] && board[ny][nx] <= 'Z') {
				if (!bag[board[ny][nx] - 'A']) {
					door[board[ny][nx] - 'A'].push_back({ ny,nx });
					isvisited[ny][nx] = true;
					continue;
				}
			}
			if (board[ny][nx] == '$') ret++;
			isvisited[ny][nx] = true;
			Q.push({ ny,nx });
		}
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> h >> w;
		fill_n(&board[0][0], 102 * 102, '.');
		fill_n(&isvisited[0][0], 102 * 102, false);
		fill_n(bag, 26, false);
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				cin >> board[i][j];
			}
		}
		string keys;
		cin >> keys;
		if (keys.compare("0") != 0)
			for (char v : keys) bag[v - 'a'] = true;
		int answer = BFS();
		cout << answer << '\n';
	}
	return 0;
}
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int R, C;
char board[1500][1500];
bool isvisited[1500][1500];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int swanx, swany;
queue<pair<int, int>> border;
queue<pair<int, int>> swanQ;
void melting() {
	queue<pair<int, int>> Q;
	int cnt = border.size();
	while (cnt>0) {
		int cy = border.front().first;
		int cx = border.front().second;
		board[cy][cx] = '.';
		border.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (board[ny][nx] == 'X') { 
				border.push({ ny,nx });
				board[ny][nx] = '#';
			}
			if (isvisited[ny][nx] && !isvisited[cy][cx]) { 
				swanQ.push({ cy,cx });
				isvisited[cy][cx] = true;
			}
		}
		cnt--;
	}
}
bool BFS() {
	while (!swanQ.empty()) {
		int cy = swanQ.front().first;
		int cx = swanQ.front().second;
		swanQ.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if (isvisited[ny][nx] || board[ny][nx] == 'X'||board[ny][nx]=='#') continue;
			if (board[ny][nx] == 'L') return true;
			isvisited[ny][nx] = true;
			swanQ.push({ ny,nx });
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'L') {
				swany = i; swanx = j;
			}
		}
	}//입력받기
	if (R == 1 && C == 1) {
		cout << 0;
		return 0;
	}
	board[swany][swanx] = '.';
	swanQ.push({ swany,swanx });
	isvisited[swany][swanx] = true;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (board[i][j] != 'X') continue;
			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				if (board[ny][nx] == '.'|| board[ny][nx] == 'L') {
					border.push({ i,j });
					break;
				}
			}
		}
	}//border초기화
	int answer = 0;
	while (!BFS()) {
		answer++;
		melting();
	}
	cout << answer;
	return 0;
}